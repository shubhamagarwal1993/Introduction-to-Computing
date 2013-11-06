/* computing the minimum and maximum elements of an array*/

#include<stdio.h>
#define N 10												//global defination

int setMinMax(int List[], *minInList, *maxInList );

int main()
{
	int List[N]={4,5,10,19,-43,-3,19,33,34,2};
	int maxInList;									//declaring max
	int minInList;									//declaring min
	setMinMax(List, &minInList, &maxInList);		//calling the function
	printf("Min %d Max %d \n", minInList, maxInList );
	return 0;												//in case nothing satisfies
}

int setMinMax(int List[], *minInList, *maxInList )		//one function for min and max	
{
	int i;
	int maximum = List[0];
	int minimum = List[0];
	
	for (i = 1; i < N; i++)
	{
					//finding max
		if (List[i] > maxInList)
		{
			maximum = List[i];
		}
					//finding min
		if (List[i] < minInList)
		{
			minimum = List[i];
		}
	}
*minInList = minimum;
*maxInList = maximum;
}
