#include <iostream>
#include "Lista.h"
#include "IngresaDato.h"

using namespace std;

Lista *lista = NULL;
Lista *list = new Lista;
Nodo *nodo = new Nodo;

void ingresoMenu();
void opcMenu();
void ingresoDato(int opc)
{
    system("cls");
    switch (opc)
    {
    case 1:
        lista = list->agregarNodoInicio(lista, recoDato());
        break;
    case 2:
        lista = list->agregarNodo(lista, recoDato());
        break;
    case 3:
        list->imprimirLista(lista);
        lista = list->insertarAntes(lista, recoDato(), recoPos());

        break;
    case 4:
        list->imprimirLista(lista);
        lista = list->insertarDespues(lista, recoDato(), recoPos());

        break;

    default:
        break;
    }
    ingresoMenu();
}
