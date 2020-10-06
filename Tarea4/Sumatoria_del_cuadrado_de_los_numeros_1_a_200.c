#include<stdio.h>

int main()
{
	int elementos_maximos = 200;
	int serie[elementos_maximos];
	int indice,sumatoria = 0;
	printf("Valores Sumados:\n");
	for(indice = 1; indice <= elementos_maximos; indice++)
	{
		serie[indice] = indice*indice;
	}
	for(indice = 1; indice <= elementos_maximos; indice++)
	{
			sumatoria += serie[indice];
			printf("%d,",serie[indice]);
	}
	int total_calculado = (elementos_maximos*(elementos_maximos+1)*(2*elementos_maximos + 1))/6;
	printf("\nSumatoria = %d\nTotal Calculado = %d\n\n",sumatoria,total_calculado);
	return 1;
}
