#include <stdio.h>
#include <stdlib.h>

struct nodo
{
  void *datos;
  struct nodo *next;
};

struct nodo * DetectaLazo (struct nodo *);