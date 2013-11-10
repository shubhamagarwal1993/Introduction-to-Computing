/* computing ln(x) using Taylor polynomials */

#include<stdio.h>
#include<math.h>
#include<conio.h> 

/* add function prototype here */

int natural_log(float x, float error);

int main()
{
	float x;
	float error_range;

	printf("enter the value of 1<=x<=2: ");
	scanf("%f", &x);
	if (x > 2 || x < 1)
	{
		printf("Incorrect input");	
		return -1;
	}
		
	printf("maximum allowed error: ");
	scanf("%f", &error_range);

	natural_log(x, error_range);	
	
	printf("");
	/* output ln(x) */
	return 0;
}

int natural_log(float x, float error)
{
	
}
