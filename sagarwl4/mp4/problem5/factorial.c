#include<stdio.h>

int main() 
{
	int c;
	int n = 5;
	int fact = 1;
	for (c = 1; c <=n; c++)
	{
		fact = fact*c;
	}
	printf("%d", fact);
}
