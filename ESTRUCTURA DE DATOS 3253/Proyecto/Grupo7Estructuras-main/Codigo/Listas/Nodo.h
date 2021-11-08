#include <iostream>
using namespace std;

class Nodo
{
private:
public:
    int dato;
    //int Tam;
    Nodo *siguiente;
    Nodo *crearNodo(int dato);
};

Nodo *Nodo::crearNodo(int dato)
{
    Nodo *aux = new Nodo; //Reservando memoria para 1 nodo
    if (aux != NULL)
    {
        aux->dato = dato; //Asignar un dato a un puntero
        aux->siguiente = NULL;
        cout << "\nDato: " << aux->dato << endl;
    }
    return aux; //Cuando retorno aux, me retorna una direccion
}
 
