/**
 *	Creado por Silvia Valdez. 
 *	Vectores.
 */
#include <stdio.h>

int foo(int x[1], float y[1])
{
	x[0] = 10;
	y[0] = 11.1;

	fprintf(stdout, "El valor de x es %d y el de y es %f\n", x[0], y[0]);

	return 0;
}

int main()
{
	int a[1];
	float b[1];

	a[0] = 3;
	b[0] = 3.14;

	fprintf(stdout, "El valor de a es %d y el de b es %f\n", a[0], b[0]);
	foo(a,b);
	fprintf(stdout, "El valor de a es %d y el de b es %f\n", a[0], b[0]);

	return 0;
}
