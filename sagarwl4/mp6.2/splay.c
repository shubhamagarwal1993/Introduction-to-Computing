/*
	Name: Shubham Agarwal
	NetID: sagarwl4
	Lab Section: AD9
*/


#include "splay.h"

NODE* getNewNode()
{
    /* Copy your implementation from MP 6.1 here */

}

NODE* insert_splay(NODE *root, int data)
{
    /* Your implementation goes here */
    
	NODE *newNode;    
    if (root == NULL)
	{
    	newNode = getNewNode();
    	newNode->left = newNode->right = NULL;
    	newNode->data = data;
    	newNode->parent = NULL;
    }
    else
    {
    	if(data < root->data)
    	{
    		root->left = insert(root->left, data);
    		root->left->parent = node;		//check
    	}
    	/*              ergt   */
    	else if (data > root->data)
    	{
    		root->right = insert(root->right, data)
    		root->right->parent = root;		//check
    	}
	}
return root;
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
    
    if (root == NULL)
    {
    	return root;
    }
    
    if (root->data == data)
    {
    	return root;
    }
    
    else if (data < root->data)
    {
    	search(root->left, data);
    }
    
    else
    {
    	search(root->right, data);
    }
}


void left_rotate( NODE *node, NODE **root ) 
{
    /* Your implementaion goes here */
    
    temp = root->right;
    root->right = temp->left;
    if (temp->left != NULL)
    {
    	temp->left->parent = node;			//check
    } 
    temp->parent = root->parent;
    if (root->parent == NULL)
    {
    	set root = temp;
    }
    else if (root == root->parent->left)	//check
    {
    	root->parent->left = temp;
    }
    else
    {
    	root->parent->right = temp;
    }
    temp->left = root;
    root->parent = temp;
}
 
void right_rotate( NODE *node, NODE **root ) 
{
    /* Your implementaton goes here */
	
	temp = root->left;
    root->left = temp->right;
    if (temp->right != NULL)
    {
    	temp->right->parent = node;			//check
    } 
    temp->parent = root->parent;
    if (root->parent == NULL)
    {
    	set root = temp;
    }
    else if (root == root->parent->left)	//check
    {
    	root->parent->left = temp;
    }
    else
    {
    	root->parent->right = temp;
    }
    temp->right = root;
    root->parent = temp;

}

void splay(NODE *node , NODE **root) 
{
    /* Your implementation goes here */
    
    while (root->parent != NULL)
    {
    	if (root->parent == NULL)
    	{
    		if (root->parent->left = root)
    		{
    			right_rotate(root->parent, root);
    		}
    		else 
    		{
    			left_rotate(root->parent, root);
    		}


    	}
    }
    
    
    
    
    
    
    
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
