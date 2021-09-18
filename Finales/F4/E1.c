/*
 * Argumentos del main:
 * 	Argc = 1 si solo le mandas el ./ejecutabe
 * 	Argv[0] "./ejecutable\n"
 */

#include<stdio.h>

int main( int argc, char **argv)
{
  if( !(strcmp( argv[0], "./verificador\n")) )
  {    
    printf("\nNombre incorrecto\n");
    return -1;
  }
  printf("\nNombre Correcto\n");
  return 0;
}