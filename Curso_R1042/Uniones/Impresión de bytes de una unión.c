/**
 *	\file impresion_de_bytes.c
 *	\fn void main(void);
 *	\brief Imprime byte a byte los bytes que constituyen una variable long.
 *	\author Pose Fernando Ezequiel (fernandoepose@gmail.com)
 *	\date 2014.08.08 
 *	\return 0 si todo sale bien.
 */
 
//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
 
//--------------
//-- Defines --
//--------------

#define CANT 4

//--------------
//-- Uniones --
//--------------

/**Defino un nuevo tipo de dato denominado union ejercicio.**/

union ejercicio{
	char caracteres[CANT];
    long total;
}; 

/* INICIA FUNCION MAIN PRINCIPAL */

int main(void){

	int i;
	union ejercicio muestra;  //Defino muestra del tipo de dato: union ejercicio.
    muestra.total = 0;           //Inicializo la variable total.
   
    printf("Total: %#x\n",&muestra.total);  // #x  - Imprime la dirección de memoria en Hexadecimal y le agrega un 0xDIR
    printf("Dato a dato: \n");
   
    for(i=0;i<CANT;i++)
   	    printf("Caracter[%d]: %#x\n",i,&muestra.caracteres[i]);  //Imprimo dirección a dirección.
   
   return(0);
}