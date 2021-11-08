#include <iostream>
#include <stdlib.h>
#include "sumar.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int opc, p1, p2, cont = 0;
	float d;
	int Coordenadas[10][2];
	ClaseSumar encerar; 
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
            cout<<"Ingrese el primer punto: "<<endl;
            cin>>p1;
            cout<<"Ingrese un segundo punto: "<<endl;
            cin>>p2;
            cont = cont + 1;
            encerar.AsignarValores(Coordenadas,p1,p2, cont);
			system("PAUSE()");
            break;
			}
			case 2 :
			{
			cout<<"Ingrese un indice: "<<endl;
			cin>>p1;
			cout<<"Ingrese otro indice: "<<endl;
			cin>>p2;
			ClaseSumar distancia;
			d= distancia.CalcularDistancia(Coordenadas, p1, p2);
			cout<<"La distancia es: "<<d<<"\n";
			system("PAUSE()"); 
			;
			break;	
			}
			case 3:
			{
			ClaseSumar imprimir;
			imprimir.imprimirArreglo(Coordenadas,cont);
			system("PAUSE()");
			break;
			}
		}; //Ciclo switch
		}while (opc!=4); //Ciclo do - whhile

}
