/*
 * This program accepts two integer inputs from the user, sorts them, and
 * prints them. It uses a function swap() that accepts pointers to the
 * variables to be swapped.
 *
 * Do not change the arguments passed to the function.
 */
#include <stdio.h>

void swap(int *x, int *y);

int main(int argc, const char *argv[])
{
    int a = 0, b = 0;
    int *x = 0;
    int *y = 0;

    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);
	
	x = &a;
	y = &b;
	
    if (a > b)
    {
        swap(x, y);
    }

    printf("The sorted numbers are: %d %d\n", a, b);

    return 0;
}

void swap(int *x, int *y)
{
    int temp = 0;
    temp = *y;
    *y = *x;
    *x = temp;
}
