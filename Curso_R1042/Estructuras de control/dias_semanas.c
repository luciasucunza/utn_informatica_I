/**
 * \fn int main(void)
 * \brief if anidados
 * \author Fernando Pose (Fernandoepose@gmail.com)
 * \date 2014.04.011 
 * \return Retorna 0 en caso de exito
 */


//--------------

#include <stdio.h>              


int main(void){                 // retorno main (argumentos)
    
    
    int dia_semana;
    
       
    printf("Ingrese un numero: \n");
    scanf("%d",&dia_semana);
    
    
    if(dia_semana == 1){     
	printf("Hoy es LUNES\n");
    }
    else if(dia_semana ==  2){
	printf("Hoy es MARTES\n");
    }else if(dia_semana == 3){
	    printf("Hoy es MIERCOLES\n");
	}else if(dia_semana == 4){
		printf("Hoy es JUEVES\n");
	    }else if(dia_semana == 5){
		printf("Hoy es VIERNES\n");
	      }else if(dia_semana == 6){
		  printf("Hoy es SABADO\n");
	      }else if(dia_semana == 7){
		    printf("Hoy es DOMINGO\n");
		}
    return(0);                  // Retorno de funcion (fin de la funcion)
}
