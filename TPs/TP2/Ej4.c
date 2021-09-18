#include <stdio.h>

int Diferencia(void);

int main (void)
{
    int diferencia;
    
    diferencia = Diferencia();
    
    if(diferencia < 0)
    {
	printf("El resultado es negativo\n");  
    }
    else if(diferencia > 0)
    {
	printf("El resultado es positivo\n");  
    }
    else if(diferencia == 0)
    {
	printf("El resultado es 0\n");
    }
    
    return 0;
}


int Diferencia (void)
{	
    int sustraendo,minuendo,r;
    
    printf("Ingrese el sustraendo\n");  
    scanf("%d",&sustraendo);
    
    printf("Ingrese el minuendo\n");
    scanf("%d",&minuendo);
    
    r = sustraendo-minuendo;

    return r;
}