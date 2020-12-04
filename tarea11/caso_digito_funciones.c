#include <stdio.h>

/*caso digito co funciones*/

int valor_ascii(char caracter){
  return ((int) caracter);
}

void verificar(char caracter){
  int valor = valor_ascii(caracter);

  if(valor >= 48 && valor <= 57){
    printf("El valor de %c Es digito\n",caracter);
  }else{
    if(valor >= 65 && valor <= 90){
      printf("El valor %c es una letra mayuscula\n",caracter);
    }else{
      if(valor >= 97 && valor <= 122){
        printf("El valor %c es una letra minuscula\n",caracter);
      }else{
        printf("El valor %c es un caracter especial\n",caracter);
      }
    }
  }
}

int main() {
  char caracter = '#';

  verificar(caracter);

  return 0;
}
