#include<stdio.h>

int main()
{
	int elemento_maximo = 4 ;
	int matriz_1[elemento_maximo][elemento_maximo], matriz_2[elemento_maximo][elemento_maximo];
	int matriz_resultante[elemento_maximo][elemento_maximo];
	int indice_x, indice_y;
	for(indice_x = 0; indice_x < elemento_maximo; indice_x++)
	{
		for(indice_y = 0; indice_y < elemento_maximo; indice_y++)
		{
			matriz_1[indice_x][indice_y] = indice_x + 0 ;
			matriz_2[indice_x][indice_y] = indice_y + 0 ;
		}
	}
	for(indice_x = 0; indice_x < elemento_maximo; indice_x++)
	{
		for(indice_y = 0; indice_y < elemento_maximo; indice_y++)
		{
			matriz_resultante[indice_x][indice_y] = matriz_1[indice_x][indice_y] 
			+ matriz_2[indice_x][indice_y] ;
		}
	}
	printf("MATRIZ 1:\n");
	for(indice_x = 0; indice_x < elemento_maximo; indice_x++)
	{
		for(indice_y = 0; indice_y < elemento_maximo; indice_y++)
		{
			printf("%d ",matriz_1[indice_x][indice_y]);
		}
		printf("\n");
	}
	printf("MATRIZ 2:\n");
	for(indice_x = 0; indice_x < elemento_maximo; indice_x++)
	{
		for(indice_y = 0; indice_y < elemento_maximo; indice_y++)
		{
			printf("%d ",matriz_2[indice_x][indice_y]);
		}
		printf("\n");
	}
	printf("MATRIZ RESULTANTE:\n");
	for(indice_x = 0; indice_x < elemento_maximo; indice_x++)
	{
		for(indice_y = 0; indice_y < elemento_maximo; indice_y++)
		{
			printf("%d ",matriz_resultante[indice_x][indice_y]);
		}
		printf("\n");
	}
	printf("\n");
	return 1;
}
