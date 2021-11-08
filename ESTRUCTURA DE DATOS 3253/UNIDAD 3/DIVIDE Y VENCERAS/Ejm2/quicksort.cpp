#include <iostream>
#include <stdio.h>
#include "quicksort.h"
using namespace std;
/*METODO DIVIDE Y VENCERAS APLICANDO AL EJEMPLO DE ORDENAMIETO DE ARRAYS
							GRUPO NUMERO 6
					ESTRUCTURA DE DATOS 3293*/	

int main(void) {
  int arreglo[] = {8,1,5,14,4,15,12,6,2,11,10,7,9};
  int longitud = sizeof arreglo / sizeof arreglo[0];
  cout << "Imprimiendo arreglo antes de ordenar...\n";
  for (int x = 0; x < longitud; x++) {
    cout << ", "<< arreglo[x];
  }
  cout<< "\n";

	system("pause");
  /*
  Invocamos al metodo quicksort indicando todo el arreglo, desde 0 hasta el índice final
  */
  quicksort(arreglo, 0, longitud - 1);
  cout << "Imprimiendo arreglo despues de ordenar...\n";
  for (int x = 0; x < longitud; x++)
    cout << ", " << arreglo[x];
  return 0;
}
