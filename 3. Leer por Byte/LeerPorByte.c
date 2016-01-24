/** 
 *	Creado por Silvia Valdez.
 *
 *	------- PROGRAMA 3 -------
 *	Lee un archivo formato ASCII o Binario y lee su contenido byte por byte,
 *	mostrandolo en bloques de 4 bytes en formato decimal, octal o hexadecimal,
 *	dependiendo del formato de salida indicado por el usuario.
 *	
 *	Recibe como parametros: archivoEntrada.txt -d 
 *							archivoEntrada.bin -o -x
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SALIDA EN FORMATO DECIMAL.
int Decimal(FILE *archivo)
{	
	// Variables.
	unsigned int valor;
	int contador;

	contador = 0;

	fprintf(stdout, "El contenido byte por byte es:\n");

	// Leer el contenido del archivo, por byte.
	while(fread(&valor, sizeof(char), 1, archivo))
	{
		fprintf(stdout, "%4d ", valor);
		contador++;

		if(contador == 4)
		{
			fprintf(stdout, "\n");
			contador = 0;
		}
	}
	fprintf(stdout, "\n");
}

// SALIDA EN FORMATO OCTAL.
int Octal(FILE *archivo)
{
	// Variables.
	unsigned int valor;
	int contador;

	contador = 0;

	fprintf(stdout, "El contenido byte por byte es: \n");

	// Leer el contenido del archivo, por byte.
	while(fread(&valor, sizeof(char), 1, archivo))
	{
		fprintf(stdout, "%4o ", valor);
		contador++;

		if(contador == 4)
		{
			fprintf(stdout, "\n");
			contador = 0;
		}
	}
	fprintf(stdout, "\n");
}

// SALIDA EN FORMATO HEXADECIMAL.
int Hexadecimal(FILE *archivo)
{
	//Variables.
	unsigned int valor;
	int contador;

	contador = 0;

	fprintf(stdout, "El contenido byte por byte es:\n");

	// Leer el contenido del archivo, por byte.
	while(fread(&valor, sizeof(char), 1, archivo))
	{
		fprintf(stdout, "%4X ", valor);
		contador++;

		if(contador == 4)
		{
			fprintf(stdout, "\n");
			contador = 0;
		}
	}
	fprintf(stdout, "\n");
}

// MAIN.
int main(int argc, char **argv)
{
	// Referencia al archivo que se leerá.
	FILE *entrada;

	// Abrir el archivo de entrada.
	entrada = fopen(argv[1], "r");

	if(entrada == NULL)
	{
		fprintf(stdout, "Error al leer archivo de entrada.\n");
		return 1;
	}
	else if(argv[2] == NULL)
	{
		fprintf(stdout, "Ingrese parámetro de salida.\n");
	}
	else
	{
		if(strcmp(argv[2], "-d") == 0)
		{
			Decimal(entrada);		// Imprimir en formato decimal.
		}
		else if(strcmp(argv[2], "-o") == 0)
		{
			Octal(entrada);			// Imprimir en formato octal.
		}
		else if(strcmp(argv[2], "-x") == 0)
		{
			Hexadecimal(entrada);	// Imprimir en formato hexadecimal.
		}
	}

	return 0;
}
