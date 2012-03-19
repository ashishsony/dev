#include "tree.hh"
#include "tree_util.hh"
#include<iostream>
using namespace std;
int L=0,R=0,lL=0,rL=0,lR=0,rR=0;
/*struct node*;
node* node::root=NULL;
int Max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}
*/
typedef tree<int>::sibling_iterator node;
//int traverse1(node,int);
int traverse1(const tree<int>::iterator_base& it,int dir);
int diameterOfTree(const tree<int>::iterator_base& it) {
//    const iterator_base&
  //  it.node->first_child
    traverse1(it.node->first_child,-1);
    int a=max(lL,rL);
    traverse1(it.node->last_child,1);
    a+=max(lL,rL);
    return a;
}

int traverse1(const tree<int>::iterator_base& it,int dir)
{
    if(it.node!=NULL)
    {
        if(dir==-1)
            lL++;
        if(dir==1)
            rL++;
    traverse1(it.node->first_child,-1);
    traverse1(it.node->last_child,1);
    //    traverse1(root->first_child,-1);
      //  traverse1(root->last_child,1);
    }
}
/**/
int main(int, char **)
	{
	tree<int> tr;
tree<int>::iterator ii1;
tree<int>::iterator ii2;
	tr.insert(tr.begin(), 1);
	tree<int>::iterator i2 = tr.insert(tr.end(), 2);
	tree<int>::iterator i3 = tr.insert(tr.end(), 3);
	tr.append_child(i2, 4);
	ii1=tr.append_child(i2, 5);
	ii2=tr.append_child(i3, 6);
	ii1=tr.append_child(ii1, 7);
	ii1=tr.append_child(ii1, 8);
	ii2=tr.append_child(ii2, 9);
	ii2=tr.append_child(ii2, 10);
	ii1=tr.append_child(ii2, 11);
	tr.append_child(ii2, 12);
	tr.append_child(ii1, 13);
	tr.append_child(ii1, 14);
        //tree<int>::sibling_iterator iRoots=tr.begin();
        tree<int>::iterator_base iRoots=tr.begin();
cout<<"\nroot node data:"<<*++iRoots<<"\n";
cout<<"\nDia::"<<diameterOfTree(iRoots)<<"\n";
/*	tree<int>::iterator i4 = tr.insert(tr.end(), 7);
	tree<int>::iterator i5 = tr.insert(tr.end(), 5);
	tree<int>::iterator i6 = tr.insert(tr.end(), 6);
	tr.append_child(i6, 61);
	tr.append_child(i6, 62);
	tr.append_child(i6, 63);
	tr.append_child(i6, 64);
	tree<int>::iterator i7 = tr.insert(tr.end(), 7);
*/
	kptree::print_tree_bracketed(tr, std::cout);

	std::cout << std::endl;
	}
