/**
 * \fn void strlwr(char *cadena)
 * \brief Reemplaza los caracteres mayusculas por minusculas.
 * \author Pose, Fernando Ezequiel.
 * \date 2010.06.11
 * \param Entrada de la palabra.
 * \return No retorna.
 */

void strlwr(char *cadena){
     int i, len;
     len = my_strlen(cadena);
     for(i=0; i< len; i++){
	    if( *(cadena + i)>='A' && *(cadena + i) <= 'Z') *(cadena + i ) +=  'a' -'A';
     }
}
