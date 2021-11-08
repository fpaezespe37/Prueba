#include <iostream>
#include "punto.h"
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
Desarrollar un programa que permita registrar una seri de puntos de un
plano cartesiano con sus coordenadas (x,y). Luego calcular la distancia 
entre un par de puntos sleccionados por el usuario.
Utilizar un menú de opciones para la interfaz con el usuario. 
ANALISIS
D. Entrada: punto (x,y)
D. Salida: distancia
DISEÑO
INICIO
	1. Registrar puntnos on su coordenadas
	2. Selccionar 2 puntos para calcular su ditancia
	3. Mostrar el resultado
FIN
*/
int main(int argc, char** argv){
   
    int opc,tam=0,i,j,d;
    Punto *puntos=NULL;
    do{
        system("cls");
        opc=menu();
        switch(opc){//ingresa puntos
            case 1:{
            cout<<"\nIngreso de puntos:"<<endl;
            //direccion de memoria, reservar memoria
            puntos=(Punto*)realloc(puntos,(tam+1)*sizeof(Punto));//casting
            if(puntos!=NULL){
                leerXY(&puntos[tam]);
                tam++;
            }else
            {
              cout<<"no reservaste mermoria bro.";  /* code */
            }
            
            break;
            }
            case 2:{// calcular puntos
                cout<<"\nCalcular la distancia:"<<endl;
                if(puntos!=NULL && tam>1){
                    imprimir(puntos,tam);
                    do{
                        cout<<"\nSeelecione el indice de punto 1:"<<endl;
                        cin>>i;
                    }while(i<=0||i>tam);
                    do{
                        cout<<"\nSeelecione el indice de punto 2:"<<endl;
                        cin>>j;
                    }while(j<=0||j>tam);
                    d = calcularDistancia(puntos[i-1],puntos[j-1]);
                    cout<<"\n Distancia = "<<d<<endl;
                }else
                {
                    cout<<"No ha ingresados los datos suficintes"<<endl;
                }
                
            break;
            }
            case 3:{
                imprimir(puntos,tam); 
            break;
            }
            case 0:{
            cout<<"\n Gracias por usar mi programa"<<endl;
            break;
            }
        }
        system("pause");
    } while (opc!=0);
    
    
 return 0;   
}
