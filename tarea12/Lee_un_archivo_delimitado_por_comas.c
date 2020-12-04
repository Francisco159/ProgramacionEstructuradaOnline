#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Evaluaciones{
  char Matricula[15];
  int PrimerParcial;
  int SegundoParcial;
  int PIA;
  float final;
};

int renglones(FILE *fpcp){
  int comparacion, contador = 0, indice = 0;
  char cad0[255], cad1[255];
  fgets(cad1,255,fpcp);
  do{
    fgets(cad0,255,fpcp);
    comparacion = strcmp(cad0,cad1);
    contador++;
    strcpy(cad1,cad0);
    indice++;
  }while(comparacion != 0);
  return contador;
}

void lectura_encabezados(FILE *fpcpy2){
  char Encabezados[255];
  fgets(Encabezados,255,fpcpy2);
  printf("%s",Encabezados);
}

void lectura_de_datos(FILE *fpcpy3, struct Evaluaciones *tupla2){
  char Mat[15];
  int Primer_Parcial, Segundo_Parcial, Pia;
  float Final;
  fscanf(fpcpy3,"%[^,], %d, %d, %d, %f\n", Mat,&Primer_Parcial,&Segundo_Parcial,&Pia,&Final);
  strcpy(tupla2->Matricula,Mat);
  tupla2->PrimerParcial = Primer_Parcial;
  tupla2->SegundoParcial = Segundo_Parcial;
  tupla2->PIA = Pia;
  tupla2->final = Final;
}

void impresion(struct Evaluaciones *tupla3){
  printf("%s %d %d %d %.2f\n",tupla3->Matricula, tupla3->PrimerParcial, tupla3->SegundoParcial, tupla3->PIA, tupla3->final);
}

int main(){
  FILE *fp;
  int numero_de_renglones;
  fp = fopen("/home/franckfeymann/Escritorio/evaluaciones.csv","r+");
  numero_de_renglones = renglones(fp);
  struct Evaluaciones Evaluaciones[numero_de_renglones - 1];
  rewind(fp);
  for(int indice = 0; indice < numero_de_renglones; indice++){
    if(indice == 0){
      lectura_encabezados(fp);
    }else{
      lectura_de_datos(fp,&Evaluaciones[indice - 1]);
      impresion(&Evaluaciones[indice - 1]);
    }
  }
  fclose(fp);
  return 0;
}
