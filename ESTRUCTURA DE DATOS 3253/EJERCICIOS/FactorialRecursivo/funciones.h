/*
	int fact(int n)
	{
		int f = 1;
		for (int = 1; i<=n; i++)
			f*=i;
			return f;
	}
*/

	int fact(int n)
	{
		if(n==0)
			return 1;
		
		else
			return n*fact(n-1);
	}
