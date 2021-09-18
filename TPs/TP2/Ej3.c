#include <stdio.h>
#include <math.h>

float Sumar(float, float);
float Restar(float, float);
float Multiplicar(float, float);
float Dividir(float, float);
float Potencia(float, float);
float Raiz(float);
float Factorial(float);

int main (void)
{
  float valor1, valor2, resultado;
  int operacion, flagencendido, flagmatherror;
  flagencendido = 1;
  
  
  while(flagencendido != 0)
  {
    flagmatherror = 0;
    
    printf("Ingrese el valor\n");
    scanf("%f",&valor1);
    
    printf("Indique la operación que quiere realizar:\n Sumar = 0\n Restar = 1\n Multiplicar = 2\n Dividir = 3\n Potencia = 4\n Raiz Cuadrada = 5\n Factorial = 6\n");
    scanf("%d",&operacion);
    
    switch(operacion)
    {
      case 0:
	printf("Ingrese el segundo valor\n");
	scanf("%f",&valor2);
	resultado = Sumar(valor1, valor2);
	break;
	
      case 1:
	printf("Ingrese el segundo valor\n");
	scanf("%f",&valor2);
	resultado = Restar(valor1, valor2);
	break; 
      
      case 2:
	printf("Ingrese el segundo valor\n");
	scanf("%f",&valor2);
	resultado = Multiplicar(valor1, valor2);
	break;  
	
      case 3:
	printf("Ingrese el valor del divisor\n");
	scanf("%f",&valor2);
	if (valor2 == 0)
	  flagmatherror = 1;
	else	
	  resultado = Dividir(valor1, valor2);
	break;
	
      case 4:
	printf("Ingrese el valor del exponente\n");
	scanf("%f",&valor2);
	resultado = Potencia(valor1, valor2);
	break;
	
      case 5:
	if (valor1 < 0)
	  flagmatherror = 1;
	else	
	  resultado = Raiz(valor1);
	break;
	
      case 6:
	if (valor1 < 0)
	  flagmatherror = 1;
	else	
	  resultado = Factorial(valor1);
	break;
    }
    
    if (flagmatherror == 1)
	printf("math ERROR\n");
    
    if (flagmatherror == 0)
	printf("El resultado de la operación es:	%f\n",resultado);
    
    printf("Si desea salir pulse 0, para seguir pulse cualquier otro numero		");
    scanf("%d",&flagencendido);
  }
  
  return 0;
}

float Sumar(float num1,float num2)
{
    float r;
    r = num1 + num2;
    return r;
}

float Restar(float num1,float num2)
{
    float r;
    r = num1 - num2;
    return r;
}

float Multiplicar(float factor1,float factor2)
{
    float r;
    r = factor1 * factor2;
    return r;
}

float Dividir(float dividendo,float divisor)
{
    float r;
    r = dividendo / divisor;
    return r;
}

float Raiz(float num)
{
    float r;
    r = sqrt(num);
    return r;
}

float Potencia(float base,float exponente)
{    
    float r;
    r = pow(base, exponente);
    return r; 
}

float Factorial (float num)
{
    float r;
    int i;    
    r = num;
    
    for(i = 1 ; i < num ; i++)
	r = r * i;
  
    if(num == 0)
	r = 1;
  
    return r;
}
    
    