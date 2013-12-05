#include "splay.h"

NODE* getNewNode()
{
    /* Copy your implementation from MP 6.1 here */
}

NODE* insert_splay(NODE *root, int data)
{
    /* Your implementation goes here */
}

NODE* insert(NODE *root, int data)
{
    /* Your implementaion goes here */
    /* This function is very similar to the one in MP6.1 with a few modifications */
}

void preorder(NODE *root)
{
    /* Copy your implementation from MP 6.1 here */
}

void inorder(NODE *root)
{
    /* Copy your implementation from MP 6.1 here */
}

void postorder(NODE *root)
{
    /* Copy your implementation from MP 6.1 here */
}


NODE* search(NODE *root, int data)
{
    /* Your implementaion goes here */
}

void left_rotate( NODE *node, NODE **root ) 
{
    /* Your implementaion goes here */
}
 
void right_rotate( NODE *node, NODE **root ) 
{
    /* Your implementaton goes here */
}

void splay(NODE *node , NODE **root) 
{
    /* Your implementation goes here */
}

int main()
{
    int choice, data;
    NODE *root = NULL;
    NODE *temp = NULL;
    while(1)
    {
        printf("----------------------------------\n");
        printf("Menu:\n");
        printf("----------------------------------\n");
        printf("1 - Insert\n");
        printf("2 - Pre-Order\n");
        printf("3 - In-Order\n");
        printf("4 - Post-Order\n");
        printf("5 - Exit\n");
        printf("----------------------------------\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the data to insert:");
                    scanf("%d",&data);
                    root = insert_splay(root, data);
                    printf("Data inserted successfully\n");
                    break;
            case 2: printf("Pre-Order traversal: ");
                    preorder(root);
                    printf("\n");
                    break;
            case 3: printf("In-Order traversal: ");
                    inorder(root);
                    printf("\n");
                    break;
            case 4: printf("Post-Order traversal: ");
                    postorder(root);
                    printf("\n");
                    break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
                     continue;
        }
    }
    return 0;
}
