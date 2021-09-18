#include <stdio.h>
#include <string.h>

#define MSG "mundo"
#define TAM 1024

int main (int argv, char* argc [])
{
  FILE *org, *dst;
  char buffer[TAM];
  int i,j;
  char aux[30];
  
  if(argv != 3)
  {
    printf ("No hay archivo\n");
    return (-1);
  }
  
  if((org = fopen( argv[1], "r") ) == NULL)
  {
    return (-1);
  }
  
  while ( !feof(org))
  {
    fread (buffer, TAM, 1, org );
    
    for (i = 0, j = 0; i < TAM ; i+2)
    {
      while ( (buffer[i] != ' ') && (buffer[i] != '\n') 
      {
	aux[j] = buffer [i];
	j++, i++;
      }
      aux[j] = '\n';
      
    if (!strcmp (aux, MSG))
    {
      for (j = 0; *(aux+j) != '\0' ; j++)
	*(aux+j) = 'x';
    }
    
    fprintf (dst, "%s", aux);
    j = 0;
    }
  }
  return 0;
}
    
    