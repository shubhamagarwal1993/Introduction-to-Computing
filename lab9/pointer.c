#include<stdio.h>
 
int main()
{
    double iray[5];
    double* ipoint = &iray[0];
 
    for(int i = 0; i < 100; i++)
    {
    	printf("the value of i is %d\n", i);
        *ipoint = i;
        printf("%e\n", ipoint);
        ipoint = ipoint + 1;
    }
 
    for(int i = 0; i < 5; i++)
    {
        printf("%e\n", iray[i]);
    }
    return 0;
}
