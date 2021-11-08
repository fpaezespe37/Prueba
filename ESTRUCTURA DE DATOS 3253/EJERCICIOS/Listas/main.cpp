#include <iostream>
#include "listaSimple.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"Listas\n";
	
	Lista* lista = NULL;
	Nodo* e;
	int dato;
	lista = agregar_nodoIn(lista, 20);
	system("pause"); 
	lista = agregar_nodoIn(lista, -8);
	system("pause"); 
	lista = agregar_nodoIn(lista, 12);
	system("pause"); 
	imprimir_lista(lista);
	system("pause");
	//ELIMINACION
	cout<<"\nELIMINACION: ";
	lista = eliminarNodo(lista);
	imprimir_lista(lista);
	system("pause");
	lista = eliminarNodo(lista);
	imprimir_lista(lista);
	system("pause");
	lista = eliminarNodo(lista);
	imprimir_lista(lista);
	system("pause");
	//BUSQUEDA
	cout<<"BUSQUEDA: ";
	e = buscarDesorden(lista, -8);
	system("pause");
	if(e!=NULL)
	{
		cout<<"\nDato encontrado: "<<e->dato<<endl;
		
	}
	else
	{
		cout<<"Dato no encontrado: ";
	}
	return 0;
}
