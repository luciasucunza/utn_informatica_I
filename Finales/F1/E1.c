typedef struct xyz 
{
  ST_DAT *st
  struct xyz *sig, *ant;
}SY_XYZ

int extract ( SY_XYZ **P,
	      SY_XYZ **Q,
	      SY_DAT **sp,
	      void *key, 
	      int (*pfun1)( SY_DAT *, void *), 
	      void (*pfun2)( SY_DAT *) )
{
  SY_XYZ *aux, *liberar;
  
  (*sp) = NULL;
  
  for( aux = *(P) ; aux != NULL ; aux = aux->sig )
  {
    if( (*pfun1)( aux->st, key ) )
    {
      (*sp) = aux->st;
      
      if( pfun2 == NULL ) 
      {
	liberar = aux;
	if( aux->ant == NULL) // ES EL PRIMERO
	{
	  *P = aux->sig;
	  aux->sig->ant = NULL;
	  aux = aux->ant;
	  free( liberar );	  
	}
	else if( aux->sig == NULL) // ES EL ULTIMO 
	{
	  aux->ant->sig = NULL;
	  aux = aux->ant;
	  free(liberar);
	}
	else			// ES EN EL MEDIO
	{
	  aux->sig->ant = aux->ant;
	  aux->ant->sig = aux->sig;
	  aux = aux->ant;
	  free( liberar );
      }
      else
	(*pfun2)( aux );     
    }   
  }  
}