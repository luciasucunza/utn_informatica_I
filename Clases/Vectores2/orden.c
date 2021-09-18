#define NUMEROS_LENGTH	5


int main (void)
{
    int numeros[] = {1, 8, 5, 2, 3};
    int i, j, aux;

    for (i = 0 ; i < NUMEROS_LENGTH ; i++ )
    {
	for( j = i+1 ; j < NUMEROS_LENGTH ) 
	    {
		if( numeros[i] > numeros[j] )
		    swap( &numeros[i], &numeros[j] );
	    }
    }
}

void swap (int* a, int* b)
{
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;
}
  
/*
for (i = 0 ; i < NUMEROS_LENGTH ; i++ )
{
    aux = numeros[i];
    
    for (j = i ; j >= 1 && aux < numeros[j-1] ; j--)
    {
	numeros[j] = numeros [j-1]
    }
    
    numeros[j] = aux
}
*/
