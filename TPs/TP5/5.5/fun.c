/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	07-12-16
 * @brief 	Funcion ejercicio 5
*/ 
#include "main.h"
/**
 * @brief 	Muestra en pantalla, byte a byte, el contenido de una variable long
 * @fn 		void ImprimirLong( union numero *)
 * @param num	Puntero a la union que guarda el long  
 * @return 	void
*/
void ImprimirLong( union numero *num)
{    
  int i;
  
  for(i = 0 ; i < 4 ; i++)
    printf("%x \n", (unsigned int)*((num->byte)+i));
}