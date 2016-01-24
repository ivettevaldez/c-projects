/**
 *	Creado por Silvia Valdez. 
 *	Constantes, matrices, apuntadores, ciclos.
 */
#include <stdio.h>
#define N 10	// Constante.

int main()
{
	int c[N];
	int a[N];
	int b[N];
	int matriz[3][3];
	int i;
	int *apuntador;

	matriz[0][0] = 0;
	matriz[0][1] = 1;
	matriz[0][2] = 2;

	matriz[1][0] = 3;
	matriz[1][1] = 4;
	matriz[1][2] = 5;

	matriz[2][0] = 6;
	matriz[2][1] = 7;
	matriz[2][2] = 8;

	for (i=0; i < N; i++)
	{
		c[i] = N+i+2;
		a[i] = i;
		b[i] = i+N;
	}

	for (i=0; i < N; i++)
		fprintf(stdout, "El valor de a[%d] es %d\n", i, a[i]);

	fprintf(stdout, "El elemento 1,1 es = %d\n", matriz[1][1]);
	fprintf(stdout, "El elemento 0,4 es = %d\n", matriz[0][4]);

	fprintf(stdout, "El valor de matriz es %u\n", **matriz);

	apuntador = (int *) matriz;
	fprintf(stdout, "Apuntador vale: %d\n", *apuntador);

	for (i = 0; i < 9; i ++)
		fprintf(stdout, "El valor de apuntador[%d] es %d\n", i, apuntador[i]);

	return 0;
}

