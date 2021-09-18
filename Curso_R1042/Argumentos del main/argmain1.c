#include <stdio.h>


int main(int argc,char *argv[],char *envp[])
{
  int i;
  printf("\nLista de argumentos: \n");
  for(i=0;i<argc;i++) printf("%s \n",argv[i]);
  printf("\nCantidad de argumentos: %d\n\n",argc);
  return 0;
}
