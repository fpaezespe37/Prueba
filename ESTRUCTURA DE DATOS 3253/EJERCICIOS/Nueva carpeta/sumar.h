//Aplicacion de POO en programa calculo de distancia enre dos puntos
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

class ClaseSumar
{
		public:
		
		void SumarClase(float x,float y);
	};
	
	void ClaseSumar::SumarClase(float x, float y)
		{			
			float resultado;
			resultado = x+y;
			cout<<"Resultado: "<<resultado;
			//return resultado;
		}



