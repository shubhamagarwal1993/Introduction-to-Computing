/* Sample code for Problem 2 */
#include <stdio.h>

typedef struct rawFloat
{
    unsigned char negative;
    unsigned int exponent;
    unsigned int fractional;
} rawFloat;

double mult(rawFloat alpha, rawFloat beta)
{
	
	double multi; 
	multi = alpha*beta;
	return multi;

}



int main()
{
	double multi;
	rawFloat aplha = 3.3564;
	rawFloat beta = 4.456; 
	multi = mult(rawFloat alpha, rawFloat beta);
	    
	printf("%f", multi);
	return 0;
}





