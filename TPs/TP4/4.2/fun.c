#include "main.h"

float suma (float* d, int n)
{
  int i;
  float acu;
  
  for ( i = 0 , acu = 0 ; i < n ; i++)
    acu = acu + *(d + i);
  
  return acu;   
}

float promedio(float* d, int n)
{
  float acu;
  
  acu = suma( d , n ) / (float) n;
  
  return acu;
}

float sumapar(float* d, int n)
{
    int i;
    float acu;
  
    for ( i = 1 , acu = 0 ; i < n ; i++ , i++)
      acu = acu + *(d + i);
  
    return acu;
}

float promediopositivo(float* d, int n)
{
    int i;
    float acu, cont = 0;
  
    for ( i = 0 , acu = 0 ; i < n ; i++)
    {
      if ( *(d + i) >= 0 )
      {
	acu = acu + *(d + i);
	cont++;
      }
    }
    
    acu = acu / cont ;
    
    return acu; 
}