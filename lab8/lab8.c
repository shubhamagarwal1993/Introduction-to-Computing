#include <stdio.h>
#include <math.h>

/* function declaration goes here */

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

    printf("Euclidean distance = %f\n",distance);

    return 0;
}

/* function definition goes here */
