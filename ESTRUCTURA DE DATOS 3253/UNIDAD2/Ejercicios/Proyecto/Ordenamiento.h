#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

using namespace std;

void quicksort(Persona A[],int izq, int der ){
    int i, j;
    Persona x , aux;
    i = izq;
    j = der;
    x = A[ (izq + der) /2 ];
        do{
            while( (strcmp(A[i].getNombre().c_str(), x.getNombre().c_str())<0) && (j <= der) ) i++;

            while( (strcmp(x.getNombre().c_str(), A[j].getNombre().c_str())<0) && (j > izq) ) j--;

            if( i <= j ){
                aux = A[i]; A[i] = A[j]; A[j] = aux;
                i++;  j--;
            }
        }while( i <= j );

        if( izq < j ) quicksort( A, izq, j );
        if( i < der ) quicksort( A, i, der );
}

void intercambio(Persona A[], int n){
    int i,j;
    Persona aux;

    for(i=0; i<=n-2;i++)
        for(j=i+1; j<=n-1;j++){
            if(strcmp(A[i].getNombre().c_str(), A[j].getNombre().c_str())>0){
                aux  = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
        }
}

void unir(Persona izq[], int nIzq, Persona der[], int nDer, Persona A[]) {
     int i=0,j=0,k=0;

     while( ( i < nIzq ) && ( j < nDer ) ){
        if( izq[i].getSueldo() <= der[j].getSueldo()){
           A[k] = izq[i];
           i++;
        }
        else {
           A[k] = der[j];
           j++;
        }
      k++;
     }
     while(i < nIzq) {
        A[k] = izq[i];
        i++; k++;
     }
     while(j < nDer) {
        A[k] = der[j];
        j++; k++;
     }
}

void mezcladirecta(Persona A[], int n) {
     if(n == 1) return;
     int mitad = n / 2;
     Persona izq[mitad];
     Persona der[n - mitad];

     for(int i=0;i<mitad;i++)
        izq[i] = A[i];
     for(int i = mitad; i < n; i++)
        der[i - mitad] = A[i];
     mezcladirecta(izq, mitad);
     mezcladirecta(der, n-mitad);
     unir(izq, mitad, der, n-mitad, A);
}

void shellsort(Persona arr[], int n){
    int i,j,gap;
    Persona temp;

    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i += 1) {
            temp = arr[i];

            for (j = i; j >= gap && strcmp(arr[j - gap].getNombre().c_str(), temp.getNombre().c_str())>0; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void separar(FILE *fich, FILE **aux) {
   char linea[128], anterior[2][128];
   int salida = 0;

   strcpy(anterior[0], "");
   strcpy(anterior[1], "");

   fgets(linea, sizeof(Persona), fich);
   while(!feof(fich)) {
      if(salida == 0 && strcmp(linea, anterior[0]) < 0) salida = 1;
      else if(salida == 1 && strcmp(linea, anterior[1]) < 0) salida = 0;
      strcpy(anterior[salida], linea);
      fputs(linea, aux[salida]);
      fgets(linea, sizeof(Persona), fich);
   }
}

int mezclar(FILE *fich, FILE **aux) {
   char ultima[128], linea[2][128], anterior[2][128];
   int entrada;
   int tramos = 0;

   fgets(linea[0], 128, aux[0]);
   fgets(linea[1], 128, aux[1]);
   strcpy(ultima, "");
   strcpy(anterior[0], "");
   strcpy(anterior[1], "");
   while(!feof(aux[0]) && !feof(aux[1])) {
      if(strcmp(linea[0], linea[1]) <= 0) entrada = 0; else entrada = 1;
      strcpy(anterior[entrada], linea[entrada]);
      fputs(linea[entrada], fich);
      fgets(linea[entrada], 128, aux[entrada]);
      if(strcmp(anterior[entrada], linea[entrada]) > 0) {
         if(!entrada) entrada = 1; else entrada = 0;
         tramos++;
         do {
            strcpy(anterior[entrada], linea[entrada]);
            fputs(linea[entrada], fich);
            fgets(linea[entrada], 128, aux[entrada]);
         } while(!feof(aux[entrada]) && strcmp(anterior[entrada], linea[entrada]) <= 0);
      }
   }

   if(!feof(aux[0])) tramos++;
   while(!feof(aux[0])) {
      fputs(linea[0], fich);
      fgets(linea[0], 128, aux[0]);
   }
   if(!feof(aux[1])) tramos++;
   while(!feof(aux[1])) {
      fputs(linea[1], fich);
      fgets(linea[1], 128, aux[1]);
   }
   return(tramos == 1);
}

void mezclaNatural(FILE *fich) {
   int ordenado;
   FILE *aux[2];

   do {
      aux[0] = fopen("aux1.txt", "w+");
      aux[1] = fopen("aux2.txt", "w+");
      rewind(fich);
      separar(fich, aux);
      rewind(aux[0]);
      rewind(aux[1]);
      rewind(fich);
      ordenado = mezclar(fich, aux);
      fclose(aux[0]);
      fclose(aux[1]);
   } while(!ordenado);

   remove("aux1.txt");
   remove("aux2.txt");
}
