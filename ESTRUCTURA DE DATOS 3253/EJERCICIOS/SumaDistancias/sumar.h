//Aplicacion de POO en programa calculo de distancia enre dos puntos
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

class ClaseSumar
{
		public:
		int MenuOptions(int opc, int op);
		float SumarClase(float x,float y);
		int LeerPuntos(int p1, int p2, int p3);
		int AsignarValores(int Coordenadas, int p1, int p2)
	};
	
	float ClaseSumar::SumarClase(float x, float y)
		{			
			float resultado;
			resultado = x+y;
			return resultado;
		}
		
	int ClaseSumar::MenuOptions(int opc, int op)
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
	
	int ClaseSumar::LeerPuntos(int p1, int p2,int p3)
	{
		cout<<"\n[X]: "<<endl;
		cin>>p1;
		cout<<"\n[Y]: ";
		cin>>p2;
		return p1;
	
	return 0;
	}
	
	int ClaseSumar::AsignarValores(int Coordenadas, int p1, int p2)
	{
		/*for (i=0; i<4; i++)
		{
     Coordenadas[i][j] = 0;
		}
		for (j=0; j<2; j++)
		{
     Coordenadas[i][j] = 0;
		}*/
		return 0;
	}
	
	



