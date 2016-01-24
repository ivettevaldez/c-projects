/**
 *	Creado por Silvia Valdez. 
 *	Archivos.
 */
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *entrada;

	int b;
	char a[4];

	entrada = fopen(argv[1], "r");
	
	fread(&b, sizeof(int), 1, entrada);

	fprintf(stdout, "El valor leido es: %d\n", b);

	fclose(entrada);
	
	return 0;
}

