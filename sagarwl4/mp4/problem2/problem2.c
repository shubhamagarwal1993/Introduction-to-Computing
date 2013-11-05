#include<stdio.h>

/*int Tribon();*/

int main()
{
	int n = 0;
	int sequence;
	int array[100];
loop:
	printf("input: ");
	scanf("%d", &sequence);
	
	if (n == 0)
	{
		printf("enter n>0"); 
		goto loop;
	}
	
	array[1] = 0;
	array[2] = 1;
	
	for(int i=2; i<sequence; i++)
	{
		array[i]=array[i-1]+array[i-2]+array[i-3];
	}
	printf("%d",array[n]);
return 0;
}

