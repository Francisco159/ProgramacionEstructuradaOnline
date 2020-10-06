#include<stdio.h>
/* +--------------+
   I              I
   I              I
   I              I
   I              I
   I              I
   +--------------+
*/
/*hacer un cuadrilatero con ciclo for*/
int main()
{
	int largo = 7, ancho = 16;
	int i,j;
	
	for(i = 1; i <= largo; i++)
	{
		for(j = 1; j <= ancho; j++)
		{
			if(i == 1 && j == 1 || i == largo && j == 1 
			   || i == 1 && j == ancho || i == largo && j == ancho)
			{
				printf("+");
			}
			else
			{
				if(j == 1 || j == ancho)
				{
					printf("I");
				}
				else
				{
					if((i == 1 && j >= 2 && j < ancho) 
						|| (i == largo && j >= 2 && j < ancho))
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
