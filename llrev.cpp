void reverseLinkedList(Node * head)
{
	Node* nowLast= head;

	head=head->next;
	Node* oneBehind=nowLast;
	while(head->next!=null)
	{
		Node* Next=head->next;//increment
		head->next=oneBehind;
		oneBehind=head;
		head=Next;
	}
	head->next=oneBehind;
	nowLast->next=null;
	FIRST=head;
}