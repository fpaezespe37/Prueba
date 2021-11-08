#include <iostream>
#include "ListaPOO.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Lista lista; 
	
	
	lista.agregar(20);
	lista.agregar(10);
	lista.agregar(40);
	lista.agregar(30);
	lista.imprimir();
	
	system("pause");
	
	cout << "Eliminando dato 20..." << endl; 
	lista.eliminar(20);
	 
	system("pause");
	lista.imprimir();
	return 0;

}
