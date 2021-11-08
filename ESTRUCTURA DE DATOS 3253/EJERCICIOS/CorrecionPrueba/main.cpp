#include <iostream>
#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	struct Persona dato;
	listaSimples* Lista = NULL;
	nodo *e=NULL;
	int opc;
	
	do
	{
		opc=menu();
		
		switch(opc)
		{
			case 1:{ //Agregar persona al inicio
				cout<<"Ingrese los datos de la persona: "<<endl;
				cin>>dato;				
				Lista = agregarNodoAlInicio(Lista,dato);
				break;
			}
			case 2:{
				
				break;
			}
			case 3: { //Imprimir listado mujeres
				imprimirLista(Lista,2);
				break;
			}
			case 4:{//Imprimir listado hombres
				imprimirLista(Lista,1);
				break;
			}
			case 5:{
				e = buscarMayor(Lista);
				cout<<e->dato;
				break;
			}
			case 0:{
				
				break;
			}
			default:{
				
				break;
			}
			
		}
		
		system("pause");
	}while(opc!=0);
	
	return 0;
}

