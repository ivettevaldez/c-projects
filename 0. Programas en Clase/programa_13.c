/**
 *	Creado por Silvia Valdez. 
 *	Lectura de archivos.
 */
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *mi_archivo;
	FILE *otro_archivo;

	int a = 1223;
	int b;
	float c;

	mi_archivo = fopen(argv[1], "a");
	otro_archivo = fopen(argv[2], "r");

	fprintf(mi_archivo, "Hola mundo, el valor de a es %d!\n", a);

	fscanf(otro_archivo, "%d, %d, %f\n", &a, &b, &c);

	fprintf(stdout, "Lo que acabamos de leer es: %d %d %f\n", a, b, c);

	fscanf(otro_archivo, "%d, %d, %f\n", &a, &b, &c);

	fprintf(stdout, "Lo que acabamos de leer es: %d %d %f\n", a, b, c);

	fclose(mi_archivo);
	fclose(otro_archivo);

	return 0;
}
