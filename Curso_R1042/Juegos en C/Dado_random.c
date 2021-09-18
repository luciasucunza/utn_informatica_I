/**
 * \file 3.3.c
 * \brief Programa que simula el tiro de un dado de 10 lados.
 * \author Pose, Fernando Ezequiel (fernandoepose@gmail.com)
 * \date 2011.12.05
 * \version 1.0.0
 */
//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//----------------
//-- Prototipos --
//----------------

//Se declara la función que utilizamos en el programa.

int Dado(void);

/**
 * \fn int main (void)
 * \brief Pide el ingreso de dos numeros enteros, llama a funcion potencia y devuelve el resultado retornado de la función. 
 * \author Pose, Fernando Ezequiel
 * \date 2011.12.05
 * \return Retorna siempre cero.
 */
 
int main(void){
	
	//Se declaran las variables utilizadas en la función main.
	
	int resultado;
	char c;
	
	//Se da a elegir al usuario si desea tirar el dado, mientras que el time interno se encuentra constantemente corriendo.
	
	puts ("Si desea tirar el dado aprete: T ");
	scanf("%c",&c);
	
	//Si el usuario da la orden se tira el dado.
	
	if ((c == 't')||(c == 'T')){
		
	// Se invoca a la función Dado(), la cual generará el random.
		
		resultado = Dado();
		printf ("El dado giro y el valor obtenido es: %d\r\n",resultado);
		
		
	// De lo contrario si no se desea ejecutar el dado y se ingresa otro valor de c, entonces el programa acaba.
		
	}else{
		puts ("El programa se cerrara\r\n");	
		
	}
	return (0);
}

/**
 * \fn int Dado(void)
 * \brief Genera un random.
 * \author Pose, Fernando Ezequiel
 * \date 2011.12.05
 * \param void.
 * \return Retorna el resultado de un random.
 */

	//Función Dado().

int Dado(void){
	
	//Se inicializa la función random en el tiempo interno del microprocesador.
	
	srand (time (NULL));
	
	//Se declara la funcion N, la cual va a contener el valor resultante del random.
	
	int N;
	
	//N toma el valor que le asigne la cuenta de random, la cual va de 0 a 9 (diez digitos posibles)
	
	N = (int) ((rand()*10.0)/(RAND_MAX));
	
	//Se retorna el valor N.
	
	return (N);
}