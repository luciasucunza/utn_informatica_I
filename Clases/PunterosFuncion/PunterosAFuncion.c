#include <stdio.h>

int Suma (int a, int b);
int Resta (int a, int b);
// int Resolver(int a, int b, int(*fun)(int, int) );


void main( void )
{
  int valor1, valor2,  resultado,opcion ;
  int (*opciones[2])(int,int) = { Resta, Suma };
  printf("Ingrece la Suma(1) o la Resta(0)\n");
  scanf("%d", &opcion);
  printf("Ingrece el valor de a y luego de b\n");
  scanf("%d", &valor1);
  scanf("%d", &valor2);
  
  resultado = (*opciones[opcion])(valor1, valor2);
  printf("resultado: %d\n", resultado);
  return;
  
}
/*
int main (void)
{
  int valor1, valor2, opcion, retorno;
  int (* enviar )( int,  int);  
  int *punteroa;
  
  punteroa =&valor1;
  
  printf("Ingrece la Suma(1) o la Resta(0)\n");
  scanf("%d", &opcion);
  printf("Ingrece el valor de a y luego de b\n");
  scanf("%d", punteroa);
  scanf("%d", &valor2);
    
  if( opcion )
  {
    enviar = Suma;
    retorno = Resolver(  valor1, valor2, enviar );
  }
  else
  {
    enviar = Resta;
    retorno = Resolver(  valor1, valor2, enviar ); 
  }
  printf("Retorno %d\n", retorno);
  
  return 0;
}

int Resolver( int a, int b, int(*fun)(int, int) )
{
  int respuesta;
  respuesta =(*fun)(a,b);
  return respuesta; 
}
*/

int Suma( int a, int b )
{
  return (a+b);
}
int Resta( int a, int b )
{
  return (a-b);
}