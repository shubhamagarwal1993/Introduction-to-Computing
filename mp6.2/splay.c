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
    NODE *newNode;
    newNode = NULL;
    root = insert(root, data);
    newNode = search(root, data);
    splay(newNode, &root);	
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
		newNode->left = newNode->right = NULL;		/*new node with 2 subnodes & cleared*/
		newNode->data = data;						/*put data in the new root created*/
		newNode->parent = NULL;
		return newNode;
	} 
	else
	{	
		if(data < root->data)						/*choosing place for data, left/right*/		
		{
			root->left = insert(root->left,data);	
			root->left->parent = root;	
		}
		else if(data > root->data)					/*choosing place for data, left/right*/
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
    	printf("%d ",root->data);					/*print the data on the root*/
    	preorder(root->left);						/*traverse left of root and print*/
    	preorder(root->right);						/*traverse right of root and print*/
    }
}


void inorder(NODE *root)
{
    /* Copy your implementation from MP 6.1 here */
	if (root != NULL)
    {
	    inorder(root->left);						/*traverse left of root and print*/	
	    printf("%d ",root->data);					/*print the data on the root*/
	    inorder(root->right);						/*traverse right of root and print*/
	}    
}


void postorder(NODE *root)
{
    /* Copy your implementation from MP 6.1 here */

	if (root != NULL)
    {
		postorder(root->left);						/*traverse left of root and print*/
    	postorder(root->right);						/*traverse right of root and print*/
		printf("%d ",root->data);					/*print the data on the root*/
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
return root;
}


void left_rotate( NODE *node, NODE **root ) 
{
    /* Your implementaion goes here */
    NODE *temp;
    temp = node->right;
    node->right = temp->left;
    if (temp->left != NULL)
    {
    	temp->left->parent = node;			
    } 
    temp->parent = node->parent;
    if (node->parent == NULL)
    {
    	*root = temp;
    }
    else if (node == node->parent->left)	
    {
    	node->parent->left = temp;
    }
    else
    {
    	node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}

 
void right_rotate( NODE *node, NODE **root ) 
{
    /* Your implementaton goes here */
	NODE *temp;
	temp = node->left;
    node->left = temp->right;
    if (temp->right != NULL)
    {
    	temp->right->parent = node;	
    } 
    temp->parent = node->parent;
    if (node->parent == NULL)
    {
    	*root = temp;
    }
    else if (node == node->parent->left)
    {
    	node->parent->left = temp;
    }
    else
    {
    	node->parent->right = temp;
    }
    temp->right = node;
    node->parent = temp;
}


void splay(NODE *node , NODE **root) 
{
    /* Your implementation goes here */
    while (node->parent != NULL)
    {
    	if (node->parent->parent == NULL)
    	{
    		if ((node->parent->left) == node)
    		{
    			right_rotate(node->parent, root);
    		}
    		else 
    		{
    			left_rotate(node->parent, root);
    		}
		}
		else if ((node->parent->left == node) && (node->parent->parent->left == node->parent))
		{
			right_rotate(node->parent->parent, root);
			right_rotate(node->parent, root);
		}
		else if ((node->parent->right == node) && (node->parent->parent->right == node->parent))
		{
			left_rotate(node->parent->parent, root);
			left_rotate(node->parent, root);
		}
		else if ((node->parent->left == node) && (node->parent->parent->right == node->parent))
		{
			right_rotate(node->parent, root);
			left_rotate(node->parent, root);
		}
		else 
		{
			left_rotate(node->parent, root);
			right_rotate(node->parent, root);
		}
  	}
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
