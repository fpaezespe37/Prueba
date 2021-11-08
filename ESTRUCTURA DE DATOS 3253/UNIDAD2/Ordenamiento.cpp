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
