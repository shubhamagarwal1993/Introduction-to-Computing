/* swapping the numbers at the place number satisfied*/

#include<stdio.h>
 
int a[10]={4,6,-4,-2,7,25,6,8,9,13};
 
void CompareAndSwap(int i, int j);
 
int main()
{ 
    int i,j; 
    printf("Enter the non-negative indices to be compared and swapped\n"); 
    scanf("%d %d", &i,&j );
// Call CompareAndSwap function
    CompareAndSwap(i, j); 
	printf("After compare and swap integer at index %d is %d and integer at index %d is %d",i,a[i],j,a[j]); 
    return 0;										//in case something is not satisfied
}
 
void CompareAndSwap(int i, int j)
{ 
	int hold;										//a temporary space to hold one of the value
	if (a[i] > a[j])
	{
		hold = a[i];
		a[i] = a[j];
		a[j] = hold;
	}
}

/* ASSUMPTIONS: 
THE ARRAY 'a' IS NOT DEFINED FOR 10 INTEGERS AND THERE IS NO CHECK FOR IT
THE ELEMENT a[0] IS THE FIRST ELEMENT */
