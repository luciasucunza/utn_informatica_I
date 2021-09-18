/**
 * \fn int main(void)
 * \brief Calculo el modulo de un numero ingresado por teclado si es positivo lo multiplico por su mismo valor e imprimo
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 2014.04.011 
 * \return Retorna 0 en caso de exito
 */


/*************
* Estructura if:
*
* if(condicion){
*  cuerpo funcion
*  
*  }
***************/


//--------------

#include <stdio.h>              


int main(void){                 // retorno main (argumentos)
    
    //Declaro las variables a utilizar en el programa.
    
    int numero;
    int mostrar;
    
    //Comienzo a escribir las instrucciones.
    
    printf("Ingrese el numero a calcular su modulo: \n");
    scanf("%d",&numero);      
    
    if(numero < 0){   //if(condicion) - verdadero entra, falso no.
      numero = -numero;
      printf("El valor del numero es: %d\n",numero);
    }
    else{
      mostrar = numero*numero;
      printf("El resultado es: %d\n",mostrar);
    }
	    
    return(0);                  // Retorno de funcion (fin de la funcion)
}
