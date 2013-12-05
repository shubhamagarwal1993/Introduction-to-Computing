#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
} NODE;

NODE* getNewNode();
NODE* insert(NODE*, int);
NODE* insert_splay(NODE*, int);
void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);
NODE* search(NODE*, int);
void splay(NODE*, NODE**);
void left_rotate(NODE*, NODE**);
void right_rotate(NODE*, NODE**);
