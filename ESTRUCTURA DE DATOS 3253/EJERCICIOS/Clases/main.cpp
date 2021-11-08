#include <iostream>
#include "ClassPrueba.h"
#include "Fecha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Fecha fechaDefecto;
	Fecha fecha(2020,12,9);
	
	cout<<"Fecha por defecto: ";
	fechaDefecto.escribirFecha();
	
	cout<<"Fecha con parametros: ";
	fecha.escribirFecha();
	
	
	Prueba objeto1;
	
	objeto1.leer_Entero();
	objeto1.leer_Flotante();
	objeto1.leerCadena();
	objeto1.escribirObjeto();
	
	
	
	
	return 0;
}
