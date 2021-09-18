/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Main
*/ 
#include "main.h"
/**
 * @fn 		int main( void )
 * @brief 	Main para utilizar la funcion RemoverNodo
 * @details	Pide el ingreso de datos de una lista de alumnos 5, elmina de la lista el cuarto alumno y luego muestra la nueva lista en pantalla
 * @return 	0 por exito
 */ 
int main (void)
{
  struct nodo *nodoaux, *nodoprimero, *nodoultimo, *c;
  int i;
  
  for( i = 0 ; i < 5 ; i++)
  {
    nodoaux = (struct nodo *) malloc (sizeof(struct nodo));
    nodoaux->alumno = (struct alumno *) malloc (sizeof(struct alumno));
    
    printf ("Ingrese los datos del alumno:\n");
    printf ("	NOMBRE: ");
    scanf ("%s", nodoaux->alumno->nombre);
    printf ("	APELLIDO: ");
    scanf ("%s", nodoaux->alumno->apellido);
    printf ("	EDAD: ");
    scanf ("%d", &nodoaux->alumno->edad);
    printf ("	DNI: ");
    scanf ("%d", &nodoaux->alumno->dni);
    printf ("	PROMEDIO: ");
    scanf ("%f", &nodoaux->alumno->promedio);
    nodoaux->next = NULL;   
	    
    if(i)
    {
      nodoultimo->next = nodoaux;
      nodoultimo = nodoaux;	 
    }
    else
      nodoprimero = nodoultimo = nodoaux;      
    
    if( i == 3)
      c = nodoaux;
  }
  
  RemoverNodo(c);
  
  
   for (nodoaux = nodoprimero; nodoaux != (struct nodo *)NULL ; nodoaux = nodoaux->next)
  {
    printf ("NOMBRE: %s  ", nodoaux->alumno->nombre);  
    printf ("APELLIDO: %s  ", nodoaux->alumno->apellido);  
    printf ("EDAD: %d  ", nodoaux->alumno->edad);  
    printf ("DNI: %d  ", nodoaux->alumno->dni);  
    printf ("PROMEDIO: %f\n", nodoaux->alumno->promedio);
  }
  
  return 0;
}