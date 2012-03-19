#include<iostream>
#include<cmath>
using namespace std;
       struct node {
       struct node *next;
       int val;

       };
/* Write your custom functions here */
node* insert(int n);
node * subtractLinkedLists(node * h1, node * h2){
    /*
       The above structure has already been defined, please do NOT redefine, you can just start using as node * x; 
     */
    int h1Num=0,h2Num=0;
    node * a=h1, *b=h2;
    while(a!=NULL)
    {
        h1Num++;
        a=a->next;
    }
    while(b!=NULL)
    {
        h2Num++;
        b=b->next;
    }
    a=h1;b=h2;
    node *out;
    int diff=    (h1Num-h2Num);
    if(diff!=0)
    {
        if(diff<0)
        {
            for(int i=0;i<(-diff);i++)
                b=b->next;
        }
        else
        {
            for(int i=0;i<diff;i++)
                a=a->next;
        }
    }
        node *n;
    for(int i=0;i<(h1Num<h2Num?h1Num:h2Num);i++)
    {
        if(i==0)
        {
            n=out=new node();
        //    cout<<"out=n:"<<out;
        }
        else
        {
            n->next=new node();
            n=n->next;
        }

cout<<"a-b"<<a->val<<","<<b->val<<endl;
        n->val=a->val - b->val;
        a=a->next;b=b->next;
    }
    node* t=h1Num>h2Num?h1:h2;
    node *t1,*t2;
    int i=0;
    while(i<abs(diff))
    {
        t1=insert(t->val);
        if(i==0)
            t2=t1;
        cout<<"t1,t2after ="<<t1<<","<<t2<<endl;
        t=t->next;t1=t1->next;
        i++;
    }
        cout<<"t1,t2after while"<<t1<<","<<t2<<endl;
    t2->next=t1=out;
    return t2;


}
node* insert(int n)
{
    node * a=new node();
    a->val=n;
    a->next=NULL;
    return a;
}
int main()
{
    node * a=insert(5);
    node * ra=a;
    a=a->next=insert(4);
    a=a->next=insert(3);
    a=a->next=insert(2);
    a=a->next=insert(1);
    a=a->next=insert(11);
    node * b=insert(4);
    node * rb=b;
    b=b->next=insert(3);
    b=b->next=insert(2);
    b=b->next=insert(1);
    a=ra;b=rb;
    node * out= subtractLinkedLists(a,b);
    while(a!=NULL)
    {
        cout<<a->val<<",";
        a=a->next;
    }
    while(b!=NULL)
    {
        cout<<b->val<<",";
        b=b->next;
    }
//    */
            //cout<<"out=n:"<<out;
    cout<<endl;
    while(out!=NULL)
    {
        cout<<out->val<<",";
        out=out->next;
    }
    
}
