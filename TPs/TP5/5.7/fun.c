/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Funciones ejercicio 7
*/ 
#include "main.h"
/**
 * @fn		Complex Suma (Complex *, Complex *)
 * @brief 	Realiza la suma de dos numeros complejos
 * @param s1 	Numero complejo a sumar
 * @param s2 	Numero complejo a sumar
 * @return	Resultado de la suma
*/
Complex Suma (Complex *s1 , Complex *s2)
{
  Complex suma;
  suma.real = s1->real + s2->real;
  suma.imag = s1->imag + s2->imag;
  
  return suma;
}
/**
 * @fn		Complex Resta (Complex *, Complex *)
 * @brief 	Realiza la resta de dos numeros complejos
 * @param min 	Minuendo 
 * @param sust 	Sustraendo 
 * @return	Resultado de la resta
*/
Complex Resta (Complex *min, Complex *sust)
{
  Complex resta;
  
  resta.real = min->real - sust->real;
  resta.imag = min->imag - sust->imag;
  
  return resta;
}
/**
 * @fn		Complex Producto (Complex *, Complex *)
 * @brief 	Realiza el producto entre dos numeros complejos
 * @param f1 	Numero complejo a multiplicar 
 * @param f2 	Numero complejo a multiplicar
 * @return	Resultado del producto
*/
Complex Producto (Complex *f1, Complex *f2)
{
  Complex producto;
 
  producto.real = (f1->real)*(f2->real) - (f1->imag)*(f2->imag);
  producto.imag = (f1->real)*(f2->imag) + (f1->imag)*(f2->real);
  
  return producto;
}
/**
 * @fn		Complex Cociente (Complex *, Complex *)
 * @brief 	Realiza el cociente entre dos numeros complejos
 * @param d1 	Divisor 
 * @param d2 	Dividendo
 * @return	Resultado del cociente
*/
Complex Cociente (Complex *d1, Complex *d2)
{
    Complex cociente;
    
    cociente.real = ((d1->real)*(d2->real) + (d1->imag)*(d2->imag)) / ((d2->real)*(d2->real) + (d2->imag)*(d2->imag));
    cociente.imag = ((d1->imag)*(d2->real) - (d1->real)*(d2->imag)) / ((d2->real)*(d2->real) + (d2->imag)*(d2->imag));
    
    return cociente;
}
/**
 * @fn		Complex Conjugado (Complex *)
 * @brief 	Calcula el conjugado de un numero complejo
 * @param num 	Numero complejo a conjugar
 * @return	Resultado de conjugar el complejo
*/
Complex Conjugado (Complex *num)
{
  Complex conjugado;
   
  conjugado.real = num->real;
  conjugado.imag = 0 - (num->imag);
  
  return conjugado;
}