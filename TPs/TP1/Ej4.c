#include <stdio.h>
#include <math.h>

int main (void)
{	
    float a,b,c,discriminante,imaginaria,real,x1,x2;
        
    printf("Ingrese el valor de a\n"); 
    scanf("%f",&a);
    
    printf("Ingrese el valor de b\n");
    scanf("%f",&b);
    
    printf("Ingrese el valor de c\n");
    scanf("%f",&c);
    
    discriminante = (b*b)-(4*a*c);    
    real =  -b/(2*a);    

    if(discriminante < 0)
    {
	imaginaria = sqrt(-discriminante)/(2*a);
	printf("\nLas raices son imaginarias:\n	X1 = %f - %fj\n	X2 = %f + %fj\n\n",real,imaginaria,real,imaginaria); 
    }
    else if (discriminante >0)
    {
	x1 = real - sqrt(discriminante)/(2*a);
	x2 = real + sqrt(discriminante)/(2*a);
	printf("\nLas raices son reales:\n	X1 = %f \n	X2 = %f\n\n",x1,x2); 
    }
    else
    {
	printf("\nLas raices son iguales:\n	X1 = X2 = %f\n\n",real); 
    }
    return 0;
}