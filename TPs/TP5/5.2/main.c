/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Main
*/ 
#include "main.h"
/**
 * @fn 		int main( void ) 
 * @brief 	Main para utilizar la funcion ImprimirDatos
 * @details	Pide el ingreso de los datos de un alumno y luego lo muestra en pantalla
 * @return 	0 por exito
 */ 
int main( void )
{  
  struct alumno a1;
  
  printf( "Ingrese los datos de Alumno: \n" );
  CargarDatos( &a1 );  

  printf( "Los datos del Alumno son: \n" );
  ImprimirDatos( &a1 );
  
  return 0;
}