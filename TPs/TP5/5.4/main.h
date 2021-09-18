#include <stdio.h>
#include <stdlib.h>

struct alumno
{
  char nombre[15];
  char apellido[15];
  int  edad;
  int  dni;
  float  promedio;  
};

struct nodo
{
  struct alumno *alumno;
  struct nodo *next;
};

void RemoverNodo (struct nodo *);