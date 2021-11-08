#include <iostream>
#include "funciones.h"
#include"contar.h"
#include "SumaRecursiva.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,f,n1,n2;
	
	do
	{
		cout<<"Ingrese unn entero positivo: ";
		cin>>n; 
		if(n<0)
		cout<<"ERROR! No existe factorial negativo"<<endl;
	}while(n<0);
		f = fact(n);
		cout<<"\n"<<n<<"!"<<"="<<f<<endl;
		cout<<"\nImprimir ascendente: \n";
		imprimirA(n);
		cout<<"\nImprimir descendente: \n";
		imprimirD(n);
		cout<<"La suma es: \n";
		cout<<"Suma: "<<endl;
		cout<<"Ingrese un numero: ";
		cin>>n1;
		cout<<"Ingrese un numero dos: ";
		cin>>n2;
		cout<<"La suma es:"<<SumaRecursiva(n1,n2);
		return 0;
}
