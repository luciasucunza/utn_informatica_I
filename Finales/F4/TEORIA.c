/*
 1)
 * sockfd = socket()// ABRO UN SOCKET TIPO Y FAMILIA ESPECIFICO, DEVULEVE EL FILE DESCRIPTOR DEL SOCKET 
 * bind() //COMO SERVIDOR ME ASEGURO UN PUERTO
 * connect()// COMO CLIENTE ME CONECTO A UN SERVIDOR TENIENDO SUS DATOS Y LE PASO LOS MIOS
 * listen(sockfd, maxespera)//ESPERO QUE LLEGUE UN CLIENTE, PASO COMO PARAMETRO LA MAXIMA CANTIDAD DE CLIENTES EN ESPERA QUE PUEDE HABER
 * Aaccept()//COMO SERVIDOR acepto la llamada del lciente, guardo su info
 * send(sockfd, buf, tam);//RETURN CANTIDAD
 * recive(sockfd, buf, tam);//RETURN CANTIDAD
 * close(sockfd)// CIERRA EL SOCKET
 * *\

 
/*
 * 2)
 * a)El problema es el vector esta declarado en la funcion y es una variable local
 * cuando salga de la funcion se va a liberar ese espacio
 * b)
*/
#include<stdio.h>
#include<string.h>
void asignarNombrePorDefecto( char *nombre );

int main(void)
{
  char nombre[20];
  
  asignarNombrePorDefecto( nombre );
  return;
}
void asignarNombrePorDefecto( char *nombre )
{
  strcpy( nombre, "Sin inicializar");
}
/*
 * 
*\