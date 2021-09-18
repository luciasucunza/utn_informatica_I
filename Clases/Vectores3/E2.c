//ingresar por linea de comando palabras e informar cual de ellas es: a)Mayor loongitud b) Menor Longitud
#include <stdio.h>
#include <string.h>

int main (int n, char **q)
{
  int i, lenmin, lenmax ;
  
  if (n < 2)
  {
    printf ("no se ingresaron palabras");
    return 1;
  }
  
  lenmax = lenmin = 1;			// La primera es 1 porque en 0 tengo ./ejectuable
  
  for (i = 2 ; i < n ; i++)
  {    
    if (strlen ( q[i] ) > strlen ( q[lenmax] ) ) 
      lenmax = i;
        
    if (strlen ( q[i] ) < strlen ( q[lenmin] ) ) 
      lenmin = i;     
  }
  
  printf ("La palabra de mayor longitud es: %s\n",q[lenmax]);    
  printf ("La palabra de menor longitud es: %s\n",q[lenmin]);
  
  return 0;
}
