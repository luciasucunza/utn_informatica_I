//Capas de ingresar 10 string y luego las muestre en pantalla, de las cuales no se conoce su longitud

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
  char aux[255];
  char *p[10];
  char *pchar;
  int i, l, k, marca, n;
  
  for (i = 0 ; i < 10 ; i++)
  {
    scanf ("%s",aux);
    
    l = strlen (aux) + 1;    
    p[i] = malloc(l);
    
    strcpy (p[i], aux);
  }
  
  for (i = 0 ; i < 10 ; i++)
    printf ("La cadena %d es: %s\n", i, p[i]);
  
  for (i = 0 ; i < 10 ; i++)
    free (p[i]);
    
  k = 1;
  do 
  {
    marca = 1;
    
    for (i = 0 ; i < n-k ; i++)
    {
      if (strcmp (p[i], p[i+1]) > 0)
      {
	pchar = p[i];
	p[i] = p[i+1];
	p[i+1] = pchar;
	
	marca = 1;
      }
    }
    k++;
  }while (marca);
  
  return 0; 
}