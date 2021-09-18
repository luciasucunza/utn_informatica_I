//Ordeno por burbujeo una cantidad TAM de datos, del tipo struct dato, de dos formas distintas, primero por nombre despues por
// legajo

#include<stdio.h>
#include<string.h>

#define ORDENAR 1
#define NOORDENAR 0
#define TAM 5

struct dato
{
  char n[10];
  int l;
};

int Ordenar1(struct dato *, int);
int Ordenar2(struct dato *, int);
void Ordenamiento (struct dato*, int, int (*) (struct dato *, int) );
void CargarDatos (struct dato *);

int main (void)
{
  int i;
  struct dato d[TAM];
  
  for (i = 0 ; i < TAM ; i++)
  {
    printf ("NOMBRE: ");
    scanf ("%s", d[i].n);  
    printf ("LEGAJO: ");
    scanf ("%d", &(d[i].l));
  }
  
  Ordenamiento (d, (TAM), Ordenar1);
  
  for (i = 0 ; i < TAM ; i++)
  {
    printf ("NOMBRE: %s", (d[i].n)); 
    printf (" LEGAJO: %d\n", (d[i].l));
  }
  
  Ordenamiento (d, (TAM), Ordenar2);
  
    for (i = 0 ; i < TAM ; i++)
  {
    printf ("NOMBRE: %s", (d[i].n)); 
    printf (" LEGAJO: %d\n", (d[i].l));
  }
  
  
  
  return 0;
}

int Ordenar1( struct dato *d, int i )
{
  if (strcmp (d[i].n, d[i+1].n) > 0)
    return ORDENAR;
  return NOORDENAR;
}

int Ordenar2( struct dato *d, int i )
{
  if (d[i].l > d[i+1].l)
    return ORDENAR;
  return NOORDENAR;
}

void Ordenamiento (struct dato *d, int N, int (*ord)(struct dato *, int ) )
{
  int marca, i, k = 1;
  struct dato aux;
  
  do
  {
    marca = 0;
    for(i = 0; i < N-k ; i++)
    {
	if ( ord (d, i) > 0 )
	{
	  aux = d[i];
	  d[i] = d[i+1];
	  d[i+1] = aux;
	  marca = 1;     
	}	
    }
    k++;
  }while(marca);
}