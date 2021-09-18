/**
 *	\file encriptar.c
 *	\fn void encriptar(char* password, int cant);
 *	\brief Encripta una passwd
 *	\author Fernando Pose (fernandoepose@gmail.com)
 *	\date 2010.11.16
 *	\param *password Contraseña a encriptar. 
 *	\param cant longitud de la contraseña a encriptar.
 */

//--------------
//-- Includes --
//--------------


void encriptar(char* password, int cant){
   
   int i;

   for(i = 0;i < cant; i++){                 //Mientras i no supere la longitud de la palabra.
      if(i%2 != 0){                          //Si la posicion de la letra es impar.
      	password[i] = password[i]-13;    //Le resto a la letra 13.
      }
      else{                                  //Si la posicion de la letra es par.
      	password[i] = password[i]+13;    //Le sumo a la letra 13.
      }
   }
}
