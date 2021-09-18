/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Main
*/ 
#include "main.h"
/**
 * @fn 		int main( void )
 * @brief 	Main para utilizar la funcion CargarDatos
 * @return 	0 por exito
 */ 
int main( void )
{  
  struct alumno alumno;

  printf( "Ingrese los datos de Alumno: \n" );
  CargarDatos( &alumno );
  
  return 0;
}