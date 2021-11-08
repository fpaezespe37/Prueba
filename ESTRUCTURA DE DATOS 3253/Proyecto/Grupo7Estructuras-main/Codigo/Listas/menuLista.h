#include <iostream>
#include "Lista.h"
#include "IngresaDato.h"

using namespace std;

Lista *lista = NULL;
Lista *list = new Lista;
void ingresoMenu();
void opcMenu();
void ingresoDato(int opc)
{
    system("cls");
    switch (opc)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;

    default:
        break;
    }
    ingresoMenu();
}

void eliminarDato(int opc)
{
    system("cls");
    switch (opc)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    default:
        break;
    }
    ingresoMenu();
}
void buscarDato(int opc)
{
    system("cls");
    switch (opc)
    {
    case 1:
        /* code */
        break;
    default:
        break;
    }
    ingresoMenu();
}
void imprimirLista(int opc)
{
    system("cls");
    switch (opc)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    default:
        break;
    }
    ingresoMenu();
}
void opcMenu(int opc) //Menu secundario de opciones, donde se muestran las diferentes variantes que cumple cada funcion
{

    int opc2;
    switch (opc)
    {
    case 1:
        system("cls");
        cout << "\t***** INGRESO DE DATO *****" << endl;
        cout << "\n1.Ingresar dato al inicio de la lista. " << endl;
        cout << "\n2.Ingresar dato al final de la lista. " << endl;
        cout << "\n3.Ingresar dato antes de la posicion dada. " << endl;
        cout << "\n4.Ingresar dato despues de la posicion dada. " << endl;
        cout << "\nA continuacion digite una opcion." << endl;
        cin >> opc2;
        switch (opc2)
        {
        case 1: //Llamada a subfuncion ingresar dato inicio
            ingresoDato(1);
            break;
        case 2: //Llamada a subfuncion ingresar dato final
            ingresoDato(2);
            break;
        case 3: //Llamada a subfuncion ingresar dato antes  de x posicion
            ingresoDato(3);
            break;
        case 4: //Llamada a subfuncion ingresar dato despues de x posicion
            ingresoDato(4);
            break;
        default:
            cout << "Dato erroneo.Vuelva a ingresar una opcion." << endl;
            system("pause");
            system("cls");
            opcMenu(1);
            break;
        }

        break;

    case 2:
        system("cls");
        cout << "\t***** ELIMINACION DE DATO *****" << endl;
        cout << "\n1.Eliminar dato inicial de la lista. " << endl;
        cout << "\n2.Eliminar dato final de la lista. " << endl;
        cout << "\n3.Eliminar dato antes de la posicion dada. " << endl;
        cout << "\n4.Eliminar dato despues de la posicion dada. " << endl;
        cout << "\n5.Eliminar dato en la posicion dada." << endl;
        cout << "\nA continuacion digite una opcion." << endl;
        cin >> opc2;
        switch (opc2)
        {
        case 1: //Llamada a subfuncion eliminar dato inicial
            eliminarDato(1);
            break;
        case 2: //Llamada a subfuncion eliminar dato final
            eliminarDato(2);
            break;
        case 3: //Llamada a subfuncion eliminar dato antes de x posicion
            eliminarDato(3);
            break;
        case 4: //Llamada a subfuncion eliminar dato despues de x posicion
            eliminarDato(4);
            break;
        case 5: //Llamada a subfuncion eliminar dato en x posicion
            eliminarDato(5);
            break;
        default:
            cout << "Dato erroneo.Vuelva a ingresar una opcion." << endl;
            system("pause");
            system("cls");
            opcMenu(2);

            break;
        }
        break;

    case 3:
        system("cls");
        cout << "\t***** BUSCAR DATO *****" << endl;
        cout << "\n1.Buscar dato en la posicion dada de la lista. " << endl;
        cout << "\nA continuacion digite una opcion." << endl;
        cin >> opc2;

        switch (opc2)
        {
        case 1: //Llamada a funcion buscar dato en x posicion
            buscarDato(1);
            break;

        default:
            cout << "Dato erroneo.Vuelva a ingresar una opcion." << endl;
            system("pause");
            system("cls");
            opcMenu(3);

            break;
        }
        break;

    case 4:
        system("cls");
        cout << "\t***** IMPRIMIR *****" << endl;
        cout << "\n1.Imprimir lista completa. " << endl;
        cout << "\n2.Imprimir sumatoria, promedio y moda de los datos de la lista. " << endl;
        cout << "\nA continuacion digite una opcion." << endl;
        cin >> opc2;

        switch (opc2)
        {
        case 1: //Llamada a subfuncion imprimir lista
            imprimirLista(1);
            break;

        case 2: //Llamada a funcion imprimir de las operaciones de datos de la lista
            imprimirLista(2);
            break;

        default:
            cout << "Dato erroneo.Vuelva a ingresar una opcion." << endl;
            system("pause");
            system("cls");
            opcMenu(3);
            break;
        }
        break;

    default:
        break;
    }
}

void ingresoMenu() //Menu principal de opciones, donde se muestran las funciones principales para desarrollar en la lista
{
    int opc;
    cout << "\t******** GRUPO #7 ********" << endl;
    cout << "\t***** BIENVENIDO AL MENU PRINCIPAL*****" << endl;

    cout << "\n1.Ingresar dato. " << endl;
    cout << "2.Eliminar dato. " << endl;
    cout << "3.Buscar dato. " << endl;
    cout << "4.Imprimir lista. " << endl;
    cout << "0.Salir.\n"
         << endl;
    cout << "\nA continuacion digite una opcion." << endl;

    cin >> opc;
    switch (opc)
    {
    case 1: //Llamada a submenu ingresar datos
        opcMenu(1);
        break;
    case 2: //Llamada a submenu ingresar datos
        opcMenu(2);
        break;
    case 3: //Llamada a submenu ingresar datos
        opcMenu(3);
        break;
    case 4: //Llamada a submenu ingresar datos
        opcMenu(4);
        break;
    case 0: //Fin de programa
        break;

    default:
        cout << "Dato erroneo.Vuelva a ingresar una opcion." << endl;
        system("pause");
        system("cls");
        ingresoMenu();
        break;
    }
}