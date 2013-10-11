#include <stdio.h>

int main()
{
	
	{
		char c;
		FILE *newfile;				//pointer named newfile is pointing to opened file in memory	
		newfile = fopen("data.txt", "r");	//newfile points to the first word in data.txt
		c = fgetc(newfile);			//takes the file pointer as input & outputs char that newfile points to
		for (int i=0; i<5; i++)			
		{
			printf("%c", c);			//print the char from data.txt
			c=c+1;
			c = fgetc(newfile);		
		}	
		fclose(newfile);			//we have to close the opened file.
	}
}

