 /*
 You are given a function isSumTree which takes in the root of a binary tree as it's parameter.
 Complete the function to return true if the given binary tree is a SumTree else false. A SumTree is a BinaryTree
 where the value of a node is equal to the sum of the nodes present in it's left subtree and the right subtree.

 An empty tree is a SumTree and the sum of an empty tree can be considered as zero.A leaf node is also considered as SumTree

 Sample Testcases:

 Input #00:

   6


 Output #00:
 1



 Input #01:

	6
  /   \
3		8
 Output #00:
 0

 */
 #include<iostream>
 #include<cstdio>
 #include<stdlib.h>
 using namespace std;
struct node {
        int val;
        struct node * right, * left;
};
int sumSubtree( node* root);
/* Write your custom functions here */
int isSumTree(node * root)
{
	if((root->left==NULL && root->right==NULL))
	{
		cout<<"11111111111\n";
		return 1;
	}
	int s1=0;
	s1=sumSubtree(root->left);
	int s2=0;
	s2=sumSubtree(root->right);
	if((s1+s2)==root->val)
		return 1;
	else
		return 0;

}
int sumSubtree(node* root)
{
	if(root==NULL)
		return 0;
	int s1;
	s1=sumSubtree(root->left);
	int s2;
	s2=sumSubtree(root->right);
	cout<<"s1+s2::"<<s1+s2<<endl;
	return s1+s2+root->val;
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(struct node));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
int main()
{
	node * ar[22];
	 /*   struct node *root=  newNode(1);
	    root->left        = newNode(2);
	      root->right       = newNode(3);
	        root->left->left  = newNode(4);
	          root->left->right = newNode(5);/**/
	    struct node *root= ar[0]= newNode(29);
	    ar[1]=root->left        = newNode(2);
	    ar[2]=root->right       = newNode(3);
	    ar[3]=root->left->left  = newNode(4);
	    ar[4]=root->left->right = newNode(5);
	   // cout<<"ar[4]==root->left->right"<<(ar[4]==root->left->right);
	    ar[5]=ar[2]->left = newNode(7);
	    ar[6]=ar[2]->right = newNode(8);

	    /*ar[7]=ar[2]->right = newNode(6);
	    ar[8]=ar[7]->right = newNode(9);
	    ar[9]=ar[8]->right = newNode(10);
	    ar[10]=ar[9]->left = newNode(11);
	    ar[11]=ar[9]->right = newNode(12);
	    ar[12]=ar[10]->left = newNode(13);
    ar[13]=ar[10]->right = newNode(14);/**/
    cout<<"isSum?:"<<isSumTree(root);
}