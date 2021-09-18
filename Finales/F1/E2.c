typedef struct xyz 
{
  ST_DAT *st
  struct xyz *sig, *ant;
}SY_XYZ

typedef struct st_dat
{
 char *sx;
 int val, code, qtty;
 char abc[20]; 
}ST_DAT

int pfun1 ( ST_DAT *busqueda, void *key)
{
  if( my_strcmp( busqueda->st->sx, key) ) 
    return 0;
  return 1;  
}


int my_strcmp( char *str1, char *str2)
{
  int i;
      
  for( i = 0 ; str1 != '\0' && str2 != '\0' ; i++)
  {	
    if( (str1+i) != (str2+i) )
      return -1;
  }
  if( (str1+i) != (str2+i) )
    return -1;   
  return 0;  
}
