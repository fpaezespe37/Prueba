#include <iostream>
#include "circular.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {


system("pause");
	cout<<"\nCola Circular\n";
	struct Cola* cola = crearCola(5);
	cout<<"\nEncolar: 12\n";
	encolar(cola, 12);
	system("pause");
	cout<<"\nEncolar: 19\n";
	encolar(cola,19);
	system("pause");
	cout<<"\nEncolar: 11\n";
	encolar(cola, 11);
	system("pause");
	cout<<"\nEncolar: 100\n";
	encolar(cola,100);
	system("pause");
	cout<<"\nEncolar: 95\n";
	encolar(cola,95);
	system("pause");
	//imprimir(cola);
	cout<<"\nDesencolar: "<<desencolar(cola)<<endl;
	cout<<"\nEncolar: 500\n";
	encolar(cola,500);
	system("pause");
	cout<<"\nEncolar: 1\n";
	encolar(cola,1);
	system("pause");
	return 0;
}
