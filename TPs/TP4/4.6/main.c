#include "main.h"

int main (void)
{
  char cad[20];
  char nuevo, viejo;
  
  printf ("Ingrese la cadena:\n");
  scanf ("%s", cad);
  
  printf ("Ingrese el caracter a reemplazar:\n");
  scanf ("%c", &viejo);
  scanf ("%c", &viejo);
  
  printf ("Ingrese el nuevo caracter:\n");
  scanf ("%c", &nuevo);
  scanf ("%c", &nuevo);
  
  printf ("La vieja cadena es: %s\n",cad);
  
  replace(cad, nuevo, viejo);
  
  printf ("La nueva cadena es: %s\n",cad);
  
  return 0;
}