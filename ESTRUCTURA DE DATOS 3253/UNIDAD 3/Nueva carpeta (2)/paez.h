#include<iostream>
using namespace std;

int Division(int n1){
	int  num1, num2, sumpares, sumimpares, n, cont;
	sumpares = 0;
	sumimpares = 0;
	cont = 0;
	
   	do{    
   		num1 = n1%10; 
   		cont = cont +1;
		 if(n1<10){
		 	num1 = n1%10; 
		 	n1 = 0;
		 }
	if((cont%2)==0){
		sumpares = sumpares + num1; 
		 }else{
		 	sumimpares = sumimpares + num1;
		 	
		 }
   n1 = n1 / 10;
	}while(n1 > 0); 
	
	
	cout << "\nsumpar: " << sumpares;
	cout << "\nsumimpar: " << sumimpares;
  	return (sumpares - sumimpares);
}

void Divisibilidad(int numero){
	int resultado;
	if(numero==0){
		cout << "\nSi es divisible";
		
	}else{
		cout << "\nNo es divisible"; 
	}
}
