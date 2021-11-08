#include <iostream>
#include <string>
#include "Numeros.h"
using namespace std;

int const maximo = 999;
typedef float tLista[maximo];


void iniciarAleatorios(tLista);
void ordenarAleatorios(tLista);
void buscarNumero(tLista);
void imprimirOrdenados(const tLista);

void Menu()
{
	
	
	do
	{
		system("cls");
		cout<<"Seleccione la pila que desea llenar "<<endl;
		cout << "1. Generar Numeros: " << endl;
		cout << "2. Ordenar decreciente: " << endl;
		cout << "3. Ordenar crecientemente: " << endl;
		cout << "4. Preguntar numero: " << endl;
		cout << "0. Salir" << endl;
		cout << "Digite su opcion: ";
		cin >> opcionProducto;
		switch (opcionProducto)
		{
		case 1:
		{
			iniciarAleatorios(tLista lista);
			system("pause");
			break;
		}
		case 2:
		{
			ordenarAleatorios(tLista lista);
			system("pause");
			break;
		}
		case 3:
		{
			//push(pila3,golosina3);
			system("pause");
			break;
		}
		case 4:
			{
			imprimirOrdenados(const tLista lista)
			break;
			}
		
		case 0:
		{
			cout << "Salio con exito!" << endl;
			break;
		}
		default:
		{
			cout << "No se ingreso una opcion valida!" << endl;
			break;
		}
		}	
	} while (opcionProducto != 0);
}
