/**
 * \fn int main(void)
 * \brief Función recursiva que obtiene el factorial de un número.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 2014.05.16
 * \return Retorna 0 en caso de exito
 */

#include <stdio.h>
#include <stdlib.h>


long factorial(int numero);

 int main(void){

	int numero;

   puts("¿Que numero desea calcular el factorial?");
   scanf("%d",&numero);
	printf("El factorial del numero %d es: %ld",numero,factorial(numero));
   getchar();
   getchar();
   return(0);
}


 /* Funcion recursiva que realiza el factorial de un numero ingresado
por teclado */


long factorial(int numero){

	if(numero<1){
   	return(1);
   }
   else{
   	return(numero*(factorial(numero-1)));
   }
}

