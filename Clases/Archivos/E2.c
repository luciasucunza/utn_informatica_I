#include <stdio.h>
#include <string.h>

#define CORRE "Correjido"
#define TAM 20
#define MSG "mundo" 

int main (void)
{
  FILE *fdr,*fdc;
  char buff[TAM];
  int a;
  
  fdr = fopen ( "Hola.txt", "r");
  fdc = fopen ( CORRE, "w+");
  
  while ( !feof(fdr) )
  {
    fscanf (fdr, "%s", buff);
    a = strcmp (buff, MSG);
    
    if (a)
      fprintf(fdc, "%s", buff );
    
    else
      fprintf(fdc, "XXXXX");      
    
    fprintf (fdc," ");  
  }
  
  fclose (fdr);
  fclose (fdc); 
  
  return 0;
}
/*
 * int main (int argv, char* argc [])
{
  FILE *fdr,*fdc;
  char buff[TAM];
  int a;
  
  if (argv != 2)				//Me pasaron un argumento?
  {
    fprintf (stdout, "No hay nombre\n");		// stdout escribir en pantalla
    return (-1);
  }
 * */