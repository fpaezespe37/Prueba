#include <iostream>
using namespace std;

const string INFO = "Este programa imprime la sucesion de fibonacci desde \
1 hasta N, \nsiendo este ultimo un numero ingresado por el usuario\n";

const string INFO1 = "Formula que se utiliza para el calculo de Fibonacii es xn = xn-1 + xn-2\n"   ;        
   	
int main() {
	
	unsigned long long aux = 1, fib = 0, lim, init;   //Asignacion es "1"
	cout << INFO << endl;
	cout << INFO1 << endl;
	cout << "Ingrese un numero para la sucesion de fibonacci: ";
	cin >> lim;
	  if(lim > 0) { 								//Asignacion es "1"
	    for(init = 1; init <= lim; init++) {		//Asignacion es "n+n+1+1
		    cout << "[" << fib << "] ";
	    	aux += fib; 							//Asignacion es 1
	      	fib = aux - fib;						//Asignacion es "1"
	      
		  	    }
	  } else {
	    	cout << "El numero debe ser mayor a cero!!" << endl;
	  }
	  		cout << "\n";
	  return 0;
  
}

                            
