#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* Count the number of negative values stored in a tree */
int countNegatives(struct node* root)
{
    if(root == NULL)
        return 0;


    if(root->data < 0)
        return 1 + countNegatives(root->left) + countNegatives(root->right);
    else
        return countNegatives(root->left) + countNegatives(root->right);
}

int isSameTree(struct node *root1, struct node *root2)
{
    // both trees are empty
    // both trees are not empty
    // one tree is empty, the other one is not
    return 0;
}

void mirror(struct node* root)
{
    if(root == NULL) return;

    // recursive for left subtree
    // recursive for left subtree

    // swap the left subtree and the right subtree 
    // for the current node
}


void padding(char ch, int n)
{
    int i;
    for(i=0;i<n;i++)
        putchar(ch);
}
void printTree(struct node *root, int level)
{
    if(root == NULL){
        padding('\t',level);
        printf("*\n");

    }
    else{
        printTree(root->right,level+1);
        padding('\t', level);
        printf("%d\n", root->data);
        printTree(root->left, level+1);
    }
}
