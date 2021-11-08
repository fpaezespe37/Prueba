#include <iostream>
using namespace std;

//Clase con dos atributos> entero y flotante, cadena
//Definicio dec la clase
class Prueba{
	private: 
		int entero;
		float flotante;
	protected: 
		char pCadena[81];
	public: 
		void leer_Entero();
		void leer_Flotante();
		void leerCadena();
		void escribirObjeto();
};

//Implementar metodos
void Prueba::leer_Entero(){
	cout<<"Ingrese un entero: ";
	cin>>entero;
	
}

void Prueba::leer_Flotante(){
	cout<<"Ingrese un flotante: ";
	cin>>flotante;
}

void Prueba::leerCadena(){
	cout<<"Ingrese una cadena: ";
	gets(pCadena);
	
}

void Prueba::escribirObjeto(){
	cout<<"Entero Ingresado: "<<entero<<endl;
	cout<<"Flotante Ingresado: "<<flotante<<endl;
	cout<<"Cadena Ingresado: "<<pCadena<<endl;
	
}

