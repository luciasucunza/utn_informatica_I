/**
 * \fn void strupr(char *cadena)
 * \brief Reemplaza los caracteres minuscula por mayusculas.
 * \author Pose, Fernando Ezequiel.
 * \date 2010.06.11
 * \param Entrada de la palabra.
 * \return No retorna.
 */

void strupr(char *cadena){
     int i, len;
     len = my_strlen(cadena);
     for(i=0; i< len; i++){
	    if( *(cadena + i)>= 'a' && *(cadena + i) <= 'z') *(cadena + i ) -= 'a' - 'A';
     }
}

