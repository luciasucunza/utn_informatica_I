#include <stdio.h>

int main (void)
{	
    float radio,superficie;
        
    printf("Ingrese el radio\n");  
    scanf("%f",&radio);
    
    while (radio < 0)
    {
	printf("Ingrese un valor de radio no negativo\n");   
	scanf("%f",&radio);
    }
    
    superficie = (3.1416*radio*radio);
    printf("La superficie del circulo de radio %f es: %f\n", radio,superficie);
   
    return 0;
}