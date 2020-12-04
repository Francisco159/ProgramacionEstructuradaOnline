#include <stdio.h>

int calcular_serie(int *arreglo, int cantidad_de_elementos){
  int sumatoria = 0, x = 1;
  for(int indice = 0; indice < cantidad_de_elementos; indice++){
    arreglo[indice] = x * x;
    sumatoria += arreglo[indice];
    x++;
  }
  return sumatoria;
}

void imprimir_serie(int *Arreglo, int cantidad_de_elementos, int sumatoria, int total_calculado){
  printf("Valores de la sumatoria:\n");
  for(int indice = 0; indice < cantidad_de_elementos; indice++){
    printf("%d ",Arreglo[indice]);
  }
  printf("\nSumatoria: %d\n",sumatoria);
  printf("Total calculado: %d\n",total_calculado);
}

int calcular_sumatoria_mediante_formula(int cantidad_maximos){
  return (cantidad_maximos*(cantidad_maximos + 1)*(2*cantidad_maximos + 1)) / 6;
}

int main(){
  int elementos_maximos = 10;
  int serie[elementos_maximos];
  int suma = 0;
  int total = 0;
  suma = calcular_serie(serie, elementos_maximos);
  total = calcular_sumatoria_mediante_formula(elementos_maximos);
  imprimir_serie(serie, elementos_maximos, suma, total);
  return 0;
}
