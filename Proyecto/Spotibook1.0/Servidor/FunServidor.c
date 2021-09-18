/**
 * @file FunServidor.c
 * @author Fiorentino Federico Sucunza Lucia
 * @date 19-12-16
 * @brief Funciones para el Servidor
*/ 
#include "Servidor.h"
/**
 * @fn int InicializarServidor (void)
 * @brief Inicializa el servidor
 * @return File descriptor del socket por éxito
*/ 
int InicializarServidor (void)
{
  int sockfd;
  struct sockaddr_in my_addr;
  
  if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("Socket");
    exit(EXIT_FAILURE);
  }

  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(MYPORT);
  my_addr.sin_addr.s_addr = INADDR_ANY;
  memset( &(my_addr.sin_zero),'\0',8 );	
	
  if( bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr)) == -1)
  {
    perror("Bind");
    exit(EXIT_FAILURE);   
  }  
    
  if( listen(sockfd, MAX_CLIENTES_ESPERA) == -1)
  {
    perror("Listen");
    exit(EXIT_FAILURE);
  }
  return sockfd;
}
/**
 * @fn int VerificarUser (nodo *nodoprimero, char* user, char* pass)
 * @param nodoprimero Inicio de la lista de usuarios
 * @param user String con el nombre de usuario
 * @param pass String con la contraseña
 * @brief Verifica si el usuario y la contraseña estan bien ingresados y que permisos tiene
 * @return 0 si es Admin, 1 si es usuario normal, 2 si no se encontro en la lista de usuarios
*/
int VerificarUser (nodo *nodoprimero, char* user, char* pass )
{
  nodo *nodoaux;
  for( nodoaux = nodoprimero ; nodoaux != NULL ; nodoaux = nodoaux->next )
  {
    if( (strcmp(nodoaux->contenido->datos[TITULO_NOMBRE], user)) == 0 )
    {
      if( (strcmp(nodoaux->contenido->datos[AUTOR_CONTRASENA], pass)) == 0 )
      {
        if( strcmp (nodoaux->contenido->datos[GENERO_PERMISOS], "A\n") == 0 )
          return 0;
        else
          return 1;
      }
    }
  }
  return 2;
}
/**
 * @fn void sigchld_handler(int s)
 * @brief Evitar que se creen procesos zombis a partir de los procesos hijos
*/ 
void sigchld_handler(int s)
{
  while(wait(NULL)>0);
}
/**
 * @fn nodo * CargarDatosLista (char *pathestructura)
 * @brief Crea y carga la lista de libros o usuarios a partir de un archivo de texto que contiene los datos de la misma
 * @param *pathestructura Nombre del archivo que contiene los datos de la lista
 * @return Puntero a inicio de la lista
*/ 
nodo * CargarDatosLista (char *pathestructura)
{
  int fd_estructuras;
  nodo *nodoprimero, *nodonuevo; 
  
  nodoprimero = NULL;
   
  if( (fd_estructuras = open(pathestructura, O_RDONLY)) == -1 )
  {
    perror("Open");
    exit( EXIT_FAILURE );
  }
  
  while( 1 )
  {
    nodonuevo = (nodo *)malloc( sizeof(nodo) );  
    nodonuevo->contenido = (contenido *)malloc( sizeof(contenido) );
    
    if ( (read(fd_estructuras, nodonuevo->contenido, sizeof(contenido))) != 0 )
    {
      nodonuevo->next = nodoprimero;
      nodoprimero = nodonuevo;
    }
    else
    {
      free(nodonuevo->contenido);
      free(nodonuevo);
      break;
    }
  }   
  if( (close(fd_estructuras)) == -1 )
  {
    perror("Close");
    exit( EXIT_FAILURE );
  }

  return nodoprimero;
}
/**
 * @fn void BorrarLista ( nodo **nodoprimero)
 * @brief Elimina la lista
 * @param **nodoprimero Dirección de inicio de la lista
 * @return void
*/ 
void BorrarLista ( nodo **nodoprimero)
{
  nodo *nodoaux;
  
  while( (*nodoprimero)->next != NULL )
  {
    nodoaux = (*nodoprimero)->next;
    free( (*nodoprimero) );
    (*nodoprimero) = nodoaux;
  }
  free( (*nodoprimero) );
}
/**
 * @fn void EnviarArchivo( char *path, int sockfd)
 * @brief Envía al administrador las estructuras con los datos de usuarios o libros para que el cliente pueda crear una lista
 * @param *path String con el nombre del archivo que contiene las estructuras
 * @param sockfd File descriptor del socket
 * @return void
*/
void EnviarArchivo( char *path, int sockfd)
{
  int fd_datos;
  contenido enviaraux;
  if( (fd_datos = open(path, O_RDONLY)) == -1 ) 
  {
    strcpy( enviaraux.datos[TITULO_NOMBRE], "ERROR\n");
      if( send(sockfd, &enviaraux, sizeof(contenido),0) == -1)
    perror("Send");
    close(sockfd); 
    exit(EXIT_FAILURE);   
  }
  
  while( read( fd_datos, &enviaraux, sizeof(contenido)) != 0 )
  {   
    if( send(sockfd, &enviaraux, sizeof(contenido),0) == -1)
      perror("Send");   
  }
  strcpy( enviaraux.datos[TITULO_NOMBRE], "FIN\n");
  if( send(sockfd, &enviaraux, sizeof(contenido),0) == -1)
    perror("Send");   
  
  close( fd_datos );
}
/**
 * @fn void RecibirLista( char *path, int sockfd)
 * @brief Recibe las estructuras de una lista y las guarda en un archivo
 * @param *path String con el nombre del archivo en el que se guarda
 * @param sockfd File descriptor del socket
 * @return void
*/
void RecibirLista( char *path, int sockfd )
{
  int fd_datos;
  contenido recibiraux;
  
  if( (fd_datos = open( path, O_WRONLY | O_CREAT, 0777 )) == -1 ) 
  {
    perror("Open");
    exit(EXIT_FAILURE);   
  }
  while( 1 )
  {    
    if( recv(sockfd, &recibiraux,  sizeof(contenido), 0) != -1)
    {
      if( strcmp(recibiraux.datos[TITULO_NOMBRE], "FIN\n") == 0)
      {
	break;
      }
      write( fd_datos, &recibiraux, sizeof(contenido) );      
    }
    else
    {
      exit(EXIT_FAILURE);
    }
  }
  close( fd_datos );
}/**
 * @fn void ReemplazarArchivos( char *pathdest, char *pathorg)
 * @brief Elimina el archivo viejo y nombra al temporal con el nombre del anterior
 * @param *pathdest String con el nombre del archivo viejo
 * @param *pathorg String con el nombre del archivo temporal
 * @return void
*/
void ReemplazarArchivos( char *pathdest, char *pathorg )
{
  if( remove( pathdest ) == -1)
  {
    perror("Remove");
    exit(EXIT_FAILURE);
  }
  if( rename( pathorg, pathdest ) == -1 )
  {
    perror("Rename");
    exit(EXIT_FAILURE);
  }
}
/**
 * @fn int MyStrcmp( char *texto, char *palabra)
 * @brief Algoritmo de búsqueda de los títulos
 * @param *texto El título 
 * @param *palabra La búsqueda
 * @return 0 si hay coincidencia, 1 si no hay coincidencia
*/
int MyStrcmp( char *texto, char *palabra)
{
  int i, j = 0;
  for( i = 0 ; texto[i] != '\n' ; i++)
  {
    if( *(palabra+j) != '\n')
    {
      if( *(texto+i) == *(palabra+j) )
	j++;
      else
	j = 0;
    }
    else
      return 0;
  }
  if( *(texto+i) == *(palabra+j) )
    return 0;
  return 1;
}
/**
 * @fn nodo* BusquedaLibro (busqueda *criterio, nodo* nodooriginal)
 * @brief Busca el libro deseado segun el criterio que el cliente seleccionó
 * @param *criterio Puntero a busqueda, contiene el criterio seleccionado y la cadena deseada (la misma puede ser el título, género o autor) 
 * @param *nodooriginal Puntero a inicio de la lista de libros
 * @return Puntero a inicio de la lista con las coincidencias 
*/ 
nodo* BusquedaLibro (busqueda *criterio, nodo* nodooriginal)
{
  nodo *nodonuevo, *nodoprimero = NULL;
  
  while( nodooriginal != NULL )
  {
    if( !(MyStrcmp(nodooriginal->contenido->datos[criterio->campo], criterio->cadena)) )
    {
      nodonuevo = (nodo *)malloc( sizeof(nodo) );
      nodonuevo->contenido = nodooriginal->contenido;
      nodonuevo->next = nodoprimero;
      nodoprimero = nodonuevo;
    }  
    nodooriginal = nodooriginal->next;
  }
  return nodoprimero;
}
/**
 * @fn int CargarBuffer (FILE *fd_libro, char *bufferlibro)
 * @brief Carga el buffer de texto que el servidor enviará al cliente
 * @param *fd_libro File descriptor del libro que el cliente desea leer
 * @param *bufferlibro Buffer que se enviará al cliente, el mismo es cargado en esta función
 * @return 0 si se terminó el libro, 1 si todavía no finalizó
*/ 
int CargarBuffer (FILE *fd_libro, char *bufferlibro)
{
  char caracter;
  int i = 0;
  while( i < MAXDATASIZE)
  {
    caracter= fgetc(fd_libro);
    if( caracter  == EOF)
    {    
      memset((bufferlibro+i),' ', (MAXDATASIZE-i) );
      return 0;
    }
    bufferlibro[i] = caracter;
    i++;
  }
  bufferlibro[MAXDATASIZE] = '\0';
  return 1;
}
/**
 * @fn void GuardarPath (char *titulo, char *pathlibro)
 * @brief Concatena el titulo del libro requerido por el cliente con el path fijo de la pc del cliente en donde se encuentran todos los libros
 * @param *titulo Nombre del libro requerido por el cliente
 * @param *pathlibro Es el path de la biblioteca que se encuentra en la pc del servidor
 * @return void
*/ 
void GuardarPath (char *titulo, char *pathlibro)
{
  int i, k, lentitulo;
  lentitulo = strlen(titulo);
  
  strcpy ( pathlibro, PATH_BIBLIOTECA);
  
  *(titulo+lentitulo-1) = '\0' ;
  
  for( i = 0, k = 0 ; i < lentitulo ; i++)
  {
    if( *(titulo+i) != ' ')
    {
      *(titulo+k) = *(titulo+i);
      k++;
    }      
  }
  *(titulo+k+1) = '\0';
  strcat( pathlibro, titulo);  
}
/**
 * @fn void FuncionUser (int sockfd, struct in_addr ip_cliente)
 * @brief  Programa principal para el usuario normal
 * @param sockfd File descriptor del socket
 * @param ip_cliente Ip del cliente
 * @return void
*/
void FuncionUser (int sockfd, struct in_addr ip_cliente)
{
  int j;
  FILE *fd_libro;
  char libroelegido[TAM_DATOS], libroelegidopath[TAM_PATH], bufferlibro[MAXDATASIZE];
  busqueda busquedacliente;
  nodo *nodoprimero, *nodoauxbusqueda, *nodoprimerobusqueda;
  
  nodoprimero = (nodo *)CargarDatosLista(PATH_ESTRUCTURA_LIBROS);
  
  do
  {
    if( recv(sockfd, &busquedacliente, sizeof(busqueda),0) == -1)
    {
      perror("recv");
      exit(EXIT_FAILURE);
    }
    
    printf("Solicitud del cliente %s: %d)%s", inet_ntoa(ip_cliente), busquedacliente.campo, busquedacliente.cadena);
    printf("Realizando busqueda del cliente %s...\n", inet_ntoa(ip_cliente) );
    nodoprimerobusqueda = BusquedaLibro( &busquedacliente, nodoprimero);
    nodoauxbusqueda = nodoprimerobusqueda;      
    
    if( nodoauxbusqueda == NULL )
    {
      if( send(sockfd, "Fin de la busqueda\n", TAM_DATOS, 0) == -1)
      {
	perror("Send");
	exit(EXIT_FAILURE);
      }
      if( send(sockfd, "No hubo coincidencias\n", TAM_DATOS, 0) == -1)
      {
	perror("Send");    
	exit(EXIT_FAILURE);
      }
    }
    else
    {
      while( nodoauxbusqueda != NULL )
      { 
	if( send(sockfd, nodoauxbusqueda->contenido->datos[TITULO_NOMBRE], TAM_DATOS, 0) == -1)
	{
	  perror("Send");   
	  exit(EXIT_FAILURE);
	}
	nodoauxbusqueda = nodoauxbusqueda->next;
      }   
      
      if( send(sockfd, "Fin de la busqueda\n", TAM_DATOS, 0) == -1)
      {
	perror("Send");
	exit(EXIT_FAILURE);
      }
      if( send(sockfd, "Ingrese el titulo desado\n", TAM_DATOS, 0) == -1)
      {
	perror("Send");
	exit(EXIT_FAILURE);
      }
    }
  }while( nodoprimerobusqueda == NULL );
  
  printf("Esperando respuesta del cliente %s...\n", inet_ntoa(ip_cliente) );

  if( recv(sockfd, libroelegido, TAM_DATOS,0) == -1)
  {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  
  printf("Eleccion del cliente %s: %s", inet_ntoa(ip_cliente), libroelegido);
  fflush(stdout);
  
  GuardarPath (libroelegido, libroelegidopath);
  
  if( (fd_libro = fopen(libroelegidopath, "r")) == NULL )
  {
    perror("Open");
    if( send(sockfd, "ERROR\n", TAM_DATOS, 0) == -1)
      perror("Send");
    close(sockfd);      
    BorrarLista( (&nodoprimerobusqueda) );
    exit(EXIT_FAILURE);  
  } 
  
  else
  {
    printf("Enviando libro al cliente %s...\n", inet_ntoa(ip_cliente) );
    if( send(sockfd, "\n\n\n", TAM_DATOS, 0) == -1)
    {
      perror("Send");
      exit(EXIT_FAILURE);
    }
  }
  do
  {
    j = CargarBuffer (fd_libro, bufferlibro);

    if( send(sockfd, bufferlibro, MAXDATASIZE, 0) == -1)
    {
      perror("Send"); 
      exit(EXIT_FAILURE);
    }
  }while (j);
  
  if( send(sockfd, "\nFin del Libro\n", MAXDATASIZE, 0) == -1)
  {
    perror("Send");
    exit(EXIT_FAILURE);
  }
  
  fclose(fd_libro);   
  BorrarLista( (&nodoprimerobusqueda) );
}
/**
 * @fn void FuncionAdmin (int sockfd, struct in_addr ip_cliente)
 * @brief  Programa principal para el administrador
 * @param sockfd File descriptor del socket
 * @param ip_cliente Ip del cliente
 * @return void
*/
void FuncionAdmin(int sockfd, struct in_addr ip_cliente)
{
  char opcion[TAM_DATOS];  
  do
  {
    printf("Esperando eleccion del administrador %s...\n", inet_ntoa(ip_cliente) );
    if( recv(sockfd, opcion, TAM_DATOS,0) == -1)
    {
      perror("Recv");
      exit(EXIT_FAILURE);	  
    }
    if( strcmp(opcion, "ManejoLibros\n") == 0 )
    {
      printf("Enviando DatosLibros al administrador %s...\n", inet_ntoa(ip_cliente) );
      EnviarArchivo( PATH_ESTRUCTURA_LIBROS, sockfd );      
      printf("Esperando DatosLibros modificado por administrador %s...\n", inet_ntoa(ip_cliente) );
      RecibirLista( PATH_TEMPORAL, sockfd );
      ReemplazarArchivos(PATH_ESTRUCTURA_LIBROS, PATH_TEMPORAL);
      printf("Archivo Modificado Guardado\n");
    }
    else if( strcmp(opcion, "ManejoUsuarios\n") == 0 )
    { 
      printf("Enviando DatosUsuarios al administrador %s...\n", inet_ntoa(ip_cliente) );
      EnviarArchivo( PATH_ESTRUCTURA_USUARIOS, sockfd );      
      printf("Esperando DatosUsuarios modificado por administrador %s...\n", inet_ntoa(ip_cliente) );
      RecibirLista( PATH_TEMPORAL, sockfd );
      ReemplazarArchivos(PATH_ESTRUCTURA_USUARIOS, PATH_TEMPORAL);
      printf("Archivo Modificado Guardado\n");      
    }
  }while( strcmp(opcion, "Salir\n") != 0 );
  exit(EXIT_SUCCESS);     
}