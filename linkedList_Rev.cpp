#include<iostream>
using namespace std;
struct Node
{
    int num;
    Node* next;
    static Node* HEAD;
    static Node* LAST;
    static void  initialize();
    static void addNode(int num);
};
Node* Node::HEAD=NULL;
Node* Node::LAST=NULL;
void Node::initialize()
{
    //Node* ll=new Node();
    //ll->next=NULL;
    HEAD=LAST=NULL;
    //return ll;
}
void Node::addNode(int num)
{
    //cout<<"addNode\n";
    Node * n=new Node();
    n->num=num;
    n->next=NULL;
    if(HEAD==NULL)
    {
        //cout<<"HEAD==NULL\n";
        LAST=HEAD=n;
    }
    else
    {
        //cout<<"else n="<<n<<"\n";
        LAST->next=n;
        LAST=n;
    }
}
void reverseLinkedList(Node * head)
{
    Node* nowLast= head;

    head=head->next;
    Node* oneBehind=nowLast;
    while(head->next!=NULL)
    {
        Node* Next=head->next;//increment
        head->next=oneBehind;
        oneBehind=head;
        head=Next;
    }
    head->next=oneBehind;
    nowLast->next=NULL;
    Node::HEAD=head;
    Node::LAST=nowLast;
}
int main()
{
   Node::initialize();
    //cout<<"HEAD,LAST after init\n"<<Node::HEAD<<","<<Node::LAST;
    //cout<<"list after init\n"<<list;
    for(int i=0;i<99999;i++)
        Node::addNode(i);
    Node* l1=Node::HEAD;
    for(;l1!=NULL;l1=l1->next)
        cout<<"num:"<<l1->num<<"\n";
    cout<<"HEAD"<<Node::HEAD->num<<"\n";
    cout<<"LAST"<<Node::LAST->num<<"\n";
    cout<<"Now reversing the list efficiently!!\n";
    reverseLinkedList(Node::HEAD);
    l1=Node::HEAD;
    for(;l1!=NULL;l1=l1->next)
        cout<<"num:"<<l1->num<<"\n";
    cout<<"HEAD"<<Node::HEAD->num<<"\n";
    cout<<"LAST"<<Node::LAST->num<<"\n";
}

