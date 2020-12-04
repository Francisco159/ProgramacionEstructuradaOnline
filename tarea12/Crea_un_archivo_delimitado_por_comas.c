#include <stdio.h>
#include <string.h>

struct Evaluaciones{
  char Matricula[15];
  int PrimerParcial;
  int SegundoParcial;
  int PIA;
  float final;
};

void Captura_de_datos(struct Evaluaciones *tupla, int valor){
  switch(valor){
    case 0:
      strcpy(tupla->Matricula,"11");
      break;
    case 1:
      strcpy(tupla->Matricula,"12");
      break;
    case 2:
      strcpy(tupla->Matricula,"13");
      break;
  }
  tupla->PrimerParcial = valor + 9;
  tupla->SegundoParcial = valor + 9;
  tupla->PIA = valor + 9;
  tupla->final = valor + 9;
}

void impresion(struct Evaluaciones *tupla, FILE *fp){
  fprintf(fp,"%s, %d, %d, %d, %.2f\n",tupla->Matricula,
          tupla->PrimerParcial, tupla->SegundoParcial,
          tupla->PIA, tupla->final);
}

int main(){
  FILE *fp;
  fp = fopen("/home/franckfeymann/Escritorio/evaluaciones.csv","w+");
  struct Evaluaciones Evaluaciones[3];

  for(int indice = 0; indice < 3; indice++){
    Captura_de_datos(&Evaluaciones[indice],indice);
  }

  fprintf(fp,"Matricula, PrimerParcial, SegundoParcial, PIA, Final\n");
  for(int indice = 0; indice < 3; indice++){
    impresion(&Evaluaciones[indice],fp);
  }
  fclose(fp);
  printf("Archivo Guardado\n");
  return 0;
}
