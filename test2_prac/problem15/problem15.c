/* text compression using RLE method */

#include <stdio.h>
#define N 128

int RLE(char in[], char out[], int n);
int stringLength(char string[]);

int main()
{
	char input[N];
	printf("enter text: ");
	scanf("%s", &input);
	printf("%d", stringLength(input));
	
	/* prompt user to enter string, get user’s input */
	/* call RLE function */
	/* output returned string */
	return 0;
}

/* add function implementation here */
//int RLE(char in[], char out[], int n)
//{

//}

int stringLength(char string[])
{
	int length = 0;
	int j = 0;
	int count[26] = {0};
	while (string[length] != '\0')
		length = length + 1;
		
	while (string[j] != '\0')
	{
		if (string[j] >= 'a' && string[j] <= 'z')
			count[string[j] - 'a']++;
		
		j++;
	}
	for (j = 0; j < 26; j++)
	{
		if (count[j] != 0)
		{
			c = c + 'a';
			count[c];
		}
	}
		
}
