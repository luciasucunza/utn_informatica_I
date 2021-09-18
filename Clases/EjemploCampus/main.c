#include "info1.h"


//EJERCICIO
//Contar 15 cartas e informar cuantas de cada tipo hubo
int main(void)
{

	printf("Empieza la funcion que utiliza If's\n");
	//Usamos la funcion que usa solo if
	contarPalosCortosConIf();

	printf("Empieza la funcion que utiliza If else's\n");
	//Usamos la funcion que usa if() {} else {}
	contarPalosCortosConIfElse();

	printf("Empieza la funcion que utiliza Switch\n");
	//Usamos la funcion que utiliza switch
	contarPalosCortosConSwitch();


	//Luego de esto vamos a poder ver que se imprimieron 3 lineas iguales en la consola

	//Devolvemos el valor 0
	return 0;
}