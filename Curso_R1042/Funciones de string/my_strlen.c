/**
 *	\fn int my_strlen (const char *);
 *	\brief Calcula la longitud de una palabra introducida por teclado. (4.4)
 *	\author Pose, Fernando Ezequiel.
 *	\date 2010.06.10
 *	\param Entrada de la palabra.
 *	\return Retorna la longitud de la palabra.
 */

int my_strlen (const char *palabra){
     
     int i;
     //Si la posicion de palabra+i es distinta de 0, incremento, al salir del for terno un numero el cual coincide con la longitud de la palabra.   
     for (i=0;*(palabra+i)!=0;i++);
     return (i);
}
