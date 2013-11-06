/* computing the minimum and maximum elements of an array*/

#include<stdio.h>
#define N 10												//global defination

int setMinMax(int List[], char method);

int main()
{
	int List[N]={4,5,10,19,-43,-3,19,33,34,2};
	int maxInList = setMinMax(List,'a');					//calling max
	int minInList = setMinMax(List,'b');					//calling min
	printf("Min %d Max %d \n", minInList, maxInList );
	return 0;												//in case nothing satisfies
}

int setMinMax(int List[], char method)						//one function for min and max	
{
	int i;
	int maxInList;
	int minInList;
	/*for finding max number*/
	if (method == 'a')										//finding max
	{
		maxInList = List[0];
		for (i=1; i<10; i++)
		{
			if (List[i] > maxInList)
			{
				maxInList = List[i];
			}
		}
	return maxInList;
	}
	/*for finding min number*/
	if (method == 'b')										//finding min
	{
		minInList = List[0];
		for (i=1; i<10; i++)
		{
			if (List[i] < minInList)
			{
				minInList = List[i];
			}
		}
	return minInList;
	}
return 0;
}
