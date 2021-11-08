#include <iostream>
#include <string>

using namespace std;

class Persona{
private:
    string nombre;
    int    sexo;
    double sueldo;
public:
    Persona(){
        nombre = "";
        sexo = 0;
        sueldo = 0.0;
    }
    string getNombre(){
        return nombre;
    }
    void setNombre(string nnombre){
        nombre = nnombre;
    }
    int getSexo(){
        return sexo;
    }
    void setSexo(int nsexo){
        sexo = nsexo;
    }
    double getSueldo(){
        return sueldo;
    }
    void setSueldo(double nsueldo){
        sueldo = nsueldo;
    }
    void leerDatos(){
        string nnombre, napellido;
        cout << "\nINGRESO DE DATOS" << endl;
        cout << "Nombre:   "; cin >> nnombre;
        cout << "Apellido: "; cin >> napellido;
        cout << "Sexo:     "; cin >> sexo;
        cout << "Sueldo:   "; cin >> sueldo;
        nombre = nnombre+" "+napellido;
    }
    void mostrarDatos(){
        string nsexo = sexo==1?"HOMBRE":"MUJER";
        cout << "Nombre:   " << nombre << endl;
        cout << "Sexo:     " << nsexo << endl;
        cout << "Sueldo:   " << sueldo << endl;
    }
};
