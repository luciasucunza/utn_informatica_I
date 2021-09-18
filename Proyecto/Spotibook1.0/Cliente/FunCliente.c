/**
 * @file FunCliente.c
 * @author Fiorentino Federico Sucunza Lucia
 * @date 19-12-16
 * @brief Funciones para el Cliente
*/ 
#include "Cliente.h"
/**
 * @fn int ConectarAServidor (char *ipservidor)
 * @brief  Conexión del cliente con el servidor
 * @param *ipservidor Dirección ip del servidor
 * @return Puntero a inicio de la lista, puntero a NULL si el archivo no contiene datos
*/ 
int ConectarAServidor (char *ipservidor)
{
  int sockfd;
  struct hostent *he;
  struct sockaddr_in their_addr;
  
  if((he = gethostbyname(ipservidor)) == NULL)
  {
    perror("Gethostbyname");
    exit(EXIT_FAILURE);
  }

  if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
  {
    perror("Socket");
    exit(EXIT_FAILURE);
  }

  their_addr.sin_family = AF_INET;
  their_addr.sin_port = htons(MYPORT);
  their_addr.sin_addr = *((struct in_addr *)he->h_addr);
  memset(&(their_addr.sin_zero),'\0',8);
	

  if(connect(sockfd,(struct sockaddr*)&their_addr,sizeof(struct sockaddr)) == -1)
  {
    perror("Connect");
    exit(EXIT_FAILURE);
  }
  return sockfd;
}
/**
 * @fn void ManejoLibros (int sockfd)
 * @brief  Menú del administrador para manejo de libros
 * @param sockfd File descriptor del socket
 * @return void
*/
void ManejoLibros (int sockfd)
{  
  int opcion, c;
  nodo *nodoprimero;
  void (*funcionsecundaria[6])(nodo **, int) = {AgregarNodo, BorrarNodo, ModificarNodo, MostrarNodo, LeerLista, Salir };

  if( send(sockfd, "ManejoLibros\n", TAM_DATOS,0) == -1)
  {
    perror("Send");
    exit(EXIT_FAILURE);
  }
  
  nodoprimero = CargarListaRecibida( sockfd );
  do
  {
    do
    {      
      printf( "Menu Libros: 	1)Agregar Libro\n		2)Borrar Libro\n		3)Modificar Libro\n		4)Mostrar Libro\n		5)Leer Lista\n		6)Salir\n");
      scanf("%d", &opcion); 
      while ((c = getchar()) != '\n');
    }while( opcion > 6 || opcion < 1);
    
    opcion--;
    funcionsecundaria[opcion]( &nodoprimero, LIBROS );      
  }while ( opcion != 5 );   
  
  EnviarLista( nodoprimero, sockfd );
  LibrerarLista ( &nodoprimero );
}
/**
 * @fn void ManejoUsuarios (int sockfd)
 * @brief  Menú del administrador para manejo de usuarios
 * @param sockfd File descriptor del socket
 * @return void
*/
void ManejoUsuarios( int sockfd ) 
{  
   int opcion, c;
  nodo *nodoprimero;
  void (*funcionsecundaria[6])(nodo **, int) = {AgregarNodo, BorrarNodo, ModificarNodo, MostrarNodo, LeerLista, Salir };
  
  if( send(sockfd, "ManejoUsuarios\n", TAM_DATOS,0) == -1)
  {
    perror("Send");
    exit(EXIT_FAILURE);
  }
  
  nodoprimero = CargarListaRecibida( sockfd );
  do
  {
    do
    {      
      printf( "Menu Usuarios: 	1)Agregar Usuario\n		2)Borrar Usuario\n		3)Modificar Usuario\n		4)Mostrar Usuario\n		5)Leer Lista\n		6)Salir\n");
      scanf("%d", &opcion); 
      while ((c = getchar()) != '\n');
    }while( opcion > 6 || opcion < 1);
    
    opcion--;
    funcionsecundaria[opcion]( &nodoprimero, USUARIOS );      
  }while ( opcion != 5 );  
  
  EnviarLista( nodoprimero, sockfd );
  LibrerarLista ( &nodoprimero );
}
/**
 * @fn void SalirCliente (int sockfd)
 * @brief  Le avisa al servidor que va a salir
 * @param sockfd File descriptor del socket
 * @return void
*/
void SalirCliente( int sockfd )
{
  if( send(sockfd, "Salir\n", TAM_DATOS,0) == -1)
  {
    perror("Send");
    exit(EXIT_FAILURE);
  }
}
/**
 * @fn nodo * CargarListaRecibida (int sockfd)
 * @brief  El cliente crea una lista a partir del contenido de las estructuras (tanto de libros como de usuarios)
 * @param sockfd File descriptor del socket
 * @return nodo* La direccion de inicio de la lista
*/
nodo * CargarListaRecibida( int sockfd )
{  
  nodo *nodoprimero, *nodonuevo;
  nodoprimero = NULL;
  
  while( 1 )
  {
    nodonuevo = (nodo *)malloc( sizeof(nodo) );  
    nodonuevo->contenido = (contenido *)malloc( sizeof(contenido) );
    
    if( recv(sockfd, nodonuevo->contenido,  sizeof(contenido), 0) != -1)
    {
      if( strcmp(nodonuevo->contenido->datos[TITULO_NOMBRE], "ERROR\n") == 0)
      {
	free( nodonuevo->contenido );
	free( nodonuevo );
	close( sockfd );
	exit(EXIT_FAILURE);
      }
      else if( strcmp(nodonuevo->contenido->datos[TITULO_NOMBRE], "FIN\n") == 0)
      {
	free( nodonuevo->contenido );
	free( nodonuevo );
	break;
      }
      nodonuevo->next = nodoprimero;
      nodoprimero = nodonuevo;
    }
    else
    {
      free( nodonuevo->contenido );
      free( nodonuevo );
      exit(EXIT_FAILURE);
    }
  }  
  return nodoprimero;
}
/**
 * @fn nodo* BuscarNodo ( nodo *nodoprimero, char* cadena )
 * @brief  Busca un nodo a partir de un string
 * @param nodoprimero Dirección de inicio de la lista
 * @param cadena El string que se busca
 * @return La direccion del nodo que contiene la coincidencia o NULL si no hay 
*/
nodo * BuscarNodo( nodo *nodoprimero, char* cadena )
{
  nodo *nodoaux;
  for( nodoaux = nodoprimero ; nodoaux != NULL ; nodoaux = nodoaux->next )
  {
    if( (strcmp(nodoaux->contenido->datos[TITULO_NOMBRE], cadena)) == 0 )
      return nodoaux;
  }
  return NULL;
}
/**
 * @fn void CargaContenido (contenido *contenidonuevo, int manejo)
 * @brief Carga una estructura libro/usuario
 * @param *contenidonuevo Dirección de la estructura a cargar
 * @param manejo Indica si se está trabajando con usuarios o con libros
 * @return Void
*/ 
void CargarContenido (contenido *contenidonuevo, int manejo)
{  
  memset( contenidonuevo->datos[TITULO_NOMBRE], '\n', TAM_DATOS);
  memset( contenidonuevo->datos[AUTOR_CONTRASENA], '\n', TAM_DATOS);
  memset( contenidonuevo->datos[GENERO_PERMISOS], '\n', TAM_DATOS);
  if( manejo == LIBROS )
    printf( "Ingrese titulo, autor y genero del libro:\n" );  
  if( manejo == USUARIOS)
    printf( "Ingrese nombre, contraseña y permiso ( A si es administrador, C si no)del usuario:\n" );
  fgets(contenidonuevo->datos[TITULO_NOMBRE], TAM_DATOS, stdin);
  fgets(contenidonuevo->datos[AUTOR_CONTRASENA], TAM_DATOS, stdin);
  fgets(contenidonuevo->datos[GENERO_PERMISOS], TAM_DATOS, stdin);
}
/**
 * @fn void NodoSwap  (nodo *nodo1, nodo *nodo2)
 * @brief Swap de dos nodos
 * @param *nodo1 Primer nodo del swap
 * @param *nodo2 Segundo nodo del swap
 * @return Void
*/ 
void NodoSwap (nodo *nodo1, nodo *nodo2)
{
  contenido libroaux;
  
  libroaux = *(nodo1->contenido);
  *(nodo1->contenido) = *(nodo2->contenido);
  *(nodo2->contenido) = libroaux;
}
/**
 * @fn void OrdenarLista (nodo **nodoprimero)
 * @brief Ordena la lista de libros/usuarios según sus títulos/nombre
 * @param **nodoprimero Dirección de inicio de la lista de libros/usuarios
 * @return Void
*/ 
void OrdenarLista (nodo **nodoprimero)
{
  nodo *nodoaux, *nodoaux2;
  
  for( nodoaux = (*nodoprimero) ; nodoaux->next  != NULL ;  nodoaux = nodoaux->next  )
  {
    for( nodoaux2 = nodoaux->next ; nodoaux2 != NULL ; nodoaux2 = nodoaux2->next)
    {
      if( (strcmp(nodoaux->contenido->datos[TITULO_NOMBRE], nodoaux2->contenido->datos[TITULO_NOMBRE])) > 0)
	NodoSwap( nodoaux, nodoaux2);
    }
  } 
}
/**
 * @fn void LibrerarLista (nodo **nodoprimero)
 * @brief Elimina la lista de libros/usuarios
 * @param **nodoprimero Dirección de inicio de la lista a eliminar
 * @return Void
*/ 
void LibrerarLista (nodo **nodoprimero)
{
  nodo *nodoaux;
  while( (*nodoprimero)->next != NULL )
  {
    nodoaux = (*nodoprimero)->next;
    free( (*nodoprimero)->contenido );
    free( (*nodoprimero) );
    (*nodoprimero) = nodoaux;
  }
  free( (*nodoprimero) );
}
/**
 * @fn void  EnviarLista ( nodo *nodoprimero, int sockfd )
 * @brief  El administrador envía la lista de libros/usuarios al servidor
 * @param nodoprimero Dirección de inicio de la lista de libros/usuarios
 * @param sockfd File descriptor del socket
 * @return void
*/
void EnviarLista( nodo *nodoprimero, int sockfd )
{
  nodo *nodoaux;
  contenido enviaraux;
  for( nodoaux = nodoprimero ; nodoaux != NULL ; nodoaux = nodoaux->next )
  {
    if( send(sockfd, nodoaux->contenido, sizeof(contenido),0) == -1)
    {
      perror("Send");
      exit(EXIT_FAILURE);
    }
  }
  strcpy( enviaraux.datos[TITULO_NOMBRE], "FIN\n");
  if( send(sockfd, &enviaraux, sizeof(contenido),0) == -1)
  {
    perror("Send");  
    exit(EXIT_FAILURE);
  }
}
/**
 * @fn void AgregarNodo (nodo **nodoprimero, int manejo)
 * @brief Agrega un nodo a la lista
 * @param **nodoprimero Dirección de inicio de la lista
 * @param manejo indica si se trabaja con usuarios o libros
 * @return Void
*/ 
void AgregarNodo (nodo **nodoprimero, int manejo)
{
  nodo *nodonuevo;
  
  nodonuevo = (nodo *)malloc( sizeof(nodo) );  
  nodonuevo->contenido = (contenido *)malloc( sizeof(contenido) );
  
  CargarContenido( nodonuevo->contenido, manejo );
  
  nodonuevo->next = (*nodoprimero);
  *nodoprimero = nodonuevo;  
}
/**
 * @fn void BorrarNodo (nodo **nodoprimero)
 * @brief Elimina un nodo según el título del libro o según el nombre del usuario
 * @param **nodoprimero Dirección de inicio de la lista
 * @param manejo Indica si se trabaja con libros o usuarios
 * @return Void
*/ 
void BorrarNodo (nodo **nodoprimero, int manejo)
{
  char cadena[TAM_DATOS];
  nodo *nodoaux, *nodoant;
  
  if( manejo == LIBROS )
     printf( "Ingrese el titulo del libro que quiere borrar\n	" );  
  else if( manejo == USUARIOS)       
     printf( "Ingrese el nombre del usuario que quiere borrar\n	" );  
  
  fgets(cadena, TAM_DATOS, stdin);
  
  if( strcmp(cadena, "Admin\n") == 0 )
    printf( "No se puede eliminar el usuario Admin\n" );
  else if( strcmp(cadena, "Manual\n") == 0 )
    printf( "No se puede eliminar el Manual de Uso\n" );
  
  else
  {
    nodoant = NULL;
    for( nodoaux = *nodoprimero ; nodoaux != NULL ; nodoaux = nodoaux->next )
    {
      if( strcmp(nodoaux->contenido->datos[TITULO_NOMBRE], cadena) == 0)
      {
	if( nodoant == NULL )
	{
	  *nodoprimero = nodoaux->next;
	  free( nodoaux->contenido );
	  free( nodoaux );	
	}
	else
	{
	  nodoant->next = nodoaux->next;
	  free( nodoaux->contenido );
	  free( nodoaux );
	}
	break;
      }
      nodoant = nodoaux;
    }
    if( nodoaux == NULL )
      printf( "No existe\n" );
  }
}
/**
 * @fn void ModificarNodo (nodo **nodoprimero, int manejo)
 * @brief Modifica un nodo que es encontrado a partir del título del libro o el nombre del usuario
 * @param **nodoprimero Dirección de inicio de la lista
 * @param manejo Indica si se trabaja con libros o usuarios
 * @return Void
*/ 
void ModificarNodo (nodo **nodoprimero, int manejo)
{
  char cadena[TAM_DATOS];
  nodo *nodomodificar;
  
  if( manejo == LIBROS )
     printf( "Ingrese el titulo del libro que quiere modificar\n	" );  
  else if( manejo == USUARIOS)       
     printf( "Ingrese el nombre del usuario que quiere modificar\n	" );  
  
  fgets(cadena, TAM_DATOS, stdin);
  
  nodomodificar = BuscarNodo( *nodoprimero, cadena );
  
  if( nodomodificar != NULL )  
  {
    if( strcmp(cadena, "Admin\n") == 0 )
    {      
      memset( nodomodificar->contenido->datos[AUTOR_CONTRASENA], '\n', TAM_DATOS);
      printf( "Ingrese la nueva contraseña de Admin: \n" );
      fgets(nodomodificar->contenido->datos[AUTOR_CONTRASENA], TAM_DATOS, stdin);
    }
    else if( strcmp(cadena, "Manual\n") == 0 )
    {
      printf( "No se pueden cambiar los datos del Manual: \n" );
    }
    else
      CargarContenido( nodomodificar->contenido, manejo );     
  }
  else
    printf( "No existe\n" );
}
/**
 * @fn void MostrarNodo (nodo **nodoprimero, int manejo)
 * @brief Muestra los datos que contiene un nodo que es encontrado a partir del título del libro o el nombre del usuario
 * @param **nodoprimero Dirección de inicio de la lista
 * @param manejo Indica si se trabaja con libros o usuarios
 * @return Void
*/ 
void MostrarNodo (nodo **nodoprimero, int manejo)
{
  char titulo[TAM_DATOS];
  nodo *nodomostrar;
  if( manejo == LIBROS )
     printf( "Ingrese el titulo del libro que quiere mostrar\n	" );  
  else if( manejo == USUARIOS)       
     printf( "Ingrese el nombre del usuario que quiere mostrar\n	" );  
  fgets(titulo, TAM_DATOS, stdin);
  
  nodomostrar = BuscarNodo( *nodoprimero, titulo );
  if( nodomostrar != NULL )
  {
    if( manejo == LIBROS )
    {
      printf( "	Titulo: %s", nodomostrar->contenido->datos[TITULO_NOMBRE] );
      printf( "	Autor: %s", nodomostrar->contenido->datos[AUTOR_CONTRASENA] );
      printf( "	Genero: %s", nodomostrar->contenido->datos[GENERO_PERMISOS] );  
    }
    else if( manejo == USUARIOS)       
    {
      printf( "	Nombre: %s", nodomostrar->contenido->datos[TITULO_NOMBRE] );
      printf( "	Contraseña: %s", nodomostrar->contenido->datos[AUTOR_CONTRASENA] );
      printf( "	Permisos: %s", nodomostrar->contenido->datos[GENERO_PERMISOS] );  
    }
    printf("\n");
  }
  else
    printf( "	No existe\n\n" );
}
/**
 * @fn void LeerLista (nodo **nodoprimero, int manejo)
 * @brief Muestra la lista de usuarios o libtos ordenados alfabéticamente según su nombre o título
 * @param **nodoprimero Dirección de inicio de la lista
 * @param manejo Indica si se trabaja con libros o usuarios
 * @return Void
*/ 
void LeerLista (nodo **nodoprimero, int manejo)
{
  nodo* nodoaux;
  nodoaux = *nodoprimero;
  
  OrdenarLista ( nodoprimero );
  if( manejo == LIBROS )
  {
    while( nodoaux != NULL)
    {
      printf( "	Titulo: %s", nodoaux->contenido->datos[TITULO_NOMBRE] );
      nodoaux = nodoaux->next;   
    }
  }
  else if( manejo == USUARIOS )
  {
    while( nodoaux != NULL)
    {
      printf( "	Nombre: %s", nodoaux->contenido->datos[TITULO_NOMBRE] );
      nodoaux = nodoaux->next;   
    }
  }
}
/**
 * @fn void Salir (nodo **nodoprimero, manejo)
 * @brief Se encarga de la salida del programa: ordena la lista
 * @param **nodoprimero Dirección de inicio de la lista
 * @param manejo Indica si se trabaja con libros o usuarios 
 * @return Void
*/ 
void Salir (nodo **nodoprimero, int manejo)
{
  OrdenarLista ( nodoprimero );  
}
/**
 * @fn int getch (void)
 * @brief  Sacado de internet
 * @return El caracter ingresado por teclado sin imprimirlo en pantalla
*/
int getch(void)
{
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= -(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); 
  return ch;
}
/**
 * @fn void FuncionUser (int sockfd)
 * @brief  Programa principal para el usuario normal
 * @details El usuario elige criterio de busqueda, luego el título que desea leer, puede descargalo si quiere, y ademas se imprime el texto en pantalla
 * @param sockfd File descriptor del socket
 * @return void
*/
void FuncionUser (int sockfd)
{
  int c, fd_libro, eleccion, lentitulo;
  char titulos[TAM_DATOS], recibido[TAM_DATOS], *pathlibro;
  char bufferlibro[MAXDATASIZE];
  busqueda busquedacliente;

  do
  {
    printf("Presione 1, 2 o 3 segun el criterio de busqueda que desee y luego ENTER\n	1: Titulo \n	2: Autor \n	3: Genero\n");
    while ((c = getch()) == '\n');
    busquedacliente.campo = c - '1';
    while ( getchar() != '\n' );
  }while( busquedacliente.campo > GENERO_PERMISOS || busquedacliente.campo < TITULO_NOMBRE );

  do
  {
    if( busquedacliente.campo == TITULO_NOMBRE )
      printf("Ingrese la busqueda de titulo que desee (Las palabras deben comenzar con mayúscula y despues seguir en minúscula)\n");
    if( busquedacliente.campo == AUTOR_CONTRASENA )      
      printf("Ingrese la busqueda de autor (Las palabras deben comenzar con mayúscula y despues seguir en minúscula) que desee\n");
    if( busquedacliente.campo == GENERO_PERMISOS )
    {
      printf( "GENEROS:\n	Aventura\n	Bibliografia\n	Ciencia Ficcion\n	Cuentos\n	Fantasia\n	Infantil\n	Novela\n	Policial\n	Politica\n	Suspenso\n	Terror\n" );
      printf("Ingrese la busqueda de genero que desee (Las palabras deben comenzar con mayúscula y despues seguir en minúscula)\n");
    }
    fgets( busquedacliente.cadena, TAM_DATOS, stdin );
  
    if( send(sockfd, &busquedacliente, sizeof(busqueda),0) == -1)
    {
      perror("Send");
      exit(EXIT_FAILURE);
    }
    
    printf("Los titulos disponibles son:\n");
    do
    {
      if( recv(sockfd, titulos, TAM_DATOS,0) == -1)
      {
	perror("recv");
	exit(EXIT_FAILURE);
      }
      printf("	%s",titulos);
    }while ( (strcmp(titulos, "Fin de la busqueda\n")) ); 
    
    if( recv(sockfd, titulos, TAM_DATOS,0 ) == -1)
    {
	perror("recv");
	exit(EXIT_FAILURE);
    }
    printf("%s",titulos);
    
  }while( (strcmp(titulos, "No hubo coincidencias\n")) == 0 );
  
  printf("\n\n		"); 
  fgets( titulos, TAM_DATOS, stdin );

  if( send(sockfd, titulos, TAM_DATOS,0) == -1)
  {
    perror("Send");
    exit(EXIT_FAILURE);
   }
    
  if( recv(sockfd, recibido, TAM_DATOS,0) == -1)
  {
    perror("Recv");
    exit(EXIT_FAILURE);
  }  
  
  printf("%s",recibido);

  if( (strcmp(recibido, "ERROR\n")) == 0 )
    exit(EXIT_FAILURE);  
  
  printf("Desea descargar el libro? [1/0] y luego presione ENTER\n");
  while ((c = getch()) == '\n');
  eleccion = c - '0';
  while ( getchar() != '\n' );
  printf("\nPara pasar de pagina y al final del libro presione ENTER\n\n\n");
  printf("	TITULO:	 %s\n",titulos);
  
  if( eleccion )
  {
    lentitulo = strlen( titulos );
    
    pathlibro = (char *)malloc(lentitulo+4);  
    strcpy( pathlibro, titulos );
  
    pathlibro[lentitulo-1] = '.';
    pathlibro[lentitulo] = 't';
    pathlibro[lentitulo+1] = 'x';
    pathlibro[lentitulo+2] = 't';
    pathlibro[lentitulo+3] = '\0'; 
    
    if( (fd_libro = open( pathlibro, O_WRONLY | O_CREAT, 0777 )) == -1 ) 
    {
      perror("Open");
      exit(EXIT_FAILURE);   
    }
    while(1)
    {
      if( recv(sockfd, bufferlibro, MAXDATASIZE,0) == -1)
      {
        perror("recv");
        exit(EXIT_FAILURE);
      }
      bufferlibro[MAXDATASIZE] = '\0';
      printf("%s",bufferlibro);
      getch();
      
      if( (strcmp(bufferlibro, "\nFin del Libro\n")) != 0)
      {
	if( write( fd_libro, bufferlibro, MAXDATASIZE ) == -1)
	{
	perror("Write");
	exit(EXIT_FAILURE);  
	}
      }
      else
	break;
    }
    close(fd_libro);
    free(pathlibro);
  }  
  else
  {
    do
    {
      if( recv(sockfd, bufferlibro, MAXDATASIZE,0) == -1)
      {
        perror("recv");
        exit(EXIT_FAILURE);
      }
      bufferlibro[MAXDATASIZE] = '\0';
      printf("%s",bufferlibro);
      getch();
    }while ( (strcmp(bufferlibro, "\nFin del Libro\n") ));
  }
}
/**
 * @fn void FuncionAdmin (int sockfd)
 * @brief  Menú principal para el administrador
 * @param sockfd File descriptor del socket
 * @return void
*/
void FuncionAdmin (int sockfd)
{
  int c, opcion;
  void (*funcionprincipal[3])(int) = { ManejoLibros, ManejoUsuarios, SalirCliente };
 
  do
  {
    do
    {
      printf( "Menu: 		1)Manejo de Libros\n		2)Manejo de Usuarios\n		3)Salir\n");
      scanf("%d", &opcion);    
      while ((c = getchar()) != '\n');
    }while( opcion > 3 || opcion < 1 );
    
    opcion --;
    funcionprincipal[opcion](sockfd);
  }while( opcion != 2 );
}