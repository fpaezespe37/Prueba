#include <iostream>
#include <math.h>
#include <ctype.h>

using namespace std;
struct Punto
{
	float x,y;
		
};

int menu()
{
	int opc;
	cout << "\nMenu Calculo de Distancia entre 2 puntos" << endl
		 << "99. Inicializar el archivo Puntos" << endl
		 << "1. Ingresar Puntos" << endl
		 << "2. Calcular distancia 2 puntos" << endl
		 << "3. Imprimir" << endl
		 << "0. Salir" << endl
		 << "Seleccione un opcion: ";
	cin >> opc;
	return opc;

}
//Leer las coordenadas de un punto que es pasado como puntero 
void leerXY(Punto* p)
{
	cout << "\n[X]: ";
	cin >> p->x;
	cout << "\n[Y]: ";
	cin >> p->y;
}

void imprimir(Punto* p, int n)
{
	for(int i=0; i<n; i++, p++)
	{
		cout << "\n" << i+1 <<": (" << p->x << ", " << p->y <<")";
	}
	cout << endl;
}

float calcularDistancia(Punto p1, Punto p2)
{
	float dist = 0;
	dist = sqrt(pow((p1.x - p2.x),2)+pow((p1.y - p2.y),2));
	return dist;
	
}

bool Continuar(char mensaje[])
{
	char ch;
	cout << mensaje;
	do
	{
		cin >> ch;
		ch = toupper(ch);
			
	}while(ch!='S'&&ch!='N');
	return(ch=='S'?true:false);
}

//FUNCIONES DE MANIPLACION DE ARCHIVOS
FILE *abrirArchivo(char *nombre, char *modo)
{
	FILE *F;
	//errno_r err;
	F = fopen(nombre, modo);
	if(F==NULL)
	{
		cout << "No se puede abrir el archivo" <<nombre<<endl;
		exit(1);
	}
	return F;
}

//Inicializar Archivo
void Inicializar(FILE *F, char *archivo, char *modo)
{
	char mensaje[] = "Desea continuar S/N";
	cout << "\n\Crear archivo: "<< archivo <<endl;
	cout << "\nLa informacion se perdera. "<< endl;
	if(Continuar(mensaje))
	{
		F = abrirArchivo(archivo, modo);
		fclose(F);
	}

}
//Guardar los elementos del arreglo de estructuras en disco
void guardar(FILE *F, char *nombre, Punto *p, int n)
{
	char modo[] = "rb+";
	cout << "\nGrabando datos en el archivo..." << endl;
	F =abrirArchivo(nombre, modo);
	fseek(F, 0, SEEK_END); //Buscar el ultimo bit del archivo
	for(int i = 0; i<n; i++, p++)
	{
		if(fwrite(p,sizeof(Punto),1,F)!=1)
			cout <<"\nERROR. No se pudo escribir en el archivo." << endl;	
	}
	fclose(F);
	
}

void imprimirPuntos(FILE *F, char *nombre, char *modo)
{
	Punto temp; 
	int ord= 0;
	cout << "\nLista de puntos registrados. " <<endl;
	F = abrirArchivo(nombre, modo);
	cout << "\nORD.\t[x]\t[y]" << endl;
	if(fread(&temp, sizeof(Punto),1,F)!=1) //Obtener el primer registro del archivo
		if(!feof(F))
			cout <<"\n ERROR. No se pudo leer el archivo" << endl; 
	while(!feof(F)) //Recorrer el archivo hsta encontrar eof
	{
		printf("%3d%10.2f%10.2f\n",++ord, temp.x, temp.y);
		if(fread(&temp, sizeof(Punto),1,F)!=1) //Obtener el primer registro del archivo
			if(!feof(F))
				cout <<"\n ERROR. No se pudo leer el archivo" << endl; 
	}	
	fclose(F);
}
