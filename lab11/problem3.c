/* STRING WORD REVERSAL */

#include<stdio.h>
#define N 128

void reverse(char result[]);
int str_length(char array[]);
void char_swap(char *firstVal, char *secondVal);

int main()
{
char input[N];
printf("enter text: ");
scanf("%s", input);
reverse(input);
printf("%s", input);
return 0;
}

int str_length(char array[]){
	int i = 0;
	int count = 0;
	while (array[i++] != '\0'){
	count++;
	}
	return count;
}

void char_swap(char *firstVal, char *secondVal){
	char tempVal;
	tempVal = *firstVal;
	*firstVal = *secondVal;
	*secondVal = tempVal;
}

void reverse(char result[]){
	int leng = str_length(result);	
	for (int i = 0; i < (leng/2); i++)
	{
		char_swap(&result[i], &result[leng-i-1]);
	}
	
}


