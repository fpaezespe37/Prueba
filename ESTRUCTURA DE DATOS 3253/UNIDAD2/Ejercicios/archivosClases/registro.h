#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

class Registro
{
	private:
		char referencia [31];
		float precio;
	public:
		Registro();
		void almacenar(char *, float);
		char *obtenerReferencia(){return referencia;}
		float obtenerPrecio(){return precio;}
		friend ostream &operator <<(ostream &ostreamA, Registro &registroA);
		
};


//Implementacion metodos de la clase Registro
Registro::Registro()
{
	for(int i = 0; i < 31; i++)
	{
		referencia[i] = '\0';
	}
	precio = 0;
}

void Registro::almacenar(char *referenciaA, float precioA)
{
	strcpy(referencia, referenciaA);
	precio = precioA;
}
//Implementar el sobrecarga del operador <<
ostream &operator <<(ostream &ostreamA, Registro &registroA)
{
	ostreamA << setiosflags(ios::fixed); //Formato ijo 
	ostreamA << setiosflags(ios::left) //Justificar izquierda
			 << setw(32)				//Determinar el ancho de cadenas
			 << setfill('.')			//Caracter de relleno
			 << registroA.obtenerReferencia() //Escribe referencia de producto
			 << resetiosflags(ios::left) //Suprimiendo la justificacion
			 << setw(10)				  // Definir ancho precio 
			 << setprecision(2)		  // Fijar el formato del flotantte a 2 decimas
			 << registroA.obtenerPrecio() << endl;
	return ostreamA;		 
}			  
//Interfaz
class BaseDatos: private fstream
{
	private:
		Registro registroDatos;
		char nombre[20]; //nombre del archivo
		void escribir(); //Escribir registros en el archivos
	public:
		BaseDatos(char *nombreA='\0');
		char *obtenerNombre(){return nombre;}
		int crearNuevo(); //Crear un archivo
		int agregar(); //Agregar registros al archivo
		int actualizar(); //Actualizar un registro
		int visualizar(); //Leer el archivo
};

//Implementar metodos de la Clase BaseDatos
BaseDatos::BaseDatos(char *nombreA)
{
	if(!nombreA)
		strcpy(nombre, "dato00._xx"); //Se crea el objeto sin argumentos 
	else
		strcpy(nombre, nombreA); 
}

int BaseDatos::crearNuevo()
{
	open(nombre, ios::out|ios::binary);
	if(fail() || bad()) // Validacion de creacionn del archivo 
		return 0;
	escribir();
	close();
	return 1;
}

int BaseDatos::agregar()
{
	open(nombre, ios::app|ios::out|ios::binary); //apend
	if (fail() || bad())
		return 0;
	escribir();
	close();
	return 1;
}

void BaseDatos::escribir()
{
	int tamanioA = sizeof(registroDatos);
	char referenciaA[30];
	float precioA = 0;
	
	//Puntero de archivo al final
	seekp(0L, ios::end);
	cout << "\Ingrese Datos. Para finalizar digite * en la referencia\n";
	for(;;)
	{
		cout <<"\nReferencia: "; 
		cin >>referenciaA;
		if(!strcmp(referenciaA, "*"))
			break;
		cout << "\nPrecio: ";
		fflush(stdin);
		cin >> precioA;
		registroDatos.almacenar(referenciaA, precioA); //asginar los datos al registro 
		write((const char*)&registroDatos,tamanioA);
		
	}
}
int BaseDatos::visualizar()	
{
	open(nombre, ios::in|ios::binary);
	if(fail()||bad())
		return 0;
	
	int tamanioA = sizeof(registroDatos);
	while(read((char*)&registroDatos, tamanioA))
	{
		cout << registroDatos;
	}
	system("pause");
	close();
	return 1;
}
