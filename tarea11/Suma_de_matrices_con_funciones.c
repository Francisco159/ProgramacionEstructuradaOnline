#include<stdio.h>

void Generar_matriz_1_y_2(int (*arreglo1)[4], int (*arreglo2)[4],
                          int (*arreglo_resultante)[4], int tamanio){
  for(int indice_x = 0; indice_x < tamanio; indice_x++){
    for(int indice_y = 0; indice_y < tamanio; indice_y++){
      arreglo1[indice_x][indice_y] = indice_x;
      arreglo2[indice_x][indice_y] = indice_y;
      arreglo_resultante[indice_x][indice_y] =
        arreglo1[indice_x][indice_y] + arreglo2[indice_x][indice_y] ;
    }
  }
}

void impresion(int (*arreglo)[4], char (*Encabezado), int tamanio){
  printf("%s\n",Encabezado);
  for(int indice_x = 0; indice_x < tamanio; indice_x++){
    for(int indice_y = 0; indice_y < tamanio; indice_y++){
      printf("%d ",arreglo[indice_x][indice_y]);
    }
    printf("\n");
  }
}

int main()
{
	int elemento_maximo = 4 ;
	int matriz_1[elemento_maximo][elemento_maximo];
    int matriz_2[elemento_maximo][elemento_maximo];
	int matriz_resultante[elemento_maximo][elemento_maximo];
    char Encabezados[3][20] = {"MATRIZ 1","MATRIZ 2","MATRIZ RESULTANTE"};
    Generar_matriz_1_y_2(matriz_1, matriz_2, matriz_resultante, elemento_maximo);
    impresion(matriz_1, Encabezados[0], elemento_maximo);
    impresion(matriz_2, Encabezados[1], elemento_maximo);
    impresion(matriz_resultante, Encabezados[2], elemento_maximo);return 0;
}
