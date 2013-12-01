#include "paths.h"
 
#include <math.h>
 
int count_shortest_paths(int start_x, int start_y, int end_x, int end_y)
 
/*! Given starting point (start_x, start_y) and ending coordinates
 
(end_x, end_y) on a 2D grid of city blocks, determine the number of
 
 shortest paths from the start to the end.
 
*/
 
{
 
	int paths = 0;
 
	if ((start_x == end_x) && (start_y == end_y))
	{
		return 1;
	}	 	
	
	if (start_x > end_x)
	{
		paths = paths + count_shortest_paths(start_x - 1, start_y, end_x, end_y);
	}
	
	if (start_x < end_x)
	{
		paths = paths + count_shortest_paths(start_x + 1, start_y, end_x, end_y);
	}
	
	if (start_y > end_y)
	{
		paths = paths + count_shortest_paths(start_x, start_y - 1, end_x, end_y);
	}
	
	if (start_y < end_y)
	{
		paths = paths + count_shortest_paths(start_x, start_y + 1, end_x, end_y);
	}
	
   return paths;
 
}
