#include "main.h"

int main (void)
{
  char cad1[20], cad2[20];
  int n, r;
  
  printf ("Ingrese la primera cadena:\n");
  scanf ("%s", cad1);
  
  printf ("Ingrese la segunda cadena:\n");
  scanf ("%s", cad2);
  
  printf ("Ingrese la cantidad de caracteres a comparar:\n");
  scanf ("%d", &n);
  
  r = myStrncmp(cad1, cad2, n);
  
  if ( r == 0 )
    printf ("Tienen el mismo orden alfabetico\n");
  
  else if ( r > 0 )
    printf ("La primera cadena esta primera alfabeticamente\n");
  
  else
    printf ("La segunda cadena esta primera alfabeticamente\n");
  
  
  return 0;
}