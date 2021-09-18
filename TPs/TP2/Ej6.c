#include<stdio.h>

#define TEMP 15

int MaximaTemperatura(float,float,float,float,float);
float Prueba(int);

int main (void)
{
    float MT1, MT2, MT3, MT4, MT5;
    int numsensor;
    
    MT1 = Prueba(1);
    MT2 = Prueba(2);
    MT3 = Prueba(3);  
    MT4 = Prueba(4);
    MT5 = Prueba(5);
    
    numsensor = MaximaTemperatura(MT1, MT2, MT3, MT4, MT5);
    printf("El Sensor %d registro la mayor temperatura\n", numsensor);
    
    return 0;
}

float Prueba (int sensor)
{    
    int i;
    float dato, datomax = promedio = 0;
        
    printf("Ingresar datos del Sensor %d\n",sensor);
    
    for(i = 0 ; i < TEMP ; i++)
    {
	scanf("%f",& dato);
	
	promedio = promedio + dato;
	
	if (i == 1)
	    datomax = dato;
	
	if (dato > datomax)
	    datomax = dato;	
    }

    promedio = promedio / i;
    
    printf("La temperatura promedio detectada por el Sensor %d es:	%f\n", sensor, promedio);
    printf("La maxima temperatura registrada por el Sensor %d es:	%f\n", sensor, datomax);
    
    return datomax;
}

int MaximaTemperatura(float MT1, float MT2, float MT3, float MT4, float MT5)
{
    int sensormax = 1;
    float datomax;
    datomax = MT1;
    
    if (MT2 > datomax)
    {
	sensormax = 2;
	datomax = MT2;
    }
    
    if (MT3 > datomax)
    {
	sensormax = 3;
	datomax = MT3;
    }
    
    if (MT4 > datomax)
    {
	sensormax = 4;
	datomax = MT4;
    }
    
    if (MT5 > datomax)
    {
	sensormax = 5;
	datomax = MT5;
    }
    return sensormax;    
}