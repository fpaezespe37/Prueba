#include <iostream>
#include "funciones.h"
using namespace std;

/*Tema: Templates
Implmentar tipos de datos genericos para obtener el menor de 2 numeros
que funcionan con cualquier tipo de dato.

tipo_dato menor (tipo_dato a, tipo_Dato b)

{
	si (a>b)
		retorno a
	
	caso contrario 
		retorno b

}

*/ 



int main(int argc, char** argv) {
	int x,y;
	float a,b;
	
	cout<<"Menor de 2 numeros enteros"<<endl;
	cout<<"N1: "<<endl;
	cin>>x;
	cout<<"N2: "<<endl;
	cin>>y;
	system("pause");
	cout<<"Menor int: "<<menor(x,y)<<endl;
	system("pause");
	system("cls");
	cout<<"Menor de 2 numeros flotantes"<<endl;
	cout<<"N1: "<<endl;
	cin>>a;
	cout<<"N2: "<<endl;
	cin>>b;
	system("pause");
	cout<<"Menor float: "<<menor(a,b)<<endl;
	
//cout<<"Menor int: "<<menor(5,9)<<endl;
//cout<<"Menor float: "<<menor(a,b)<<endl;
	system("pause");
	cout<<"Mayor entre entero y flotante "<<x<<" `y "<<a<<endl;
	cout<<"Mayor: "<<mayor(x,a)<<endl;
	system("pause");
	return 0;
}
