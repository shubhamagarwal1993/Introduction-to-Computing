#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE* getNewNode();
NODE* findMax(NODE*);
NODE* insert(NODE*, int);
NODE* delete(NODE*, int);
void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);
