/* computing nth Tribonacci number */

#include<stdio.h>

int Tribon(int n);

int main()
{
	int n;
	int result;
	
	printf("input n: ");
	scanf("%d", &n);
	
	result = Tribon(n);
	printf("%d th Tribonacci is %d\n",n, result);
	return 0;
}	
	
int Tribon(int n)	
{	
	int sum;
	
	if (n == 0)
	{
		return 0;
	}
	
	if (n == 1)
	{
		return 0;
	}
	
	if (n == 2)
	{
		return 1;
	}
	
	if (n == 3)
	{
		return 1;
	}
	
	else
	{
		sum = Tribon(n-1) + Tribon(n-2) + Tribon(n-3);
		return sum;
	}		
}

