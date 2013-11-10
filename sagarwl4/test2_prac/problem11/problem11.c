#include <stdio.h> 

typedef struct rawFloat{
    char negative;
    unsigned int fractional;
    unsigned int exponent;
} rawFloat;

rawFloat convert(double alpha)
{
     int counter;
     double alpha_copy; 
     rawFloat result; 
     alpha_copy = alpha;
     if (alpha < 0)
     {
          result.negative = 'n';
     }
     else 
     {
          result.negative = 'p';
     }
     while  (alpha_copy != (int) alpha_copy)
     {
          alpha_copy = alpha_copy*10;
          counter++;
     }
     result.exponent = 127 - counter;
     result.fractional = alpha_copy;
 
 
     
  return result;
}     

int main ()
{    double sample;
     rawFloat solution;
     printf("Enter your double number:");
     scanf ("%lf",&sample);
     solution = convert(sample);
     printf(" Here is negative: %c\n",solution.negative);
     printf(" Here is fractional: %d\n",solution.fractional);
     printf(" Here is exponent: %d\n",solution.exponent);
 return 0;
}
