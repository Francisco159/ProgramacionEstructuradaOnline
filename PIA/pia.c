#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Evaluaciones{
  char matricula[15];
  int Parciales[7];
  float Promedio_de_calificaciones_parciales;
  int Parciales_no_aprobados;
};

int renglones(FILE *fp){
  int comparacion, contador = 0;
  char cad0[255], cad1[255];
  fgets(cad1,255,fp);
  do{
    fgets(cad0,255,fp);
    comparacion = strcmp(cad0,cad1);
    contador++;
    strcpy(cad1,cad0);
  }while(comparacion != 0);
  return contador;
}

void lectura_de_el_encabezado(char *encabezado, FILE *fp){
  char encabezado_auxilar[255];
  fgets(encabezado_auxilar,255,fp);
  strncpy(encabezado,encabezado_auxilar,72);
  strcat(encabezado,",Promedio de las Calificaciones Parciales,No Aprobados");
}

void lectura_de_informacion(struct Evaluaciones *Evaluacion, FILE *fp){
  int parcial;
  fscanf(fp,"%[^,],",Evaluacion->matricula);
  for(int indice = 0; indice < 7; indice++){
    if(indice < 6){
      fscanf(fp,"%d,",&parcial);
      Evaluacion->Parciales[indice] = parcial;
    }else{
      fscanf(fp,"%d\n",&parcial);
      Evaluacion->Parciales[indice] = parcial;
    }
  }
}

void impresion_de_encabezado_en_archivo(char *encabezado, FILE *fp){
  fprintf(fp,"%s\n",encabezado);
}

void impresion_de_informacion_en_archivo(struct Evaluaciones *Evaluacion, FILE *fp){
  int longitud_de_matricula;
  longitud_de_matricula = strlen(Evaluacion->matricula);
  fprintf(fp, "'");
  for(int indice = 3; indice < longitud_de_matricula; indice++){
    fprintf(fp,"%c",Evaluacion->matricula[indice]);
    if(indice == (longitud_de_matricula - 1)){
      fprintf(fp,"',");
    }
  }
  for(int indice = 0; indice < 7; indice++){
    fprintf(fp,"%d,",Evaluacion->Parciales[indice]);
  }
  fprintf(fp,"%.0f,",Evaluacion->Promedio_de_calificaciones_parciales);
  fprintf(fp,"%d\n",Evaluacion->Parciales_no_aprobados);
}

void impresion_de_promedios_de_parciales(float *promedios, FILE *fp,
                                         float promedio_del_grupo){
  fprintf(fp, "Promedios,");
  for(int indice = 0; indice < 7; indice++){
    fprintf(fp, "%.0f,",promedios[indice]);
  }
  fprintf(fp,"%.0f\n",promedio_del_grupo);
}

void impresion_de_cantidad_de_parciales_no_aprobados(int *cantidad_de_parciales, FILE *fp, int alumnos_reprobados){
  fprintf(fp, "No Aprobados,");
  for(int indice = 0; indice < 7; indice++){
    fprintf(fp, "%d,",cantidad_de_parciales[indice]);
  }
  fprintf(fp,"%d\n",alumnos_reprobados);
}

float Calcula_promedio_de_calif_de_parciales(struct Evaluaciones *Evaluacion, int tamanio, int alumno){
  float Promedio = 0;
  for(int indice = 0; indice < 7; indice++){
    Promedio += (float) Evaluacion[alumno].Parciales[indice];
  }
  return Promedio/7;
}

int Calcula_cuantos_parciales_no_aprobados_de_cada_alumno(struct Evaluaciones *Evaluacion, int tamanio, int alumno){
  int contador_de_parciales = 0;
  bool condicion;
  for(int indice = 0; indice < 7; indice++){
    condicion = Evaluacion[alumno].Parciales[indice] < 7;
    if(condicion){
      contador_de_parciales++;
    }
  }
  return contador_de_parciales;
}

float Calcular_promedios_de_parciales(struct Evaluaciones *Evaluacion, int tamanio, int parcial){
  float Promedio = 0.0;
  for(int indice = 0; indice < tamanio; indice++){
    Promedio += Evaluacion[indice].Parciales[parcial];
  }
  return Promedio / tamanio;
}

float Promedio_de_calificaciones_del_grupo(struct Evaluaciones *Evaluacion, int tamanio){
  float Promedio_del_grupo = 0.0;
  for(int indice = 0; indice < tamanio; indice++){
    Promedio_del_grupo += Evaluacion[indice].Promedio_de_calificaciones_parciales;
  }
  return Promedio_del_grupo / tamanio;
}

int Calcular_cantidad_de_parciales_no_aprobados(struct Evaluaciones *Evaluacion, int tamanio, int parcial){
  int cantidad_de_parciales = 0;
  for(int indice = 0; indice < tamanio; indice++){
    if(Evaluacion[indice].Parciales[parcial] < 7){
      cantidad_de_parciales++;
    }
  }
  return cantidad_de_parciales;
}

int Total_de_alumnos_no_aprobados(struct Evaluaciones *Evaluacion, int tamanio){
  int total_de_reprobados = 0;
  for(int indice = 0; indice < tamanio; indice++){
    if(Evaluacion[indice].Promedio_de_calificaciones_parciales < 6.5){
      total_de_reprobados++;
    }
  }
  return total_de_reprobados;
}

int main(){
  FILE *fp;
  int numero_de_renglones;
  char Encabezado[255];
  float Promedio_de_parciales[7];
  int Cantidad_de_parciales_no_aprobados[7];
  float Promedio_del_grupo;
  int Total_de_no_aprobados;
  fp = fopen("/home/franckfeymann/Segundo_Semestre/Programacion_estructurada/Proyecto_Final/calificaciones_pia_pe.csv","r+");
  numero_de_renglones = renglones(fp);
  struct Evaluaciones Evaluacion[numero_de_renglones - 1];
  rewind(fp);
  for(int indice = 0; indice < numero_de_renglones; indice++){
    if(indice == 0){
      lectura_de_el_encabezado(Encabezado, fp);
    }else{
      lectura_de_informacion(&Evaluacion[indice - 1], fp);
    }
  }
  fclose(fp);

  for(int indice = 0; indice < (numero_de_renglones - 1); indice++){
    Evaluacion[indice].Promedio_de_calificaciones_parciales = Calcula_promedio_de_calif_de_parciales(&Evaluacion, numero_de_renglones - 1, indice);
  }

  for(int indice = 0; indice < (numero_de_renglones - 1); indice++){
    Evaluacion[indice].Parciales_no_aprobados = Calcula_cuantos_parciales_no_aprobados_de_cada_alumno(&Evaluacion, numero_de_renglones - 1, indice);
  }

  for(int indice = 0; indice < 7; indice++){
    Promedio_de_parciales[indice] = Calcular_promedios_de_parciales(&Evaluacion, numero_de_renglones - 1, indice);
  }

  Promedio_del_grupo = Promedio_de_calificaciones_del_grupo(&Evaluacion, numero_de_renglones - 1);

  for(int indice = 0; indice < 7; indice++){
    Cantidad_de_parciales_no_aprobados[indice] = Calcular_cantidad_de_parciales_no_aprobados(&Evaluacion, numero_de_renglones - 1, indice);
  }

  Total_de_no_aprobados = Total_de_alumnos_no_aprobados(&Evaluacion, numero_de_renglones - 1);

  fp = fopen("/home/franckfeymann/Segundo_Semestre/Programacion_estructurada/Proyecto_Final/PIA.csv","w+");
  for(int indice = 0; indice < (numero_de_renglones + 2); indice++){
    if(indice == 0){
       impresion_de_encabezado_en_archivo(Encabezado, fp);
    }else{
      if(indice <= 29){
        impresion_de_informacion_en_archivo(&Evaluacion[indice - 1], fp);
      }else{
        if(indice == 30){
          impresion_de_promedios_de_parciales(Promedio_de_parciales, fp,
                                              Promedio_del_grupo);
        }else{
          impresion_de_cantidad_de_parciales_no_aprobados(
                Cantidad_de_parciales_no_aprobados, fp, Total_de_no_aprobados);
        }
      }
    }
  }
  fclose(fp);
  printf("Archivo Guardado\n");
  return 0;
}
