#include <iostream>
#include "cola.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	cout<<"\n COLAS DINAMICA CON CLASES";
	Cola c;
	cout<<"\nEncolar 15\n";
	c.encolar(15);
	system("pause");
	cout<<"\nEncolar 30\n";
	c.encolar(30);
	system("pause");
	cout<<"\nEncolar 9\n";
	c.encolar(9);
	system("pause");
	
	cout<<"\nDesencolar: "<<c.desencolar()<<endl;
	system("pause");
	cout<<"\nDesencolar: "<<c.desencolar()<<endl;
	system("pause");
	cout<<"\nDesencolar: "<<c.desencolar()<<endl;
	system("pause");
	return 0;
}
