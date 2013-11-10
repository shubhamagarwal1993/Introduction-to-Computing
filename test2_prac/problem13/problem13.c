#include<stdio.h>
 
int a[10]={4,6,-4,-2,7,25,6,8,9,13};
 
void CompareAndSwap(int i , int j);
 
void FindLargest();
 
int main()
{
    FindLargest();													//Call FindLargest function        
    printf("The largest integer in the array is %d\n",a[9]);
    return 0; 
}
 
void CompareAndSwap(int i, int j)
{ 
	int hold;
	if (a[i] > a[j])
	{
		hold = a[i];
		a[i] = a[j];
		a[j] = hold;
	}
	
}	
 
void FindLargest()
{
	for(int i = 0; i < 9; i++)
	{
		CompareAndSwap(i,i+1);
	} 
}



