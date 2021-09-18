#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int BinC2Dec ( char *bin, int *dec );
long BinDec ( char *bin );

int main (void)
{
  int a, res;
  char b[33];
  
  printf("Ingrese el numero binario:   ");
  scanf("%s",b);
  
  res = BinC2Dec( b, &a );
  if( res == 0 )
    printf("\nEn decimal es: %d\n",a);
  if (res == -1)
    printf("return -1\n");
  if (res == -2)
    printf("return -2\n");  
  
  return  0; 
}

int BinC2Dec ( char *bin, int *dec )
{
  int i, complemento2 ;
  char auxbin[33];

  for( i = 0 ; i < 32 ; i++ )
  {
    if( (*(bin+i)) == '\0' )
      return -1;
    if( (*(bin+i)) != '1' && (*(bin+i)) != '0' )
      return -2;
    (*(auxbin+i)) = (*(bin+i));
  }
  
  if( (*auxbin) == '0' )
  {
    (*dec) = (int)BinDec( auxbin );
  }
  else if( (*auxbin) == '1' )
  {  
    for( i = 31, complemento2 = 0 ; i > 0 ; i-- )
    {
      if( complemento2 )
	*(auxbin+i) = (!(*(auxbin+i)-'0'))+'0';
      if( *(auxbin+i) == '1' )
	complemento2 = 1;
    }
    
    (*dec) = - BinDec( auxbin );
    if( (*dec) == 0 )
      *dec = -2147483648;
  }
  return 0;
}

int BinDec ( char *bin )
{
  int i, retorno = 0;
  for( i = 0 ; i < 32 ; i++ )
  {
    *(bin+i) = (*(bin+i)) - '0';
    retorno = retorno + ((*(bin+i)) *( pow(2,(31-i)) ) );  
  }
  return retorno;
}

