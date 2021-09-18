#include "main.h"

int main (void)
{
  char cad[20];
  int longitud;
  
  printf ("Ingrese la cadena\n");
  scanf("%s", cad);
  
  longitud = myStrlen(cad);
  
  printf ("El largo de la cadena es: %d\n",longitud);
  
  return 0;
}