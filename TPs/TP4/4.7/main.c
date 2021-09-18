#include "main.h"

int main (void)
{
  char str[50];
  int i, c;
  int (*pFun[3]) (char *) = {validateIP, validateCorreo, validateTarjeta};
  printf("Ingrese la cadena a validar:\n");
  scanf("%s", str);
  
  printf("Ingrese el criterio de validación\n Para IP: 0\nPara Correo: 1\nPara Tarjeta: 2\n");
  scanf("%d", &c);  
  
  i = validateString (str, pFun[c]);
  
  if( i )
    printf("Cadena Validad\n");
  else
    printf("Cadena Invalida\n");
  
  return 0;
}
