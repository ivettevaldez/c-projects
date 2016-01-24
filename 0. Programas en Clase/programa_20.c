/**
 *	Creado por Silvia Valdez. 
 *	Conversion de ASCII a entero.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int string_a_entero(char *string)
{
	int i = 0;
	int potencia = 1;
	int valor = 0;

	while(string[i] != 0)
	{
		i ++;
	}
	while(i > 0)
	{
		i--;
		valor = valor + ((string[i]-48) * potencia);
		potencia = potencia * 10;
	}

	return valor;
}

int main(int argc,char **argv)
{
	fprintf(stdout, "El valor entero del argmumento 1 es %d\n", string_a_entero(argv[1]));
	fprintf(stdout, "El valor entero del argmumento 2 es %d\n", string_a_entero(argv[2]));

	fprintf(stdout, "El producto es %d\n", string_a_entero(argv[1]) * string_a_entero(argv[2])); 
	fprintf(stdout, "El producto es %d\n", atoi(argv[1]) * atoi(argv[2])); 
	fprintf(stdout, "La raiz cuadrada del producto es %f\n", sqrt(atoi(argv[1]) * atoi(argv[2]))); 

	return 0;
}
