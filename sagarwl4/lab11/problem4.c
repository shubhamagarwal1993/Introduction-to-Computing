/* computing nth Tribonacci number */

#include<stdio.h>

int Tribon(int n);

int main()
{
	int n;
	int result;
	
	printf("input n: ");								//user input for n > 0		
	scanf("%d", &n);
	
	result = Tribon(n);
	printf("%d th Tribonacci is %d\n",n, result);
	return 0;
}	
	
int Tribon(int n)	
{	
	int sum;
	
	if (n == 0)											//not defined for 0th number
	{
		return 0;
	}
	
	if (n == 1)											//first number
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
		sum = Tribon(n-1) + Tribon(n-2) + Tribon(n-3);		//adding prev 3 numbers
		return sum;
	}		
}

