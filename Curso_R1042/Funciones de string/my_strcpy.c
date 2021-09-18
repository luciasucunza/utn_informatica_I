
/**
 * \fn void my_strcpy (char *t, const char *s);
 * \brief Copia una palabra en otra dirección de memoria.
 * \author Pose, Fernando Ezequiel.
 * \date 2010.06.10
 * \param Entrada de la palabra.
 * \return No retorna resultados.
 */

void my_strcpy (char *t, const char *s){
     
     int i;
     for (i=0;*(s+i)!=0;i++){
	    //Guarda el contenido de una posicion del vector en otro vector.
	    *(t+i) = *(s+i);
     }
     *(t+i) = 0;
}
