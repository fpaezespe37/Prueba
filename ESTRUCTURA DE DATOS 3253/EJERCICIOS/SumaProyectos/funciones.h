/* */

int suma(int a, int b)
{
	if(b==0)
	{
		return a;
		
	}
	else
	{
		return suma(a,b-1)+1;
	}
}

int producto(int a, int b)
{
	//caso base
	if(b==0)
	{
		return 0;	
	}
	else
	{
		if(b==1)
		{
			return a;
		}
		else
			return suma(a, producto(a,b-1));
		//	return a + producto(a,b-1);
	}
}
