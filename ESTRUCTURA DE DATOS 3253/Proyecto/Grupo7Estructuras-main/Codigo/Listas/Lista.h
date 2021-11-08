#include <iostream>
#include "Nodo.h"
using namespace std;
class Lista
{
private:
    Nodo *primero;
    Nodo *ultimo;

public:
    Lista *agregarNodo(Lista *L, int datoAgregar);
    Lista *agregarNodoInicio(Lista *L, int datoAgregar);
    Lista *agregarNodoAnt_Desp(Lista *L, int datoAgregar);
    void *InsertarElemento(Lista *L, int datoAgregar,int valor, int pos);
    void *insertAtPos(int pos,int val)
{
    void *imprimirLista(Lista *L);
};

Lista *Lista::agregarNodo(Lista *L, int datoAgregar)
{
    Nodo *e = new Nodo;
    e = e->crearNodo(datoAgregar);

    if (e != NULL)
    {
        if (L != NULL)
        {
            cout << "Lista No Vacia, Se agregara un Nodo al Final" << endl;
            L->ultimo->siguiente = e;
            L->ultimo = e;
            return L;
        }
        else
        {
            cout << "Lista Vacia, se agrega el primer elemento." << endl;
            Lista *l = new Lista;
            l->primero = e;
            l->ultimo = e;
            return l;
        }
    }
}

void *Lista::imprimirLista(Lista *L)
{
    int i = 1;
    if (L != NULL)
    {
        cout << "\nLista Completa: " << endl;
        Nodo *e = L->primero;
        do
        {
            cout << "\nNodo: " << i << ": " << e->dato << endl;
            e = e->siguiente;
            i++;
        } while (e != NULL);
    }
    else
    {
        cout << "La Lista Esta Vacia" << endl;
    }
}

Lista *Lista::agregarNodoInicio(Lista *L, int datoAgregar)
{
    Nodo *e;
    e->crearNodo(datoAgregar);
    if (e != NULL)
    {
        if (L != NULL)
        {
            cout << "Lista No Vacia, Agregamos Nodo Al Inicio: " << endl;
            L->primero = e;
            L->ultimo->siguiente = e;
            return L;
        }
        else
        {
            cout << "Lista Vacia, Se Agrega el Primer Elemento: " << endl;
            Lista *l = new Lista;
            l->primero = e;
            l->ultimo = e;
            return l;
        }
    }
}

int insertarAntesDespues()
{
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;
 
    cout<<"\n\t Opcion : "; cin>> _op;
 
    if(_op==1)
        band = -1;
    else
        band = 0;
 
    return band;
}

void *Lista::insertAtPos(int pos,int val)
{
    Nodo *e = new Nodo();
    e = e->crearNodo(val);
    
    if(pos==1)
    {
        //as head
        e->siguiente=this->ultimo;

        this->ultimo=e;
        return;
    }
    pos--;
    Nodo *e=this->ultimo;
    while(e!=NULL && --pos)
    {
        e=e->siguiente;
    }
    if(e==NULL)
    return;//not enough elements

    e->siguiente=e->siguiente;
    e->siguiente=e;
;}
