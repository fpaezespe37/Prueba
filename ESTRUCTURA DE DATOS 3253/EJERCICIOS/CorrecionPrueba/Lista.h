#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Persona
{
	char nombre[100];
	int sexo;
	float sueldo;
};

struct nodo
{
    struct Persona dato;
    struct nodo* sig;
};

struct listaSimples
{
    struct nodo* pri;
    struct nodo* ult;
};

istream& operator >>(istream &i,Persona &a)
{
	cout<<"\tNombre: ";
	i>>a.nombre;
	cout<<"\tSexo (1-Hombre, 2-Mujer):";
	i>>a.sexo;
	cout<<"\tSueldo:";
	i>>a.sueldo;
	i.ignore();
	return i;
}

ostream& operator <<(ostream &os,Persona a)
{
	os<<a.nombre<<"\t";
	if(a.sexo==1)
		cout<<"Hombre";
	else
		cout<<"Mujer";
	os<<"\t"<< a.sueldo<<endl;
	return os;
}

int menu()
{
    int opc;
    system("cls");
    cout << "\t\t\tRegistro Sueldos" << endl;
    cout << "\n1. Agregar una persona (al inicio)";
    cout << "\n2. Eliminar una persona";
    cout << "\n3. Imprimir listado de  mujeres ";
    cout << "\n4. Imprimir listado de hombres";
    cout << "\n5. Imprimir los datos de la persona con el mayor sueldo";
    cout << "\n0. Salir";
    cout << "\nIngrese una opcion: ";
    cin >> opc;
    return opc;
}

//int menu()
//{
//    int opc;
//    system("cls");
//    cout << "\t\t\tListas Simplemente Enlazadas" << endl;
//    cout << "\n1. Agregar Nodo.";
//    cout << "\n2. Agregar Nodo al inicio de la lista.";
//    cout << "\n3. Agregar Nodo Despues de un nodo x.";
//    cout << "\n4. Agregar Nodo antes de un nodo x.";
//    cout << "\n5. Imprimir lista.";
//    cout << "\n6. Buscar dato";
//    cout << "\n7. Eliminar primer nodo de la lista.";
//    cout << "\n8. Eliminar ultimo nodo de la lista.";
//    cout << "\n9. Eliminar Nodo siguiente";
//    cout << "\n10. Eliminar nodo antes de otro nodo";
//    cout << "\n11. Eliminar un Nodo X";
//    cout << "\n0. Salir";
//    cout << "\nIngrese una opcion: ";
//    cin >> opc;
//    return opc;
//}

nodo* crearNodo(Persona dato)
{
    nodo* e = new nodo;
    if (e != NULL)
    {
        e->dato.sexo = dato.sexo;
        e->dato.sueldo = dato.sueldo;
        strcpy(e->dato.nombre,dato.nombre);
        e->sig = NULL;
        cout << "Dato: " << e->dato.nombre;
    }
    return e;
}

struct listaSimples* agregarNodo(struct listaSimples* L, Persona dato)
{
    nodo* e = crearNodo(dato);
    if (e != NULL)
    {
        if (L != NULL)
        {
            cout << "\nLista no vacia, se va agregar el nodo al final" << endl;
            L->ult->sig = e;
            L->ult = e;
            cout << "Dato " << e->dato.nombre << " ingresado correctamente." << endl;
            return L;
        }
        else
        {
            cout << "\nLista vacia, se va a crear el primer elemento" << endl;
            listaSimples* l = new listaSimples;
            l->pri = e;
            l->ult = e;
            cout << "Dato " << e->dato.nombre << " ingresado correctamente." << endl;
            return l;
        }
    }
    else
    {
        return NULL;
    }
}

void imprimirLista(listaSimples* L,int sexo)
{
    int i = 1;
    if (L != NULL)
    {
    	if(sexo==1)
    	{
    		cout << "\n\tHOMBRES. " << endl;
		}
		else
		{
			cout << "\n\tMUJERES. " << endl;
		}
        cout<<"Ord.\tNOMBRE\tSUELDO"<<endl;
        nodo* e = L->pri;
        do
        {
            if(sexo==e->dato.sexo)
            {
            	cout << "\nNodo " << i << ": " << e->dato << endl;
            	i++;
			}			
            e = e->sig;            
        } while (e != NULL);
    }
    else
    {
        cout << "\nLa lista esta vacia" << endl;
    }
}

struct nodo* buscarMayor(listaSimples* L)
{
	nodo* e = NULL;
	nodo* m = NULL;
	float mayor;
   	if (L != NULL)
    {
        e = L->pri;
        mayor = e->dato.sueldo;
        m = e;
        while (e != NULL)
        {
            if(e->dato.sueldo>mayor)
            {
            	mayor = e->dato.sueldo;
        		m = e;
			}
			e = e->sig;
        }
    }
    return m;
}


//struct nodo* buscarNodo(listaSimples* L, int x)
//{
//    nodo* e = NULL;
//    if (L != NULL)
//    {
//        e = L->pri;
//        while (e != NULL && e->dato != x)
//        {
//            e = e->sig;
//        }
//    }
//    return e;
//}

//struct listaSimples* eliminarPrimero(listaSimples* L)
//{
//    int opc;
//    if (L != NULL)
//    {
//        nodo* e;
//        e = L->pri;
//        cout << "\nSe eliminara el dato -> " << e->dato << " Desea continuar? 1-SI/0-NO: ";
//        cin >> opc;
//        if (opc == 1)
//        {
//            L->pri = e->sig;
//            delete e;
//            if (L->pri == NULL)
//            {
//                delete L;
//                L->ult = NULL;
//                cout << "\nSe elimino el ultimo elemento de la lista. Lista vacia" << endl;
//            }
//        }
//    }
//    else
//    {
//        cout << "\nLa lista esta vacia. " << endl;
//    }
//    return L;
//}

struct listaSimples* eliminarUltimo(listaSimples* L)
{
    int opc;
    if (L != NULL)
    {
        nodo* e;
        e = L->pri;
        cout << "\nSe eliminara el ultimo dato."
            << " Desea continuar? 1-SI/0-NO: ";
        cin >> opc;
        if (opc == 1)
        {
            if (e->sig != NULL)
            {
                while ((e->sig)->sig != NULL)
                {
                    e = e->sig;
                }
                free(e->sig);
                e->sig = NULL;
            }
            else
            {
                L = NULL;
            }
        }
    }
    else
    {
        cout << "\nLa lista esta vacia. " << endl;
    }
    return L;
}

//struct listaSimples* eliminarNodoSiguiente(listaSimples* L)
//{
//    int x;
//    if (L != NULL)
//    {
//        nodo* e, * f, * aux;
//        cout << "\nBuscar dato anterior al eliminar: ";
//        cin >> x;
//        e = buscarNodo(L, x);
//
//        if (e != NULL)
//        {
//            cout << "\nDato encontrado: " << e->dato << endl;
//            if (e->sig != NULL)
//            {
//                f = e->sig;
//                aux = (e->sig)->sig;
//                e->sig = aux;
//                cout << "\nDato " << f->dato << " eliminado" << endl;
//                delete f;
//            }
//            else
//                cout << "\nNo existe un nodo siguiente al ingresado.";
//        }
//        else
//            cout << "\nDato NO encontrado: :( " << endl;
//    }
//
//    else
//    {
//        cout << "\nLa lista esta vacia. " << endl;
//    }
//    return L;
//}


//struct listaSimples* agregarNodoDespues(struct listaSimples* L, int dato, struct nodo* e)
//{
//    nodo* en = crearNodo(dato);
//    if (en != NULL)
//    {
//        if (L != NULL) //LISTA NO VACIA
//        {
//            //Agregar nodo depues de x elemento//
//
//            en->sig = e->sig;
//            e->sig = en;
//            cout << "\nSe va a agregar despues del nodo: " << e->dato << endl;
//            return L;
//        }
//        else
//        { //LISTA VACIA
//            //Agregar primer elemento a la lista, crear la lista
//            cout << "\nLista Vacia, se va a crear el primer nodo" << endl;
//            listaSimples* l = new listaSimples;
//            l->pri = en;
//            l->ult = en;
//            return l;
//        }
//    }
//    else
//        return NULL;
//};


//struct listaSimples* insertarAntes(listaSimples* L, int dato, int x)
//{
//
//    cout << "Que dato desea ingresar \n"
//        << endl;
//    cin >> dato;
//    nodo* e = crearNodo(dato);
//    ;
//    nodo* aux_pre = L->pri;
//    nodo* aux_post = buscarNodo(L, x);
//    if (e != NULL && aux_post != NULL)
//    {
//        if (L != NULL)
//        {
//            cout << "\n Se va a agregar nodo antes de: " << x << endl;
//
//            do
//            {
//
//                if (aux_pre->sig == aux_post)
//                {
//                    aux_pre->sig = e;
//                    e->sig = aux_post;
//                    break;
//                }
//                aux_pre = aux_pre->sig;
//            } while (aux_pre != NULL);
//
//            return L;
//        }
//    }
//    else
//        cout << "\n No existe ese nodo, la lista esta vacia o existe un solo elemento\n";
//    return NULL;
//};



struct listaSimples* agregarNodoAlInicio(struct listaSimples* L,Persona dato)
{ //INICIO
    nodo* e = crearNodo(dato);
    if (e != NULL)
    {
        if (L != NULL) //LISTA NO VACIA
        {
            //Agregar nodo al final de la lista
            cout << "\nLista No Vacia, se va a agregar nodo al inicio" << endl;
            e->sig = L->pri;
            L->pri = e;
            return L;
        }
        else
        { //LISTA VACIA
            //Agregar primer elemento a la lista, crear la lista
            cout << "\nLista Vacia, se va a crear el primer nodo" << endl;
            listaSimples* l = new listaSimples;
            l->pri = e;
            l->ult = e;
            return l;
        }
    }
    else
    {
        return NULL;
    }
}

//struct listaSimples* eliminarAntesNodo(listaSimples* L)
//{
//    nodo* q = NULL;
//    nodo* t = NULL;
//    nodo* r = NULL;
//    nodo* e = NULL;
//    int band, x;
//    cout << "\nIngrese el valor del nodo" << endl;
//    cin >> x;
//    if (L != NULL)
//    {
//        e = L->pri;
//        if (e->dato == x)
//        {
//            cout << "no existe un nodo anterior al que contiene " << x << endl;
//        }
//        else
//        {
//            q = e;
//            t = e;
//            band = 1;
//            do
//            {
//                if (q->sig != NULL)
//                {
//                    r = t;
//                    t = q;
//                    q = q->sig;
//                }
//                else
//                    band = 0;
//            } while (q->dato != x && band == 1);
//            if (band == 0)
//            {
//                cout << "El elemento no se encuentra en la Lista" << endl;
//            }
//            else
//            {
//                if (e->sig == q)
//                {
//                    L->pri = q;
//                }
//                else
//                {
//                    r->sig = q;
//                }
//
//                cout << "Se ha eliminado el elemento " << t->dato << endl;
//                delete t;
//            }
//        }
//    }
//    else
//    {
//        cout << "Lista vacia" << endl;
//    }
//    return L;
//}


//FUNCIONES DE ELIMINACION DE NODO EN X POSICION Y UNA POSCICION ANTERIOR
//struct listaSimples* eliminarDato(listaSimples* L, int x)
//{
//    nodo* q, * t=NULL;
//    int ban = 1;
//    q = L->pri;
//    while ((q->dato != x) && (ban == 1))
//    {
//        if (q->sig != NULL)
//        {
//            t = q;
//            q = q->sig;
//        }
//        else
//            ban = 0;
//    }
//    if (ban == 0)
//        cout << "\nel elemento no se encuentra en la lista" << endl;
//    else if (L->pri == q)
//    {
//        L->pri = q->sig;
//    }
//    else
//    {
//        t->sig = q->sig;
//        delete q;
//    }
//
//    return L;
//}

