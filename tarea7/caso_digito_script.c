#include<stdio.h>
/*caso digito*/
/*caso mayuscula*/
/*caso minuscula*/
/*caso de caracterers especiales*/
int main(int argc, char **argv)
{
	/*declaracion de variables*/
	char caracter = argv[1][0];
	int valor_ascii = (int) caracter;
	
	if(valor_ascii >= 48 && valor_ascii <= 57)
	{
		printf("El valor de %c Es digito\n",caracter);
	}
	else
	{
		if(valor_ascii >= 65 && valor_ascii <= 90)
		{
			printf("El valor %c es una letra mayuscula\n",caracter);
		}
		else
		{
			if(valor_ascii >= 97 && valor_ascii <= 122)
			{
				printf("El valor %c es una letra minuscula\n",caracter);
			}
			else
			{
				printf("El valor %c es un car%ccter especial\n",caracter,160);
			}
		}
	}
	
	return 1;
}
