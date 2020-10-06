#include<stdio.h>
/*caso digito*/
/*caso mayuscula*/
/*caso minuscula*/
/*caso de caracterers especiales*/
int main()
{
	/*declaracion de variables*/
	char caracter = 'Z';
	int valor_ascii = (int) caracter;
	
	if(valor_ascii >= 48 && valor_ascii <= 57)
	{
		printf("El valor de %c Es digito",caracter);
	}
	else
	{
		if(valor_ascii >= 65 && valor_ascii <= 90)
		{
			printf("El valor %c es una letra mayuscula",caracter);
		}
		else
		{
			if(valor_ascii >= 97 && valor_ascii <= 122)
			{
				printf("El valor %c es una letra minuscula",caracter);
			}
			else
			{
				printf("El valor %c es un car%ccter especial",caracter,160);
			}
		}
	}
	
	return 1;
}
