#include<iostream>
#include "funciones.h"
#include<iostream> 
using namespace std;
int main()
{
    int m;
    cout<<"\t\t\tElija una opcion\n\n";
//con '\t\t\t' llevo un poco al centro el mensaje, y con '\n\n' salto 2 lineas hacia abajo.
    cout<<"1  Verificar si un numero es divisible\n";
    cout<<"2  Criterio de divisibilidad\n";
    cout<<"3  Consultas\n";
    cout<<"6  Salir\n\n";
    cout << "Ingrese una opcion: " ;
    cin>>m;
 
switch(m)
{
	case 1:
	;	//Division(4320);    
		break;
	case 2:
		cout<<"¿Que desea modificar?"<<endl;
		break;
	case 3:
		cout<<"Escriba su consulta aqui: "<<endl;
		break;
	case 6:
		cout<<"Gracias por usarlo"<<endl;
		break;
	default: 
		cout<<"El valor ingresado no esta en el menu"<<endl;
}
     return 0;
}
