/** 
 *	Creado por Silvia Valdez.
 *
 *	------- PROGRAMA 1 -------
 *	Lee un archivo formato ASCII con numeros enteros y cuenta el numero
 *	de elementos e imprime el contenido; obtiene el numero minimo, maximo
 *	y promedio resultante.
 *
 *	Recibe como parametro: archivoEntradaInt.txt 
 */
#include <stdio.h>
#include <stdlib.h>

// Funcion que imprime los numeros leidos.
void fImprimir(int TotalDigitos, int* Vector)
{
	int i;
	for(i = 0; i < TotalDigitos; i++)
	{
		fprintf(stdout, "%d\n", Vector[i]);  
	}
}

// El numero minimo.
int fMin(int TotalDigitos, int* Vector)
{
    int temp = Vector[0];
    for(int i = 1; i < TotalDigitos; i++)
    {        
        if(temp > Vector[i])
        {
            temp = Vector[i];
        }
    }
    return temp;
}

// Obtiene el numero maximo.
int fMax(int TotalDigitos, int* Vector)
{
    int temp = Vector[0];
    for(int i = 1; i < TotalDigitos; i++)
    {        
        if(temp < Vector[i])
        {
            temp = Vector[i];
        }
    }
    return temp;
}

// Calcula el promedio.
float fPromedio(int TotalDigitos, int* Vector)
{
    int suma = Vector[0];
    for(int i = 1; i < TotalDigitos; i++)
    {
        suma = suma + Vector[i];
    }
    float promedio = (float) suma / TotalDigitos;
    return promedio;
}

// Main.
int main(int argc, char *argv[])
{
	// Crear referencia al archivo (stream).
	FILE *archivo;

	// Variables.
	int valor, contador;
	int *ptrVector;

	contador = 0;

	// Leer el archivo de texto.
	archivo = fopen(argv[1],"r");

	// Ciclo para leer el archivo.
	while(fscanf(archivo,"%d", &valor) == 1) //si pudo leer
	{
		contador++;
	}

	// Imprimir # de elementos en el archivo.
	printf("Son %d numeros \n", contador); 
	// Crear el vector del tamaño del # de archivos.
	ptrVector = (int *) malloc(contador * sizeof(int));

	// Comenzar desde la posicion 0 el archivo.
	fseek(archivo, 0, SEEK_SET);
	contador = 0;

	// Re escanear y asignarle los valores al vector.
	while(1 == fscanf(archivo, "%d", &ptrVector[contador]))
	{
		contador++;
	}
	printf("\nLos numeros leidos son:\n");

  	fImprimir(contador, ptrVector);

	int min = fMin(contador, ptrVector);
	int max = fMax(contador, ptrVector);
	float promedio = fPromedio(contador, ptrVector);

	fprintf(stdout, "\nEl numero menor es: %d \n", min);
	fprintf(stdout, "El numero mayor es: %d \n", max);
	fprintf(stdout, "El promedio es: %f \n", promedio);

	return 0;
}
