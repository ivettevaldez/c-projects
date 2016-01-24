/**
 *	Creado por Silvia Valdez. 
 *	Asignacion de memoria.
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int *a;
	int contador;

	contador = atoi(argv[1]);
	
//	a = (int *) malloc(contador*sizeof(int));
	a = (int *) calloc(contador, sizeof(int));

	if (a != NULL)
	{
		fprintf(stdout, "Se asignaron %d elementos al array a\n", contador);
	}
	else
	{
		fprintf(stderr, "Error, no hay memoria suficiente para %d elementos\n", contador);
		return 1;
	}	

	free(a);

	return 0;
}
