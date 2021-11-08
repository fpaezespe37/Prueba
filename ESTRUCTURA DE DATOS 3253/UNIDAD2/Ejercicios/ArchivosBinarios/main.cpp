#include <iostream>
#include <stdlib.h>
#include "punto.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int opc,tam=0; 
	Punto *puntos = NULL;  
	FILE* F = NULL;
	char archivo[] ="PUNTOS"; 
	char modowb[] = "wb";
	char modorb[] = "rb";
	 
	do
	{
		system("cls");
		opc = menu();
		switch(opc)
		{
			case 99:
				{
					Inicializar(F, archivo, modowb);
					
					break;
				}
			case 1:
				{ //Ingresar datos al arreglo dinamico
				
					char mensaje [] = "\nDesea Ingresar otro punto? (S/N): ";
					cout << "\nIngrese puntos." << endl;
					do
					{
						puntos = (Punto *)realloc(puntos, (tam+1)*sizeof(Punto));
						if(puntos!=NULL)
						{
							leerXY(&puntos[tam]);
						 	tam++;
						}
					}while(Continuar(mensaje));
					char mensaje1 []="\nDesea grabar los datos en el archivo? S/N: ";
					if(Continuar(mensaje1))
					{
						guardar(F, archivo, puntos, tam);
						free(puntos);
						puntos = NULL;
						tam = 0;
					}
					break; 
				}
			case 2:
				{
					break;
				}
			case 3:
				{
					imprimirPuntos(F, archivo, modorb);
					break;
				}
			case 0:
				{
					break;
				}
			default:
				{
					cout << "\n ERROR opcion incorrecta" << endl;
				}		
		}
	}while(opc!=0);
	return 0;
}
