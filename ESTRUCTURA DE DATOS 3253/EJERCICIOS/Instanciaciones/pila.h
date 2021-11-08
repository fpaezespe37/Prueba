#include <iostream>

using namespace std;

struct Pila 
{
	int tope;
	int max;
	int* arreglo;
};

Pila* crearPila(int max)
{
	cout << "\n Crear pila con " << max << " elementos" << endl;
	Pila* pila = new Pila; //Reserva de memoria para cabecera de la pila 
	pila->max=max;
	pila->tope=-1;
	pila->arreglo = new int [max];
	return pila;
}

bool estaLlena(Pila* pila)
{
	if(pila->tope==pila->max-1)
		return true;
	return false;
}

bool estaVacia(Pila* pila)
{
	if(pila->tope==-1)
		return true;
	return false;
}

void push(Pila* pila, int dato)\
{
	if(estaLlena(pila))
	{
		cout << "\nPila llena. " << endl;
	}
	else
	{
		++pila->tope;
		pila->arreglo[pila->tope]=dato;
		cout << "\Se agrego: " <<pila->arreglo[pila->tope]<<endl;
		
	}
}

void pop(Pila* pila)
{
	if(estaVacia(pila))
	{
		cout << "Esta llena. " << endl; 
	}
	else
	{
		cout << "\nSe elimino: " << pila->arreglo[pila->tope] << endl;
		--pila->tope;	
	}
}

void imprimir(Pila* pila)
{
	if(pila !=NULL)
	{
		for(int i=pila->tope;i>=0;i--)
			cout << "\n" << i << ": " << pila->arreglo[i];
	}
}

