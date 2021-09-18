/**
 * @file Servidor.c
 * @author Fiorentino Federico Sucunza Lucia
 * @date 19-12-16
 * @brief Main del Servidor
*/ 
#include "Servidor.h"

int main(void)
{
  int sockfd, sockfd_new;
  socklen_t size;
  struct sockaddr_in their_addr;
  nodo *nodoprimero;
  char user[TAM_DATOS];
  char pass[TAM_DATOS];
  int opcion;
  void (*funcionmain[2])(int, struct in_addr) = { FuncionAdmin, FuncionUser };
  
  sockfd = InicializarServidor();
  
  if(signal(SIGCHLD, sigchld_handler) == SIG_ERR)
  {
    perror("Signal");
    exit(EXIT_FAILURE);
  }

  while(1)
  {
    size = sizeof(struct sockaddr_in);
    if( (sockfd_new = accept(sockfd, (struct sockaddr *)&their_addr, &size)) == -1)
    {
      perror("Accept");
      exit(EXIT_FAILURE);
    }    
    printf("Server: Se recibio una conexion de %s\n",inet_ntoa(their_addr.sin_addr)); 
    fflush(stdout);
 
    if(!fork())
    {
      close(sockfd);
      nodoprimero = (nodo *)CargarDatosLista(PATH_ESTRUCTURA_USUARIOS);
      if( recv(sockfd_new, user, sizeof(user),0) == -1)
      {
	  perror("recv");
	  exit(EXIT_FAILURE);
      }
      if( recv(sockfd_new, pass, sizeof(pass),0) == -1)
      {
	perror("recv");
	exit(EXIT_FAILURE);
      }
       
      opcion = VerificarUser (nodoprimero, user, pass);
      BorrarLista( &nodoprimero );
	  
      if( send(sockfd_new, &opcion, sizeof(opcion),0) == -1)
      {
	perror("Send");
	exit(EXIT_FAILURE);
      }
      
      if( opcion != 2 )
	funcionmain[opcion](sockfd_new, their_addr.sin_addr);
      else
	printf( "Usuario o Contraseña erroneo %s\n",inet_ntoa(their_addr.sin_addr)); 
      
      close(sockfd_new);
      printf("Fin de la comunicacion con %s\n",inet_ntoa(their_addr.sin_addr)); 
      
      exit(EXIT_SUCCESS);     
    }
    close(sockfd_new);  
  }
}
