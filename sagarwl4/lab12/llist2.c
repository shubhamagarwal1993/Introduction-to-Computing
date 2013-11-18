#include <stdio.h>
#include <stdlib.h>
typedef struct node_t
{
    int data;
    struct node_t *next;
} node;
void reverse(node** head);
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
    append(&head,20);
    append(&head,10);
    append(&head,90);
    append(&head,100);
    append(&head,80);
    append(&head,0);
    append(&head,4);
    append(&head,60);
    append(&head,05);
    printf("Before:\n");
    printList(head);
    //call your function here
	reverse(&head);
    printf("After:\n");
    printList(head);
    //free linked list here
	while(head!=NULL)
	{
		node* temp = head;
		head=head->next;
		free(temp);
	}
    return 0;
}
void reverse(node** head)
{
    //add your code here
    if(*head==NULL)
    	return;
	node* h=*head;
	node* prev=NULL;
	node* temp=h->next;
	while(h!=NULL)
	{
		h->next=prev;
		prev=h;
		if(temp==NULL)
			break;
		h=temp;
		temp=temp->next;
	}
	*head=h;
}
