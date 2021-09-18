#include<stdio.h>
#include<string.h>
int main( void )
{
  char string[20];
  int numA, numB, numC, resu;
  FILE *f_origen;
  
  if( ( f_origen = fopen( "numeros", "r" ) ) == NULL )
    return -1;
  
  while( !feof(f_origen) )
  {
    if(  (fscanf( f_origen, "NUMERO%d-%d-%d\r\n", &numA,&numB,&numC)) == 0 )
      return -2;
    printf("%d %d  %d \n", numA, numB, numC );
  } 
}