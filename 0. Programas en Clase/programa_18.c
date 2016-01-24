/**
 *	Creado por Silvia Valdez. 
 *	Estructuras de datos.
 */
#include <stdio.h>

struct a
{
	int x;
	float y;
};

int main()
{
	struct a b;
	int c[20];

	fprintf(stdout, "Tamaño de a %d\n", sizeof(struct a));
	fprintf(stdout, "Tamaño de c %d\n", sizeof(c));

	return 0;
}
