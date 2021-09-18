/**
 *	\fn void validarluhn(char *tarjetanum,cantidadDigitos)
 *	\brief Algoritmo de Luhn.
 *	\author Pose, Fernando Ezequiel (fernandoepose@gmail.com)
 *	\date 2010.07.22.
 *	\param Entrada numero de tarjeta (16 digitos).
 *	\return La funcion retorna validacion.
 */

int validarluhn(char *tarjetaNum){

     system("clear");

     int suma=0;                            //buffer que contiene la suma de digitos.
     int i;                                       //Contador del bucle for.
     int validacion;                          //Variable que contiene la validacion de tarjeta correcta o incorrecta.
     char digito;                              //variable que contiene al digito convertido a su numero el cual lo representa segun ASCII
     
	 for(i=0; i< cantidadDigitos; i++){  //El bucle convierte el numero, si es par multiplica por 1, si es impar multiplica por dos, guarda suma.
	    digito = tarjetaNum[i] - '0';         //Guardo el digito que convierto en la variable para trabajar sobre el numero.
	     if((i%2)==0) {                          //Este filtro lo uso para ver si multiplico o no por dos, segun la posicion del vector.
            digito = digito*2;                  //Si es impar multiplico al digito por dos.
            if (digito >= 10) {
                digito = digito - 10 + 1;
            }
        }
        suma += digito;  //Guardo la suma de todos los digitos.
     }
     if(suma%10==0){     //Termino el algoritmo fijandome si el modulo 10 de la suma es 0 o no, si es 0 entonces el valor es correcto, retorno 1.
	    validacion = 1;
	    puts("Valor de tarjeta correcto\r\n");
     }
     else{
	    validacion = 0;  // si es distinto de 0 entonces el valor es correcto, retorno 0.
	    puts("Valor de tarjeta incorrecto\r\n");
     }
     return(validacion);
}