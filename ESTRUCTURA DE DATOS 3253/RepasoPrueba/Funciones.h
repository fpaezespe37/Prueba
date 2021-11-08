#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Persona
{
	int codigo;
	int cantidad;
	float precio;
};

struct nodo
{
    struct Persona dato;
    struct nodo* sig;
};

struct listaSimples
{
    struct nodo* pri;
    struct nodo* ult;
};

istream& operator >>(istream &i, Persona &a)
{
	cout << "\tCodigo: ";
	i >> a.codigo;
	cout << "\tCantidad: ";
	i >>a.cantidad;
	cout << "\tPrecio: ";
	i >> a.precio;
	i.ignore();
	return i;
}

/*ostream& operator <<(ostream &os,Persona a)
{
	
	os<<a.codigo<<"\t";
	os<<"\t"<< a.cantidad;
	os<<"\t"<<a.precio<<endl;
	return os;
}*/

int menu()
{
    int opc;
    system("cls");
    cout<<"\t Bienvenido al sistema "<<endl;
    cout<<"\n Lista de productos con su codigo: "<<endl;
    cout<<"Balon de futbol - Codigo 1"<<endl;
    cout<<"Jafas para nadar - Codigo 2"<<endl;
    cout<<"Guantes de box - Codigo 3"<<endl;
    cout<<"Raquetas de Ping Pong - Codigo 4"<<endl;
    cout<<"Vendas - Codigo 5"<<endl;
	cout << "\n1. Agregar Articulo a la lista de compra";
	//cout << "\n2. Agregar Nodo Despues de un nodo x.";
	//cout << "\n3. Agregar Nodo antes de un nodo x.";
	cout << "\n2. Imprimir lista.";
	cout << "\n3. Buscar articulo por codigo";
	cout << "\n4. busqueda.";
	//cout << "\n7. Eliminar ultimo nodo de la lista.";
	//cout << "\n8. Eliminar Nodo siguiente";
	cout << "\n0. Salir";
	cout << "\nIngrese una opcion: ";
	cin >> opc;
	return opc;
}

nodo* crearNodo(Persona dato)
{
    nodo* e = new nodo;
    if (e != NULL)
    {
        e->dato.codigo = dato.codigo;
        e->dato.cantidad = dato.cantidad;
        e->dato.precio = dato.precio;
        //strcpy(e->dato.nombre,dato.nombre);
        e->sig = NULL;
        cout << "Dato: " << e->dato.codigo;
    }
    return e;
}

struct listaSimples* agregarNodo(struct listaSimples* L, Persona dato)
{
    nodo* e = crearNodo(dato);
    if (e != NULL)
    {
        if (L != NULL)
        {
            cout << "\nLista no vacia, se va agregar el nodo al final" << endl;
            L->ult->sig = e;
            L->ult = e;
            //cout << "Dato " << e->dato << " ingresado correctamente." << endl;
            return L;
        }
        else
        {
            cout << "\nLista vacia, se va a crear el primer elemento" << endl;
            listaSimples* l = new listaSimples;
            l->pri = e;
            l->ult = e;
            //cout << "Dato " << e->dato << " ingresado correctamente." << endl;
            return l;
        }
    }
    else
    {
        return NULL;
    }
}

void imprimirLista(listaSimples* L)
{
    int i=1;
     if (L != NULL)
	{
		cout << "\nLista Completa. " << endl;
		nodo *e = L->pri;
		do
		{
			cout << "\nArticulo " << i << ": Codigo: " <<  e->dato.codigo << "\tCantidad: "<<e->dato.cantidad << "\tPrecio: "<< e->dato.precio<<"Total: "<<e->dato.cantidad*e->dato.precio;
			e = e->sig;
			i++;
			
		} while (e != NULL);
		system("pause");
	}
	else
	{
		cout << "\nLa lista esta vacia" << endl;
	}
}

struct listaSimples* agregarNodoAlInicio(struct listaSimples* L,Persona dato)
{ //INICIO
    nodo* e = crearNodo(dato);
    if (e != NULL)
    {
        if (L != NULL) //LISTA NO VACIA
        {
            //Agregar nodo al final de la lista
            cout << "\nLista No Vacia, se va a agregar nodo al inicio" << endl;
            e->sig = L->pri;
            L->pri = e;
            return L;
        }
        else
        { //LISTA VACIA
            //Agregar primer elemento a la lista, crear la lista
            cout << "\nLista Vacia, se va a crear el primer nodo" << endl;
            listaSimples* l = new listaSimples;
            l->pri = e;
            l->ult = e;
            return l;
        }
    }
    else
    {
        return NULL;
    }
}
struct listaSimples* eliminarUltimo(listaSimples* L)
{
    int opc;
    if (L != NULL)
    {
        nodo* e;
        e = L->pri;
        cout << "\nSe eliminara el ultimo dato."
            << " Desea continuar? 1-SI/0-NO: ";
        cin >> opc;
        if (opc == 1)
        {
            if (e->sig != NULL)
            {
                while ((e->sig)->sig != NULL)
                {
                    e = e->sig;
                }
                free(e->sig);
                e->sig = NULL;
            }
            else
            {
                L = NULL;
            }
        }
    }
    else
    {
        cout << "\nLa lista esta vacia. " << endl;
    }
    return L;
}


