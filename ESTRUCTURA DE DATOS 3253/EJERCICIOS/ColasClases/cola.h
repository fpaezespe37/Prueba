#include <iostream>
using namespace std;

class Nodo{
	private:
		int valor;
		Nodo* sig;
	public:
		Nodo(int v, Nodo* s=NULL)
		{
			valor = v;
			sig =s; 
		}
	friend class Cola;
};
typedef Nodo* pNodo;

class Cola {
	private:
		pNodo pri;
		pNodo ult;
	public:
		Cola():pri(NULL),ult(NULL){}
		~Cola();
		void encolar(int v);
		int desencolar();
};
Cola::~Cola(){
	while(pri)
	{
		desencolar();
	}
}
void Cola::encolar(int v)
{
	pNodo nuevo;
	nuevo = new Nodo(v);
	//si la cola no esta vacia
	if(ult)
		ult->sig=nuevo;
	//Objeto ultimo es el elemento nuevo
	ult=nuevo;
	//si la cola esta vacia
	if(!pri)
		pri=nuevo;	
}

int Cola::desencolar(){
	pNodo nodo;
	int v;
	nodo = pri;
	if(!nodo)
	{
		cout<<"\n Cola Vacia."<<endl;
		return 0;
	}
	//Asignar a pri la direccion del siguiente nodo
	pri=nodo->sig;
	v = nodo->valor;
	delete nodo;
	//Si se desencolo el ultimo elemento
	if(!pri)
		ult=NULL;
	return v;
}
