#include<stdio.h>

float Temperatura (void);

int main (void)
{
    float kelvin;
    
    kelvin = Temperatura();    
    printf("La temperatura en kelvin es igual a %f°K\n", kelvin);
    
    return 0;
}

float Temperatura(void)
{	
    float r,celsius;
        
    printf("Ingrese la temperatura en grados Celsius\n");  
    scanf("%f",&celsius);
    
    r = celsius + 273;
   
    return r;
}