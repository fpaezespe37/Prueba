//Informacion 
//Clase Persona, nombre, sexo, sueldo 

#include <string.h>
#include <iostream>
using namespace std;

class Persona
{
	private: 
		char *nombre;
		int sexo; 
		float sueldo; 
	public: 
		Persona(char n[], int s, float suel);
		~Persona();
		Persona &operator=(const Persona &c)
		{
			if(this!=&c)
			{
				nombre = new char[strlen(n)+1];
				strcpy(nombre, n);
				sexo = s;
				sueldo = suel; 
			}	
			return *this;
		} 
		bool operator>(const Persona, &d)const 
		{
			return strcmp(nombre, d.nombre)>0;
		}
		bool operator<=(const Persona, &d)const 
		{
			return strcmp(nombre, d.nombre)<=0;
		}
		bool operator!=(const Persona, &d)const 
		{
			return strcmp(nombre, d.nombre);
		}
		bool operator<(const Persona, &d)const 
		{
			return strcmp(nombre, d.nombre)<0;
		}
}

Persona::Persona(char *n, int s, float suel)
{
	nombre = new char[strlen(n)+1];
	strcpy(nombre, n);
	sexo = s;
	sueldo = suel; 
};

~Persona::Persona()
{
	delete[] nombre;
}

ostream& operator << (ostream &os, Persona a)
{
	os << a.nombre << "\t";
	if(a.sexo==1)
		cout << "Hombre";
	else 
		cout << "Mujer";
	os<<a.sueldo<<endl;
	return os;
}
