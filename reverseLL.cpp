#include<iostream>
using namespace std;

struct node 
{
    int a;
    node * next;
};

void addNode(node ** HEAD ,int data)
{
    node * h = *HEAD;

    if(h == NULL)
    {
        node * t = new node();
        t->a = data;
        t-> next = NULL;
        *HEAD = t;
    }
    else
    {
        while(h)
        {
            if(h->next == NULL)
                break;
            h = h->next;
        }
        node * t = new node();
        t->a = data;
        t-> next = NULL;
        h->next = t;
    }
}
void reverseLL(node ** HEAD)
{
    if(*HEAD == NULL)
        return;
    node * h = *HEAD;
    node * prev = NULL;
    while(h)
    {
        node * nxt = h->next;
        h->next = prev;
        prev = h;
        if(nxt == NULL)
        {
            *HEAD = h;
            break;
        }
        h = nxt;
    }
}
void printLL(node * HEAD)
{
    node * h = HEAD;
    while(h)
    {
        cout<<" "<<h->a;
        h = h->next;
    }
    cout<<endl;
}
int main()
{
    node * H = NULL;
    for(int i =0;i<30;i++)
    {
        addNode(&H,i);       
    }
    printLL(H);
    reverseLL(&H);
    printLL(H);
}
