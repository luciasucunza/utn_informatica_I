//Leo un archivo que le paso como argumento del main y lo muestro en pantalla

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define TAM 4096

int main (int argc, char **argv)
{
  int fd, cant;
  char *buffer;
  
  if ( argc != 2 )
  {
    printf("Error\n");			//por si no pasaron el archivo
    return 1;
  }
  
  if ( (fd = open( argv[1], O_RDONLY ) ) < 0 )
  {
    perror("Error: ");			//aca salta si no existe o no tenes los permisos
    return 1;
  }
  
  if ( ( buffer = (char *)malloc( sizeof(char) * TAM) ) == NULL )
  {
    perror("Malloc: ");
    return 1;
  }
//no es responsabilidad del read fijarse que no haya seg. fall. por eso 
//quiero leer una cantidad (TAM) de variables (char) y tengo que castear malloc poruqe devuelve un *
    
  cant = read( fd, buffer, TAM );
  // no hace falta castear el buffer a void*, no tira warning ni nada
  
  cant = write( 1, buffer, TAM );
  // 1 es el stdout, escrube en pantalla
  
  close(fd);
  free(buffer);
  
  return 0;
} 
