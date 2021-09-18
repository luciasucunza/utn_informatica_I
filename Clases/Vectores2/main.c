#include "main.h"

int main (void)
{
    char cad[TAM];
    char auxiliar[TAM2];
    
    scanf("%s", cad); 	//el & va para señalar la direccion de la variable, em cambio cad ya es la direccion
    
    print f("La longitud es: %d", my_strlen(cad) );    
    
    if ( ! my_strcpy(auxiliar, cad) )
	printf("ERROR");
    
    if ( ! my_strcmp((auxiliar, cad) )
	printf ("Son iguales");
    
    else
	printf ("Son distintas");
} 