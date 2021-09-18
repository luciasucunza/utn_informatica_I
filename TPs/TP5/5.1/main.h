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

void CargarDatos (struct alumno *);