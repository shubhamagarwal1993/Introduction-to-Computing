/*
    Name:		shubham agarwal
    NetID:		sagarwl4
    Lab Section:	
*/

#include <stdio.h>

float polynomial(float A, float B, float C, float x);

float riemann(float a, float b, int N, float A, float B, float C, char method);
/*
    Document functions (and the rest of your code) according to the style guide
*/

int main() {
    /* mp3.2 code here */
    	float a;				/*starting point of integration*/
	float b;				/*endpoint of integration*/
	float A;				/*coefficient of x^2*/		
	float B;				/*coeficient of x*/
	float C;				/*constant*/
	float N;				/*the number of rectangles*/
	float left;				/*left method sum*/
	float right;				/*right method sum*/
	float middle;				/*middle method sum*/
	float average;				/*average sum*/

	printf("\n");	
	printf("integration of Ax^2+Bx+C over a<=x<=b with N rectangles!\n");
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
	printf("Approximate the integration of a polynomial Ax^2+Bx+C over a<=x<=b with N rectangles!\n");
	printf("Input A: %f \n", A);
	printf("Input B: %f \n", B);
	printf("Input C: %f \n", C);
	printf("Input a: %f \n", a);
	printf("Input b: %f \n", b);	
	printf("Results: \n");
	printf("%fx^2 + %fx + %f \n",A,B,C);
	left = riemann(a,b,N,A,B,C);
	printf("left method sum = %f \n", left);
	printf("right method sum = %f \n", right);
	printf("middle method sum = %f \n", middle);
	printf("average sum = %f \n", average);
    
    
    return 0;

}

float polynomial(float A, float B, float C, float x)
{
	int sum;
	sum = (A*x*x)+(B*x)+(C);		 	
	return sum;

}
	
float riemann(float a, float b, int N, float A, float B, float C /*,char method*/)
{	
	int L, R, M;
	int del_x;
	int sum_L,sum_R,sum_M;
	del_x = (b-a)/N;
	int sum_riemann;
 	int x;

	if (method == L)	
	{
		for (x = a; x < (N*del_x); x=x+del_x)
		{ 	
			sum_L = sum_L + (A*x*x)+(B*x)+(C);
		}			
		return sum_L;	
	}

	if (mehod == R)
	{
		for (x = a+del_x; x <= b; x=x+del_x)
		{ 	
			sum_R = sum_R + (A*x*x)+(B*x)+(C);
		}			
		return sum_R;	
	
	}
	
	if (method == M)
	{
		for (x = a+(del_x/2); x < b; x=x+del_x)
		{ 	
			sum_M = sum_M + (A*x*x)+(B*x)+(C);
		}			
		return sum_M;	

	}

}	
