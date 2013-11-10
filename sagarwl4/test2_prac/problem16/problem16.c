/* computing statistics */

#include <stdio.h>
#include <math.h> /* needed to call sqrtf() function */

int statistics(float array[], int n, float *mean, float *stdev);

int main()
{
	float myarray[] = { 1.3f, 2.4f, 3.5f, 4.6f, 5.7f };
	float mean, stdev;
	int retval;
	
	/* call statistics function */
	statistics(myarray, n, mean, stdev)
	
	retval = statistics(myarray, 5, . . . 
	/* output results */
	printf(“mean=%f, stdev=%f, retval=%d\n”, mean, stdev, retval);
	return 0;
}
	/* add function implementation here */



int statistics(float array[], int n, float *mean, float *stdev)
{
	/* you can use sqrtf function from standard math library 
	to compute square root needed in stdev formula */
}
