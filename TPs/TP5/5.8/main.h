#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_VECTOR 255
#define PATH_ARCHIVO "legajos.dbf" 

struct datos
{
  long legajo;
  char apellido[31];
  char nombre[31];
};

void carga( struct datos *);
int fin( struct datos );
void SwapDatos( struct datos *, struct datos *);
void Ordenar( struct datos *);
void Guardar( struct datos *);
void printefearvector( struct datos *);