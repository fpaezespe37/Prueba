#include <iostream>
#include <stdlib.h>
using namespace std;

struct Cola
{
	int frente; 
	int final;
	int max;
	int *arreglo;
};

struct Cola* crearCola(int max) 
{
	cout<<"\nCrear cola con "<<max<<" elementos. "<<endl;
	struct Cola* cola =(struct Cola*)malloc(sizeof(struct Cola)) ;
	cola->max=max;
	cola->frente=-1;
	cola->final=-1;
	cola->arreglo = (int*)malloc(cola->max*sizeof(int));
	return cola;	
}
bool estaLlena(struct Cola* cola){
	if((cola->frente==0&&cola->final==cola->max-1)||(cola->final+1==cola->frente)){
		return true;		
	}
	return false;
}
bool estaVacia(struct Cola* cola)
{
	if(cola->frente==-1 && cola->final==-1)
	{
		return true;
	}
	return false;
}

void encolar(struct Cola* cola,int valor)
{
	if(estaLlena(cola))
	{
		cout<<"\n Cola llena"<<endl;
	}
	else
	{
		//Actualizar el subindice
		if(cola->final==cola->max-1) //Si final llego al maximo de cola,
		{
			cola->final=0;
		}
		else
		{
			++cola->final;
		}
		cola->arreglo[cola->final]=valor;
		if(cola->frente==-1)
			++cola->frente;
		cout<<"\nSe encolo: "<<cola->arreglo[cola->final]<<endl;
	}
}

int desencolar(struct Cola* cola)
{
	int c;
	if(estaVacia(cola))
	{
		cout<<"\n Cola llena"<<endl;
	}
	else
	{
		c = cola->arreglo[cola->frente];
		cout<<"Posicion: "<<cola->frente;
		if(cola->frente==cola->final)//Si solo queda un elemento en la cola
		{
			cola->frente=-1;
			cola->final=-1;
		}
		else{
			if(cola->frente==cola->max-1)
				cola->frente=0;
			else
				++cola->frente;
		}
	}
	return c;
}

void imprimir(struct Cola* cola)
{
	for(int i=cola->frente;i<=cola->final;i++)
	{
		cout<<"\n"<<i<<": "<<cola->arreglo[i];
	}
}
