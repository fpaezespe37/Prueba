#include<iostream>
using namespace std;

struct Nodo{
	int dato;
	struct Nodo* sig; // autoreferencia
	
};
//Cabecera de la lista
struct Lista{
	struct Nodo* pri;
	struct Nodo* ult;
};
// crear el nodo en menoria 
Nodo* crear_nodo(int dato)
{
	Nodo* e = new Nodo; // Reserva memoria para 1 nodo
	if (e != NULL){
		e->dato = dato;
		e->sig = NULL;
		cout<<"\nNodo: "<<e->dato;
	}
	return e;
};
struct Lista* agregar_nodoIn(struct Lista* L, int dato)//final
{
	Nodo* e = crear_nodo(dato);
	if(e != NULL)
	{
		
		if(L != NULL)//Si la lista no esta vacia
		{
			cout<<"\nLista no vacia, se agrega nodo al final"<<endl;
			L->ult->sig = e; //Hago que el ultimo nodo de la lista apunte al nuevo nodo
			L->ult = e; // Hago que el puntero ult de la cabercera apunte al nuevo	
		}	
		else 
		{
			cout<<"\n Lista vacia, se agrega primer elemento"<<endl;
			Lista *l = new Lista;
			l->pri = e;
			l->ult = e;
			return l;
		} 	
		
	}
	else //La lista esta vacia
	{
		return NULL;
	}
}
/*

*/

void imprimir_lista(Lista* L)
{
	int i=0;
	if(L != NULL)
	{
		cout<<"Lista completa\n";
		Nodo *e = L->pri;
		do{
			i++;
			cout<<"Nodo "<<i<<": "<<e->dato<<endl;
			e = e->sig;// para moverme por la lista	
		}while(e != NULL);
	}
	else{
		cout<<"No contiene datos"<<endl;
	}
	
}

struct Lista* eliminarNodo(Lista *L)
{
	int opc; 
	if(L !=NULL)
	{
		Nodo *e = L->pri;
		cout<<"\nSe eliminara el dato -> "<<e->dato<<"Desea Continuar 1. SI / 0. NO?\n";
		cin>>opc;
		if(opc==1)
		{
			L->pri = e->sig;
			delete e;
			if(L->pri == NULL)
			{
				delete L; 
				L = NULL;
				cout<<"Se elimino el ultimo elemento de la lista. "<<endl;
					
			}	
		}		
	}
	else
			cout<<"La lista esta vacia.";
			
	return L;
}

struct Nodo* buscarDesorden(Lista *L, int x)
{
	Nodo *e = NULL;
	if(L!=NULL)
	{
		e=L->pri;
		while(e!=NULL && e->dato!=x)
		{
			e=e->sig;
		}
	}
	return e;
}

