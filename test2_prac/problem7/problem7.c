/* PALINDROME */
#include<stdio.h>

int charcount(char word[], int len);
int checkPalindrome(char word[], int len);

int main()
{
	int wlen, ret;
	char word[80];
	FILE *infile;
	
	infile = fopen("words.txt","r");
	
	if(infile == NULL)
	{
		printf("Error: File not found\n");
		return -1;
	}

	while (fscanf(infile,"%80s", word) == 1) 
	{
		wlen = charcount(word, 80);
		ret = checkPalindrome(word, wlen);
		if (ret == 1)
		{
			printf("the word is a palindrome");
		}
		else
			printf("not a palindrome"); 
	}

	fclose(infile);
	return 0;
}

int charcount(char word[], int len)
{
	int i = 0;
	while(word[i] != '\0' && i < len)
	i++;
	return i;
}

int checkPalindrome(char word[], int len)
{
	int i = 0;
	int flag = 1;
	while (i<len/2)
		{
			if (word[i] != word[len-1-i]){
			flag = 0;
			break;}
			i++;
		}

return flag;
}
