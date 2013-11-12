/* text compression using RLE method */

#include <stdio.h>
#define N 128

int str_len(char *input);

int main()
{
	int len;
	char input[N];
	printf("enter text: ");
	scanf("%s", input);
	len = str_len(input);
	printf("length = %d\n", len);
	return 0;
}

int str_len(char *input)
{
	int i = 0;
	while (input[i++] != '\0');
	return i-1;
}
