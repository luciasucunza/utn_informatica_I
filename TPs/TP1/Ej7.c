#include <stdio.h>

int main (void)
{	
    int numero,producto,factor;
            
    printf("Ingrese un numero del 0 al 10 para conocer su tabla\n");  
    scanf("%d",&numero);
    
    for(factor = 0 ; factor < 11 ; factor++)
    {
	producto = factor*numero;  
	printf("%d x %d = %d\n", numero,factor,producto); 
    }

    return 0;
}
