/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Main
*/ 
#include "main.h"
/**
 * @fn 		int main( void )
 * @brief 	Main para utilizar la funcioes de Suma, Resta, Producto, Cociente y Conjugado entre numero complejos
 * @details	Se ingresa un numero, luego la operacion a realizar y, si es necesario, un segundo numero, por ultimo muestra el resultado de la operacion en pantalla
 * @return 	0 por exito
 */ 
int main (void)
{
  int i;
  Complex num1, num2, resultado;
  Complex (*Operacion[4]) (Complex *, Complex *) = {Suma, Resta, Producto, Cociente};
  
  printf( "Ingrese la parte real y luego la imaginaria del primer numero:\n");
  scanf( "%f", &num1.real);
  scanf( "%f", &num1.imag);
  printf( "Ingrese la operacion que desea realizar\n1: Suma\n2: Resta\n3: Producto \n4: Cociente\n5: Conjugado\n");
  scanf( "%d", &i);
  while ( i < 1 || i > 5)
  {
     printf( "Ingrese una opcion valida\n1: Suma\n2: Resta\n3: Producto \n4: Cociente\n5: Conjugado\n");
     scanf( "%d", &i);
  }   
    
  if ( i == 5)
    resultado = Conjugado( &num1);
  else
  {
    i--;
    printf( "Ingrese la parte real y luego la imaginaria del segundo numero:\n");
    scanf( "%f", &num2.real);
    scanf( "%f", &num2.imag);
    resultado = (Operacion[i])( &num1, &num2);  
  }
  
  if ( resultado.imag < 0)
    printf( "El resultado es: %f %f i\n", resultado.real, resultado.imag);
  else
    printf( "El resultado es: %f +%f i\n", resultado.real, resultado.imag);
  return 0;  
}