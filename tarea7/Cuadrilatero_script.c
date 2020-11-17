#include<stdio.h>
#include<stdlib.h>
/* +--------------+
   |              |
   |              |
   |              |
   |              |
   |              |
   +--------------+
*/
/*hacer un cuadrilatero con ciclo for, usando argumentos en el main*/
int main(int argc,char **argv)
{
  int largo;
  largo = atoi(argv[1]);
  int ancho;
  ancho = atoi(argv[2]);
  int i,j;           /*i y j son indices de los ciclos for*/
	
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
					printf("|");
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
