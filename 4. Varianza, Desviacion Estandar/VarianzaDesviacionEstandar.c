/** 
 *	Creado por Silvia Valdez.
 *
 *	------- PROGRAMA 4 -------
 *	Lee un archivo ASCII/Binario con elementos Int/Float,
 *	guarda su contenido en un vector y calcula Promedio,
 *	Varianza y Desviacion Estandar del conjunto de elementos.
 *	
 *	Recibe como parametros las siguientes combinaciones:
 *	archivoEntradaInt.txt -a -d
 *	archivoEntradaInt.bin -b -d
 *	archivoEntradaFloat.txt -a -f
 *	archivoEntradaFloat.bin -b -f
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// CALCULAR DESVIACION ESTANDAR.
float CalcularDesviacionInt(int *vector, int contador)
{
	int i;
	float suma, promedio, varianza, desvEstandar;

	i = 0;
	suma = 0.0;
	promedio = 0;
	varianza = 0;
	desvEstandar = 0;

	// Se calcula el promedio de los elementos del vector.
	while(i < contador)
	{
		suma = suma + vector[i];
		i++;
	}

	promedio = suma / contador;
	fprintf(stdout, "\nPROMEDIO:\n%f\n", promedio);

	i = 0;

	// Se calcula la varianza.
	while(i < contador)
	{
		varianza =  varianza + pow((vector[i] - promedio), 2);
		i++;
	}

	varianza = varianza / contador;
	fprintf(stdout, "\nVARIANZA:\n%f\n", varianza);

	// Se calcula la desviacion estandar.
	desvEstandar = sqrt(varianza);
	fprintf(stdout, "\nDESVIACION ESTANDAR:\n%f\n", desvEstandar);

	return desvEstandar;
}


float CalcularDesviacionFloat(float *vector, int contador)
{
	int i;
	float suma, promedio, varianza, desvEstandar;

	i = 0;
	suma = 0.0;
	promedio = 0;
	varianza = 0;
	desvEstandar = 0;

	// Se calcula el promedio de los elementos del vector.
	while(i < contador)
	{
		suma = suma + vector[i];
		i++;
	}

	promedio = suma / contador;
	fprintf(stdout, "\nPROMEDIO:\n%f\n", promedio);

	i = 0;

	// Se calcula la varianza.
	while(i < contador)
	{
		varianza =  varianza + pow((vector[i] - promedio), 2);
		i++;
	}

	varianza = varianza / contador;
	fprintf(stdout, "\nVARIANZA:\n%f\n", varianza);

	// Se calcula la desviacion estandar.
	desvEstandar = sqrt(varianza);
	fprintf(stdout, "\nDESVIACION ESTANDAR:\n%f\n", desvEstandar);

	return desvEstandar;
}


// LEER ARCHIVOS ASCII.
void LeerASCII(FILE *entrada, char formato)
{
	// Variables.
	int i;
	i = 0;

	if(formato == 'd')	// Leer enteros.
	{
		int valor;
		valor = 0;

		while(fscanf(entrada, "%d", &valor) == 1)
		{
			i++;
		}

		// Se crea el vector que contendra los valores.
		int *vector;
		vector = (int *) malloc(i * sizeof(int));

		fseek(entrada, 0, SEEK_SET);	// Volvemos al inicio del archivo.
		i = 0;

		fprintf(stdout, "Los valores leidos son:\n");

		// Reescanear y almacenar valores.
		while(fscanf(entrada, "%d", &vector[i]) == 1)
		{
			fprintf(stdout, "%d\n", vector[i]);
			i++;
		}

		// Se invoca al procedimiento que calcula la Desviacion Estandar.
		CalcularDesviacionInt(vector, i);

	}
	else	// Leer flotantes.
	{
		float valor;
		valor = 0;

		while(fscanf(entrada, "%f", &valor) == 1)
		{
			i++;
		}

		// Se crea el vector que contendra los valores.
		float *vector;
		vector = (float *) malloc(i * sizeof(float));

		fseek(entrada, 0, SEEK_SET);	// Volvemos al inicio del archivo.
		i = 0;

		fprintf(stdout, "Los valores leidos son:\n");

		// Reescanear y almacenar valores.
		while(fscanf(entrada, "%f", &vector[i]) == 1)
		{
			fprintf(stdout, "%f\n", vector[i]);
			i++;
		}

		// Se invoca a la funcion que calcula la Desviacion Estandar.
		CalcularDesviacionFloat(vector, i);
	}

}


// LEER ARCHIVOS BINARIOS.
void LeerBinario(FILE *entrada, char formato)
{
	// Variables.
	int i;
	i = 0;

	if(formato == 'd')	// Leer enteros.
	{
		int valor;
		valor = 0;

		while(fread(&valor, sizeof(int), 1, entrada) == 1)
		{
			i++;
		}

		// Se crea el vector que contendra los valores.
		int *vector;
		vector = (int *) malloc(i * sizeof(int));

		fseek(entrada, 0, SEEK_SET);	// Volvemos al inicio del archivo.
		i = 0;

		fprintf(stdout, "Los valores leidos son:\n");

		// Reescanear y almacenar valores.
		while(fread(&vector[i], sizeof(int), 1, entrada) == 1)
		{
			fprintf(stdout, "%d\n", vector[i]);
			i++;
		}

		// Se invoca al procedimiento que calcula la Desviacion Estandar.
		CalcularDesviacionInt(vector, i);
	}
	else	// Leer flotantes.
	{
		float valor;
		valor = 0;

		while(fread(&valor, sizeof(float), 1, entrada) == 1)
		{
			i++;
		}

		// Se crea el vector que contendra los valores.
		float *vector;
		vector = (float *) malloc(i * sizeof(float));

		fseek(entrada, 0, SEEK_SET);	// Volvemos al inicio del archivo.
		i = 0;

		fprintf(stdout, "Los valores leidos son:\n");

		// Reescanear y almacenar valores.
		while(fread(&vector[i], sizeof(float), 1, entrada) == 1)
		{
			fprintf(stdout, "%f\n", vector[i]);
			i++;
		}

		// Se invoca al procedimiento que calcula la Desviacion Estandar.
		CalcularDesviacionFloat(vector, i);
	}
}


// MAIN.
int main(int argc, char **argv)
{
	// Referencia al archivo que se leera.
	FILE *archivoEntrada;
	char formato;

	// Se abre el archivo.
	archivoEntrada = fopen(argv[1], "r");

	// Validaciones.
	if(archivoEntrada == NULL)
	{
		fprintf(stdout, "Error al leer archivo de entrada.\n");
		return 1;
	}
	else if(argv[2] == NULL || argv[3] == NULL)
	{
		fprintf(stdout, "Especifique el formato del archivo de entrada.\n");
		return 1;
	}
	else
	{
		// Se evalua el tercer parametro.
		if(strcmp(argv[3], "-d") == 0)
		{
			formato = 'd';
		}
		else if(strcmp(argv[3], "-f") == 0)
		{
			formato = 'f';
		}
		else
		{
			fprintf(stdout, "Formato de archivo incorrecto.");
			return 1;
		}

		// Se evalua el segundo parametro.
		if(strcmp(argv[2], "-a") == 0)
		{
			LeerASCII(archivoEntrada, formato);
		}
		else if(strcmp(argv[2], "-b") == 0)
		{
			LeerBinario(archivoEntrada, formato);
		}
		else
		{
			fprintf(stdout, "Formato de archivo incorrecto.\n");
			return 1;
		}
	}

	return 0;
}
