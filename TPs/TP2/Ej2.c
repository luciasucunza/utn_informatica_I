#include <stdio.h>

float Factorial(int);

int main (void)
{   
    int dato;
    float resultado;
    
    printf("Ingrese un numero del 0 al 34:	");
    scanf("%d",&dato);
    
    while (dato < 0)
    {
	printf("No existe el factorial de un numero negativo\nIngrese un nuevo numero, del 0 al 34:	");
	scanf("%d",&dato);
    }
      
    resultado = Factorial(dato);  
    printf("Su factorial es: 		%f\n",resultado);  
    
    return 0;
}

float Factorial (int numero)
{
    float r;
    int i;    
    r = numero;
    
    for(i = 1 ; i < numero ; i++)
	r = r * i;
  
    if(numero == 0)
	r = 1;
  
    return r;
}