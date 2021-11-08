#include <iostream>
#include <stdlib.h>
#include "sumar.h"
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int opc, p1, p2,p3;
	float x,y;
	float pClase;
	
		do
		{
			
		
		system("cls");
		ClaseSumar options;
		opc = options.MenuOptions(opc);
		ClaseSumar points;
		switch(opc)
		{
			case 1:
			{
			cout<<"\nIngreso de puntos:"<<endl;
            //direccion de memoria, reservar memoria
            cout<<"Ingrese el primer punto: "<<endl;
            cin>>p1;
            cout<<"Ingrese un segundo punto: "<<endl;
            cin>>p2;
            break;
			}
			case 2:
			{
			cout<<"[X]: "<<p1;
			cout<<"[Y]: "<<p2;
			
		
			
			break;
			
			}
		
		}; //Ciclo switch
		}while (opc!=4); //Ciclo do - whhile
	
	
	//ClaseSumar suma;
 	//pClase = suma.SumarClase(x,y);
	//cout<<"La suma es:" <<pClase;
	//return 0;
	
}
