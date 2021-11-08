#include <iostream>
#include "Persona.h"
using namespace std;

template <class DATO>

class Nodo{
    private:
        DATO dato;
        Nodo *sig;
    public:
        //el metodo constructor me permite  instancear o definir crear un nodo
        Nodo(DATO d,Nodo *sig=NULL){
            dato=d; //SOBRECARGAR EL OPERADOR = 
            this->sig=sig;
        }
    friend class Lista;
};

    typedef Nodo *pnodo;
template <class DATO>
class Lista{
    private:
    // Nodod *pri;
        pnodo pri;
        pnodo ult;
    public:
        Lista(){pri=ult=NULL;}//constructor enline
        ~Lista();//liberar memoria destrutor
        void agregar(DATO d);
        void eliminar(DATO d);
        void imprimir();
        bool ListaVacia(){return pri==NULL;}
        void siguiente();
        void primero();
        void ultimo();
        bool actual(){return ult!=NULL;}
        int valorActual(){return ult->dato;}       
};
template <class DATO>
Lista::~Lista(){
    pnodo aux;
    while(pri){
        aux=pri;
        pri=pri->sig;
        delete aux;
    }pri=NULL;
    ult=NULL;
};
template <class DATO>
void Lista<DATO>::agregar(DATO d){
    pnodo anterior;
    // si la lista esta vacia
    if(ListaVacia() || pri->dato >d){
        pri=new Nodo(d,pri);
    }else{
        //Buscar el nodo con valor menor a v
        anterior = pri;
        //Avanzamos hasta el ultimo o hasta el nodo que tenga menor valor que d
        while(anterior->sig && anterior->sig->dato <= d){
            anterior=anterior->sig;
        }anterior->sig=new Nodo(d,anterior->sig);
    }
}
template <class DATO>
void Lista<DATO>::imprimir(){
    Nodo *aux;
    aux=pri;
    while(aux){
        cout<<aux->dato<<"->";
        aux=aux->sig;
    }
    cout<<"NULL"<<endl;
}
template <class DATO>
void Lista<DATO>::eliminar(DATO d){
    //hay que buscar el nodo que cumpla la condicion y eliminarlo
    pnodo anterior,nodo;
    nodo =pri;
    anterior=NULL;
    while(nodo && nodo->dato < d){
        anterior = nodo;
        nodo=nodo -> sig;
    }
    if(!nodo || nodo->dato !=d)return;//llegue al final de lista o el dato no esta 
    else{ //borrar nodo
        if(anterior){
            pri = nodo->sig;
            }else{
                anterior->sig=nodo->sig;
                }
                delete nodo;//primer elemneto
    }
}
//le falta poner menu, mensajes, que ingrese los datos el usuario
