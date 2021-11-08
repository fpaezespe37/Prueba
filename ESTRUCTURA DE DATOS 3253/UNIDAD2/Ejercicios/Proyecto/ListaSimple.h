#include <iostream>
#include <cstring>
#include <string>
#include "Ordenamiento.h"
#include "Hash.h"

using namespace std;

class Nodo {
private:
    Persona persona;
    Nodo* siguiente;
public:
    Persona getPersona(void){
        return persona;
    }
    void setPersona(Persona npersona){
        persona = npersona;
    }
    Nodo* getSiguiente(void){
        return siguiente;
    }
    void setSiguiente(Nodo* nsiguiente){
        siguiente = nsiguiente;
    }
};

class ListaSimple{
private:
    Nodo* actual;
    int num_nodos;
public:
    ListaSimple(){
        actual = NULL;
        num_nodos = 0;
    }
    int getNumNodos(){
        return num_nodos;
    }
    bool esVacio(){
        if(actual == NULL)
            return true;
        else
            return false;
    }
    void insertarInicio(Persona npersona){
        if(esVacio()){
            actual = new Nodo();
            actual->setPersona(npersona);
            actual->setSiguiente(NULL);
            num_nodos++;
        }else{
            Nodo *aux = new Nodo();
            aux->setPersona(npersona);
            aux->setSiguiente(actual);
            actual = aux;
            num_nodos++;
        }
    }
    void eliminarFinal(){
        Nodo *aux = new Nodo();
        Nodo *anterior = new Nodo();
        aux = actual;

        if(!esVacio()){
            while(aux->getSiguiente()!=NULL){
                anterior = aux;
                aux = aux->getSiguiente();
            }
            anterior->setSiguiente(NULL);
            num_nodos--;
        }
        else
            cout << "\nLa lista esta vacia" << endl;
    }
    void buscarMayorSueldo(){
        Persona auxp;
        Nodo *aux = new Nodo();
        aux = actual;
        auxp = aux->getPersona();

        if(!esVacio()){
            while(aux!=NULL){
                if(auxp.getSueldo()<aux->getPersona().getSueldo()){
                    auxp = aux->getPersona();
                }
                aux = aux->getSiguiente();
            }
            cout << "\nLa persona con mayor sueldo es: " << endl;
            auxp.mostrarDatos();
        }
        else
            cout << "\nLa lista esta vacia" << endl;
    }
    void imprimirLista(int nsexo){
        Nodo *aux = new Nodo();
        aux = actual;
        int contador = 1;
        bool bandera = true;
        string tab = "\t";

        if(!esVacio()){
            while(aux != NULL){
                    if(nsexo == 1 && bandera){
                        cout << "                   HOMBRES                   " << endl;
                        cout << "_____________________________________________" << endl;
                        cout << " Ord.     | Nombre            | Sueldo       " << endl;
                        cout << "_____________________________________________" << endl;
                        bandera = false;
                    }
                    if(nsexo == 2 && bandera){
                        cout << "                   MUJERES                   " << endl;
                        cout << "_____________________________________________" << endl;
                        cout << " Ord.     | Nombre            | Sueldo       " << endl;
                        cout << "_____________________________________________" << endl;
                        bandera = false;
                    }
                    if(aux->getPersona().getSexo() == nsexo){
                        cout << " " << contador << "\t    " << aux->getPersona().getNombre();
                        if(aux->getPersona().getNombre().length() >11) cout << tab;
                        else cout << tab << tab;
                        cout << aux->getPersona().getSueldo() << endl;
                        cout << "_____________________________________________" << endl;
                        contador++;
                    }
                aux = aux->getSiguiente();
            }
        } else
            cout << "\nLa lista esta vacia" << endl;
    }
    void ordenamientoPorBurbuja(){
        Nodo *aux = new Nodo();
        Nodo *siguiente = new Nodo();
        aux = actual;
        Persona t;

        while(aux->getSiguiente() != NULL){
            siguiente = aux->getSiguiente();

            while(siguiente!=NULL){
                    string nombre1 = aux->getPersona().getNombre();
                    string nombre2 = siguiente->getPersona().getNombre();
                if(strcmp(nombre1.c_str(), nombre2.c_str())>0){
                    t = siguiente->getPersona();
                    siguiente->setPersona(aux->getPersona());
                    aux->setPersona(t);
                }
                siguiente = siguiente->getSiguiente();
            }
            aux = aux->getSiguiente();
            siguiente = aux->getSiguiente();
        }
    }
    void listaAArreglo(Persona lPersona[]){
        int i = 0;
        Nodo *aux = new Nodo();
        aux = actual;

        while(aux!=NULL){
            lPersona[i] = aux->getPersona();
            aux = aux->getSiguiente();
            i++;
        }
    }
    void arregloALista(Persona lPersona[]){
        int i = 0;
        Nodo *aux = new Nodo();
        aux = actual;

        while(aux!=NULL){
            aux->setPersona(lPersona[i]);
            aux = aux->getSiguiente();
            i++;
        }
    }
    void listaAArchivo(FILE *arch){
        Persona lPersona[num_nodos];
        listaAArreglo(lPersona);
        arch = fopen("mezclanatural.txt", "w+");

        if (arch==NULL){
            cout << "\nError al abrir mezclanatural.txt" << endl;
            exit(1);
        }
        fwrite(lPersona, sizeof(Persona), num_nodos, arch);
        cout << "\nArchivo mezclanatural.txt guardado con exito" << endl;
        fclose(arch);
    }
    Persona* arregloAHash(HASH *tabla){
        Persona lPersona[num_nodos];
        listaAArreglo(lPersona);

        return lPersona;
    }
    void ordenamientoPorQuicksort(){
        Persona lPersona[num_nodos];
        listaAArreglo(lPersona);
        quicksort(lPersona, 0, num_nodos-1);
        arregloALista(lPersona);
    }

    void ordenamientoPorIntercambio(){
        Persona lPersona[num_nodos];
        listaAArreglo(lPersona);
        intercambio(lPersona, num_nodos);
        arregloALista(lPersona);
    }
    void ordenamientoPorShell(){
        Persona lPersona[num_nodos];
        listaAArreglo(lPersona);
        shellsort(lPersona, num_nodos);
        arregloALista(lPersona);
    }
    void ordenamientoPorMezclaDirecta(){
        Persona lPersona[num_nodos];
        listaAArreglo(lPersona);
        mezcladirecta(lPersona, num_nodos);
        arregloALista(lPersona);
    }
    void ordenamientoPorMezclaNatural(FILE *fichero){
        Persona lPersona[num_nodos];
        listaAArreglo(lPersona);
        mezcladirecta(lPersona, num_nodos);
        arregloALista(lPersona);
    }
    void busquedaSecuencial(string nnombre){
        Persona lPersona[num_nodos];
        listaAArreglo(lPersona);
        bool bandera = false;

        for(int i=0; i<num_nodos; i++){
            if(strcmp(lPersona[i].getNombre().c_str(), nnombre.c_str())==0){
                cout << "\nPersona encontrada en la posicion " << i+1 << endl;
                lPersona[i].mostrarDatos();
                bandera = true;
            }
        }
        if(!bandera) cout << "\nNo se encontro a la persona" << endl;
    }
    void busquedaBinaria(string nnombre){
        Persona lPersona[num_nodos];
        listaAArreglo(lPersona);
        int primero = 0;
        int ultimo = num_nodos;
        int medio = (primero+ultimo)/2;

        while (primero<=ultimo){
            if (strcmp(lPersona[medio].getNombre().c_str(), nnombre.c_str())<0) primero=medio+1;
            else if (strcmp(lPersona[medio].getNombre().c_str(), nnombre.c_str())==0) {
                cout << "\nPersona encontrada en la posicion " << medio+1 << endl;
                lPersona[medio].mostrarDatos();
                break;
            }
            else ultimo = medio - 1;
            medio = (primero+ultimo)/2;
        }
        if (primero>ultimo) cout << "\nNo se encontro a la persona" << endl;
    }
};
