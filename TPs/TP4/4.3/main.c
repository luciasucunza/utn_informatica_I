#include "main.h"

int main (void)
{
  char cad[20];
  
  printf("Ingrese la primera cadena:\n");
  scanf("%s",cad);
  
  stringReverse (cad);
  
  printf("La cadena invertida es: %s\n", cad);  
  
  return 0;
}