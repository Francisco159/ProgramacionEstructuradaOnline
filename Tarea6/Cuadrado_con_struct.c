#include<stdio.h>

struct cuadrilatero{
	int base;
	int altura;
};

int main()
{
	int i,j; /*indices de los  ciclos for*/
	struct cuadrilatero cuadrilatero1;
	cuadrilatero1.base=10;
	cuadrilatero1.altura = 5;
	
	for(i = 1; i <= cuadrilatero1.altura; i++)
	{
		for(j = 1; j <= cuadrilatero1.base; j++)
		{
			if(i == 1 && j == 1 || i == cuadrilatero1.altura && j == 1 
			   || i == 1 && j == cuadrilatero1.base || i == cuadrilatero1.altura && j == cuadrilatero1.base)
			{
				printf("+");
			}
			else
			{
				if(j == 1 || j == cuadrilatero1.base)
				{
					printf("|");
				}
				else
				{
					if((i == 1 && j >= 2 && j < cuadrilatero1.base) 
						|| (i == cuadrilatero1.altura && j >= 2 && j < cuadrilatero1.base))
					{
						printf("-");
					}
					else
					{
						printf(" ");
					}
				}
			}
		}
		printf("\n");
	}
	
	return 1;
}
