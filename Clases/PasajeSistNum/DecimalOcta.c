#include<math.h>
#include<stdio.h>
#include<stdlib.h>
// NO CALCULA EL -(2 A LA 31), PORQUE NO ME ENTRA EN EL INT SI ES POSITIVO)
int DecOcta ( int Dec, char *Octa);

int main (void)
{
  int a;
  char o[13];
  
  printf("Ingrese el numero decimal:   ");
  scanf("%d",&a);
  
  DecOcta( a, o);
  
  printf("En Octa es: %s",o);
  
  
  return  0; 
}
// PODRÍA IR SIN EL \n SI DESPUES NO LO QUIERO MOSTRAR y NO '0' ni '1' sino 0 y 1
int DecOcta ( int Dec, char *Octa)
{
  int i, aux;
 
  if( Dec >= 0 )   
    *(Octa) = '+';
  else
  {
    *(Octa) = '-';
    Dec = -Dec;
  }
  
  for( i = 1 ; i < 12 ; i++ )
  {
    if( (aux = (Dec%8)) > 12 )
      *(Octa+12-i) = aux -10 + 'A';
    else
      *(Octa+12-i) = aux + '0';
    Dec = Dec / 8;
  }
  *(Octa+12) = '\n';
  return 1;
}