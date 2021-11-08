#include<iostream>
#include "paez.h"
#include<iostream> 
using namespace std;
int main()
{
    int m, numero, resultado; 
    cout<<"\t\t\tElija una opcion\n\n";
    cout<<"1  Verificar si un numero es divisible\n";
    cout<<"2  Criterio de divisibilidad\n";
    cout<<"6  Salir\n\n";
    cout << "Ingrese una opcion: " ;
    cin>>m;
 
switch(m)
{               
	case 1: 
  		cout << "Ingrese el numero: "; 
  		cin >> numero;
  		resultado = Division(numero);
		  cout << "\nEl resultado es: " << resultado;   
		  Divisibilidad(resultado);              
		break;
	case 2:  
		cout<<"Un número es divisible entre 11 cuando la suma de los números que ocupan la posición par menos la suma de los números que ocupan la posición impar es igual a 0 o a un número múltiplo de 11."<<endl;
		break;
	case 6:
		cout<<"Gracias por usarlo"<<endl;
		break;
	default: 
		cout<<"El valor ingresado no esta en el menu"<<endl;
}  
     return 0;
}
