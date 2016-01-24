/** 
 *	Creado por Silvia Valdez.
 *
 *	------- PROGRAMA 7 -------
 */
#include <stdio.h>
#include <stdlib.h>

//CÁLCULO DE LAS CELDAS ASIGNADAS A CADA WORKER. ---ENTEROS---
void ObtenerCeldasINT(int inicial, int final, int **matriz1, int **matriz2, int **matrizResultante, int m, int p, int n)
{
	fprintf(stdout, "Tarea realizada.\n");

	//Variables.
	int i, j, k, celda;

	i = 0;
	j = 0;
	k = 0;
	celda = 0;

	//Calcular valores de matriz resultante.
	for(i = 0; i < m; i++) //Ciclo que controla los renglones.
	{
		for(j = 0; j < n; j++) //Ciclo que controla las columnas.
		{
			if(celda >= inicial && celda < final)
			{
				for(k = 0; k < p; k++) //Sumatoria de la multiplicacion de valores.
				{
					matrizResultante[i][j] += matriz1[i][k] * matriz2[k][j];
				}
				//Se imprime el valor de la posicion (renglon, columna).
				fprintf(stdout, "%d\t", matrizResultante[i][j]); 
			}
			else
			{
			}
			fprintf(stdout, "celda: %d\n", celda);
			celda = celda + 1;
		}
		fprintf(stdout, "\n");
	}	
	fprintf(stdout, "\n");
}

//CÁLCULO DE LAS CELDAS ASIGNADAS A CADA WORKER. ---FLOTANTES---
void ObtenerCeldasFLOAT(int inicial, int final, float **matriz1, float **matriz2, float **matrizResultante, int m, int p, int n)
{
	fprintf(stdout, "Tarea realizada.\n");

	//Variables.
	int i, j, k, celda;

	i = 0;
	j = 0;
	k = 0;
	celda = 0;

	//Calcular valores de matriz resultante.
	for(i = 0; i < m; i++) //Ciclo que controla los renglones.
	{
		for(j = 0; j < n; j++) //Ciclo que controla las columnas.
		{
			if(celda >= inicial && celda < final)
			{
				for(k = 0; k < p; k++) //Sumatoria de la multiplicacion de valores.
				{
					matrizResultante[i][j] += matriz1[i][k] * matriz2[k][j];
				}
				//Se imprime el valor de la posicion (renglon, columna).
				fprintf(stdout, "%f\t", matrizResultante[i][j]); 
			}
			else
			{
			}
			fprintf(stdout, "celda: %d\n", celda);
			celda = celda + 1;
		}
		fprintf(stdout, "\n");
	}	
	fprintf(stdout, "\n");
}


//MULTIPLICACIÓN DE MATRICES PARA ENTEROS.
void MultiplicarMatricesPorTareasINT(int **matriz1, int **matriz2, int m, int p, int n, int tareas)
{	
	//Variables.
	int i, j, k, t, numeroTotalCeldas, celdasPorTarea, residuo, inicial, final, celdasPendientes;

	i = 0;
	t = 0;
	numeroTotalCeldas = 0;
	celdasPorTarea = 0;
	residuo = 0;
	inicial = 0;
	final = 0;
	celdasPendientes = 0;

	//Declarar e inicializar la matriz resultante de la multiplicacion.
	int **matrizResultante;
	matrizResultante = (int **) malloc(m * sizeof(int));

	while(i < m)
	{
		matrizResultante[i] = (int *) malloc(n * sizeof(int)); //Se inicializa cada renglon de la matriz.
		i++;
	}

	//Calculo de las celdas que se obtendran por tarea.
	numeroTotalCeldas = m*n;
	celdasPorTarea = numeroTotalCeldas / tareas;	
	residuo = numeroTotalCeldas % tareas;

	fprintf(stdout, "\n--- DATOS DE LA MATRIZ RESULTANTE ---\n");
	fprintf(stdout, "Renglones: %d\tColumnas: %d\n\n", m, n);

	celdasPendientes = numeroTotalCeldas;

	while(t < tareas) //Mientras el "trabajador" sea menor al numero de tareas.
	{
		if(tareas < numeroTotalCeldas) //Menos tareas que celdas que calcular.
		{
			//Si la division de tareas fue exacta:
			if(residuo == 0)
			{
				final = inicial + celdasPorTarea;

				//Funcion que calcula las celdas asignadas al trabajador.
				ObtenerCeldasINT(inicial, final, matriz1, matriz2, matrizResultante, m, p, n);
				inicial = final;
			}
			else //Si existe residuo:
			{
				final = inicial + celdasPorTarea + 1;
				residuo = residuo - 1;

				//Funcion que calcula las celdas asignadas al trabajador.
				ObtenerCeldasINT(inicial, final, matriz1, matriz2, matrizResultante, m, p, n);
				inicial = final;
			}
		}
		else //Mayor numero de tareas que de celdas.
		{			
			if(celdasPendientes != 0)
			{
				final = inicial + 1;

				//Funcion que calcula las celdas asignadas al trabajador.
				ObtenerCeldasINT(inicial, final, matriz1, matriz2, matrizResultante, m, p, n);
				inicial = final;

				celdasPendientes = celdasPendientes - 1;
			}
			else
			{
				fprintf(stdout, "Tarea vacia.\n");
			}
		}
		t++; //Aumenta el "trabajador".
	}

	i = 0;
	j = 0;
	k = 0;

	//IMPRIMIR MATRIZ RESULTANTE.
	fprintf(stdout, "\n--- MATRIZ RESULTANTE ---\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			//Se imprime el valor de la posicion (renglon, columna).
			fprintf(stdout, "%d\t", matrizResultante[i][j]); 		
		}
		fprintf(stdout, "\n");
	}	
	fprintf(stdout, "\n");
}

//MULTIPLICACIÓN DE MATRICES PARA FLOTANTES.
void MultiplicarMatricesPorTareasFLOAT(float **matriz1, float **matriz2, int m, int p, int n, int tareas)
{	
	//Variables.
	int i, j, k, t, numeroTotalCeldas, celdasPorTarea, residuo, inicial, final, celdasPendientes;

	i = 0;
	t = 0;
	numeroTotalCeldas = 0;
	celdasPorTarea = 0;
	residuo = 0;
	inicial = 0;
	final = 0;
	celdasPendientes = 0;

	//Declarar e inicializar la matriz resultante de la multiplicacion.
	float **matrizResultante;
	matrizResultante = (float **) malloc(m * sizeof(float));

	while(i < m)
	{
		matrizResultante[i] = (float *) malloc(n * sizeof(float)); //Se inicializa cada renglon de la matriz.
		i++;
	}

	//Calculo de las celdas que se obtendran por tarea.
	numeroTotalCeldas = m*n;
	celdasPorTarea = numeroTotalCeldas / tareas;	
	residuo = numeroTotalCeldas % tareas;

	fprintf(stdout, "\n--- DATOS DE LA MATRIZ RESULTANTE ---\n");
	fprintf(stdout, "Renglones: %d\tColumnas: %d\n\n", m, n);

	celdasPendientes = numeroTotalCeldas;

	while(t < tareas) //Mientras el "trabajador" sea menor al numero de tareas.
	{
		if(tareas < numeroTotalCeldas) //Menos tareas que celdas que calcular.
		{
			//Si la division de tareas fue exacta:
			if(residuo == 0)
			{
				final = inicial + celdasPorTarea;

				//Funcion que calcula las celdas asignadas al trabajador.
				ObtenerCeldasFLOAT(inicial, final, matriz1, matriz2, matrizResultante, m, p, n);
				inicial = final;
			}
			else //Si existe residuo:
			{
				final = inicial + celdasPorTarea + 1;
				residuo = residuo - 1;

				//Funcion que calcula las celdas asignadas al trabajador.
				ObtenerCeldasFLOAT(inicial, final, matriz1, matriz2, matrizResultante, m, p, n);
				inicial = final;
			}
		}
		else //Mayor numero de tareas que de celdas.
		{			
			if(celdasPendientes != 0)
			{
				final = inicial + 1;

				//Funcion que calcula las celdas asignadas al trabajador.
				ObtenerCeldasFLOAT(inicial, final, matriz1, matriz2, matrizResultante, m, p, n);
				inicial = final;

				celdasPendientes = celdasPendientes - 1;
			}
			else
			{
				fprintf(stdout, "Tarea vacia.\n");
			}
		}
		t++; //Aumenta el "trabajador".
	}

	i = 0;
	j = 0;
	k = 0;

	//IMPRIMIR MATRIZ RESULTANTE.
	fprintf(stdout, "\n--- MATRIZ RESULTANTE ---\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			//Se imprime el valor de la posicion (renglon, columna).
			fprintf(stdout, "%f\t", matrizResultante[i][j]); 		
		}
		fprintf(stdout, "\n");
	}	
	fprintf(stdout, "\n");
}


//LEER ARCHIVOS ASCII y almacenar valores.
void LeerASCII(FILE *archivo1, FILE *archivo2, char formato, int tareas)
{
	//Variables.
	int i, j, contador, renglones1, columnas1, renglones2, columnas2;

	i = 0;
	j = 0;
	contador = 0; //Guardara el numero de elementos de la matriz.
	renglones1 = 0;
	columnas1 = 0;
	renglones2 = 0;
	columnas2 = 0;

	if(formato == 'd') //Leer enteros.
	{
		int valor;
		valor = 0;

		//PARA LA PRIMERA MATRIZ.
		fprintf(stdout, "--- MATRIZ 1 ---\n");

		while(fscanf(archivo1, "%d", &valor) == 1)
		{
			if(contador == 0) //Asignar el primer valor del archivo al numero de renglones.
			{
				renglones1 = valor;
				fprintf(stdout, "Renglones: %d\t", renglones1);
			}
			else if(contador == 1) //Asignar el segundo valor del archivo al numero de columnas.
			{
				columnas1 = valor;
				fprintf(stdout, "Columnas: %d\n\n", columnas1);
			}
			contador++;
		}

		//Se crea e inicializa la matriz que contendra los valores.
		int **matriz1;
		matriz1 = (int **) malloc(renglones1 * sizeof(int));

		while(i < renglones1)
		{
			matriz1[i] = (int *) malloc(columnas1 * sizeof(int)); //Se inicializa cada renglon de la matriz.
			i++;
		}

		fseek(archivo1, 3, SEEK_SET); //Comenzamos a leer despues de los indicadores de renglones y columnas.
		
		//Reescanear y almacenar valores.
		for(i = 0; i < renglones1; i++)
		{
			for(j = 0; j < columnas1; j++)
			{
				fscanf(archivo1, "%d", &valor);
				matriz1[i][j] = valor;
				fprintf(stdout, "%d\t", matriz1[i][j]);
			}
			fprintf(stdout, "\n");
		}


		//PARA LA SEGUNDA MATRIZ.
		i = 0;
		valor = 0;
		contador = 0;

		fprintf(stdout, "\n--- MATRIZ 2 ---\n");

		while(fscanf(archivo2, "%d", &valor) == 1)
		{
			if(contador == 0) //Asignar el primer valor del archivo al numero de renglones.
			{
				renglones2 = valor;
				fprintf(stdout, "Renglones: %d\t", renglones2);
			}
			else if(contador == 1) //Asignar el segundo valor del archivo al numero de columnas.
			{
				columnas2 = valor;
				fprintf(stdout, "Columnas: %d\n\n", columnas2);
			}
			contador++;
		}

		//Se crea e inicializa la matriz que contendra los valores.
		int **matriz2;
		matriz2 = (int **) malloc(renglones2 * sizeof(int));

		while(i < renglones2)
		{
			matriz2[i] = (int *) malloc(columnas2 * sizeof(int)); //Se inicializa cada renglon de la matriz.
			i++;
		}

		fseek(archivo2, 3, SEEK_SET); //Comenzamos a leer despues de los indicadores de renglones y columnas.
		
		//Reescanear y almacenar valores.
		for(i = 0; i < renglones2; i++)
		{
			for(j = 0; j < columnas2; j++)
			{
				fscanf(archivo2, "%d", &valor);
				matriz2[i][j] = valor;
				fprintf(stdout, "%d\t", matriz2[i][j]);
			}
			fprintf(stdout, "\n");
		}

		if(columnas1 != renglones2)
		{
			fprintf(stdout, "El numero de columnas de la primera matriz debe ser igual al de renglones de la segunda.\n");
		}

		//Invocar a la funcion que multiplica las matrices.
		MultiplicarMatricesPorTareasINT(matriz1, matriz2, renglones1, columnas1, columnas2, tareas);
	}
	else //Leer flotantes.
	{
		float valor;
		valor = 0;

		//PARA LA PRIMERA MATRIZ.
		fprintf(stdout, "--- MATRIZ 1 ---\n");

		while(fscanf(archivo1, "%f", &valor) == 1)
		{
			if(contador == 0) //Asignar el primer valor del archivo al numero de renglones.
			{
				renglones1 = (int) valor;
				fprintf(stdout, "Renglones: %d\t", renglones1);
			}
			else if(contador == 1) //Asignar el segundo valor del archivo al numero de columnas.
			{
				columnas1 = (int) valor;
				fprintf(stdout, "Columnas: %d\n\n", columnas1);
			}
			contador++;
		}

		//Se crea e inicializa la matriz que contendra los valores.
		float **matriz1;
		matriz1 = (float **) malloc(renglones1 * sizeof(float));

		while(i < renglones1)
		{
			matriz1[i] = (float *) malloc(columnas1 * sizeof(float)); //Se inicializa cada renglon de la matriz.
			i++;
		}

		fseek(archivo1, 3, SEEK_SET); //Comenzamos a leer despues de los indicadores de renglones y columnas.
		
		//Reescanear y almacenar valores.
		for(i = 0; i < renglones1; i++)
		{
			for(j = 0; j < columnas1; j++)
			{
				fscanf(archivo1, "%f", &valor);
				matriz1[i][j] = valor;
				fprintf(stdout, "%f\t", matriz1[i][j]);
			}
			fprintf(stdout, "\n");
		}


		//PARA LA SEGUNDA MATRIZ.
		i = 0;
		valor = 0;
		contador = 0;

		fprintf(stdout, "\n--- MATRIZ 2 ---\n");

		while(fscanf(archivo2, "%f", &valor) == 1)
		{
			if(contador == 0) //Asignar el primer valor del archivo al numero de renglones.
			{
				renglones2 = (int) valor;
				fprintf(stdout, "Renglones: %d\t", renglones2);
			}
			else if(contador == 1) //Asignar el segundo valor del archivo al numero de columnas.
			{
				columnas2 = (int) valor;
				fprintf(stdout, "Columnas: %d\n\n", columnas2);
			}
			contador++;
		}

		//Se crea e inicializa la matriz que contendra los valores.
		float **matriz2;
		matriz2 = (float **) malloc(renglones2 * sizeof(float));

		while(i < renglones2)
		{
			matriz2[i] = (float *) malloc(columnas2 * sizeof(float)); //Se inicializa cada renglon de la matriz.
			i++;
		}

		fseek(archivo2, 3, SEEK_SET); //Comenzamos a leer despues de los indicadores de renglones y columnas.
		
		//Reescanear y almacenar valores.
		for(i = 0; i < renglones2; i++)
		{
			for(j = 0; j < columnas2; j++)
			{
				fscanf(archivo2, "%f", &valor);
				matriz2[i][j] = valor;
				fprintf(stdout, "%f\t", matriz2[i][j]);
			}
			fprintf(stdout, "\n");
		}

		if(columnas1 != renglones2)
		{
			fprintf(stdout, "El numero de columnas de la primera matriz debe ser igual al de renglones de la segunda.\n");
		}

		//Invocar a la funcion que multiplica las matrices.
		MultiplicarMatricesPorTareasFLOAT(matriz1, matriz2, renglones1, columnas1, columnas2, tareas);
	}
}


//LEER ARCHIVOS BINARIOS y almacenar valores.
void LeerBinario(FILE *archivo1, FILE *archivo2, char formato, int tareas)
{
	//Variables.
	int i, j, contador, renglones1, columnas1, renglones2, columnas2;

	i = 0;
	j = 0;
	contador = 0; //Guardara el numero de elementos de la matriz.
	renglones1 = 0;
	columnas1 = 0;
	renglones2 = 0;
	columnas2 = 0;

	if(formato == 'd') //Leer enteros.
	{
		int valor;
		valor = 0;

		//PARA LA PRIMERA MATRIZ.
		fprintf(stdout, "--- MATRIZ 1 ---\n");

		while(fread(&valor, sizeof(int), 1, archivo1) == 1)
		{
			if(contador == 0) //Asignar el primer valor del archivo al numero de renglones.
			{
				renglones1 = valor;
				fprintf(stdout, "Renglones: %d\t", renglones1);
			}
			else if(contador == 1) //Asignar el segundo valor del archivo al numero de columnas.
			{
				columnas1 = valor;
				fprintf(stdout, "Columnas: %d\n\n", columnas1);
			}
			contador++;
		}

		//Se crea e inicializa la matriz que contendra los valores.
		int **matriz1;
		matriz1 = (int **) malloc(renglones1 * sizeof(int));

		while(i < renglones1)
		{
			matriz1[i] = (int *) malloc(columnas1 * sizeof(int)); //Se inicializa cada renglon de la matriz.
			i++;
		}

		fseek(archivo1, 4, SEEK_SET); //Comenzamos a leer despues de los indicadores de renglones y columnas.
		fread(&valor, sizeof(int), 1, archivo1);

		//Reescanear y almacenar valores.
		for(i = 0; i < renglones1; i++)
		{
			for(j = 0; j < columnas1; j++)
			{
				fread(&valor, sizeof(int), 1, archivo1);
				matriz1[i][j] = valor;
				fprintf(stdout, "%d\t", matriz1[i][j]);
			}
			fprintf(stdout, "\n");
		}

		//PARA LA SEGUNDA MATRIZ.
		i = 0;
		valor = 0;
		contador = 0;

		fprintf(stdout, "\n--- MATRIZ 2 ---\n");

		while(fread(&valor, sizeof(int), 1, archivo2) == 1)
		{
			if(contador == 0) //Asignar el primer valor del archivo al numero de renglones.
			{
				renglones2 = valor;
				fprintf(stdout, "Renglones: %d\t", renglones2);
			}
			else if(contador == 1) //Asignar el segundo valor del archivo al numero de columnas.
			{
				columnas2 = valor;
				fprintf(stdout, "Columnas: %d\n\n", columnas2);
			}
			contador++;
		}

		//Se crea e inicializa la matriz que contendra los valores.
		int **matriz2;
		matriz2 = (int **) malloc(renglones2 * sizeof(int));

		while(i < renglones2)
		{
			matriz2[i] = (int *) malloc(columnas2 * sizeof(int)); //Se inicializa cada renglon de la matriz.
			i++;
		}

		fseek(archivo2, 4, SEEK_SET); //Comenzamos a leer despues de los indicadores de renglones y columnas.
		fread(&valor, sizeof(int), 1, archivo2);
		
		//Reescanear y almacenar valores.
		for(i = 0; i < renglones2; i++)
		{
			for(j = 0; j < columnas2; j++)
			{
				fread(&valor, sizeof(int), 1, archivo2);
				matriz2[i][j] = valor;
				fprintf(stdout, "%d\t", matriz2[i][j]);
			}
			fprintf(stdout, "\n");
		}

		if(columnas1 != renglones2)
		{
			fprintf(stdout, "El numero de columnas de la primera matriz debe ser igual al de renglones de la segunda.\n");
		}

		//Invocar a la funcion que multiplica las matrices.
		MultiplicarMatricesPorTareasINT(matriz1, matriz2, renglones1, columnas1, columnas2, tareas);
	}
	else //Leer flotantes.
	{
		float valor;
		valor = 0;

		//PARA LA PRIMERA MATRIZ.
		fprintf(stdout, "--- MATRIZ 1 ---\n");

		while(fread(&valor, sizeof(int), 1, archivo1) == 1)
		{
			if(contador == 0) //Asignar el primer valor del archivo al numero de renglones.
			{
				renglones1 = (int) valor;
				fprintf(stdout, "Renglones: %d\t", renglones1);
			}
			else if(contador == 1) //Asignar el segundo valor del archivo al numero de columnas.
			{
				columnas1 = (int) valor;
				fprintf(stdout, "Columnas: %d\n\n", columnas1);
			}
			contador++;
		}

		//Se crea e inicializa la matriz que contendra los valores.
		float **matriz1;
		matriz1 = (float **) malloc(renglones1 * sizeof(float));

		while(i < renglones1)
		{
			matriz1[i] = (float *) malloc(columnas1 * sizeof(float)); //Se inicializa cada renglon de la matriz.
			i++;
		}

		fseek(archivo1, 4, SEEK_SET); //Comenzamos a leer despues de los indicadores de renglones y columnas.
		fread(&valor, sizeof(float), 1, archivo1);
		
		//Reescanear y almacenar valores.
		for(i = 0; i < renglones1; i++)
		{
			for(j = 0; j < columnas1; j++)
			{
				fread(&valor, sizeof(int), 1, archivo1);
				matriz1[i][j] = valor;
				fprintf(stdout, "%f\t", matriz1[i][j]);
			}
			fprintf(stdout, "\n");
		}


		//PARA LA SEGUNDA MATRIZ.
		i = 0;
		valor = 0;
		contador = 0;

		fprintf(stdout, "\n--- MATRIZ 2 ---\n");

		while(fread(&valor, sizeof(int), 1, archivo2) == 1)
		{
			if(contador == 0) //Asignar el primer valor del archivo al numero de renglones.
			{
				renglones2 = (int) valor;
				fprintf(stdout, "Renglones: %d\t", renglones2);
			}
			else if(contador == 1) //Asignar el segundo valor del archivo al numero de columnas.
			{
				columnas2 = (int) valor;
				fprintf(stdout, "Columnas: %d\n\n", columnas2);
			}
			contador++;
		}

		//Se crea e inicializa la matriz que contendra los valores.
		float **matriz2;
		matriz2 = (float **) malloc(renglones2 * sizeof(float));

		while(i < renglones2)
		{
			matriz2[i] = (float *) malloc(columnas2 * sizeof(float)); //Se inicializa cada renglon de la matriz.
			i++;
		}

		fseek(archivo2, 4, SEEK_SET); //Comenzamos a leer despues de los indicadores de renglones y columnas.
		fread(&valor, sizeof(float), 1, archivo2);
		
		//Reescanear y almacenar valores.
		for(i = 0; i < renglones2; i++)
		{
			for(j = 0; j < columnas2; j++)
			{
				fread(&valor, sizeof(int), 1, archivo2);
				matriz2[i][j] = valor;
				fprintf(stdout, "%f\t", matriz2[i][j]);
			}
			fprintf(stdout, "\n");
		}

		if(columnas1 != renglones2)
		{
			fprintf(stdout, "El numero de columnas de la primera matriz debe ser igual al de renglones de la segunda.\n");
		}

		//Invocar a la funcion que multiplica las matrices.
		MultiplicarMatricesPorTareasFLOAT(matriz1, matriz2, renglones1, columnas1, columnas2, tareas);
	}
}


//MAIN.
int main(int argc, char **argv)
{
	//Referencia a los archivos de entrada.
	FILE *matriz1;
	FILE *matriz2;
	//Variables.
	char formato;
	int tareas;

	tareas = 0;

	//Abrir archivos.
	matriz1 = fopen(argv[1], "r");
	matriz2 = fopen(argv[2], "r");

	//Validaciones.
	if(matriz1 == NULL || matriz2 == NULL)
	{
		fprintf(stdout, "Error al leer archivos de entrada.\n");
		return 1;
	}
	else if(argv[3] == NULL || argv[4] == NULL)
	{
		fprintf(stdout, "Especifique un formato de archivo.\n");
		return 1;
	}
	else if(argv[5] == NULL)
	{
		fprintf(stdout, "Especifique el numero de tareas.\n");
		return 1;
	}
	else
	{
		/*Evaluar el parametro que indica el numero de tareas
		en que se dividira el proceso.*/
		tareas = atoi(argv[5]);
		if (tareas == 0)
		{
			fprintf(stdout, "Ingrese un numero valido de tareas.\n");
			return 1;
		}

		//Evaluar el parametro que indica el contenido de las matrices (Int/Float).
		if(strcmp(argv[4], "-d") == 0)
		{
			formato = 'd';
		}
		else if(strcmp(argv[4], "-f") == 0)
		{
			formato = 'f';
		}
		else
		{
			fprintf(stdout, "Formato de archivos incorrecto (-d, -f).\n");
			return 1;
		}

		//Evaluar el parametro que indica el formato de los archivos (ASCII/Binario).
		if(strcmp(argv[3], "-a") == 0)
		{
			LeerASCII(matriz1, matriz2, formato, tareas);
		}
		else if(strcmp(argv[3], "-b") == 0)
		{
			LeerBinario(matriz1, matriz2, formato, tareas);
		}
		else
		{
			fprintf(stdout, "Formato de archivos incorrecto (-a, -b).\n");
		}
	}

	return 0;
}
