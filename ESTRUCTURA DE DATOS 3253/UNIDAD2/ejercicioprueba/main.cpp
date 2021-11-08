#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int const maximo = 999;
typedef float tLista[maximo];

void iniciarAleatorios(tLista);
void ordenarAleatorios(tLista);
void buscarNumero(tLista);
void imprimirOrdenados(const tLista);



int main() {

//	iniciarAleatorios(lista);
//	ordenarAleatorios(lista);
//	imprimirOrdenados(lista);
//	buscarNumero(lista);
//	system("PAUSE");
int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        tLista lista;
	
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Lleenar lista: " << endl;
        cout << "2. Imprimir decreciente " << endl;
        cout << "3. Buscar numero" << endl;
        cout << "4. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                
				// Lista de instrucciones de la opción 1                
                iniciarAleatorios( lista);
                system("pause>nul"); // Pausa
                break;
                
            case 2:
                // Lista de instrucciones de la opción 2                
                imprimirOrdenados( lista);
                system("pause>nul"); // Pausa
                break;
                
            case 3:
                // Lista de instrucciones de la opción 3                
                buscarNumero( lista);
                system("pause>nul"); // Pausa            
                break;
                
            
        }        
    } while (opcion != 4);            // En vez de 5 pones el número de la opción de SALIDA        
    return 0;
}
void iniciarAleatorios(tLista lista){
	cout << "Asignando numeros aleatorios numeros aleatorios..." << endl;
	
	for (int i = 0; i < maximo; i++){ 
		lista[i] = 1 + rand() % (2001 - 1);
	}
}

void ordenarAleatorios(tLista lista){
	float temporal;
	
	for (int i = 0;i < maximo; i++){
		for (int j = 0; j< maximo-1; j++){
			if (lista[j] < lista[j+1]){ 
			temporal = lista[j]; 
			lista[j] = lista[j+1]; 
			lista[j+1] = temporal;
			}
		}
	}
}

void imprimirOrdenados(const tLista lista){
	cout << "Ordenamiento decrecientemente..." << endl;
	
	for (int i = 0; i < maximo; i++) 
		cout << "Posicion: " << i+1 << " - Aletorio: " << lista[i] << endl;
}

void buscarNumero(tLista lista){
	int num;
	int vacio=0;
	int pos;
	cout << "Ingrese numero a buscar: ";
	cin >> num;
	for (int i = 0; i < maximo; i++) 
	{
			if(num==lista[i]){
				vacio = 1;
				pos = i;
			} 
			
	} if(vacio==1){
		cout << "Se encuentra en la lista en la posicion: " << pos; 
	}else{
		cout << "EL numero no esta en la lista ";
	}
	
	
}
