#include <iostream>
#include "paeznodo.h"
using namespace std;
class Lista
{
private:
    Nodo *primero;
    Nodo *ultimo;
    public:
    Lista *agregarNodo(Lista *L, String persona);
    Lista *agregarNodoInicio(Lista *L, String persona);
    Nodo *busqueda(Lista *L, String persona);
    void *imprimirLista(Lista *L);
    void *sumatoriaLista(Lista *L);
    Lista *eliminarNodoInicio(Lista *L);
    Lista *eliminarDato(Lista *L, int opc2);
    
    
};

void *Lista::imprimirLista(Lista *L)
{
    int i = 1;
    if (L != NULL)
    {
        cout << "\nLista Completa: " << endl;
        Nodo *e = L->primero;
        do
        {
            cout << "\t\nNODO " << i << ": " << e->dato << endl;
            e = e->siguiente;
            i++;
        } while (e != NULL);
        system("pause");        
    }
    else
    {
        cout << "La lista se encuentra vacia." << endl;
        system("pause");
        system("cls");
    }
}


Lista *Lista::agregarNodoInicio(Lista *L, String persona)
{
    
    Nodo *e = new Nodo;
    e->dato = datoAgregar;
    e->siguiente = NULL;

    if (e != NULL)
    {
        if (L != NULL)
        {
            cout << "Lista no vacia, se agregara el dato: " << datoAgregar << " a la lista." << endl;
            Nodo *temp = new Nodo;
            temp->dato = datoAgregar;
            temp->siguiente = L->primero;
            L->primero = temp;
            system("pause");
            system("cls");
            return L;
        }
        else
        {
            cout << "Lista vacia, se agrega el dato: " << datoAgregar << " ,como primer elemento." << endl;
            Lista *l = new Lista;
            l->primero = e;
            l->ultimo = e;
            system("pause");
            system("cls");
            return l;
        }
    }
}
/*Codigo para el Menu de Opciones
int menu(){
	int opc;
	cout<<"\nLISTA DE PERSONAS: "<<endl;
	cout<<"1. Ingrese un Numero: "<<endl
		<<"2. Salir"<<endl
		<<"Seleccione una opcion: ";
	cin>>opc; 
	return opc;	
}*/
