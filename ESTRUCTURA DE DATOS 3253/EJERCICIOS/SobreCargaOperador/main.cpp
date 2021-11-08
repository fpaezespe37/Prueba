#include <iostream>
#include "Complejo.h"

using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*Sobrecarga del operador + para sumas dos complejos*/

complejo operator + (complejo a, complejo b)
{
	complejo temp = {a.real + b.real, a.i+b.i};
	//int a[] = {5+85,3,9,2};
	return temp;
	
}

void imprimir(complejo a)
{
	cout<<"("<<a.real<<","<<a.i<<"i"<<")"<<endl;
	
	
}



int main(int argc, char** argv) {
	
	complejo x,y,z;
	
	cout<<"*****SOBRECARGA DE OPERADORES*****"<<endl;
	cout<<"INGRESE DOS NUNMEROS COMPLEJOS"<<endl;
	cout<<"Complejo x "<<endl;
	cout<<"\tParte Real: ";
	cin>>x.real;
	cout<<"\tParte Imaginaria: ";
	cin>>x.i;
	
	cout<<"*****SOBRECARGA DE OPERADORES*****"<<endl;
	cout<<"INGRESE DOS NUNMEROS COMPLEJOS"<<endl;
	cout<<"Complejo y "<<endl;
	cout<<"\tParte Real: ";
	cin>>y.real;
	cout<<"\tParte Imaginaria: ";
	cin>>y.i;
	
	z = x + y; //Invocar al operador sobrecargado de suma +
	
	imprimir (z);
	system("pause");
	return 0;
}
