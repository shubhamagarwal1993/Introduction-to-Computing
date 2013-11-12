/* text compression using RLE method */

#include <stdio.h>
#define N 128

int RLE(char in[], char out[], int n);
int str_len(char *input);

int main()
{
	int len;
	char input[N];
//	char output[N];
	printf("enter text: ");
	scanf("%s", input);
	len = str_len(input);
	printf("length = %d\n", len);
	RLE(input, output, len);
	printf("%s\n", output);
	return 0;
}

int RLE(char in[], char out[], int n)
{
	int character[26];				// will keep into account the number of characters
	int number [26];				// number will keep a track of the repetitions
	int i = 0;						// 'i' will keep a track of 
	int j = 0;						// 'j' will keep a track of the different alphabets
	/* cleaning all the memory */
	for (int i = 0; i < 26; i++){
		character[i] = 0;
		number[i] = 0;	
	}
	
	/*  */
	for (int i = 0; i < n; i++)
	{
		if (i == 0){
			character[0] = in[0];
			number[i]++;
		}
		else{ 
			if (character[i] == in[j])
			number[j]++;
		}	

	
	}
}


int str_len(char *input)
{
	int i = 0;
	while (input[i++] != '\0');
	return i-1;
}
