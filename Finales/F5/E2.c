int rot_13 (char *origen, char *destino)
{
  char caracter;
  int cant = 0;
  FILE *fd_origen, *fd_destino;
  
  if( ( fd_origen = fopen( origen, r ) ) == NULL )
    return -1;
  if( ( fd_destino = fopen( destino, w ) ) == NULL )
    return -2;
  
  while( !feof(fd_origen) )
  {
    if( !(fscanf(fd_origen, "%c", caracter)) )
      return -1;
    if( caracter >= 'A' && caracter <= 'M'  )
    {
      cant++;
      caracter = caracter + 'N';
      if( (fprintf( fd_destino,"%c", caracter )) == -1 )
	return -2;
    }
    else if( caracter >= 'N' && caracter <= 'Z'  )
    {
      cant++;
      caracter = caracter - 'N' + 'A';
      if( (fprintf( fd_destino,"%c", caracter )) == -1 )
	return -2;
    }
    else if( caracter == ' ')
    {
      if( (fprintf( fd_destino,"%c", caracter )) == -1 )
	return -2;
    }
    else
      return -3;      
  }
  fclose( fd_origen );
  fclose( fd_destino );
}