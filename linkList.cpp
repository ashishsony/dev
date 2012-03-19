#include<iostream>
using namespace std;
struct Node
{
    int num;
    Node* next;
    static Node* HEAD;
    static Node* LAST;
    static Node * initialize();
    static void addNode(int num);
};
Node* Node::HEAD=NULL;
Node* Node::LAST=NULL;
Node * Node::initialize()
{
    Node* ll=new Node();
    ll->next=NULL;
    HEAD=LAST=ll;
    return ll;
}
void Node::addNode(int num)
{
    cout<<"addNode\n";
    if(HEAD==LAST)
    {
        cout<<"HEAD==LAST\n";
        HEAD->num=num;
    }
    else
    {
        cout<<"else\n";
        LAST->next=new Node();
        LAST->next->num=num;
        LAST->next->next=NULL;
        LAST=LAST->next;
    }
}
int main()
{
    Node* list=Node::initialize();
    cout<<"HEAD,LAST after init\n"<<Node::HEAD<<","<<Node::LAST;
    for(int i=0;i<10;i++)
        Node::addNode(i);
    Node* l1=list;
    for(;l1->next!=NULL;l1=l1->next)
        cout<<"num:"<<l1->num;

}
