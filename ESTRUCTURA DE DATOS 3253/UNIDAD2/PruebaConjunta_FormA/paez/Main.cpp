/*Se dispone de un árbol binario de búsqueda de elementos de tipo int. Escribir funciones que calculen:
a) La suma de sus elementos.
b) La suma de sus elementos que son múltiplos de 3
Para implementar las funciones debe programar las opciones de menú que permitan agregar nodos e imprimir
los nodos de forma ordenada ascendente.*/
 
 /*-------------------------------------------------------------------------------------------------------------*/
 /*Nombre: Freddy Paez - NRC 3253
 Prueba Forma A*/ 

#include <iostream>
#include <stdio.h>
#include "Arbol.h"
using namespace std;

Nodo* arbol = NULL; 

void subMenu(){

    Arbol objArbol;
    int subOpcion = 0;

    while (subOpcion != 4){
    
        cout << "\n 1. Preorden";
        cout << "\n 2. Inorden";
        cout << "\n 3. Postorden";
        cout << "\n 4. Regresar";
        cout << "\n\nDigite una opcion: ";        
        cin >> subOpcion;

        system("cls");
        if( subOpcion == 1 ){
            
            objArbol.preOrden(arbol);

            cout << endl;
            system("pause");
            system("cls");
        } 
        else if(subOpcion == 2){

            objArbol.inOrden(arbol);

            cout << endl;
            system("pause");
            system("cls");
        }
        else if(subOpcion == 3){

            objArbol.postOrden(arbol);

            cout << endl;
            system("pause");
            system("cls");
        }
    }
}


void menu(){


    Arbol objArbol;
    int contador = 0, opcion = 0, dato = 0;

    while(opcion != 7){

        cout << "\n 1. Insertar nodo";
        cout << "\n 2. Mostrar arbol";
        cout << "\n 3. Buscar en el arbol";
        cout << "\n 4. Impresion de arboles";
        cout << "\n 5. Sumatoria";
        cout << "\n 6. Sumatoria de los multiplos de 3";
        cout << "\n 7. Salir";
        cout << "\n\nDigite una opcion: ";
        cin >> opcion;

        system("cls");

        if(opcion == 1){

            cout << "Ingrese un dato: ";
            cin >> dato;

            objArbol.insertarNodo(arbol, dato);

            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 2){

            cout << "A R B O L" << endl;

            objArbol.mostrar(arbol, contador);
            
            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 3){

            cout << "Digite un elemento a buscar: ";
            cin >> dato;

            if(objArbol.buscar(arbol, dato) == true){
                cout << "Elemento " << dato << " encontrado dentro del arbol" << endl; 
            }
            else{
                cout << "Elemento no pertenese al arbol";
            }

            cout << endl;
            system("pause");
            system("cls"); 
        }
        else if(opcion == 4){

            subMenu();

            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 5){

            cout << "Respuesta: " << objArbol.sumatoria(arbol);

            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 6){
            int c = 3;
            cout << "Respuesta: " << objArbol.sumatoriaTres(arbol,c);

            cout << endl;
            system("pause");
            system("cls");
        }
        

    }

}

int main(){

    menu();

    cout << endl;
    return 0;
}

