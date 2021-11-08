#include<iostream>
#include "paez1.h"
//Prueba Freddy Páez
#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int numero,opc;
    do{
        cout<<"INGRESO DE NUMEROS"<<endl;
        cout<<"1.Ingresar"<<endl;
		cout<<"0.salir"<<endl;
        cout<<"Elija una opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:{
            ImprimirNum(numero);
            break;
        }
        case 0:
            break;
            
        }
    }while(opc!=0);
	return 0;
}
