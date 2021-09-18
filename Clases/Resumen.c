#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct nodo
{
  int dato;
  struct nodo sig;
}nodo;

int main(void)
{
  
  int datoaux;
  nodo *nodoaux, *nodoaux2, **nodoprimero;
  
  FILE *f_archivo, *f_archivo2;
  
//   TAMÑAO DE VARIABLES
  printf("Un CHAR ocupa: %d\n",sizeof(char) );
  printf("Un UNSIGNED CHAR ocupa: %d\n",sizeof(unsigned char) );
  printf("Un INT ocupa: %d\n",sizeof(int) );
  printf("Un UNSIGNED int ocupa: %d\n",sizeof(unsigned int) );
  printf("Un FLOAT ocupa: %d\n",sizeof(float) );
  printf("Un PUNTERO ocupa: %d\n",sizeof(char *) );
  printf("Un PUNTERO a PUNTERO ocupa: %d\n",sizeof(char **) );
  printf("Un PUNTERO a FUNCION  char()(char); ocupa: %d\n",sizeof( char(*)(char) ) );
  
  
//   VALOR DE CARACTERES
  printf("EOF: %d\n", EOF );
  printf(" Barra n: %d\n", ('\n') );
  printf(" Barra 0: %d\n", ('\0') );
  
  
//   ARCHIVOS  
  if( ( f_archivo = fopen("archivo", "r")) == NULL )
    return -1;
  while( !(feof(f_archivo)) )
  {        
    printf("%c\n", fgetc(f_archivo) );
  }
  fclose( f_archivo );
  
  if( ( f_archivo2 = fopen("archivo2", "w+")) == NULL )
    return -1;
  
  fputc( 'B', f_archivo2); 
  fclose( f_archivo2 );
  
// LISTA ORDENAR YA CARGADA
  for( nodoaux = *nodoprimero ; nodoaux->sig != NULL ; nodoaux = nodoaux->sig )
  {
    for( nodoaux2 = nodoaux->sig ; nodoaux2 != 	NULL ; nodoaux2 = nodoaux2 )
    {
      if( nodoaux->dato > nodoaux2->dato)
      {
	datoaux = nodoaux->dato;
	nodoaux->dato = nodoaux2->dato;
	nodoaux2->dato = nodoaux;
      }
    }
  }

  return;
}