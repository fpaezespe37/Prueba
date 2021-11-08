//Aplicacion de POO en programa calculo de distancia enre dos puntos
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;
class ClaseSumar
{
		public:
		int p1, p2; 
		int MenuOptions(int opc);
		float SumarClase(float x,float y);
		int LeerPuntos(int p1, int p2);
		void AsignarValores(int Coordenadas[10][2], int p1, int p2, int cont);
		void imprimirArreglo(int Coordenadas[10][2], int cont);
		float CalcularDistancia(int Coordenadas[10][2], int p1, int p2);
	};
	
	int ClaseSumar::MenuOptions(int opc)
	{
		cout<<"\nCALCULO DE DISTANCIA ENTRE 2 PUNTOS: "<<endl;
		cout<<"1. Ingresar Puntos"<<endl
		<<"2. Calcular  distancia 2 puntos"<<endl
		<<"3. Imprimir"<<endl
		<<"4. Salir"<<endl
		<<"Seleccione una opcion: ";
	cin>>opc; 
	return opc;	
	}
	
	int ClaseSumar::LeerPuntos(int p1, int p2)
	{
		cout<<"\n[X]: "<<endl;
		cin>>p1;
		cout<<"\n[Y]: ";
		cin>>p2;
		return p1;
	
	return 0;
	}
	
	void ClaseSumar::AsignarValores(int Coordenadas[10][2], int p1, int p2, int cont)
	{
		Coordenadas[cont-1][0] = p1;
		Coordenadas[cont-1][1] = p2;
		;
	}
	
	void ClaseSumar::imprimirArreglo(int Coordenadas[10][2], int cont)
	{
		int i,j;
		for (i=0; i<cont; i++)
		{
     	cout<<" ("<<Coordenadas[i][0]<<", "<<Coordenadas[i][1]<<")"<<"\n";
		}
	}
	float ClaseSumar::CalcularDistancia(int Coordenadas[10][2], int p1, int p2)
{
	int x1,x2,y1,y2; 
	float dist=0;
	x1 = Coordenadas[p1-1][0];
	y1 = Coordenadas[p1-1][1];
	x2 = Coordenadas[p2-1][0];
	y2 = Coordenadas[p2-1][1];
    dist = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return dist;
}
