#include <iostream> 
using namespace std;
#include <cstdlib>

class Numeros{
	

//int const 999 = 999;

public:
typedef float tLista[999];
	
	
	
void iniciarAleatorios(tLista);
void ordenarAleatorios(tLista);
void buscarNumero(tLista);
void imprimirOrdenados(const tLista);

};
	

void iniciarAleatorios(tLista lista){
	cout << "Asignando numeros aleatorios numeros aleatorios..." << endl;
	
	for (int i = 0; i < 999; i++){ 
		lista[i] = 1 + rand() % (2001 - 1);
	}
}

void ordenarAleatorios(tLista lista){
	float temporal;
	
	for (int i = 0;i < 999; i++){
		for (int j = 0; j< 999-1; j++){
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
	
	for (int i = 0; i < 999; i++) 
		cout << "Posicion: " << i+1 << " - Aletorio: " << lista[i] << endl;
}

void buscarNumero(tLista lista){
	int num;
	int vacio=0;
	int pos;
	cout << "Ingrese numero a buscar: ";
	cin >> num;
	for (int i = 0; i < 999; i++) 
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


