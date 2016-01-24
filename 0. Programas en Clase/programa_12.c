/**
 *	Creado por Silvia Valdez. 
 *	Argumentos.
 */
#include <stdio.h>

int main(int argc, char **argv)
{
	int a;

	fprintf(stdout, "El numero de arguentos es %d\n", argc);	

	fprintf(stdout, "El primer argumento es %s\n", argv[0]);
	fprintf(stdout, "El segundo argumento es %s\n", argv[1]);
	fprintf(stdout, "El tercer argumento es %s\n", argv[2]);

	a = (int) argv[1][0];
	fprintf(stdout, "El valor de a es %d\n", a);

	return 0;
}
