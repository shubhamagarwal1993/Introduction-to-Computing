/* Sample code for Problem 4 */
#include <stdio.h>

void checkWord(int* w, int* s, int* m, char c[]);

int main()
{
    int wcount = 0;
    int scount = 0;
    int maxlen = 0; 
    FILE *infile;
    char candidate[80];

    infile = fopen("story.txt","r");
    if(infile == NULL)
    {
        printf("Error: File not found\n");
        return -1;
    }

    while (fscanf(infile,"%80s", candidate) == 1) 
    {
        checkWord(&wcount, &scount, &maxlen, candidate);		/* Call to function checkWord */
    }
    fclose(infile);

    printf("Statistics:\n"); 
    printf("\tLong word count: %d\n", wcount); 
    printf("\tSmall word count: %d\n", scount);
    printf("\tLength of longest word: %d\n", maxlen);

    return 0;
}


void checkWord(int* w, int* s, int* m, char c[])
{
	int q = 0;
	int array[120];
	int temp[1];
	int i = 0;
	int length = 0;
	int j = 0;
	int words = 0;
	while (c[j++] == ' '){
			
			while (c[i++] != ' '){
				length = length + 1;
							
				array[i] = length;
			}
		//LONG WORD COUNT
			if (length >= 4){
				*w = *w + 1;
			}
		//SHORT WORD COUNT
			if (length < 4){
				*s = *s + 1;
			}
	}		
words = words + 1;

//	CLACULATING THE LENGTH OF THE LONGEST WORD 										

	for (q = 0; q < words - 1; q++){
		if(array[q] > array[q +1])
			temp[1] = array[q];
		else
			temp[1] = array[q+1];
	}
	*m = temp[1];

}					

