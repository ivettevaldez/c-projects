/**
 *	Creado por Silvia Valdez. 
 *	Apuntadores.
 */
#include <stdio.h>

int foo(int *x, float *y)
{
	*x = 10;
	*y = 11.1;

	fprintf(stdout, "El valor de x es %d y el de y es %f\n", *x, *y);

	return 0;
}

int main()
{
	int a;
	float b;

	a = 3;
	b = 3.14;

	fprintf(stdout, "El valor de a es %d y el de b es %f\n", a, b);
	foo(&a,&b);
	fprintf(stdout, "El valor de a es %d y el de b es %f\n", a, b);
	
	return 0;
}
