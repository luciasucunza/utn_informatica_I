/**
 * \fn int main(void)
 * \brief sumo dos numeros enteros
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 2014.04.011 
 * \return Retorna 0 en caso de exito
 */

//--------------

#include <stdio.h>              


int main(void){                 // retorno main (argumentos)
    
    //Declaro las variables a utilizar en el programa.
    
    int valor1;     // tipo de dato   nombre variable = inicializacion, siendo esta ultima no obligatoria.
    int valor2;
    int resultado;  //Acumulador de resultado.
    
    //Lo que es lo mismo: int a,b,c;
    
    //Comienzo a escribir las instrucciones.
    
    printf("Ingrese el primer operando: \n"); // \n Indica que el cursor se corra a siguiente linea.
    scanf("%d",&valor1);  // %d indica que el formato del dato a ingresar es del tipo entero.        
    printf("Ingrese el segundo operando: \n"); 
    scanf("%d",&valor2);  
    
    /* Realizo la suma */
    resultado = valor1 + valor2; 
    
    printf("La suma de: %d + %d = %d\n",valor1,valor2,resultado);
    
    /* Realizo la resta */
    resultado = valor1 - valor2; 
    
    printf("La resta de: %d - %d = %d\n",valor1,valor2,resultado);
    
    /* Realizo la division */
    resultado = valor1 / valor2; 
    
    printf("El cociente de: %d / %d = %d\n",valor1,valor2,resultado);
    
    /* Realizo la multiplicacion */
    resultado = valor1 * valor2; 
    
    printf("La multiplicacion: %d * %d = %d\n",valor1,valor2,resultado);
    
    return(0);                  // Retorno de funcion (fin de la funcion)
}
