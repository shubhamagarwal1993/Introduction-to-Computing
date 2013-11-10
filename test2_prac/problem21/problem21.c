/* text reversion */

#include <stdio.h>
#define N 128

int reverse(char input[]);

int main()
{
	char input[N];
	int c;
	printf("enter text: ");
	scanf("%s", &input);
	c = reverse(input);
	
	printf("no of words are %d", c);			/* output returned string */
	
	return 0;
}

int reverse(char input[])
{
	int word = 0;
	
	for (int i =0; i < N ; i++)
	{
		if (input[i] == ' ')
		{
			word = word + 1;
		}
	}
	
	return word;
}
