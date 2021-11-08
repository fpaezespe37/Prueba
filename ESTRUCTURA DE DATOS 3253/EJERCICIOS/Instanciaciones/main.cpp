#include <iostream>
#include "pila.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout << "**** PILA ESTATICA ****";
	Pila* pila = NULL;
	pila = crearPila(5);
	push(pila,100);
	push(pila, 500);
	imprimir(pila);
	push(pila, 700);
	push(pila, 123);
	push(pila, 900);
	push(pila, 2);
	imprimir(pila);
	pop(pila);
	pop(pila);
	imprimir(pila);
	return 0;
	
}
