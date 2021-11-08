#include <stdio.h>

void intercambiar(int *a, int *b) {
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

int particion(int arreglo[], int izquierda, int derecha) {
  int pivote = arreglo[izquierda];
  		while (1) {
        while (arreglo[izquierda] < pivote) {
      izquierda++;
    }
    
    while (arreglo[derecha] > pivote) {
      derecha--;
    }
    
    if (izquierda >= derecha) {
      /
      return derecha;
    } else {
    	
      intercambiar(&arreglo[izquierda], &arreglo[derecha]);
      izquierda++;
      derecha--;
    }
  }
}

// Divide y vencerás
void quicksort(int arreglo[], int izquierda, int derecha) {
  if (izquierda < derecha) {
    int indiceParticion = particion(arreglo, izquierda, derecha);
    quicksort(arreglo, izquierda, indiceParticion);
    quicksort(arreglo, indiceParticion + 1, derecha);
  }
}


