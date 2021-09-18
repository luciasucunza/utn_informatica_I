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
  struct alumno *datos;
  struct nodo *next;
};


void CargarLista( struct nodo **);
void CargarDatos (struct alumno *);
void RemoverDuplicados( struct nodo *);
void MostrarLista( struct nodo *);
void LiberarLista( struct nodo **);