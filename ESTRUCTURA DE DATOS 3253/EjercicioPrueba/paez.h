#include <iostream>
#include <math.h>
using namespace std;

//Codigo para el Menu de Opciones
int menu(){
	int opc;
	cout<<"\nCALCULO DE DISTANCIA ENTRE 2 PUNTOS: "<<endl;
	cout<<"1. Ingrese un Numero: "<<endl
		<<"2. Salir"<<endl
		<<"Seleccione una opcion: ";
	cin>>opc; 
	return opc;	
}

 void ImprimirNum(int numero)
{
    
	int aux, n; 
    cout << "Ingrese el numero entero: " << endl;
 	cin >> n;
 	int cifras[10];
 	int i=0; 
 	while(n<0 || n>0)
 	{
 		cifras[i] = n%10;
 		n = n/10;
 		i++;
	}
	 //Linea de Codigo que sirve para imprimir digito a digito 
	 for(int aux = i-1 ; aux>=0; aux--)
	 {
		cout <<cifras[aux]<< ","<<endl;
	  } 

}
