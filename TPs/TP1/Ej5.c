#include <stdio.h>

int main (void)
{	
    float kelvin,celsius;
        
    printf("Ingrese la temperatura en grados Celsius\n");  
    scanf("%f",&celsius);
    
    kelvin = celsius+273;
    printf("La temperatura es %f°C, igual a %f°K\n", celsius,kelvin); 
   
    return 0;
}