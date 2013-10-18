#include <stdio.h>
#include <math.h>

/* function declaration goes here */
int euc_dist(int x1, int y1, int x2, int y2);

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

/* function definition goes here */int euc_dist(int x1, int y1, int x2, int y2)
{
int sum_x;
int sum_y;
int result; 
sum_x = (x1-x2)*(x1-x2);
sum_y = (y1-y2)*(y1-y2);
result = sqrt(sum_x + sum_y);
return result;
}

