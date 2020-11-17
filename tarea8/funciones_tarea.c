#include <stdio.h>

typedef int (*operaciones)(int, int);

struct tarea{
  int arreglo[4];
  operaciones ejercicio;
};

int suma(int valor1,int valor2){
  return valor1+valor2;
}

int mayor(int valor1, int valor2){
    return valor1 > valor2 ? valor1 : valor2;
}

int menor(int valor1, int valor2){
    return valor1 < valor2 ? valor1 : valor2;
}

int ejecutar(struct tarea *arreglos){
  int numero = arreglos->arreglo[0];
  for(int i=0;i<3;i++){
    numero = arreglos->ejercicio(numero,arreglos->arreglo[i+1]);
  }
  return numero;
}

int main(){
  struct tarea listado_arreglos[3];
  for(int i = 0; i < 4; i++){
    listado_arreglos[0].arreglo[i] = i+1;
    listado_arreglos[0].ejercicio = menor;
  }
  for(int i = 0; i < 4; i++){
    listado_arreglos[1].arreglo[i] = i+1;
    listado_arreglos[1].ejercicio = mayor;
  }
  for(int i = 0; i < 4; i++){
    listado_arreglos[2].arreglo[i] = i+1;
    listado_arreglos[2].ejercicio = suma;
  }

  int resultado1,resultado2,resultado3,resultado4;
  resultado1 = ejecutar(&listado_arreglos[0]);
  resultado2 = ejecutar(&listado_arreglos[1]);
  resultado3 = ejecutar(&listado_arreglos[2]);

  printf("Menor = %d\n",resultado1);
  printf("Mayor = %d\n",resultado2);
  printf("Suma = %d\n",resultado3);
  printf("Promedio = %d\n",resultado4);
  for(int i=0;i<4;i++){
    printf("%d ",listado_arreglos[0].arreglo[i]);
  }
  printf("\n");
  return 1;
}
