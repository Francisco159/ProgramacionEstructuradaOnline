#include <stdio.h>

struct Medidas{
  int largo;
  int ancho;
};

void esquinas(int x, int y, int largo, int ancho){
  if((x == 1 && y == 1) || (x == 1 && y == ancho)
     || (x == largo && y == 1) || (x == largo && y == ancho)){
   printf("+") ;
  }
}

void laterales(int i, int j, int largo, int ancho2){
  if((j == 1 && i > 1 && i < largo) || (j == ancho2 && i > 1 && i < largo)){
    printf("|");
  }
}

void espacios_en_blanco(int a,int b,int largo,int ancho){
  if((b > 1 && b < ancho && a < largo && a > 1)){
    printf(" ");
  }
}

void barras_superior_e_inferior(int z, int k, int largo, int ancho){
  if((z == 1 && k >= 2 && k < ancho) || (z == largo && k >= 2 && k < ancho)){
    printf("-");
  }
}

void inspeccionar(int largo, int ancho){
  for(int indice_x = 1; indice_x <= largo; indice_x++){
    for(int indice_y = 1; indice_y <= ancho; indice_y++){
      esquinas(indice_x, indice_y, largo, ancho);
      laterales(indice_x, indice_y, largo, ancho);
      barras_superior_e_inferior(indice_x, indice_y, largo, ancho);
      espacios_en_blanco(indice_x, indice_y, largo, ancho);
    }
    printf("\n");
  }
}

int main() {
  struct Medidas cuadrado;
  cuadrado.largo = 7;
  cuadrado.ancho = 16;
  inspeccionar(cuadrado.largo, cuadrado.ancho);
  return 0;
}
