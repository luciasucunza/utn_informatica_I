// Ejercios 1 y 2 hechos en la carpeta "Final" con nombre de las funciones 

struct nodo
{
  int numero;
  struct nodo sig;
};


int transformar( char *archivo )
{
  int numaux, len;
  struct nodo *nodonuevo, *nodoaux, *nodoprimero;
  FILE *f_origen, *f_destino;
  char *destino;
  
  if( ( f_origen = fopen( archivo, "r") ) ==  NULL )
    return -1;
  
  nodoprimero == NULL;
  
  while( !feof(fopen) )
  {
    nodonuevo = (struct nodo *) malloc ( sizeof(struct nodo) );
    if( ( fscanf( f_origen, "NUMERO%d ", &nodonuevo->numero ) == -1 )
      return -3;
    
    nodonuevo->sig = nodoprimero;
    nodoprimero = nodonuevo;
    
    nodonuevo = (struct nodo *) malloc ( sizeof(struct nodo) );
    if( ( fscanf( f_origen, "NUMERO%d \n", &nodonuevo->numero ) ) == -3)
      return -3;
    
    nodonuevo->sig = nodoprimero;
    nodoprimero = nodonuevo;
  }
  
  fclose( f_origen );
  
  for( nodoaux = nodoprimero ; nodoaux->sig != NULL ; nodoaux = nodoaux->sig )
  {
    for( nodonuevo = nodoaux->sig ; nodonuevo == NULL ; nodonuevo = nodonuevo->sig )
    {
      if( nodonuevo->numero < nodoaux->numero )
      {
	numaux = nodoaux->numero;
	nodoaux->numero = nodonuevo->numero;
	nodonuevo->numero = numaux;
      }
    }
  }
  len = strlen( archivo ); 
  destino = ( char *) malloc ( len );
  
  strcpy( destino, archivo)
  destino[len-3] = 'b';
  destino[len-2] = 'i';
  destino[len-1] = 'n';

  if( ( f_destino = fopen( destino, "r") ) ==  NULL )
    return -2;
  free(destino);
  
  for( nodoaux = nodoprimero ; nodoaux != NULL ; nodoaux = nodoaux->sig )
  {
    if( (fprintf( f_destino, "NUMERO%d", nodoaux->sig)) == -1) ;
       return -4;
    nodoaux = nodoaux->sig;
    if( (fprintf( f_destino, " NUMERO%d \n", nodoaux->sig)) == -1);   
  }
  
  fclose(f_destino);
  while ( nodoprimero != NULL )
  {
    nodoaux = nodoprimero->sig;
    free(nodoprimero);
    nodoprimero = nodoaux;
  }
}