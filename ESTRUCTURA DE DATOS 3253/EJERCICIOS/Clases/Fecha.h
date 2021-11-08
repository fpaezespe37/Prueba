class Fecha{
	private:
		int anio,mes,dia;
	public:
		//Constructor
		Fecha(); //Por defecto
		Fecha(int a, int m, int d);
		void escribirFecha();
};

Fecha::Fecha()
{
	anio = 1990;
	mes = 1;
	dia = 1;
	
}

Fecha::Fecha(int a, int m, int d){
	anio = a;
	mes = m;
	dia = d;
}

void Fecha::escribirFecha(){
	cout<<"Fecha: "<<dia<<"/"<<mes<<"/"<<anio;
}

