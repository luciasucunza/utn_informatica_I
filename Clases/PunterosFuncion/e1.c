//Es una mejor forma de hacer un switch case, porque no pregunta uno por uno sino que se dirije de una a la funcion que se
// quiere
#include<stdio.h>

int fun1 (void);
int fun2 (void);
int fun3 (void);
int fun4 (void);

int main (void)
{
  int (*pNombre[4]) (void) = {fun1, fun2, fun3, fun4};
  int c, i = -1;
  
  while(i)
  {
    scanf("%d", &c);
    i = pNombre[c] (); 
  }
}


int fun1 (void)
{
  printf("Soy funcion 1\n");
  return 1;
}
int fun2 (void)
{
  printf("Soy funcion 2\n");
  return 1;
}
int fun3 (void)
{
    printf("Soy funcion 3\n");
  return 1;
}
int fun4 (void)
{
    printf("Soy funcion 4\n");
  return 0;
}