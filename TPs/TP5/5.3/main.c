/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Main
*/ 
#include "main.h"
/**
 * @fn 		int main( void )
 * @brief 	Main para utilizar la funcion RemoverDuplicados
 * @details	Pide el ingreso de datos de una lista de alumnos, elimina los duplicados y luego muestra la nueva lista en pantalla
 * @return 	0 por exito
 */ 
int main( void )
{
  struct nodo *nodoprimero = NULL;
  
  CargarLista( &nodoprimero );
  RemoverDuplicados( nodoprimero ); 
  MostrarLista( nodoprimero );
  LiberarLista( &nodoprimero );
  
  return 0;
  
}