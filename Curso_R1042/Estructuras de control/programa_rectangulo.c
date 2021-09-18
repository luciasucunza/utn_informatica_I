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
    
    int lado_menor;     // tipo de dato   nombre variable = inicializacion, siendo esta ultima no obligatoria.
    int lado_mayor;
    int perimetro;  //Acumulador de resultado.
    int superficie;
    
    //Comienzo a escribir las instrucciones.
    
    printf("Ingrese el lado menor: \n"); // \n Indica que el cursor se corra a siguiente linea.
    scanf("%d",&lado_menor);  // %d indica que el formato del dato a ingresar es del tipo entero.        
    printf("Ingrese el lado mayor: \n"); 
    scanf("%d",&lado_mayor);  
    
    /* calculo area */
    perimetro = (lado_mayor * 2) + (lado_menor * 2); 
    
    printf("El perimetro es: %d\n",perimetro);
    
    /* Calculo de superficie */
    superficie = lado_mayor * lado_menor; 
    
    printf("La superficie es: %d\n",superficie);
    
    return(0);                  // Retorno de funcion (fin de la funcion)
}
