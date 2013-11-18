#include <stdio.h>
#include <stdlib.h>


typedef struct node_t
{
    int data;
    struct node_t *next;
} node;

void remove_duplicates(node * head);


// Fucnction to append nodes to the Linked list.
void append(node **head,int data)
{   
		
    node *temp,*n;

    temp = (node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;

    n = *head;

    if(*head==NULL)
    {   
        *head=temp;
    }
    else
    {  
        while(n->next !=NULL)
	{  
	    n=n->next;
	}
	
	n->next=temp;
    }
}


void printList(node *head)
{
    node *n = head;
 
    while(n != NULL)
    {
	    printf("%d ",n->data);
	    n = n->next;
    }
    printf("\n");
}


int main()
{
    node* head = NULL;

    append(&head,10);
    append(&head,10);
    append(&head,20);
    append(&head,30);
    append(&head,30);
    append(&head,30);
    append(&head,40);
    append(&head,50);
    append(&head,60);

    printf("Before:\n");
    printList(head);

    remove_duplicates(head);
    
    printf("After:\n");
    printList(head);

    while(head!=NULL)
    {
    	node *tempo = head;
    	
    	free(tempo);
    	
    	head = head-> next;
	}

    return 0;
}

void remove_duplicates(node * head)
{
    node* next_node;
    
    node* current_node = head;
	
	if(current_node==NULL)
	{
		return;
	}
	
	while(current_node->next!=NULL)
	{
		
		if(current_node -> data == current_node -> next -> data)
		{
			next_node = current_node->next->next;
			
			free(current_node->next);
			
			current_node -> next= next_node;
		}
		
		else
		{
			current_node = current_node -> next;
		}
	}
    
    
    
    
    
    
    
    	
}
