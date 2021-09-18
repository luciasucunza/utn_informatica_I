
int main (void)
{
  void* handle;
  vpod (*hello) (void);// TENGO QUE CONOCER EL PROTOTIPO DE LA FUNCION QE ESTA EN LIBRERIA
  char *error;
// Abrimos la liibreria y obtenemos un puntero a la instancia de la misma

  handle = dlopen("libhola.so.1", RTLD_LAZY);
  
  if(handle == NULL)
  {
      error = dlerror();
      frpintf(stderr, "%s\n", error);
      exit(EXIT_FAILURE);
  }
 
 hello = dlsym(handle, "hola");
  
  if((error dlerror()) != NULL)
  {
      frpintf(stderr, "%s\n", error);
      exit(EXIT_FAILURE);
  }
  
  (*hello)();
  close(handle);
  return 0;
}
  