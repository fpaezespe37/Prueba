/*Suma recursiva*/

int SumaRecursiva(int n1, int n2)
{
	int sumar;
	if(n2==0)
		return n1; 
	else return SumaRecursiva(n1,n2-1)+1;
	
		
	
}
