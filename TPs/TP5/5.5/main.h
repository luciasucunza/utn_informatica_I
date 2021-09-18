#include <stdio.h>

union numero
{
  long variable;
  char byte[4];
};

void ImprimirLong( union numero*);