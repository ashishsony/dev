/* Write your custom functions here */
#include<iostream>
using namespace std;

       struct node {
           static node* root;
       struct node *left,*right;
       node()
       {
           left=right=root=NULL;
       }
       node(int i)
       {
           val=i;
           right=left=NULL;
       }
       void insert(int i,int dir)
       {
            if(dir<1)    
            {
                node* nxt=root;
                node* prev;
                while(nxt!=NULL)
                {
                    prev=nxt;
                    nxt=nxt->left;
                }
                prev->left=new node(i);
            }
            else
            {
                node* nxt=root;
                node* prev;
                while(nxt!=NULL)
                {
                    prev=nxt;
                    nxt=nxt->right;
                }
                prev->right=new node(i);
            }
       }
       int val;
       };
int L=0,R=0,lL=0,rL=0,lR=0,rR=0;
node* node::root=NULL;
int Max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}
int traverse1(node*,int);
int diameterOfTree(node * root) {
     
    traverse1(root->left,-1);
    int a=max(lL,rL);
    traverse1(root->right,1);
    a+=max(lL,rL);
    return a;
}

int traverse1(node* root,int dir)
{
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
int main()
{
    node *node1=new node();
    node1->root=node1;
    node1->insert(1,-1);
    node1->insert(2,1);
    node1->left->left->insert(3,-1);
    node1->left->right->insert(4,-1);
    node1->left->right->left->insert(5,-1);
    node1->left->right->right->insert(6,-1);

    node1->right->left->insert(7,-1);
    node1->right->left->left->insert(8,-1);
    node1->right->left->left->left->insert(9,-1);
    node1->right->left->left->left->left->insert(10,-1);
    node1->right->left->left->left->left->left->insert(11,-1);
    node1->right->left->left->left->left->right->insert(12,-1);
cout<<"Dia:"<<diameterOfTree(node1);

}
