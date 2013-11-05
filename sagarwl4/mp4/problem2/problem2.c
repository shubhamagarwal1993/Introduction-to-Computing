#include<stdio.h>

int Tribon(int n);

int main()
{
	int i;
	int sequence;
	
	printf("input: ");
	scanf("%d", &i);
	
	sequence = Tribon(i);
	printf("the Tribonacci number is %d\n", sequence);
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
		return 1;
	}
	
	if (n == 2)
	{
		return 1;
	}
	
	else
	{
		sum = Tribon(n-1) + Tribon(n-2) + Tribon(n-3);
		return sum;
	}		
}

