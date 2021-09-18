
[1]


int read_param ( char *sFile, char *sSec, char *sPar, char *sRet, int ilen )
{
  int fd_param, i, comparacion;
  char caracter;
  
  if( (fd_param = open( sFile,  O_RDONLY)) == -1 ) 
    return -1;
  

  while( read( fd_param, &caracter, 1 ) )
  {
    if( caracter == '[' )	//Empieza una Seccion
    {
      for( i = 0, comparacion = 1 ; caracter != ']' && comparacion == 1 ; i++) //Termina o no coinci
      {
	read( fd_param, &caracter, 1 );
	if( caracter != *(sSec + i) ) 
	  comparacion = 0;
      }
      
      if( comparacion )			//Hubo conicidencia en la seccion
      {
	
	for( i = 0, comparacion = 1 ; caracter != '=' && comparacion == 1 ; i++)// Busco 
	{
	  read( fd_param, &caracter, 1 );
	  if( i = 0 && caracter = '\n')
	    i--;
	  if( caracter != *(sPar + i) )
	    comparacion = 0;
	}
	if( comparacion ) //coincidio el parametro? Enviar el sRet yel ilen
	{
	  read( fd_param, &caracter, 1 ); 
	  for( ilen = 0 ; caracter != '\n' ; ilen++ )
	  {
	    (sRet + ilen) = (char *)malloc( sizeof(caracter) )
	    read( fd_param, &caracter, 1 );	
	  }
	}
	else  //NO CONICIDIO EL PARAMETRO, VOY HASTA EL ENTER
	{
	  for( i = 0, comparacion = 1 ; caracter != '=' && comparacion == 1 ; i++)// Busco 
	
	  
	}
      }
    }
  }
}

      
      
     
     
     
  }
  
}
