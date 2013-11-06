#include <stdio.h>

int main()
{
	char c;
	int count = 0;
	int word_count = 0;
	FILE *newfile;
	newfile = fopen("story.txt", "r");
	c = fgetc(newfile);

	if(newfile == NULL)
    	return -1;
	
	while((c = fgetc(newfile)) != EOF)
	{
		while (word_count < 4)
		{
			
			word_count++;
		}
	
    	if (c == '\n')
		count++;
    
    	if(c == ' ')
    		count++;
	}
	
	fclose(newfile);
	printf("Total: %d\n", count);

  return 0;
}
