#include<stdio.h>

int cuit_validar( char *origen, char *destino );

void main( int argc, char **argv )
{
  int len;
  char *destino;
  
  if( argc != 2 )
    return -1;
  
  len = strlen( argv[1] );
  
  destino = ( char *) malloc ( len + 4) );
  
  strcpy( destino, argv[1] );
  argv[len] = '.';  
  argv[len] = 'v';
  argv[len] = 'a';
  argv[len] = 'l';
  argv[len] = '\0';
  
  cuit_validar( argv[1], destino );
  
}

int cuit_validar( char *origen, char *destino )
{
  int numA, numB, numC, resu;
  FILE *f_origen, *f_destino;
  
  if( ( f_origen = fopen( origen, r ) ) == NULL )
    return -1;
  if( ( f_destino = fopen( destino, w ) ) == NULL )
    return -2;
  
  while( !feof(f_origen) )
  {
    if(  (fscanf( f_origen, "%d-%d-%d\r\n", &numA,&numB,&numC)) == 0 )
      return -2;
   
    resu = 	  numB%10 * 2;    
    numB = numB / 10;
    resu = resu + numB%10 * 3;    
    numB = numB / 10;
    resu = resu + numB%10 * 4;    
    numB = numB / 10;
    resu = resu + numB%10 * 5;    
    numB = numB / 10;
    resu = resu + numB%10 * 6;    
    numB = numB / 10
    resu = resu + numB%10 * 7;    
    numB = numB / 10;
    resu = resu + numB%10 * 2;    
    numB = numB / 10;
    resu = resu + numB%10 * 3;      
    
    resu = resu + numA%10 * 4;
    numA = numA / 10;    
    resu = resu + numA%10 * 5 ;    
    
    resu = resu%11;
    resu = 11 - resu;
    
    if( resu == 10 ) 
      resu = 9;
    else if resu == 11)
      resu = 0;
    
    if( resu == numC )
    {
      if(  (fprintf( f_destino, "%d-%d-%d\r\n", numA,numB,numC)) == 0 )
	return -2;
    }      
  }
  fclose( f_origen );
  fclose( f_destino );
}