/** 
 *	Creado por Silvia Valdez.
 *
 *	------- PROGRAMA 2 -------
 *	Lee un archivo en formato ASCII que contiene numeros flotantes
 *	y graba el contenido en un nuevo archivo en formato Binario.
 *
 *	Recibe como parametros: ArchivoEntrada.txt NuevoArchivoSalida.bin
 */
#include <stdio.h>
#include <stdlib.h>

// Funcion para leer archivos ASCII.
int fLeerASCII(FILE *archivo)
{
	//Variables.
	int contador;
	float valor;

	contador = 0;
	valor = 0;

	// Validar el archivo de entrada.
	if(archivo == NULL)
	{
		fprintf(stdout, "Error en el archivo de entrada.\n");
		return 1;
	}
	else
	{
		// Leer archivo de entrada y obtener numero de datos.
		while(fscanf(archivo, "%f", &valor) == 1)
		{
			contador++;
		}
	}
	return contador;
}


// Funcion para grabar un archivo en formato binario.
int fEscribir(FILE *entrada, FILE *salida, float *vector)
{
	// Variables.
	int contador;
	contador = 0;

	// Validar el archivo de salida.
	if(salida == NULL)
	{
		fprintf(stdout, "Error al escribir archivo de salida.\n");
		return 1;
	}
	else
	{
		/*
		 *	Volver a leer archivo de entrada y escribir archivo de salida.
		 *	Posicionarse al principio del archivo de entrada.
		 */
		fseek(entrada, 0, SEEK_SET);

		while(fscanf(entrada, "%f", &vector[contador]) == 1)
		{
			fwrite(&vector[contador], sizeof(float), 1, salida);
			contador++;
		}

		fclose(salida);

		return contador;
	}
}


// Funcion para leer archivos binarios.
int fLeerBinario(FILE *salida, float *vector, int contador)
{
	// Validar archivo de salida.
	if(salida == NULL)
	{
		fprintf(stdout, "Error al leer el archivo de salida.\n");
		return 1;
	}
	else
	{
		while(fread(&vector[contador], sizeof(float), 1, salida) == 1)
		{
			fprintf(stdout, "%f\n", vector[contador]);
			contador++;
		}
		return contador;
	}
}


// Main.
int main(int argc, char **argv)
{
	// Referencia a los archivos de entrada y salida.
	FILE *entrada;
	FILE *salida;
	// Variables.
	int contador;
	float *vector, valor;

	contador = 0;
	valor = 0;

	// Abrir archivo de entrada.
	entrada = fopen(argv[1], "r");

	// Leer archivo e imprimir numero de datos.
	contador = fLeerASCII(entrada);
	fprintf(stdout, "Son %d datos.\n", contador);

	// Abrir archivo de salida.
	salida = fopen(argv[2], "w");	// Escribir binario.

	// Grabar los datos leídos en un archivo binario.
	vector = (float *) malloc(contador * sizeof(float));
	contador = fEscribir(entrada, salida, vector);

	// Abrir archivo de salida.
	salida = fopen(argv[2], "r");	// Leer binario.

	// Leer archivo de salida y mostrar contenido.
	fLeerBinario(salida, vector, contador);

	return 0;
}
