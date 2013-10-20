/* 
    Name:	shubham agarwal
    NetID:	sagarwl4
    Lab Section:AD9
*/

#include <stdio.h>

int main()
{
	float a;				/*starting point of integration*/
	float b;				/*endpoint of integration*/
	float A;				/*coefficient of x^2*/		
	float B;				/*coeficient of x*/
	float C;				/*constant*/
	float N;				/*the number of rectangles*/
	float left = 0.0f;			/*left method sum*/
	float right = 0.0f;			/*right method sum*/
	float middle = 0.0f;			/*middle method sum*/
	float average = 0.0f;			/*average sum*/

	printf("\n");	
	printf("we will find the integration of Ax^2+Bx+C from a to b \n");
	printf("\n");
	printf("enter startpoint\n");
	scanf("%f", &a);	
		
LOOP1:
	printf("enter endpoint\n");
	scanf("%f", &b);
	
	if (a>b)
	{
		goto LOOP1;		
	}

	printf("enter value for A\n");
	scanf("%f", &A);

	printf("enter value for B\n");
	scanf("%f", &B);

	printf("enter value for C\n");
	scanf("%f", &C);

LOOP2:	
	printf("enter the number of rectangles you want\n");
	scanf("%f", &N);
	
	if (N<=0)
	{
		goto LOOP2;	
	}
	printf("Input A: %f \n", A);
	printf("Input B: %f \n", B);
	printf("Input C: %f \n", C);
	printf("Input a: %f \n", a);
	printf("Input b: %f \n", b);	
	printf("Results: \n");
	printf("%fx^2 + %fx + %f \n",A,B,C);
	printf("left method sum = %f \n", left);
	printf("right method sum = %f \n", right);
	printf("middle method sum = %f \n", middle);
	printf("average sum = %f \n", average);
return 0;

}
