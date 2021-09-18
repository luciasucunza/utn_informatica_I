/**
	\file oper.c
	\brief Contiene funciones que realizan operaciones matemáticas
	\details En esta unidad hay funciones para realizar sumas y productos.
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\version 1.0.0
*/
//--------------
//-- Includes --
//--------------
#include "oper.h"

/**
	\fn int operSuma (int a, int b)
	\brief Suma dos numeros enteros y retorna el resultado.
	\details Sin detalles
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\param [in] a Primer operando a sumar
	\param [in] b Segundo operando a sumar
	\return Retorna la suma de los operandos pasados como parámetros
	\bug No verifica.
	
*/
int operSuma (int a, int b)
{
	return (a + b);
}

/**
	\fn int operProducto (int a, int b)
	\brief Multiplica dos numeros enteros y retorna el resultado.
	\details Sin detalles
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\param [in] a Primer operando a multiplicar
	\param [in] b Segundo operando a multiplicar
	\return Retorna el producto suma de los operandos pasados como parámetros
	\bug No verifica nada.
*/
int operProducto (int a, int b)
{
	return (a * b);
}
