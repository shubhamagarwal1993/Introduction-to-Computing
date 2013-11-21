#include "bst.h"

NODE* getNewNode()
{
    /* Your implementation goes here */
}

NODE* findMax(NODE *root)
{
    /* Your implementation goes here */
}

NODE* insert(NODE *root, int data)
{
    /* Your implementation goes here */
}

NODE* delete(NODE *root, int data)
{
    /* Your implementation goes here */
}

void preorder(NODE *root)
{
    /* Your implementation goes here */
}

void inorder(NODE *root)
{
    /* Your implementation goes here */
}

void postorder(NODE *root)
{
    /* Your implementation goes here */
}

int main()
{
    int choice, data;
    NODE *root = NULL;
    while(1)
    {
        printf("----------------------------------\n");
        printf("Menu:\n");
        printf("----------------------------------\n");
        printf("1 - Insert\n");
        printf("2 - Delete\n");
        printf("3 - Pre-Order\n");
        printf("4 - In-Order\n");
	printf("5 - Post-Order\n");
        printf("6 - Exit\n");
        printf("----------------------------------\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data to insert:");
                    scanf("%d",&data);
                    root = insert(root, data);
                    printf("Data inserted successfully\n");
                    break;
            case 2: printf("Enter the data to be deleted:");
                    scanf("%d",&data);
                    root = delete(root, data);
                    printf("Data deleted successfully\n");
                    break;
            case 3: printf("Pre-Order traversal: ");
                    preorder(root);
                    printf("\n");
                    break;
            case 4: printf("In-Order traversal: ");
                    inorder(root);
                    printf("\n");
                    break;
            case 5: printf("Post-Order traversal: ");
                    postorder(root);
                    printf("\n");
                    break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
                     continue;
        }
    }
    return 0;
}
