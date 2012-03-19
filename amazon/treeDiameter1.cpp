#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int L=0,R=0,lL=0,rL=0,lR=0,rR=0;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* function to create a new node of tree and returns pointer */
struct node* newNode(int data);

/* returns max of two integers */
int max(int a, int b);

/* function to Compute height of a tree. */
int height(struct node* node);

/* Function to get diameter of a binary tree */
int diameter(struct node * tree)
{
//    cout<<"\ndata111111111111:"<<tree->data; 
    /* base case where tree is empty */
    if (tree == 0)
        return 0;

    /* get the height of left and right sub-trees */
    int lheight = height(tree->left);
    int rheight = height(tree->right);

    /* get the diameter of left and right sub-trees */
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    /* Return max of following three
       1) Diameter of left subtree
       2) Diameter of right subtree
       3) Height of left subtree + height of right subtree + 1 */
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 

/* UTILITY FUNCTIONS TO TEST diameter() FUNCTION */

/*  The function Compute the "height" of a tree. Height is the
    number f nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
    /* base case tree is empty */
    if(node == NULL)
        return 0;

    /* If tree is not empty then height = 1 + max of left
       height and right heights */
    return 1 + max(height(node->left), height(node->right));
} 

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

/* returns maximum of two integers */
int max(int a, int b)
{
    return (a >= b)? a: b;
}    

int traverse1(node* root,int dir);
int diameterOfTree(node * root) {
    traverse1(root->left,-1);
    int a=max(lL,rL);
    traverse1(root->right,1);
    a+=max(lL,rL);
    return a;
}

int traverse1(node* root,int dir)
{
//    cout<<"\ndata22222222222222:"<<root->data; 
    if(root!=NULL)
    {
        if(dir==-1)
            lL++;
        if(dir==1)
            rL++;
        traverse1(root->left,-1);
        traverse1(root->right,1);
    }
}
/* Driver program to test above functions*/
int main()
{

    /* Constructed binary tree is
       1
       /   \
       2      3
       /  \
       4     5
     */
    node * ar[22];
 /*   struct node *root=  newNode(1);
    root->left        = newNode(2);
      root->right       = newNode(3);
        root->left->left  = newNode(4);
          root->left->right = newNode(5);/**/
    struct node *root= ar[0]= newNode(1);
    ar[1]=root->left        = newNode(2);
    ar[2]=root->right       = newNode(3);
    ar[3]=root->left->left  = newNode(4);
    ar[4]=root->left->right = newNode(5);
   // cout<<"ar[4]==root->left->right"<<(ar[4]==root->left->right);
    ar[5]=ar[4]->left = newNode(7);
    ar[6]=ar[4]->right = newNode(8);

    ar[7]=ar[2]->right = newNode(6);
    ar[8]=ar[7]->right = newNode(9);
    ar[9]=ar[8]->right = newNode(10);
    ar[10]=ar[9]->left = newNode(11);
    ar[11]=ar[9]->right = newNode(12);
    ar[12]=ar[10]->left = newNode(13);
    ar[13]=ar[10]->right = newNode(14);
//------------
    ar[14]=ar[5]->right=newNode(15);
    ar[15]=ar[14]->left=newNode(16);
    ar[16]=ar[14]->right=newNode(17);
    ar[17]=ar[16]->right=newNode(18);
    ar[18]=ar[17]->left=newNode(19);
    ar[19]=ar[18]->right=newNode(20);
    ar[20]=ar[19]->left=newNode(21);
    ar[21]=ar[20]->right=newNode(22);

    /*
     
    ar[5]=root->left->right->left = newNode(7);
    ar[6]=root->left->right->right = newNode(8);
    ar[7]=root->right->right = newNode(6);
    ar[8]=root->right->right->right = newNode(9);
    ar[9]=root->right->right->right->right = newNode(10);
    ar[10]=root->right->right->right->right->left = newNode(11);
    ar[11]=root->right->right->right->right->right = newNode(12);
    ar[12]=root->right->right->right->right->left->left = newNode(13);
    ar[13]=root->right->right->right->right->left->right = newNode(14);
     */
  /**/  
    printf("Diameter of the given binary tree is %d\n", diameter(root));
    printf("Diameter of the given binary tree is %d\n", diameterOfTree(root));

    return 0;
}
