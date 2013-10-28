/*
    Name:		shubham agarwal
    NetID:		sagarwl4
    Lab Section:	
*/

#include <stdio.h>

float polynomial(float A, float B, float C, float x);

float riemann(float a, float b, int N, float A, float B, float C,char method);

int main() 
{
	float a;					/*starting point of integration*/
	float b;					/*endpoint of integration*/
	float A;					/*coefficient of x^2*/		
	float B;					/*coeficient of x*/
	float C;					/*constant*/
	float N;					/*the number of rectangles*/
	printf("Riemann Sum Calculator:\n");
	printf("Approximate the integration of a polynomial Ax^2+Bx+C with N rectangles!\n");	
	printf("Input A: ");
	scanf("%f", &A);
	printf("Input B: ");
	scanf("%f", &B);
	printf("Input C: ");
	scanf("%f", &C);
	printf("Input a: ");
	scanf("%f", &a);
			
LOOP1:
	printf("Input b: ");
	scanf("%f", &b);	
	if (a>b)
	{
		printf("	Please ensure b>a\n");
		goto LOOP1;		
	}
	
LOOP2:	
	printf("Input N: ");
	scanf("%f", &N);
	if (N<=0)
	{
		printf("	Please ensure N>0\n");
		goto LOOP2;	
	}
	
	printf("Results:\n");
	printf("left method sum = %f \n", riemann(a,b,N,A,B,C,'L'));
	printf("right method sum = %f \n", riemann(a,b,N,A,B,C,'R'));
	printf("middle method sum = %f \n", riemann(a,b,N,A,B,C,'M'));
    	printf("average sum = %f \n", (riemann(a,b,N,A,B,C,'L')+riemann(a,b,N,A,B,C,'R')+riemann(a,b,N,A,B,C,'M'))/3 );
	printf("\n");
    return 0;
}

float polynomial(float A, float B, float C, float x)
{
	float sum;
	sum = (A*x*x)+(B*x)+(C);		 	
	return sum;
}
	
float riemann(float a, float b, int N, float A, float B, float C,char method)
{	
	
	float del_x;
	float sum = 0;
	del_x = (b-a)/N;
	float x;

	if (method == 'L')
	{
		for (x = a; x <= b-del_x; x=x+del_x)
		{ 	
			sum = sum + (((A*x*x)+(B*x)+(C))*del_x);
		}			
		return sum;	
	}

	if (method == 'R')
	{
		for (x = a+del_x; x <= b; x=x+del_x)
		{ 	
			sum = sum + (((A*x*x)+(B*x)+(C))*del_x);
		}			
		return sum;	
	
	}
	
	if (method == 'M')
	{
		for (x = a+(del_x/2); x < b; x=x+del_x)
		{ 	
			sum = sum + (((A*x*x)+(B*x)+(C))*del_x);
		}			
		return sum;
	}	
return 0;
}	


