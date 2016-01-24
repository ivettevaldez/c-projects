/**
 *	Creado por Silvia Valdez. 
 *	Asignacion de memoria.
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int *a;
	int N;

	N = atoi(argv[1]);
	a = (int *) calloc(N, sizeof(int));

	if (a)
	{
		fprintf(stdout, "se asignaron %d posiciones para el arreglo a\n", N);
	}	
	else
	{
		fprintf(stderr, "No se pudo asignar memoria al arreglo a\n");
		return 1;
	}

	free(a);
	return 0;
}
