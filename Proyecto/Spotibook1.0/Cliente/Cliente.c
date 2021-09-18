/**
 * @file Cliente.c
 * @author Fiorentino Federico Sucunza Lucia
 * @date 19-12-16
 * @brief Main del cliente
*/

#include "Cliente.h"

int main (int argc, char* argv[])
{
  int opcion, sockfd;
  char user[TAM_DATOS];
  char pass[TAM_DATOS];
  void (*funcionmain[2])(int) = { FuncionAdmin, FuncionUser };
  
  if(argc != 2)
  {
    printf("Ingrese la IP a quien conectarse\n");
    exit(EXIT_FAILURE);
  }

  sockfd = ConectarAServidor( argv[1] );
  
  printf( "Ingrese el nombre de usuario y la contraseña\n" );
  fgets( user, TAM_DATOS, stdin);
  fgets( pass, TAM_DATOS, stdin);
  
  if( send(sockfd, user, sizeof(user),0) == -1)
  {
    perror("Send");
    exit(EXIT_FAILURE);
  }
  if( send(sockfd, pass, sizeof(pass),0) == -1)
  {
    perror("Send");
    exit(EXIT_FAILURE);
  }
  
  if( recv(sockfd, &opcion, sizeof(opcion),0) == -1)
  {
    perror("recv");
    exit(EXIT_FAILURE);
  }
	  
  if( opcion != 2 )
	  funcionmain[opcion](sockfd);
  else
    printf( "Usuario o Contraseña erroneo\n" );
  
  printf( "Fin de la comunicacion\n" );
  close(sockfd);
  return 0;
}
