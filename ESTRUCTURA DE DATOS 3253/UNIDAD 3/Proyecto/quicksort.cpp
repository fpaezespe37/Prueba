 
#include <stdio.h>
using namespace std;


void intercambiar(int *a, int *b) {
  int temporal = *a;
  *a = *b;
  *b = temporal;
}



int particion(int arreglo[], int izquierda, int derecha) {
  // Elegimos el pivote, es el primero
  int pivote = arreglo[izquierda];
  // Ciclo infinito
  while (1) {
    // Mientras cada elemento desde la izquierda esté en orden (sea menor que el
    // pivote) continúa avanzando el índice
    while (arreglo[izquierda] < pivote) {
      izquierda++;
    }
    // Mientras cada elemento desde la derecha esté en orden (sea mayor que el
    // pivote) continúa disminuyendo el índice
    while (arreglo[derecha] > pivote) {
      derecha--;
    }
    /*
    Si la izquierda es mayor o igual que la derecha significa que no
    necesitamos hacer ningún intercambio
    de variables, pues los elementos ya están en orden (al menos en esta
    iteración)
    */
    if (izquierda >= derecha) {
      // Indicar "en dónde nos quedamos" para poder dividir el arreglo de nuevo
      // y ordenar los demás elementos
      return derecha;
    } else {//Nota: yo sé que el else no hace falta por el return de arriba, pero así el algoritmo es más claro
      /*
      Si las variables quedaron "lejos" (es decir, la izquierda no superó ni
      alcanzó a la derecha)
      significa que se detuvieron porque encontraron un valor que no estaba
      en orden, así que lo intercambiamos
      */
      intercambiar(&arreglo[izquierda], &arreglo[derecha]);
      /*
      Ya intercambiamos, pero seguimos avanzando los índices
      */
      izquierda++;
      derecha--;
    }
    // El while se repite hasta que izquierda >= derecha
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

int main(void) {
  // El arreglo
  int arreglo[] = {28, 11, 96, -5, 21, 18, 12, 22, 30, 97, -1, -40, -500};
  /*
  Calcular la longitud, puede ser definida por ti o calculada:
  https://parzibyte.me/blog/2018/09/21/longitud-de-un-arreglo-en-c/
  */
  int longitud = sizeof arreglo / sizeof arreglo[0];
  /*
  Imprimirlo antes de ordenarlo
  */
  printf("Imprimiendo arreglo antes de ordenar...\n");
  for (int x = 0; x < longitud; x++) {
    printf("%d ", arreglo[x]);
  }
  // Un salto de línea
  printf("\n");

  /*
  Invocar a quicksort indicando todo el arreglo, desde 0 hasta el índice final
  */
  quicksort(arreglo, 0, longitud - 1);
  /*
  Imprimirlo después de ordenarlo
  */
  printf("Imprimiendo arreglo despues de ordenar...\n");
  for (int x = 0; x < longitud; x++)
    printf("%d ", arreglo[x]);
  return 0;
}
