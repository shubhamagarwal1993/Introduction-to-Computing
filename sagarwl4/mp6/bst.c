/*
	Name: Shubham Agarwal
	NetID: sagarwl4
	Lab Section: AD9
*/


#include "bst.h"

NODE* getNewNode()
{
    /* Your implementation goes here */

		NODE* newNode;											/*a pointer newnode with type NODE*/
		newNode = (NODE *) malloc(sizeof(NODE));				/*this will allocate dynamic memory*/
		return newNode;
}

NODE* findMax(NODE *root)
{
    /* Your implementation goes here */
    
    if (root == NULL)
    {
    	return NULL;
    }
    else														/*this will find the max number from the tree */
    {
    	if (root->right == NULL)
    	{
    		return root;
    	}
    	else 
    	{
    		return findMax(root->right);
    	}
    }	
}

NODE* insert(NODE *root, int data)
{
    /* Your implementation goes here */

	NODE *newNode;
	if(root == NULL)
	{
		newNode = getNewNode();
		newNode->left = newNode->right = NULL;					/*create a new node with 2 subnodes and clear them*/
		newNode->data = data;									/*put data in the new root created*/
		return newNode;
	} 
	else if(data < root->data)									/*we are decideing whether to place data in left or right subnode*/		
	{
		root->left = insert(root->left,data);		
	}
	else if(data > root->data)									/*we are decideing whether to place data in left or right subnode*/
	{
		root->right = insert(root->right,data);
	}
	return root;
}

NODE* delete(NODE *root, int data)
{
    /* Your implementation goes here */

   	NODE * maxNode; 
    if (root == NULL)
    {
    	printf("Element not found in the tree");				/*error check message if we try deleting a void root*/
    }
    else if (data < root->data)
    {
    	root->left = delete(root->left, data);					/*here we delete the corresponding subnode data*/
    }
    else if (data > root->data)
    {
    	root->right = delete(root->right, data);
    }
    else
    {
    	if(root->left != NULL && root->right != NULL)			/*here we properly delete each element to prevent memory leaks*/
    	{
    		
    		maxNode = findMax(root->left);
			root->data = maxNode->data;
			root->left = delete (root->left, maxNode->data); 
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
    	else return NULL;
    }
    return root;
}

void preorder(NODE *root)						 				/* print order - root/left/right*/
{
    /* Your implementation goes here*/	
    
    if (root != NULL)
    {
    	printf("%d ",root->data);								/*print the data on the root*/
    	preorder(root->left);									/*traverse left of root and print*/
    	preorder(root->right);									/*traverse right of root and print*/
    }
}

void inorder(NODE *root)										/*print order - left/node/right*/
{
    /* Your implementation goes here*/ 

	if (root != NULL)
    {
	    inorder(root->left);									/*traverse left of root and print*/	
	    printf("%d ",root->data);								/*print the data on the root*/
	    inorder(root->right);									/*traverse right of root and print*/
	}    
}

void postorder(NODE *root)										/* print order - left/right/root*/
{
    /* Your implementation goes here*/ 

	if (root != NULL)
    {
		postorder(root->left);									/*traverse left of root and print*/
    	printf("%d ",root->data);								/*print the data on the root*/
    	postorder(root->right);									/*traverse right of root and print*/
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
