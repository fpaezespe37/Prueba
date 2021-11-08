#include <iostream>
#include"recoDato.h"


#include "Funciones.h"

/* run this pr ogram using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	struct Persona dato;
	listaSimples* Lista = NULL;
	nodo* e = NULL;
	int opc; 
	
	
	do
	{
		opc =menu();
		switch(opc)
		{
			case 1:{//Agregar persona al inicio 
				cout << "Ingrese el codigo del producto: ";
				cin >> dato;
				Lista = agregarNodoAlInicio(Lista, dato);
			break;
			}
			case 2:{

				imprimirLista(Lista);
				break;
	
			}
			case 3:{ //ImprimirLista
			eliminarUltimo(Lista);
				break;
			}
			case 4:{ //Imprimir listado hombres
				cout << "\nBuscar Articulo: ";
            cin >> x;
            e = buscarNodo(Lista, x);
            if (e != NULL)
            {
                cout << "\nArticulo encontrado: " << e->dato << endl;
            }
            else
            {
                cout << "\nArticulo no encontrado" << endl;
            }
            system("pause");
            band = 1;
    
				break;
			}
			case 5:{
				
				//e = buscarMayor(Lista);
				//cout <<e->dato;
				break;
			}
			case 0:{
				
				break;
			}
			default:{
				
				break;
			}
		}
	}while(opc !=0);
		
		
	
	return 0;
}
