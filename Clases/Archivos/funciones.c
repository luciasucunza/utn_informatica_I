void GardarLista (NODO *primero, char *archivo)
{
  FILE *fd;
  NODO *aux;
  
  if( (fd = fopen(archivo, "w")) == NULL )
    return(-1);					//ERROR, no tengo permisos
  
  for (aux = primero ; aux != NULL ; aux = aux->next )
    fwrite ( aux->dato, sizeof(DATO), 1, fd ); //aux->dato es un puntero porque dato es un puntero de la lib  
    
  fclose(fd);
}

/* 
void LevantarLista (NODO **primero, char *archivo)
{
  FILE *fd;
  NODO *aux;
  
  if( (fd = fopen(archivo, "r")) == NULL )
    return(-1);					//ERROR, no tengo permisos
  
  for (aux = primero ; aux != NULL ; aux = aux->next )
  {
    fread ( aux->dato, sizeof(DATO), 1, fd ); //aux->dato es un puntero porque dato es un puntero de la lib
  }   
    
}
*/


void GardarListaConComa (NODO *primero, char *archivo)
{
  FILE *fd;
  NODO *aux;
  
  if( (fd = fopen(archivo, "w")) == NULL )
    return(-1);					//ERROR, no tengo permisos
  
  for (aux = primero ; aux != NULL ;)
  {
    fprintf (fd, "%s, %d\n", aux->dato->nombre,aux->dato->edad );
    
    primero = aux;				//hay que liberar pero antes hay que pasar al siguiente porque
    aux = aux->next;				//no se puede pasar al sigueinte si liberas el nodo
    free(aux);
    
  }
  
  fclose(fd);
  
}
