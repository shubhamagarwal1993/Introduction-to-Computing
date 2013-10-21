#include <stdio.h>
#include <math.h>

/* function declaration goes here */
float euc_dist(float x1, float y1, float x2, float y2);

int main()
{
    float x1_in, y1_in, x2_in, y2_in;
    float distance;

    printf("Enter the x value for point 1: ");
    scanf("%f",&x1_in);
    printf("Enter the y value for point 1: ");
    scanf("%f",&y1_in);
    printf("Enter the x value for point 2: ");
    scanf("%f",&x2_in);
    printf("Enter the y value for point 2: ");
    scanf("%f",&y2_in);

    /* function call goes here */
	distance = euc_dist(x1_in, y1_in, x2_in, y2_in);
    printf("Euclidean distance = %f\n",distance);

    return 0;
}

/* function definition goes here */
float euc_dist(float x1, float y1, float x2, float y2)
{
float sum_x;
float sum_y;
float result; 
float summation;
sum_x = (x1-x2)*(x1-x2);
sum_y = (y1-y2)*(y1-y2);
summation = sum_x+sum_y;
printf("summation = %f \n", summation);
result = sqrtf (summation);
return result;
}
