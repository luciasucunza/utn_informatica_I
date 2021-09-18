#include <stdio.h>

#define TAM 20

int main (int argv, char* argc[])
{
  FILE* fd;
  char a;
  char buff[TAM];
  
  if (argv != 2)				//Me pasaron un argumento?
  {
    fprintf (stdout, "No hay nombre\n");		// stdout escribir en pantalla
    return (-1);
  }
  
  fd = fopen (argc[1], "r");
  
  if (fd == NULL)				//Se pudo abrir el archivo?Falta de permisoso/No existe
  {
    fprintf (stdout, "Error al abrir el archivo\n");
    return (-1);    
  }
  
  while (! feof(fd))			//Devuelve un 1 cuando termian sino un 0
  {
    
    a = fgetc (fd);			//Por caracteres
    if ( a == EOF )			//Si es EndOfFile imprime un enter y termina el programa
    {
      printf ("\n");
      fclose (fd);
      return 0;
    }
    fprintf (stdout, "%c",a);
/*
    fscanf (fd, "%s", buff);		//Por cadenas
    fprintf (stdout, "%s\n", buff);
  
*/  
  }
  
  fclose (fd);
  return 0;
}