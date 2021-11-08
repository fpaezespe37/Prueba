#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Sumar(int x, int y)
{
	int result;
	result = x+y;
	//cout << "El resultado es: " << result;
	return result;
}

int main(int argc, char** argv) {
	int x,y, res;
	cout << "Ingrese un primer numero: ";
	cin >> x;
	cout << "Ingrese un segundo numero> ";
	cin >> y;
	
	res= Sumar(x,y);
	
	
	
	
	return 0;
}


