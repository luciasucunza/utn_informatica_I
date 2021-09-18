#include <stdlib.h>
#include <stdio.h>

int rgbGris (char *origen, char *destino)
{
    FILE *f_origen, *f_destino;
    char *byte, *dest;
    int i,a,b;
    i=0;
    
    if( (f_origen = fopen(origen, "r+")) == NULL )
        return -1;
    
    if( (f_destino = fopen(destino, "w+")) == NULL )
        return -2;
    
    for( i = 0 ; !feof(f_origen); i++)
        fread( &a , 1 , 1 , f_origen );
    
    rewind(f_origen);
    
    if( (byte = (char*) malloc ( i )) == NULL )
        return -5;
        
    if( (i = fread(byte,1,i, f_origen) ) == 0)
        return -3;
    
    if ( (dest = (char*) malloc (i/3) ) == NULL)
            return -5;
            
    for( a=0,b=0; a<=i; a=a+3,b++)
        dest[b] = (0.2126 * (byte[a])) + (0.7152 * (byte[a+1])) + (0.0722 * (byte[a+2]));
    
    if( (fwrite(dest,1,b,f_destino)) == 0)
        return -4;
    fclose(f_origen);
    fclose(f_destino);
    free(byte);
    free(dest);
    
    return b;
}

int main (int argv, char*argc[])
{
    int a;
    if(argv <3)
    {
        printf("Faltan los names\n");
        return -1;
    }
    if( (a=rgbGris(argc[1], argc[2])) <= 0 )
    {
        printf("Opa quise mamaaa %d\n", a);
        return -1;
    }
    
    return 0;
}

int rotar90 (char* origen, int pixelX, int pixelY, char *destino)
{
    char **original, **modificado;
    int fila, columna = 0;
    FILE* fp;
    
   original = (char ** ) malloc( pixelY );
   for( i = 0 ; i < pixelY ; i++ )
   {
     original[i] = (char * ) malloc( pixelX );
   }
     
   modificado = (char ** ) malloc( pixelX );
   for( i = 0 ; i < pixelX ; i++ )
   {
     modificado[i] = (char * ) malloc( pixelY );
   }
   
   if( ( fp = fopen(origen,"r+") ) == NULL)
        return -1;
    
   if( ( fread( original,1,(pixelY*pixelX),fp ) ) <= 0)
        return -3;
    
   fclose(fp);
    
   
   for( fila = 0 ; fila <= pixelY ; fila++)
   {
        for( columna = 0 ; columna <= pixelX ; columna++)
            modificado[columna][fila] = original[fila][columna];
   }
    
   if( (fp = fopen(destino, "w+") ) == NULL)
        return -2;
    
   if( ( fwrite(modificado,1,(pixelY*pixelX),fp) ) <= 0)
        return -4;
    
    
    
    for( i = 0 ; i < pixelY ; i++ )
      free( origen[i] );
   
    free( origen );
     
    for( i = 0 ; i < pixelX ; i++ )
      free( modificado[i] );

    free( modificado );
    
  
    fclose(fp);
    return (pixelY*pixelX);
}

int histograma (char *origen, int pixelX, int pixelY, int *destino)
{
    int cantidad,i;
    char *original;
    FILE *fp;
    
    cantidad = pixelY * pixelX;
    
    if( ( original = (char*) malloc (cantidad) ) == NULL)
        return -5;
    
    if( ( fp = fopen(origen) ) == NULL)
        return -1;
        
    if( ( fread(original,cantidad,1,fp) ) <= 0)
        return 3;
    
    for( i = 0 ; i <= cantidad ; i++ )
        destino[i] = 0;
    
    for( i = 0 ; i <= cantidad ; i++ )
        destino[ (original[i]) ]++;
    
    return cantidad;
}