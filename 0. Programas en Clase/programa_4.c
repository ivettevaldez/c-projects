/**
 *	Creado por Silvia Valdez. 
 *	Funciones y variables globales.
 */
 #include <stdio.h>

int n = 20;	// Variable global.

// Funcion.
int imprime_n()
{
	n = 3;
	if (3 == n)
		fprintf(stdout, "El valor de n en imprime_n es %d\n", n);
	return n;
}

int main()
{
	int n;
	n = 50;
	fprintf(stdout, "el valor de n es %d\n", n);

	imprime_n();
	return 0;
}
