#include<math.h>
#include<stdio.h>
#include<stdlib.h>
// NO CALCULA EL -(2 A LA 31), PORQUE NO ME ENTRA EN EL INT SI ES POSITIVO)

int DecHexa ( int Dec, char *Hexa);

int main (void)
{
  int a;
  char h[10];
  
  printf("Ingrese el numero decimal:   ");
  scanf("%d",&a);
  
  DecHexa( a, h);
  
  printf("En hexadecimal es: %s",h);
  
  
  return  0; 
}
// PODRÍA IR SIN EL \n SI DESPUES NO LO QUIERO MOSTRAR y NO '0' ni '1' sino 0 y 1
int DecHexa ( int Dec, char *Hexa)
{
  int i, aux;
 
  if( Dec >= 0 )   
    *(Hexa) = '+';
  else
  {
    *(Hexa) = '-';
    Dec = -Dec;
  }
  
  for( i = 1 ; i < 9 ; i++ )
  {
    if( (aux = (Dec%16)) > 9 )
      *(Hexa+9-i) = aux -10 + 'A';
    else
      *(Hexa+9-i) = aux + '0';
    Dec = Dec / 16;
  }
  *(Hexa+9) = '\n';
  return 1;
}