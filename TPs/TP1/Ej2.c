#include <stdio.h>

int main (void)
{	
    int sustraendo,minuendo,diferencia;
    
    printf("Ingrese el sustraendo\n");  
    scanf("%d",&sustraendo);
    
    printf("Ingrese el minuendo\n");
    scanf("%d",&minuendo);
    
    diferencia = sustraendo-minuendo;

    if(diferencia < 0)
	printf("El resultado es negativo\n");  
    
    else if(diferencia > 0)
	printf("El resultado es positivo\n");  
    
    else
    	printf("El resultado es 0\n");
    
    return 0;
}