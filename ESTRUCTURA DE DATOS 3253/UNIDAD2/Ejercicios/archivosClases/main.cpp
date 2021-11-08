#include <iostream>
#include "registro.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu()
{
	int opc;
	cout << "\n **** Registro de Productos ****"
		 << "\n1. Nuevo archivo"
		 << "\n2. Anadir producto"
		 << "\n3. Actualizar producto"
		 << "\n4. Visualizar productos"
		 << "\n0. Salir"
		 << "\nEscoja una opcion: ";
	cin  >> opc;
	return opc; 
}	
int main(int argc, char** argv) {
	char nombre [20];
	
	int opc;
	
	cout << "\nNombre del archivo: ";
	cin >> nombre;
	BaseDatos datos(nombre);
	do
	{
		system("cls"); 
		opc = menu(); 
		switch(opc)
		{
			case 1:
				{
					//Crear archivo desde objeto
					if(!datos.crearNuevo())
						cout << "No se puede abrir el archivo: " << datos.obtenerNombre();
					break;
				}
			case 2:
				{
					if(!datos.agregar())
						cout << "No se puede abrir el archivo: " << datos.obtenerNombre();
					break;
				}
			case 3:
				{
				break;
				}
			case 4:
				{
					if(!datos.visualizar())
						cout << "No se puede abrir el archivo: " << datos.obtenerNombre();
					break;
				}
			case 0:
				{
					cout << "Adios";    
					break;
				}
			default:             
				{
					cout << "\nERROR. Opcion Incorrecta";
				}		
		}
	}while(opc!=0);
	
	
	
	return 0;
}
