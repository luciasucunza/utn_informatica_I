/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	07-12-16
 * @brief 	Main
*/ 
#include "main.h"
/**
 * @fn 		int main(void)
 * @brief 	Main para utilizar la funcion ImprimirLong
 * @details	Guarda un numero en la variable long de la union y luego muestra este numero en pantalla 
 * @return 	0 por exito
 */ 
int main (void)
{
  union numero numero1;
  
  numero1.variable = 0x1234567812345678;  
  ImprimirLong( &numero1 );
  
  return 0;
}
