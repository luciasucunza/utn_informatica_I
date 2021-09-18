#include "main.h"

int main (void)
{
    float v[DATOS_NUMERICOS]; 
    int i;
    float r; 
    
    for( i = 0; i < DATOS_NUMERICOS ; i++ )
    {
	printf("Ingrese el valor del dato numero %d:", (i + 1) );
	scanf("%f", (v + i));
    }
    
    r = suma(v, DATOS_NUMERICOS);
    printf("La suma es %f\n ", r);
    
    r = promedio(v, DATOS_NUMERICOS);
    printf("El promedio es %f\n ", r);    
    
    r = sumapar(v, DATOS_NUMERICOS);
    printf("La suma par es %f\n ", r);
    
    r = promediopositivo(v, DATOS_NUMERICOS);
    printf("El promedio positivo es %f\n ", r);
    
    return 0;  
}