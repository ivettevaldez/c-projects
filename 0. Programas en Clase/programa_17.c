/**
 *	Creado por Silvia Valdez. 
 *	Archivos.
 */
 #include <stdio.h>

int main(int argc, char **argv)
{
	FILE *salida;
	FILE *entrada;

	FILE *bin_in;
	FILE *bin_out;

	int a;
	int b;
	float c;
	char d;

	d = 'a';
	
	salida = fopen(argv[1], "a");
	entrada = fopen(argv[2], "r");

	bin_out = fopen(argv[3], "w");
//	bin_in  = fopen(argv[4], "r");

	fprintf(salida, "Hola mundo desde un archivo!\n");
	fscanf(entrada, "%d, %d, %f\n", &a, &b, &c);

	fprintf(stdout, "Acabo de leer ==%d== ++%d++ **%f**\n", a, b, c);
	fscanf(entrada, "%d, %d, %f\n", &a, &b, &c);

	fprintf(stdout, "Acabo de leer ==%d== ++%d++ **%f**\n", a, b, c);
	fwrite(&d, sizeof(char), 1, bin_out);

	fclose(salida);
	fclose(entrada);
	
	return 0;
}
