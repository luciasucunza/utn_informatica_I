#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h>
#include <termios.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
 
#define MYPORT 				34965
#define MAX_CLIENTES_ESPERA 		10
#define MAXDATASIZE 			990
#define TAM_DATOS 			32
#define TAM_PATH 			100
#define PATH_ESTRUCTURA_LIBROS 		"DatosLibros.txt"
#define PATH_ESTRUCTURA_USUARIOS	"DatosUsuarios.txt"
#define PATH_TEMPORAL 			"Temp.txt"
#define PATH_BIBLIOTECA 		"Biblioteca/" 
#define TITULO_NOMBRE 			0
#define AUTOR_CONTRASENA 		1
#define GENERO_PERMISOS 		2 
#define LIBROS 				3
#define USUARIOS 			4

#define CAMPO_X		75
#define CAMPO_Y		70
#define USUARIO_X	100
#define USUARIO_Y 	30
#define PASSWORD_X 	101
#define PASSWORD_Y 	95
#define TITULO_X	40
#define TITULO_Y	460
#define REC_TAM_Y 	25
#define REC_TAM_X 	250

typedef struct busqueda_t{
  int campo;
  char cadena[TAM_DATOS];
}busqueda;

typedef struct contenido_t{
  char datos[3][TAM_DATOS];
}contenido;	

typedef struct nodo_t{
  contenido *contenido;
  struct nodo_t *next;
}nodo;

typedef struct cv_t
{
  IplImage* im;
  busqueda* bus;
}cv;


void FuncionAdmin( int );
void FuncionUser( int );
int ConectarAServidor (char *);
void AgregarNodo (nodo **, int);
void BorrarNodo (nodo **, int);
void ModificarNodo (nodo **, int);
void MostrarNodo (nodo **, int);
void LeerLista (nodo **, int);
void Salir (nodo **, int);
nodo * CargarLista (int);  
nodo * BuscarNodo (nodo *, char*);
void CargarContenido (contenido *, int);
void OrdenarLista (nodo **);
void LibrerarLista (nodo **);
void NodoSwap (nodo* , nodo* );
void EnviarLista( nodo *, int );
void ManejoLibros(int);
void ManejoUsuarios(int);
void SalirCliente(int);
nodo * CargarListaRecibida( int );

void crearCampodeTexto(IplImage*, int, int);
void leemosDelCampo(char*, IplImage*, CvFont, int, int, char*);
void Logueo(char*,char*);
void EleccionDeDescarga( CvFont, int *);
void EleccionDeCampoBoton (busqueda *);
void crearBotonCampo(IplImage*);
void callbackBotonCampo(int, int, int, int, void*);
void EleccionDeCadena( CvFont, busqueda *);
void MostrarSinopsis( CvFont , char *);
void EleccionDeDescargaBoton (busqueda *);
void crearBotonDescarga(IplImage*);
void callbackBotonDescarga(int, int, int, int, void*);

void SalirPorError( void );
void MostrarLogo(void);


int main (int argc, char* argv[])
{
  int opcion, sockfd;
  char user[TAM_DATOS];
  char pass[TAM_DATOS];
  void (*funcionmain[2])(int) = { FuncionAdmin, FuncionUser };
  
  if(argc != 2)
  {
    printf("Ingrese la IP a quien conectarse\n");
    exit(EXIT_FAILURE);
  }

  sockfd = ConectarAServidor( argv[1] );
  
    MostrarLogo();
  Logueo(user, pass);
  
  if( send(sockfd, user, sizeof(user),0) == -1)
  {
    perror("Send");
    exit(EXIT_FAILURE);
  }
  if( send(sockfd, pass, sizeof(pass),0) == -1)
  {
    perror("Send");
    exit(EXIT_FAILURE);
  }
  
  if( recv(sockfd, &opcion, sizeof(opcion),0) == -1)
  {
    perror("recv");
    exit(EXIT_FAILURE);
  }
	  
  if( opcion != 2 )
    funcionmain[opcion](sockfd);
  else
    SalirPorError();   
  printf( "Fin de la comunicacion\n" );
  close(sockfd);
  return 0;
}

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
 * @fn void FuncionUser (int sockfd)
 * @brief  Programa principal para el usuario normal
 * @details El usuario elige criterio de busqueda, luego el título que desea leer, puede descargalo si quiere, y ademas se imprime el texto en pantalla
 * @param sockfd File descriptor del socket
 * @return void
*/
void FuncionUser (int sockfd)
{
  int fd_libro, eleccion, lentitulo, columna, fila, i = 0;
  char titulos[TAM_DATOS], recibido[TAM_DATOS], *pathlibro, *titulosaux;
  char bufferlibro[MAXDATASIZE];
  busqueda busquedacliente;
  IplImage* imagenFondoTitulosDisponibles;
  
  CvFont Font;
  cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1,8);

    do
    {
      EleccionDeCampoBoton( &busquedacliente );
    }
    while( busquedacliente.campo > GENERO_PERMISOS || busquedacliente.campo < TITULO_NOMBRE );

    do
    {
      if( i )
	EleccionDeCadena( Font, &busquedacliente );      
      
      i++;
      
      if( send(sockfd, &busquedacliente, sizeof(busqueda),0) == -1)
      {
	perror("Send");
	exit(EXIT_FAILURE);
      }
      
      imagenFondoTitulosDisponibles = cvCreateImage(cvSize(840, 510), 8, 3);
      cvZero(imagenFondoTitulosDisponibles);    

      for( fila = 35, columna = 10, eleccion = 1 ;  (strcmp(titulos, " ")) != 0 ; eleccion++ )
      {        
	if( recv(sockfd, titulos, TAM_DATOS,0) == -1)
	{
	  perror("recv");
	  exit(EXIT_FAILURE);
	}
	
	lentitulo = strlen(titulos);
	titulosaux = (char *)malloc(lentitulo+1); 
	strcpy( titulosaux, titulos );       
	titulosaux[lentitulo-1] = '\0';
	titulosaux[lentitulo] = '\n';
	cvPutText (imagenFondoTitulosDisponibles, titulosaux,cvPoint( TITULO_X + columna,  TITULO_Y - 440 + fila), &Font, cvScalar (255,255,255,0));
	free(titulosaux);
	
	if( eleccion < 3 )
	  columna = columna + 290;
	else
	{
	  eleccion = 0;
	  columna = 10;
	  fila = fila + 35;
	}   
      }
      if( recv(sockfd, titulos, TAM_DATOS,0 ) == -1)
      {
	  perror("recv");
	  exit(EXIT_FAILURE);
      }
    }while( (strcmp(titulos, "No hubo coincidencias\n")) == 0 );
    
    cvNamedWindow("Spotibook",  CV_WINDOW_NORMAL);
    cvResizeWindow("Spotibook", 840, 510);
    cvMoveWindow("Spotibook", 75, 50);
      
    cvPutText (imagenFondoTitulosDisponibles,"Ingrese el titulo deseado:",cvPoint( TITULO_X,  TITULO_Y - 18), &Font, cvScalar (255,255,255,0));
    cvPutText (imagenFondoTitulosDisponibles,"Los titulos disponibles son:",cvPoint( TITULO_X,  TITULO_Y - 440), &Font, cvScalar (255,255,255,0));
    crearCampodeTexto(imagenFondoTitulosDisponibles, TITULO_X, TITULO_Y);	
    cvShowImage("Spotibook",imagenFondoTitulosDisponibles);
    leemosDelCampo("Spotibook", imagenFondoTitulosDisponibles, Font, (TITULO_X+10), TITULO_Y, titulos );

    cvReleaseImage(&imagenFondoTitulosDisponibles);
    cvDestroyWindow("Spotibook");

    if( strcmp(titulos, "\n") == 0)
      strcpy(titulos, "ERROR\n");

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
    
    if( (strcmp(recibido, "ERROR\n")) == 0 )
    {
      SalirPorError( );
      exit(EXIT_FAILURE);  
    }
    
    if( recv(sockfd, bufferlibro, MAXDATASIZE,0) == -1)
    {
      perror("recv");
      exit(EXIT_FAILURE);
    }
    
    MostrarSinopsis( Font, bufferlibro);
    
    do
    {
      EleccionDeDescargaBoton( &busquedacliente );
    }
    while( busquedacliente.campo != 1 && busquedacliente.campo != 0 );

    if( send(sockfd, &busquedacliente.campo, sizeof(busquedacliente.campo),0) == -1)
    {
	perror("Send");
	exit(EXIT_FAILURE);
    }  
    
    if( busquedacliente.campo )
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
      
      if( recv(sockfd, recibido, TAM_DATOS,0) == -1)
      {
      perror("Recv");
      exit(EXIT_FAILURE);
      }  
    
      if( (strcmp(recibido, "ERROR\n")) == 0 )
      {
	SalirPorError();
	exit(EXIT_FAILURE);
      }
    
      while(1)
      {
	if( recv(sockfd, bufferlibro, MAXDATASIZE,0) == -1)
	{
	  perror("recv");
	  exit(EXIT_FAILURE);
	}      
	if( (strcmp(bufferlibro, "\nFin del Libro\n") ) )
	{
	  if( write( fd_libro, bufferlibro, MAXDATASIZE ) == -1 )
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
void Logueo(char *user, char *pass)
{
  CvFont Font;
  cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1,8);

  cvNamedWindow("Spotibook",  CV_WINDOW_NORMAL);
  cvResizeWindow("Spotibook", 450, 140);
  cvMoveWindow("Spotibook", 75, 50);	
  IplImage* imagenFondoLogueo = cvCreateImage(cvSize(450, 140), 8, 3);
  cvZero(imagenFondoLogueo);

  cvPutText (imagenFondoLogueo,"Ingrese el Usuario",cvPoint( USUARIO_X + 15,  USUARIO_Y - 10), &Font, cvScalar (255,255,255,0));

  crearCampodeTexto(imagenFondoLogueo,USUARIO_X, USUARIO_Y);
  cvShowImage("Spotibook",imagenFondoLogueo);
  leemosDelCampo("Spotibook", imagenFondoLogueo, Font, (USUARIO_X+10), USUARIO_Y, user );

  cvPutText (imagenFondoLogueo,"Ingrese la Password",cvPoint( PASSWORD_X + 15,  PASSWORD_Y - 10), &Font, cvScalar (255,255,255,0));

  crearCampodeTexto(imagenFondoLogueo,PASSWORD_X, PASSWORD_Y);	
  cvShowImage("Spotibook",imagenFondoLogueo);
  leemosDelCampo("Spotibook", imagenFondoLogueo, Font, (PASSWORD_X+10), PASSWORD_Y, pass );

  cvReleaseImage(&imagenFondoLogueo);	
  cvDestroyWindow("Spotibook");
}
void crearCampodeTexto(IplImage* imagenFondo, int rectanguloDesdeDonde_X, int rectanguloDesdeDonde_Y)
{
  int rectanguloHastaDonde_X = rectanguloDesdeDonde_X + REC_TAM_X;
  int rectanguloHastaDonde_Y = rectanguloDesdeDonde_Y + REC_TAM_Y;
  
  cvRectangle (imagenFondo, cvPoint (rectanguloDesdeDonde_X, rectanguloDesdeDonde_Y), cvPoint (rectanguloHastaDonde_X, rectanguloHastaDonde_Y),cvScalar (255,255,255,0),1,8,0);
}
void leemosDelCampo(char* nombreVentana, IplImage* imagenFondo, CvFont Font,int textoDesdeDonde_X, int textoDesdeDonde_Y, char *texto)
{
  int baseline, puntero_lector = 0, i = 0;
  CvSize text_size;
  char aux = cvWaitKey(0);
  int textoHastaDonde_X = textoDesdeDonde_X + REC_TAM_X;
  int textoHastaDonde_Y = textoDesdeDonde_Y + REC_TAM_Y - 8;

  for (i=0; i<TAM_DATOS; i++) 
    texto[i]= '\0';
  
  while (aux != 27 && aux != 10 )
  {
    if (aux > 31 && aux < 127)
    {
      cvGetTextSize(texto, &Font, &text_size, &baseline);     //Tamaño que va a ocupar el texto

      if ((textoHastaDonde_X - textoDesdeDonde_X - 10) > text_size.width)
      {
	texto[puntero_lector]=aux;
	cvPutText(imagenFondo,texto,cvPoint(textoDesdeDonde_X,textoHastaDonde_Y), &Font, cvScalar (255,255,255,0));
	cvShowImage(nombreVentana,imagenFondo);
	puntero_lector++;
      }
    }
    if ((aux==8 || aux==127) && puntero_lector)
    {
      cvPutText(imagenFondo,texto,cvPoint(textoDesdeDonde_X,textoHastaDonde_Y), &Font, cvScalar (0,0,0,0));
      texto[puntero_lector]=(char)0;
      puntero_lector--;
      texto[puntero_lector]=(char)0;
      cvPutText(imagenFondo,texto,cvPoint(textoDesdeDonde_X,textoHastaDonde_Y), &Font, cvScalar (255,255,255,0));
      cvShowImage(nombreVentana,imagenFondo);
    }
    aux = cvWaitKey(0);
  }
  texto[puntero_lector]=10 ;// MUY IMPORTENTE LE AGREGO EL ENTER PARA QUE SEA COMPATIBLE
}
void EleccionDeCadena( CvFont Font, busqueda *busquedacliente)
{
  IplImage* imagenFondoEleccionCadena;
  
  cvNamedWindow("Spotibook",  CV_WINDOW_NORMAL);
  cvResizeWindow("Spotibook", 740, 170);
  cvMoveWindow("Spotibook", 75, 50);
  imagenFondoEleccionCadena = cvCreateImage(cvSize(740, 170), 8, 3);
  cvZero(imagenFondoEleccionCadena);
  
  
  if( busquedacliente->campo == TITULO_NOMBRE )
  {
    cvPutText (imagenFondoEleccionCadena,"Ingrese la busqueda de titulo que desee",cvPoint( CAMPO_X,  CAMPO_Y - 40), &Font, cvScalar (255,255,255,0));
    cvPutText (imagenFondoEleccionCadena,"       Las palabras deben comenzar con mayuscula y seguir en minuscula",cvPoint( CAMPO_X,  CAMPO_Y - 15), &Font, cvScalar (255,255,255,0)); 
  }
  else if( busquedacliente->campo == AUTOR_CONTRASENA )   
  {
    cvPutText (imagenFondoEleccionCadena,"Ingrese la busqueda de autor que desee",cvPoint( CAMPO_X,  CAMPO_Y - 40), &Font, cvScalar (255,255,255,0));
    cvPutText (imagenFondoEleccionCadena,"       Las palabras deben comenzar con mayuscula y seguir en minuscula",cvPoint( CAMPO_X,  CAMPO_Y - 15), &Font, cvScalar (255,255,255,0));
  }
  else if( busquedacliente->campo == GENERO_PERMISOS )
  {
    cvPutText (imagenFondoEleccionCadena,"Ingrese el genero que desee",cvPoint( CAMPO_X,  CAMPO_Y - 40), &Font, cvScalar (255,255,255,0));
    cvPutText (imagenFondoEleccionCadena,"       El genero debe estar escrito como se muestra en la lista",cvPoint( CAMPO_X,  CAMPO_Y - 15), &Font, cvScalar (255,255,255,0));
    cvPutText (imagenFondoEleccionCadena,"Aventura     Ciencia Ficcion     Cuentos      Fantasia       Infantil",cvPoint( CAMPO_X,  CAMPO_Y + 50), &Font, cvScalar (255,255,255,0));
    cvPutText (imagenFondoEleccionCadena,"Novela       Policial              Politica     Suspenso       Terror",cvPoint( CAMPO_X,  CAMPO_Y + 80), &Font, cvScalar (255,255,255,0));
  }
  crearCampodeTexto(imagenFondoEleccionCadena, CAMPO_X, CAMPO_Y);	
  cvShowImage("Spotibook",imagenFondoEleccionCadena);
  leemosDelCampo("Spotibook", imagenFondoEleccionCadena, Font, (CAMPO_X+10), CAMPO_Y, busquedacliente->cadena );
    
  cvReleaseImage(&imagenFondoEleccionCadena);
  cvDestroyWindow("Spotibook");
}
void MostrarSinopsis( CvFont Font, char *buffersinopsis)
{
  int i, fila = 0, j = 0;
  char auxsinopsis[90];
  IplImage* imagenFondoSinopsis = cvLoadImage("sinopsis.jpg", CV_LOAD_IMAGE_COLOR);
  cvNamedWindow("Spotibook",  CV_WINDOW_AUTOSIZE);
  cvMoveWindow("Spotibook", 75, 50);
    
  for (i =0 ; buffersinopsis[i] != '\n' && i< 990; i++);
  buffersinopsis[i-1] = '\0';      
  buffersinopsis[i] = '\n';
  
  while( j < 990)
  {
    for( i = 0 ; i < 90 ; i++, j++)
      auxsinopsis[i] = buffersinopsis[j];
    cvPutText (imagenFondoSinopsis,auxsinopsis,cvPoint( TITULO_X - 10 ,  TITULO_Y - 430+ fila), &Font, cvScalar (0,0,0,0));
    fila = fila +35;
  }
  
  cvPutText (imagenFondoSinopsis,"Presione cualquier tecla para continuar",cvPoint( TITULO_X,  TITULO_Y - 18), &Font, cvScalar (0,0,0,0));
  cvShowImage("Spotibook",imagenFondoSinopsis);
    
  cvWaitKey(0);
  cvReleaseImage(&imagenFondoSinopsis);
  cvDestroyWindow("Spotibook");
}
void EleccionDeDescarga( CvFont Font, int *eleccion )
{
  IplImage* imagenFondoEleccionDescarga;
  char eleccionaux[TAM_DATOS];
  do
  {
    cvNamedWindow("Spotibook",  CV_WINDOW_NORMAL);
    cvResizeWindow("Spotibook", 600, 170);
    cvMoveWindow("Spotibook", 75, 50);
    imagenFondoEleccionDescarga = cvCreateImage(cvSize(600, 170), 8, 3);
    cvZero(imagenFondoEleccionDescarga);

    cvPutText (imagenFondoEleccionDescarga,"Desea descargar el libro [1/0]",cvPoint( CAMPO_X,  CAMPO_Y - 30), &Font, cvScalar (255,255,255,0));
	
    crearCampodeTexto(imagenFondoEleccionDescarga, CAMPO_X, CAMPO_Y);	
    cvShowImage("Spotibook",imagenFondoEleccionDescarga);
    leemosDelCampo("Spotibook", imagenFondoEleccionDescarga, Font, (CAMPO_X+10), CAMPO_Y, eleccionaux );

    if( (strcmp(eleccionaux, "0\n")) == 0 )
      *eleccion = 0;
    else if( (strcmp(eleccionaux, "1\n")) == 0 )
      *eleccion = 1;
    else
      *eleccion = 2;
    
  }while( *eleccion != 1 && *eleccion != 0 );
  
  cvReleaseImage(&imagenFondoEleccionDescarga);
  cvDestroyWindow("Spotibook"); 
  

}
void SalirPorError( void )
{
  CvFont Font;
  cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.8, 0.8, 0, 2,8);

  cvNamedWindow("Spotibook",  CV_WINDOW_NORMAL);
  cvResizeWindow("Spotibook", 640, 100);
  cvMoveWindow("Spotibook", 75, 50);
  IplImage* imagenFondoError = cvCreateImage(cvSize(640, 100), 8, 3);
  cvZero(imagenFondoError);

  cvPutText (imagenFondoError,"Error: Presione cualquier tecla para salir",cvPoint( USUARIO_X - 30,  USUARIO_Y + 25), &Font, cvScalar (255,255,255,0));
  cvShowImage("Spotibook",imagenFondoError);
   
  cvWaitKey(0);
  cvReleaseImage(&imagenFondoError);
  cvDestroyWindow("Spotibook");  
}
void EleccionDeCampoBoton (busqueda *eleccion)
{
  cv* uno;
  
  cvNamedWindow( "Spotibook" ,  CV_WINDOW_NORMAL);
  cvResizeWindow("Spotibook", 740, 170);
  cvMoveWindow("Spotibook", 75, 50);
  IplImage* imagenFondoEleccionCampo = cvCreateImage(cvSize(740, 170), 8, 3);
  cvZero(imagenFondoEleccionCampo);

  uno = (cv*) malloc (sizeof (cv));

  uno->im = (IplImage*) malloc (sizeof (IplImage));
  uno->bus = (busqueda*) malloc (sizeof (busqueda) );
  uno->im = imagenFondoEleccionCampo;
  
  crearBotonCampo(imagenFondoEleccionCampo);

  cvShowImage ("Spotibook",imagenFondoEleccionCampo);
  cvSetMouseCallback("Spotibook", callbackBotonCampo, (void*) uno );
  cvWaitKey(0);
  eleccion->campo = uno->bus->campo;
  strcpy(eleccion->cadena, uno->bus->cadena);
  cvReleaseImage( &(uno->im) );
  free(uno);
  cvDestroyWindow("Spotibook");
}
void crearBotonCampo(IplImage* imagenFondo)
{
  CvFont Font;
  cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1,8);

  cvPutText (imagenFondo,"Elija el criterio de busqueda",cvPoint(50, 35), &Font, cvScalar (255,255,255,0));
  
  cvRectangle (imagenFondo, cvPoint (50, 70), cvPoint (140, 100), cvScalar (255,255,255,0),1,8,0);
  cvPutText (imagenFondo,"AUTOR",cvPoint(70, 90), &Font, cvScalar (255,255,255,0));

  cvRectangle (imagenFondo, cvPoint (240, 70), cvPoint (330, 100), cvScalar (255,255,255,0),1,8,0);
  cvPutText (imagenFondo,"GENERO",cvPoint(255, 90), &Font, cvScalar (255,255,255,0));

  cvRectangle (imagenFondo, cvPoint (430, 70), cvPoint (520, 100), cvScalar (255,255,255,0),1,8,0);
  cvPutText (imagenFondo,"TITULO",cvPoint(450, 90), &Font, cvScalar (255,255,255,0));
}
void callbackBotonCampo(int evento, int x, int y,int flags, void* sth)
{
  cv* dos;
  dos = (cv*)sth;
   CvFont Font;
  cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1,8);

  IplImage* imagenFondo = dos->im;
  IplImage* in = cvCreateImage(cvSize(740, 170), 8, 3);
  cvZero(in);
  
  if(evento == CV_EVENT_LBUTTONDOWN && x > 50 && y > 70 && x < 140 && y < 100)
  {    
    fflush(stdout);
    dos->bus->campo = 1;
    cvReleaseImage(&imagenFondo);
    dos->im = in;
    cvPutText (in,"Ingrese la busqueda de autor que desee",cvPoint( CAMPO_X,  CAMPO_Y - 40), &Font, cvScalar (255,255,255,0));
    cvPutText (in,"       Las palabras deben comenzar con mayuscula y seguir en minuscula",cvPoint( CAMPO_X,  CAMPO_Y - 15), &Font, cvScalar (255,255,255,0)); 
    crearCampodeTexto(in, CAMPO_X, CAMPO_Y);	
    cvShowImage("Spotibook",in);
    leemosDelCampo("Spotibook", in, Font, (CAMPO_X+10), CAMPO_Y,  dos->bus->cadena );
  }
  else if(evento == CV_EVENT_LBUTTONDOWN && x > 240 && y > 70 && x < 330 && y < 100)
  {
    fflush(stdout);
    dos->bus->campo = 2;
    cvReleaseImage(&imagenFondo);
    dos->im = in;
    cvPutText (in,"Ingrese el genero que desee",cvPoint( CAMPO_X,  CAMPO_Y - 40), &Font, cvScalar (255,255,255,0));
    cvPutText (in,"       El genero debe estar escrito como se muestra en la lista",cvPoint( CAMPO_X,  CAMPO_Y - 15), &Font, cvScalar (255,255,255,0));
    cvPutText (in,"Aventura     Ciencia Ficcion     Cuentos      Fantasia       Infantil",cvPoint( CAMPO_X,  CAMPO_Y + 50), &Font, cvScalar (255,255,255,0));
    cvPutText (in,"Novela       Policial              Politica     Suspenso       Terror",cvPoint( CAMPO_X,  CAMPO_Y + 80), &Font, cvScalar (255,255,255,0));
   crearCampodeTexto(in, CAMPO_X, CAMPO_Y);	
    cvShowImage("Spotibook",in);
    leemosDelCampo("Spotibook", in, Font, (CAMPO_X+10), CAMPO_Y,  dos->bus->cadena );
  }
  else if(evento == CV_EVENT_LBUTTONDOWN && x > 430 && y > 70 && x < 520 && y < 100)
  {
    fflush(stdout);
    dos->bus->campo = 0;
    cvReleaseImage(&imagenFondo);
    dos->im = in;
    cvPutText (in,"Ingrese la busqueda de titulo que desee",cvPoint( CAMPO_X,  CAMPO_Y - 40), &Font, cvScalar (255,255,255,0));
    cvPutText (in,"       Las palabras deben comenzar con mayuscula y seguir en minuscula",cvPoint( CAMPO_X,  CAMPO_Y - 15), &Font, cvScalar (255,255,255,0)); 
    crearCampodeTexto(in, CAMPO_X, CAMPO_Y);	
    cvShowImage("Spotibook",in);
    leemosDelCampo("Spotibook", in, Font, (CAMPO_X+10), CAMPO_Y,  dos->bus->cadena );
  }
}
void MostrarLogo( void )
{
  cvNamedWindow("Spotibook",  CV_WINDOW_AUTOSIZE);
  cvMoveWindow("Spotibook", 75, 50);

  IplImage* imagenLogo = cvLoadImage("logo.jpg", CV_LOAD_IMAGE_COLOR);//CV_LOAD_IMAGE_COLOR o 1
  cvShowImage("Spotibook",imagenLogo);
   
  cvWaitKey(0);
  cvReleaseImage(&imagenLogo);
  cvDestroyWindow("Spotibook");  
}

void EleccionDeDescargaBoton (busqueda *eleccion)
{
  cv* uno;
  
  cvNamedWindow( "Spotibook" ,  CV_WINDOW_NORMAL);
  cvResizeWindow("Spotibook", 740, 170);
  cvMoveWindow("Spotibook", 75, 50);
  IplImage* imagenFondoEleccionDescarga = cvCreateImage(cvSize(740, 170), 8, 3);
  cvZero(imagenFondoEleccionDescarga);

  uno = (cv*) malloc (sizeof (cv));

  uno->im = (IplImage*) malloc (sizeof (IplImage));
  uno->bus = (busqueda*) malloc (sizeof (busqueda) );
  uno->im = imagenFondoEleccionDescarga;
  
  crearBotonDescarga(imagenFondoEleccionDescarga);

  cvShowImage ("Spotibook",imagenFondoEleccionDescarga);
  cvSetMouseCallback("Spotibook", callbackBotonDescarga, (void*) uno );
  cvWaitKey(0);
  eleccion->campo = uno->bus->campo;
  strcpy(eleccion->cadena, uno->bus->cadena);
  cvReleaseImage( &(uno->im) );
  free(uno);
  cvDestroyWindow("Spotibook");
}
void crearBotonDescarga(IplImage* imagenFondo)
{
  CvFont Font;
  cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1,8);

  cvPutText (imagenFondo,"Desea descargar el libro?",cvPoint(50, 35), &Font, cvScalar (255,255,255,0));
  
  cvRectangle (imagenFondo, cvPoint (50, 70), cvPoint (140, 100), cvScalar (255,255,255,0),1,8,0);
  cvPutText (imagenFondo,"SI",cvPoint(90, 90), &Font, cvScalar (255,255,255,0));

  cvRectangle (imagenFondo, cvPoint (240, 70), cvPoint (330, 100), cvScalar (255,255,255,0),1,8,0);
  cvPutText (imagenFondo,"NO",cvPoint(275, 90), &Font, cvScalar (255,255,255,0));
}
void callbackBotonDescarga(int evento, int x, int y,int flags, void* sth)
{
  cv* dos;
  dos = (cv*)sth;
   CvFont Font;
  cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.7, 0.7, 0, 1,8);

  IplImage* imagenFondo = dos->im;
  IplImage* in = cvCreateImage(cvSize(740, 170), 8, 3);
  cvZero(in);
  
  if(evento == CV_EVENT_LBUTTONDOWN && x > 50 && y > 70 && x < 140 && y < 100)
  {    
    fflush(stdout);
    dos->bus->campo = 1;
    cvReleaseImage(&imagenFondo);
    dos->im = in;
    cvPutText (in,"El libro ya ha sido descargado",cvPoint( CAMPO_X,  CAMPO_Y - 30), &Font, cvScalar (255,255,255,0));
    cvPutText (in,"Gracias por utilizar Spotibook!",cvPoint( CAMPO_X + 20,  CAMPO_Y + 10 ), &Font, cvScalar (255,255,255,0)); 
    cvShowImage("Spotibook",in);
  }
  else if(evento == CV_EVENT_LBUTTONDOWN && x > 240 && y > 70 && x < 330 && y < 100)
  {
    fflush(stdout);
    dos->bus->campo = 0;
    cvReleaseImage(&imagenFondo);
    dos->im = in;
    cvPutText (in,"Gracias por utilizar Spotibook!",cvPoint( CAMPO_X + 20,  CAMPO_Y +10 ), &Font, cvScalar (255,255,255,0));
    cvShowImage("Spotibook",in);
  }
}