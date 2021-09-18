#include <stdio.h>

float RealizarPotencia(int, int);

int main (void)
{
    int x,y;
    float resultado;
       
    printf("Para calcular una potencia ingrese el valor de la base:	");
    scanf("%d",&x);

    printf("Ingrese el valor de su exponente:			");
    scanf("%d",&y);

    resultado = RealizarPotencia(x,y); 
    printf("El resultado es: 	%f\n", resultado);
    
    return 0;    
}


float RealizarPotencia(int base, int exponente)
{
    float r, acum;
    int cont;
    acum = 1;
    
    if (exponente >= 0)
    {
	for(cont = 0 ; cont < exponente ; cont++)
	    acum = base * acum;
	r = acum;
    }
    
    else
    {
	for(cont = exponente ; cont < 0; cont++)
	    acum = base * acum;		
	r = 1 / acum;
    }
    
    return r;  
}
