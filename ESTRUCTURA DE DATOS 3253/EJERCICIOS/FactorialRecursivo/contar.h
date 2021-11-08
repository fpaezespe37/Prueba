#include <iostream>
using namespace std;

/*Imprimir numeros del 1 a n o de n a 1
	si n = 1 -> n //caso base
	si n > 1 -> cout<<n; imprimir(n-1)
	
*/

void imprimirD(int n) //descendente
{
	if(n>0)
	{
		cout<<"\t"<<n;
		imprimirD(n-1);
	}
}
	
void imprimirA(int n) //ascendente
{
	if(n>0)
	{
		imprimirA(n-1);
		cout<<"\t"<<n;
	}
}
