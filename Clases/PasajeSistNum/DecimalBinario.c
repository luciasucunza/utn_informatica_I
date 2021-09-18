#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int DecBin ( int Dec, char *Bin);

int main (void)
{
  int a;
  char b[33];
  
  printf("Ingrese el numero decimal:   ");
  scanf("%d",&a);
  
  DecBin( a, b);
  
  printf("En binario es: %s",b);
  
  
  return  0; 
}
// PODRÍA IR SIN EL \n SI DESPUES NO LO QUIERO MOSTRAR y NO '0' ni '1' sino 0 y 1
int DecBin ( int Dec, char *Bin)
{
  int i, complemento2 = 0;
 
  if( Dec >= 0 )   
  {
    *(Bin) = '0';
    for( i = 1 ; i < 32 ; i++ )
    {
      *(Bin+32-i) = (Dec%2) +'0';
      Dec = Dec / 2;
    }
  }
  
  else
  {
    Dec = -Dec;
    *(Bin) = '1';
    for( i = 1 ; i < 32 ; i++ )
    {
      *(Bin+32-i) = (Dec%2) +'0';
      Dec = Dec / 2;
    }
    
    for( i = 31 ; i > 0 ; i-- )
    {
      if( complemento2 )
	*(Bin+i) = (!(*(Bin+i)-'0'))+'0';
      if( *(Bin+i) == '1' )
	complemento2 = 1;
    }
  }
  
  *(Bin+32) = '\n';
  return 1;
}