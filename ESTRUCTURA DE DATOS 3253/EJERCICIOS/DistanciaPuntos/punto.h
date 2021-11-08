#include <iostream>
#include <math.h>
using namespace std;

struct Punto{
	float x,y;
};

//Menu de opciones 

int menu(){
	int opc;
	cout<<"\nCALCULO DE DISTANCIA ENTRE 2 PUNTOS: "<<endl;
	cout<<"1. Ingresar Puntos"<<endl
		<<"2. Calcular  distancia 2 puntos"<<endl
		<<"3. Imprimir"<<endl
		<<"4. Salir"<<endl
		<<"Seleccione una opcion: ";
	cin>>opc; 
	return opc;	
}


void leerXY(Punto *p)
{
	cout<<"\n[X]: ";
	cin>>p->x;
	cout<<"\n[Y]: ";
	cin>>p->y;
}

void imprimir(Punto *p, int n)
{
	for(int i=0;i<n;i++,p++){
		cout<<endl<<i+1<<": ("<<p->x<<","<<p->y<<")";
	}
	cout<<endl;
}	

float calcularDistancia(Punto p1,Punto p2)
{
    float dist=0;
    dist = sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
    return dist;
}
