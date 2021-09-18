/**
 * \file 3.8.c
 * \brief Programa que realiza la conversion de temperaturas entre Celsius y Fahrenheit.
 * \author Pose, Fernando Ezequiel.
 * \date 2011.22.05
 * \version 1.0.1
 */
//--------------
//-- Includes --
//--------------

#include <stdio.h>

//----------------
//-- Prototipos --
//----------------

enum test{
	
	CELSIUS = 0,
	FAHRENHEIT,
	
};

double conv(double temperatura, enum test escala);

/**
 * \fn int main (void)
 * \brief Funcion que pide el ingreso de la temperatura y muestra la conversion en pantalla. 
 * \author Pose, Fernando Ezequiel.
 * \date 2011.22.05
 * \return Retorna siempre cero.
 */

int main(){
	
	//Ingreso las variables de la función main.
	
	double temperatura;
	double conversion;
	int test;
	
	//Comienzo del switch, el usuario eligera la conversion a realizar.
	
	puts ("¿Que conversion desea realizar?");
	puts ("0- Celsius a Fahrenheit");
	puts ("1- FAhrenheit a Celsius\r\n");
	scanf("%d",&test);
	
	//Menu de seleccion de conversion.
	
	switch(test){
		
		//Caso CELSIUS a FAHREINHEIT.
		
		case 0:
			
			puts ("Introduzca el valor a convertir: ");
			scanf("%lf",&temperatura);
			//Llamo a la funcion conv (donde se realizara la conversion).
			conversion = conv(temperatura, CELSIUS);
			//Se muestra la temperatura convertida.
			printf("La temperatura convertida a Fahrenheit es: %lf ºF\r\n",conversion);
			break;

			//Caso FAHREINHEIT a CELSIUS.
			
		case 1:
			
			puts ("Introduzca el valor a convertir: ");
			scanf("%lf",&temperatura);
			//Llamo a la función conv (donde se realizara la conversion).
			conversion = conv(temperatura,FAHRENHEIT);
			//Se muestra la temperatura convertida.
			printf("La temperatura convertida a Celsius es: %lf ºC\r\n",conversion);
			break;
		
		default:
			puts ("Opcion incorrecta\r\n");	
	}
	
	return (0);
}

/**
 * \fn double conv(double temperatura, enum test escala)
 * \brief Funcion que realiza la conversion de temperatura.
 * \author Pose, Fernando Ezequiel.
 * \date 2011.22.05
 * \param temperatura.
 * \param escala.
 * \return Retorna el resultado de la conversion.
 */

double conv(double temperatura, enum test escala){
	
	//Se declaran las variables internas de la función.
	
	double convtemperatura;
	
	//Si la escala esta en CELSIUS la convierte en FAHREINHEIT.
	if (escala == CELSIUS){
		convtemperatura = (((temperatura*9)/5)+32);
		//Si la escala esta en FAHREINHEIT la convierte en CELSIUS.
	}else{
		convtemperatura = (((temperatura - 32)*5)/9);
	}
	
	return (convtemperatura);
}