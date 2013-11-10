#include <stdio.h>
#define N 10
#define M 4
/* Partition N nonnegative integers into M+1 bins */
/* write function prototype */
void doBinning(int A, int B, int C, int List[N], int Bins[M]); 

int main ()
{
	int A,B,C;
	printf("input A: ");
	scanf("%d", &A);
	printf("input B: ");
	scanf("%d", &B);
	printf("input C: ");
	scanf("%d", &C);
	int List[N] = {4, 5, 10, 19, 0, 55, 19, 33, 34, 2}; 
	int Bins[M];

	doBinning(A,B,C,List,Bins);
/* call doBinning function */
	printf("Number of elements in [0, %d): %d\n",A,Bins[0]);
	printf("Number of elements in [%d,%d): %d\n",A,B,Bins[1]);
	printf("Number of elements in [%d,%d): %d\n",B,C,Bins[2]);
	printf("Number of elements above %d: %d\n",C,Bins[3]);
	return 0;
}

void doBinning(int A, int B, int C, int List[N], int Bins[M])
{
	Bins[0] = 0;
	Bins[1] = 0;
	Bins[2] = 0;
	Bins[3] = 0;
	
	for (int i = 0;i < N ;i++)
	{
		if (0 <= List[i] && List[i] < A)
		{
			Bins[0] = Bins[0] + 1; 
		}
	} 

	for (int i = 0;i < N ;i++)
	{
		if (A <= List[i] && List[i] < B)
		{
			Bins[1] = Bins[1] + 1; 
		}
	}

	for (int i = 0;i < N ;i++)
	{
		if (B <= List[i] && List[i]< C)
		{
			Bins[2] = Bins[2] + 1; 
		}
	}

	for (int i = 0;i < N ;i++)
	{
		if (List[i] > C)
		{
			Bins[3] = Bins[3] + 1; 
		}
	}
}
