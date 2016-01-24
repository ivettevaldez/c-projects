/** 
 *	Creado por Silvia Valdez.
 *
 *	------- PROGRAMA 5 -------
 */
#include <stdio.h>
#include <stdlib.h>

//MINIMO.
void Minimo(int tareas, int numeroDatos, int *vector)
{
	//Variables.
	int datosProcesar;
	datosProcesar = 0;

	//Se evalua si la division de el numero de datos es exacta.
	if((numeroDatos % tareas) == 0) //La division es exacta.
	{
		datosProcesar = numeroDatos / tareas;
	}
	else //La division tiene residuo.
	{
		numeroDatos -= 1; //Se resta 1 para que la division no tenga residuo.
		datosProcesar = numeroDatos / tareas;
	}
}


//MAXIMO.
void Maximo(int tareas, int numeroDatos, float *vector)
{
	
}


//PROMEDIO.
void Promedio(int tareas, int numeroDatos, float *vector)
{
	
}


//LEER ARCHIVOS ASCII y almacenarlos en un vector.
void LeerASCII(FILE *entrada, char formato, int tareas)
{
	//Variables.
	int i;
	i = 0;

	if(formato == 'd') //Leer enteros.
	{
		int valor;
		valor = 0;

		while(fscanf(entrada, "%d", &valor) == 1)
		{
			i++;
		}

		//Se crea el vector que contendra los valores.
		int *vector;
		vector = (int *) malloc(i * sizeof(int));

		fseek(entrada, 0, SEEK_SET); //Volvemos al inicio del archivo.
		i = 0;

		fprintf(stdout, "Los valores leidos son:\n");

		//Reescanear y almacenar valores.
		while(fscanf(entrada, "%d", &vector[i]) == 1)
		{
			fprintf(stdout, "%d\n", vector[i]);
			i++;
		}

		//Se invoca a las funciones que realizan los calculos.
		Minimo(tareas, i, vector);

	}
	else //Leer flotantes.
	{
		float valor;
		valor = 0;

		while(fscanf(entrada, "%f", &valor) == 1)
		{
			i++;
		}

		//Se crea el vector que contendra los valores.
		float *vector;
		vector = (float *) malloc(i * sizeof(float));

		fseek(entrada, 0, SEEK_SET); //Volvemos al inicio del archivo.
		i = 0;

		fprintf(stdout, "Los valores leidos son:\n");

		//Reescanear y almacenar valores.
		while(fscanf(entrada, "%f", &vector[i]) == 1)
		{
			fprintf(stdout, "%f\n", vector[i]);
			i++;
		}
	}
}


//LEER ARCHIVOS BINARIOS y almacenarlos en un vector.
void LeerBinario(FILE *entrada, char formato, int tareas)
{
	//Variables.
	int i;
	i = 0;

	if(formato == 'd')
	{
		int valor;
		valor = 0;

		while(fread(&valor, sizeof(int), 1, entrada) == 1)
		{
			i++;
		}

		//Se crea el vector que contendra los valores.
		int *vector;
		vector = (int *) malloc(i * sizeof(int));

		fseek(entrada, 0, SEEK_SET); //Volvemos al inicio del archivo.
		i = 0;

		fprintf(stdout, "Los valores leidos son:\n");

		//Reescanear y almacenar valores.
		while(fread(&vector[i], sizeof(int), 1, entrada) == 1)
		{
			fprintf(stdout, "%d\n", vector[i]);
			i++;
		}
	}
	else
	{
		float valor;
		valor = 0;

		while(fread(&valor, sizeof(float), 1, entrada) == 1)
		{
			i++;
		}

		//Se crea el vector que contendra los valores.
		float *vector;
		vector = (float *) malloc(i * sizeof(float));

		fseek(entrada, 0, SEEK_SET); //Volvemos al inicio del archivo.
		i = 0;

		fprintf(stdout, "Los valores leidos son:\n");

		//Reescanear y almacenar valores.
		while(fread(&vector[i], sizeof(float), 1, entrada) == 1)
		{
			fprintf(stdout, "%f\n", vector[i]);
			i++;
		}
	}
}


//MAIN.
int main(int argc, char **argv)
{
	//Archivos de entrada.
	FILE *entrada;
	//Variables.
	int tareas;
	char formato;

	tareas = 0;

	//Abrir archivo.
	entrada = fopen(argv[1], "r");

	//Validaciones.
	if(entrada == NULL)
	{
		fprintf(stdout, "Error al leer el archivo de entrada.\n");
		return 1;
	}
	else if(argv[2] == NULL || argv[3] == NULL)
	{
		fprintf(stdout, "Ingrese formato de archivo.\n");
		return 1;
	}
	else
	{
		//Se evalua y asigna el parametro que indica el numero de tareas.
		if(*argv[4] > 48 && *argv[4] < 58) //Es un digito.
		{
			tareas = *argv[4] - 48;
			fprintf(stdout, "Numero de tareas: %d\n", tareas);
		}
		else
		{
			fprintf(stdout, "Ingrese un numero valido de tareas.\n");
			return 1;
		}

		//Se evalua el parametro que indica el formato (int/float) de los datos.
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
			fprintf(stdout, "Formato de archivo incorrecto.\n");
			return 1;
		}

		//Se evalua el parametro que indica el formato (ascii/binario) del archivo.
		if(strcmp(argv[2], "-a") == 0)
		{
			LeerASCII(entrada, formato, tareas);
		}
		else if(strcmp(argv[2], "-b") == 0)
		{
			LeerBinario(entrada, formato, tareas);
		}
		else
		{
			fprintf(stdout, "Formato de archivo incorrecto.\n");
			return 1;
		}
	}

	return 0;
}
