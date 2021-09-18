/**
	\file main.c
	\brief Contiene el main.
	\details Sin detalles.
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\version 1.0.0
*/
//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include "main.h"
#include "oper.h"

//------------
//-- Global --
//------------
/** 
 *  \var unsigned char buffer[SIZE_1];
 *  \brief Descripción breve de la variable.
 *  \details Descripción detallada de la variable.
 */
unsigned char buffer[SIZE_1];



/**
	\fn int main (void)
	\brief Cálcula suma y producto.
	\details Pide el ingreso de dos números enteros, realiza la suma y el producto.
	Si los dos operandos son cero sale del programa.
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\return Retorna siempre cero.
	\todo Usar parámetros por linea de comandos.
*/
int main(void)
{
int a, b;
struct resultado_S resultado;

	do {
		//-- Ingreso de datos --
		printf ("Ingrese numero:\r\n");
		scanf ("%d", &a);
		printf ("Ingrese numero:\r\n");
		scanf ("%d", &b);
		
		
		resultado.suma = operSuma (a, b);
		printf ("\r\n%d + %d = %d\r\n", a, b, resultado.suma); 
		resultado.producto = operProducto (a, b);
		printf ("\r\n%d * %d = %d\r\n", a, b, resultado.producto); 
		
	} while ((a != 0) || (b != 0));
	
	
	return (0);
}
