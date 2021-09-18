/**
 * @file Cliente.h
 * @author Fiorentino Federico Sucunza Lucia
 * @date 19-12-16
 * @brief Header, estructuras, defines y prototipo de funciones utilizadas por el Cliente
*/ 
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
 
#define MYPORT 				34965
#define MAX_CLIENTES_ESPERA 		10
#define MAXDATASIZE 			255
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

void FuncionAdmin( int );
void FuncionUser( int );
int getch(void);
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
