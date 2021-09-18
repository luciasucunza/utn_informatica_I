#include <stdio.h>
#include <stdstring.h>

int main (void)
{
  char* q[2];  
  char* r[3];
  
  char A[10];
  char B[10];
  char C[10];
  char D[10];
  
  q[0] = A;
  q[1] = B;
  r[0] = C;
  r[1] = D;
  
  strcopy (q[0], "Hola");
  strcopy (q[1], "Chau");
  strcopy (r[0], "Buen");
  strcopy (r[1], "Dia");
  
  my-main (2 ; q ; r);
}

int my-main (int n ; char **q ; char **r)
{
  int i;
  
  if ( n < 2)
    return 1;
  
  for (i = 0 ; i < n ; i++)
    printf ("%s\n", q[i]);
  
  for (i = 0 ; r[i] ; i++)
    printf ("%s\n", r[i]);
  
  return 0;
}