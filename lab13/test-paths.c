#include <stdio.h>

#include "paths.h"

int main()
{
    printf("Testing (3,4) -> (-1,5) (5 paths)\n");
    printf("Result: %d\n", count_shortest_paths(3, 4, -1, 5));
    
    // Add more test cases here.
    printf("Testing (0,-1) -> (0,1) (1 paths)\n");
    printf("Result: %d\n", count_shortest_paths(0, -1, 0, 1));
    
	

	return 0;
}
