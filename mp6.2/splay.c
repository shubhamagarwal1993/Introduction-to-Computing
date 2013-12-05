/*
	Name: Shubham Agarwal
	NetID: sagarwl4
	Lab Section: AD9
*/


#include "splay.h"

NODE* getNewNode()
{
    /* Copy your implementation from MP 6.1 here */
    	NODE* newNode;									/*a pointer newnode with type NODE*/
		newNode = (NODE *) malloc(sizeof(NODE));		/*this will allocate dynamic memory*/
		return newNode;

}

NODE* insert_splay(NODE *root, int data)
{
    /* Your implementation goes here */
    
    
    root = NULL;
    root = insert(root, data);
    root = search(root, data);
    splay(root, **root);		/**/
    return root;
}    
    
    
    
NODE* insert(NODE *root, int data)
{
    /* Your implementaion goes here */
    /* This function is very similar to the one in MP6.1 with a few modifications */

	NODE *newNode;
	if(root == NULL)
	{
		newNode = getNewNode();
		newNode->left = newNode->right = NULL;			/*new node with 2 subnodes & cleared*/
		newNode->data = data;							/*put data in the new root created*/
		newNode->parent = NULL;
	} 
	else
	{	
		if(data < root->data)							/*choosing place for data, left/right*/		
		{
		root->left = insert(root->left,data);	
		root->left->parent = root;	
		}
		else if(data > root->data)						/*choosing place for data, left/right*/
		{
		root->right = insert(root->right,data);
		root->right->parent = root;
		}
	
	}
return root;
}

void preorder(NODE *root)
{
    /* Copy your implementation from MP 6.1 here */
    
     if (root != NULL)
    {
    	printf("%d ",root->data);								/*print the data on the root*/
    	preorder(root->left);									/*traverse left of root and print*/
    	preorder(root->right);									/*traverse right of root and print*/
    }
}

void inorder(NODE *root)
{
    /* Copy your implementation from MP 6.1 here */


	if (root != NULL)
    {
	    inorder(root->left);									/*traverse left of root and print*/	
	    printf("%d ",root->data);								/*print the data on the root*/
	    inorder(root->right);									/*traverse right of root and print*/
	}    

}

void postorder(NODE *root)
{
    /* Copy your implementation from MP 6.1 here */

	if (root != NULL)
    {
		postorder(root->left);									/*traverse left of root and print*/
    	printf("%d ",root->data);								/*print the data on the root*/
    	postorder(root->right);									/*traverse right of root and print*/
    }    

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
    	*root = temp;
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
