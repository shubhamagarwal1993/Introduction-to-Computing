/*
 Name: SHUBHAM AGARWAL
 NetID:sagarwl4
 Lab Section:AD9
*/

#include <stdio.h>

// define the size of the matrix array
#define NUM_V 10
#define NUM_E 9

// functions and global variables
int graph[NUM_V][NUM_V];                      // This is the adjacency matrix you need to fill in.
int graph_reading (const char* filename);
void graph_print();
int pathlength(const int origin,const int destination, int list[]);


// read in Graph and Generate the adjacency matrix in Memory, return 1 if the file doesn't exist//
int graph_reading (const char* filename)
{
    int orig,dest;
    char st[70];
    
    if((filename[0]!='g')||(filename[1]!='r')||(filename[2]!='a')||(filename[3]!='p')||filename[4]!='h'||(filename[5]!='.')||(filename[6]!='t')||	(filename[7]!='x')||(filename[8]!='t'))  /*checking if correct file name*/
    	return 1;
    
    FILE *inf;
    
    inf = fopen("graph.txt", "r");
    fscanf(inf,"%s",st);
    while(fscanf(inf,"%d %d",&orig,&dest)!=EOF) /*reading till end of file*/
    {
    	graph[orig-1][dest-1]=1;
    	graph[dest-1][orig-1]=1;
    }
    fclose(inf);
    return 0;
}


// print adjacency matrix on the screen
  void graph_print()
{   
    int i;
    int j;
    for(i=0;i<NUM_V;i++) /*2 for loops for 2-D Array*/
    {
    	for(j=0;j<NUM_V;j++)
    	{
    		printf("%d",graph[i][j]);
    	}
    	printf("\n");
    }
    return;
}


// find the shortest path length
int pathlength(const int origin,const int destination, int list[])
{ 

    int shortestlength = 0;
    int l[NUM_V];
    int c=0;
    int le;
    int i;
    list[origin-1]=1;   /*marking current vertices as listed*/
    list[destination-1]=1;
    
	if(graph[origin-1][destination-1]==1 && graph[destination-1][origin-1]==1)   /*if destination directly connecting to current vertex*/              
		return 1;
	
	for(i=0;i<NUM_V;i++)
	{
		if(list[i]==0) /*checking if untraversed*/
		{
			c++;
			break;	   
    	}	
    }
    
    if(c==0)
    	return 0;
    	
    for(i=0;i<NUM_V;i++)
    {
    	if(graph[origin-1][i]==1 && list[i]==0) /*checking for directly connected unvisited vertices*/
    	{
    		le=pathlength(i+1,destination,list);  /*recursion*/
    		
    		if(shortestlength==0)
    			shortestlength=le;	
    		else if(le<shortestlength)
    			shortestlength=le;
    	}		
    }	
    	
    if(shortestlength==0)
    	return shortestlength;
    
    shortestlength++;	
    return shortestlength;
}

// main function: display the right messages. Please refer to MP5 requirement
 int main(int argc, const char **argv)
{
    int gc;
    int list[NUM_V];
    int origin;
    int destination;
    int sl;
    int i;
    
    if(argv[1]==NULL)
    {
    	printf("enter the input file name\n");
    	return -1;
    }
    
    gc = graph_reading(argv[1]); 
    
    if(gc==1)
    {
    	printf("input file cannot be opened\n");
    	return -1;
    }
    else
    	printf("The adjacency matrix has been loaded\n");
    
    graph_print();
    
    printf("Enter the origin vertex:\n");
    scanf("%d",&origin);
    printf("Enter the destination vertex:\n");
    scanf("%d",&destination);
    
    for(i=0;i<NUM_V;i++)  /*list[NUM_V] has recored of traversed vertices*/
    	list[NUM_V]=0;
    	
    sl = pathlength(origin,destination,list); /*shortest path length*/
    
    if(sl==0)
    	printf("%d and %d are seperated forever!",origin,destination);
    else
    	printf("%d needs %d step(s) to get %d",origin,sl,destination); 
     	
    
    return 0;
}
  

