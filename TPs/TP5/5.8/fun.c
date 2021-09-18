/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	07-12-16
 * @brief 	Funciones ejercicio 8
*/ 
#include "main.h"
/**
 * @fn			void carga( struct datos *)
 * @brief 		Carga los datos de una estructura
 * @param persona 	Direccion de la estructura
 * @return		Void
*/
void carga( struct datos *persona)
{
  printf( "Ingrese el numero de legajo\n" );
  scanf( "%ld", &(persona->legajo) );
  if( persona->legajo )
  {
    printf( "Ingrese el apellido\n" );
    scanf( "%s", persona->apellido );
    printf( "Ingrese el nombre\n" );
    scanf( "%s", persona->nombre );
  }    
}
/**
 * @fn			int fin( struct datos )
 * @brief 		Analiza si el numero de legajo es igual a 0 o no
 * @param persona 	Direccion de la estructura
 * @return		Retorna 1 si el numero de legajo es 0, y 1 si es distinto
*/
int fin( struct datos persona)
{
  if( persona.legajo )
    return 0;
  else
    return 1;
}
/**
 * @fn		void Ordenar( struct datos *)
 * @brief 	Ordena en funcion creciente de apellido las estructuras que se encuentran en un vector
 * @param incio	Direccion de comienzo del vector de estructuras
 * @return	Void
*/
void Ordenar( struct datos *inicio )
{
  int len, i, j;
  
  for( len = 0 ; !(fin(*(inicio+len))) ; len++ );
  
  for( i = 0 ; i < len ; i++ )
  {
    for( j = i+1 ; j < len ; j++)
    {
      if( (strcmp( (inicio+j)->apellido, (inicio+i)->apellido )) < 0 )
	SwapDatos( (inicio+j), (inicio+i) );
    }
  }
}
/**
 * @fn		void SwapDatos( struct datos *, struct datos *)
 * @brief 	Intercambia el contenido de las estructuras
 * @param d1	Direccion de una de las estructuras
 * @param d2	Direccion de la otra estructura
 * @return	Void
*/
void SwapDatos( struct datos *d1, struct datos *d2 )
{
  struct datos aux;
  aux = *d1;
  *d1 = *d2;
  *d2 = aux;
}
/**
 * @fn			void Guardar( struct datos *)
 * @brief 		Guarda el contenido del vector en un archivo
 * @param inicio	Direccion de comienzo del vector
 * @return		Void
*/
void Guardar( struct datos *inicio )
{
  int fd, i = 0;
  if( (fd = open(PATH_ARCHIVO, O_WRONLY | O_CREAT)) == -1 )
  {
    perror("Open");
    exit(EXIT_FAILURE);
  }
  
  for( i = 0; !(fin(*(inicio+i))) ; i++ )
  {
    if( write(fd, (inicio+i), sizeof(struct datos)) == -1 )
    {
    perror("Write");
    exit(EXIT_FAILURE);      
    }
  }
}