/**
 *	Creado por Silvia Valdez. 
 *	Lectura y escritura de archivos recibidos como argumentos.
 */
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *salida;
	char a[4];

	a[0] = 48;
	a[1] = 49;
	a[2] = 50;
	a[3] = 51;

	salida = fopen(argv[1], "w");
	
	fwrite(a, sizeof(char), 4, salida);
	fclose(salida);

	return 0;
}

