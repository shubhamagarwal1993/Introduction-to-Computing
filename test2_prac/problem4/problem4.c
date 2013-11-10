//STACK IMPLEMENTATION
//stack is a LIFO

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10			/*Maximum size*/

int stack[MAX_SIZE];		/*global array*/
int top //=0;					/*index of top of stack*/
//int stack_number = 0
void push(int item);		/*func to push an item*/
int pop();					/*func to pop an item*/
void display();				/*func to disp items in stack*/ 

int main()
{
	int choice, item;
	while(1)
	{ 
		choice = 0;
		printf("------------------------------------\n");
		printf("Options\n");
		printf("1)Push\n");
		printf("2)Pop\n");
		printf("3)Display\n");
		printf("4)Exit\n");
		printf("------------------------------------\n");
		
		printf("Enter an option: ");
		
		if(scanf("%d", &choice) == 0)
		{
			printf("\nInvalid input. Aborting...\n");
			exit(-1);
		}
		
		switch(choice)
		{
			case 1: printf("Enter the item to push: ");
			scanf("%d", &item);
			push(item);
			break;
		
			case 2: item = pop();
			printf("Popped %d\n", item);
			break;
		
			case 3: display();
			break;
		
			case 4: exit(0);
			default:printf("Invalid choice. Try again\n");
		}
	}
	return 0;
}
		
void push(int item)
{
	int i;
	top = i; 
	for(i = 0; i < MAX_SIZE; i++)
	{
		top = stack[i];
		if (top == NULL)
		{
			stack[i] = item;
			top = i;
		}
		else
		{
			printf("STACK OVERFLOW");
		}
	}	
		
}

int pop()		
{
	int i;
	for(i = 0; i < MAX_SIZE+1; i++)
	{
		top = stack[i];
		if (top == NULL)
		{
			return stack[i-1];
			top = i-1;
		}
		else
		{
			printf("STACK UNDERFLOW");
		}
	}
}

void display()			
{	
	for(int i=0; i<MAX_SIZE; i++)
	{
		if (i != NULL)
		printf("[%d]", i);
	}
}			






stc_num += 1

if (stc_mum = 1)
{top = 0
}

else 
{
top = top + 1
}

stack[top] = item;



pop func
int value = stack[top]

stack[top] = 0;
top = top - 1;
return vlue

void display
{
for(inti =0 ; i<=top;i ++)
{
	printf("%d", stack[i]);
}
}
