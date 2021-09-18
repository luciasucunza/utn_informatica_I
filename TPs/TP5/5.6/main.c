/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Main
*/ 
#include "main.h"
/**
 * @fn 		int main( void )
 * @brief 	Main para utilizar la funcion DetectaLazo
 * @details	Pide el ingreso de caracteres para formar una lista de ellos, la cual se corrompe en el sepitimo nodo, y luego imprime en pantalla el caracter del nodo que corrompe la lista
 * @return 	0 por exito
 */ 
int main (void)
{
  struct nodo *retorno, *nodoaux, *nodoprimero, *nodoultimo, *nodolazo;
  int i;
  
  for( i = 0 ; i < 12 ; i++)
  {
    nodoaux = (struct nodo *) malloc (sizeof(struct nodo));
    nodoaux->datos = (char*) malloc (2);
    
    printf ("Ingrese un caracter para el nodo:	\n");
    scanf("%s", (char *)nodoaux->datos);
    nodoaux->next = NULL;   
	    
    if(i)
    {
      nodoultimo->next = nodoaux;
      nodoultimo = nodoaux;	 
    }
    else
    {
      nodoprimero = nodoultimo = nodoaux;      
    }
    if(i == 6)
      nodolazo = nodoaux;
  }
  nodoaux->next = nodolazo;   
  
  retorno = DetectaLazo (nodoprimero);
  
  printf( "El lazo es %s\n", (char*)retorno->datos );
  printf( "Los primeros 40 nodos son\n");
  
  for( i = 0, nodoaux = nodoprimero ; i < 40 ; i++, nodoaux = nodoaux->next )
    printf("%s	", (char *)nodoaux->datos);
  
  return 0;
}