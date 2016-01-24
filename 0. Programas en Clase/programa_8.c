/**
 *	Creado por Silvia Valdez. 
 *	Estructuras de datos y valores ASCII.
 */
#include <stdio.h>

struct mi_estructura
{
	int a;
	float b;
	char c;
	char e;
	char d;
};

int main()
{
	struct mi_estructura x;
	struct mi_estructura *y;
	char *z;

	double w[50];

	x.a = 3;
	x.b = 3.14;
	x.c = 'a';

	fprintf (stdout, "El valor de a en ASCII es %d\n", x.c);
	fprintf(stdout, "El tamaño de x es %d\n", sizeof(x));

	y = &x;

	fprintf (stdout, "El valor de a en ASCII es %d\n", y->c);
	fprintf(stdout, "El tamaño de y es %d\n", sizeof(y));

	z = (void *) y;

	z[0] = 3;
	z[1] = 0;
	z[2] = 0;
	z[3] = 0;

	fprintf (stdout, "El valor del atributo a es %d\n", x.a);

	return 0;
}
