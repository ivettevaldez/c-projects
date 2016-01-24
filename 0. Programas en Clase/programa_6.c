/**
 *	Creado por Silvia Valdez.
 *	Tipos de variables.
 */
#include <stdio.h>

int main()
{
	int a;
	float b;
	char c;

	c = 120;
	a = 200;
	b = 140.4;

	a = b;
	b = a;

	a = c;
	c = a;
	c = b;

	fprintf(stdout, "El contenido de a %d\n", a);
	fprintf(stdout, "El contenido de b %f\n", b);
	fprintf(stdout, "El contenido de c %d\n", c);

	return 0;
}
