/*
	Name: Shubham Agarwal
	NetID: sagarwl4
	Lab Section: AD9
*/


#include "bst.h"

NODE* getNewNode()
{
    /* Your implementation goes here */

	if (root == NULL)
	{
		NODE* temp = getNewNode();
	}
	
	return ;
}

NODE* findMax(NODE *root)
{
    /* Your implementation goes here */
    
    
    if (root == NULL)
    {
    	return NULL
    }
    
    else
    {
    	if (root->right == NULL)
    	{
    		return root;
    	}
    	else 
    		return findMax(root->right)
    
    
    }	
    
    
    
    
    
    
    
    
    
    
}



NODE* insert(NODE *root, int data)
{
    /* Your implementation goes here */

	if(root == NULL)
	{
		NODE* temp = getNewNode();
		temp->left = temp->right = NULL;
		temp->data = data;
		return temp;
	} 
	if(data < root->data)
	{
		root->left = insert(root->left,data);		
	}
	else if(data > root->data)
	{
		root->right = insert(root->right,data);
	}
	return root;
}


NODE* delete(NODE *root, int data)
{
    /* Your implementation goes here */
    
    
    
    if (root == NULL)
    {
    	printf("Element not found in the tree");
    }
    
    else if (data < root->data)
    {
    	root->left = delete(root->left, data)
    }
    
    else if (data < root->data)
    {
    	root->right = delete(root->right, data)
    }
    
    else
    {
    	if(root->left != NULL && root->right != NULL)
    	{
    		maxNode = findMax(root->left);
			root->data = maxNode();
			root->left = delete (root->left,) 
		}
 		else if (root->left != NULL || root->right != NULL)
 		{
 			if (root->left != NULL)
 			{
 				root = root->left;
 			}
 			else
 				root = root->right;
 				
    	}
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}

void preorder(NODE *root)
{
    /* Your implementation goes here - root/left/right*/
    
    
    if (root != NULL)
    {
    	printf("%d\t",root->data);				//print the data on the root//
    	preorder(root->left);					//traverse left of root and print//
    	preorder(root->right);					//traverse right of root and print//
    }
}

void inorder(NODE *root)
{
    /* Your implementation goes here left/node/right*/

	    if (root != NULL)
    {
    	inorder(root->left);					//print the data on the left//
    	{
    		printf("%d\t", root->data);
    	}
    	
    	
		printf("%d", );							//print the original root//
    	
    	
    	inorder(root->right);					//print the data on the right//
    	{
    		printf("%d\t", root->data);
    	}

    }

}

void postorder(NODE *root)
{
    /* Your implementation goes here - left/right/root*/

    if (root != NULL)
    {
    	postorder(root->left);					//print the data on the left//
    	{
    		printf("%d\t", root->data);
    	}
    	
    	postorder(root->right);					//print the data on the right//
    	{
    		printf("%d\t", root->data);
    	}

		printf("%d", );							//print the original root//
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
