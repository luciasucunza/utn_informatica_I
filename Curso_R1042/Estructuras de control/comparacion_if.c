/**
 * \fn int main(void)
 * \brief Comparaciones de if (estructura condicional)
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
    
    
    int numero1;
    int numero2;
       
    printf("Ingrese el numero 1: \n");
    scanf("%d",&numero1);
    printf("Ingrese el numero 2: \n");
    scanf("%d",&numero2);
    
    if(numero1 == numero2)     
	printf("Numero 1 = Numero 2\n");
    
    if(numero1 > numero2)
	printf("Numero 1 > Numero 2\n");
    
    if(numero1 < numero2)
	printf("Numero 1 < Numero 2\n");
    
    if(numero1 != numero2)
	printf("Numero 1 != numero 2\n");    
	    
    return(0);                  // Retorno de funcion (fin de la funcion)
}
