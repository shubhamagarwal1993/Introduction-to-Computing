/* Sample code for Problem 3 */

#include <stdio.h>

int firstRepeat(int myArray[], int size);

int main()
{
    int n = 5;
    int myArray[5] = {1, 2, 3, 4, 4};
    int fRepeat;

/* Call to function firstRepeat */    
	fRepeat = firstRepeat(myArray, n);

    printf("First Repeating integer : %d\n", fRepeat);
    return 0;
}


int firstRepeat(int myArray[], int size)
{
	int i = 0;
	int j = 0;							//will keep a count of the repetition						
	int count = 0;	
	while (i < size){
		
		while (j < 5000){
			if (myArray[i] != j){
				j++;
				i++;
			}
			else{
				count++;
				return j;
			}
			
		}	
		
	}
return -1;
}
