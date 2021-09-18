/**
 * @file 	func.c 
 * @author 	Lucía Sucunza
 * @date 	15-11-16
 * @brief 	Funcion ejercicio 2
*/ 
#include "main.h"
/**
 * @fn		void ImprimirDatos (struct alumno *)
 * @brief 	Imprimir los datos guardados en una estructura
 * @param a1 	Estructura de la que se imprimen los datos
 * @return	Void
*/
void ImprimirDatos (struct alumno * a1)
{  
  printf ("NOMBRE: %s\n", a1->nombre);  
  printf ("APELLIDO: %s\n", a1->apellido);  
  printf ("EDAD: %d\n", a1->edad);  
  printf ("DNI: %d\n", a1->dni);  
  printf ("PROMEDIO: %f\n", a1->promedio);
}
/**
 * @fn		void CargarDatos (struct alumno *)
 * @brief 	Carga los datos en una estructura
 * @param a1	Estructura en la que se cargan los datos
 * @return	Void
*/
void CargarDatos (struct alumno * a1)
{  
  printf ("	NOMBRE: ");
  scanf ("%s", a1->nombre);
  printf ("	APELLIDO: ");
  scanf ("%s", a1->apellido);
  printf ("	EDAD: ");
  scanf ("%d", &a1->edad);
  printf ("	DNI: ");
  scanf ("%d", &a1->dni);
  printf ("	PROMEDIO: ");
  scanf ("%f", &a1->promedio);
}