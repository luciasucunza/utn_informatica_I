/**
 * \fn int main(void)
 * \brief Función recursiva que realiza el potencial de un número.
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 2014.05.16
 * \return Retorna 0 en caso de exito
 */


#include <stdio.h>
#include <stdlib.h>

long potenciar(int numero, int potencia);

int main(void){

	int numero;
   int potencia;

   puts("¿Que numero desea potenciar: ?");
   scanf("%d",&numero);
   puts("¿A que numero lo desea elevar: ?");
   scanf("%d",&potencia);
	printf("El factorial del numero %d es: %ld",numero,potenciar(numero,potencia));
   getchar();
   getchar();
   return(0);
}

/* Funcion recursiva que realiza el potencial de un numero ingresado
por teclado elevado a otro numero ingresado por teclado. */


long potenciar(int numero, int potencia){

	if(numero<1){
   	return(1);
   }
   else{
   	return(numero*(potenciar(numero,potencia-1)));
   }
}



