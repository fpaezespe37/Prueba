#include <iostream>
#include "funciones.h"
#include <math.h>
using namespace std;

/**/
int main(int argc, char** argv) {
	int a, b, opc, resultado;
	do
	{
		system("cls");
		cout<<"****OPERACIONES****"<<endl;
		cout<<"1. Suma REcursiva"<<endl
			<<"2. Producto recursivo"<<endl
			<<"o. Salir"<<endl;
			cin>>opc;
			switch(opc)
			{
			case 1:
				{
					cout<<"\nIngrese un numero entero: ";
					cin>>a;
					cout<<"\nIngrese un numero entero: ";
					cin>>b; 
					if(b<0)
				{	
					resultado = suma(a*(-1),b*(-1))*(-1);
				}
				else{
					resultado = suma(a,b);	
				}
				cout<<"El resultado es: "<<resultado<<endl;
				system("pause");
					break;
					}//llave de case 1
				case 2:
					{
					cout<<"\nIngrese un numero entero: ";
					cin>>a;
					cout<<"\nIngrese un numero entero: ";
					cin>>b; 
					resultado = producto(abs(a),abs(b));
					if((a<0 && b>0) || (a>0 && b<0)){
						resultado = -resultado;
					}
						
					cout<<"El resultado es: "<<resultado<<endl;
					system("pause");
					break;
					}
				case 0:
					{
					cout<<"ADIOS!";
					break;
					}//llave de case 2	
				default: 
					{
					cout<<"Incorrecto";
					break;
					}	
			};//llave de switch
	}while(opc!=0);//corchete del do
	
	return 0;
}//main
