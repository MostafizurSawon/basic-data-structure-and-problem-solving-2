void reverseDoubly(Node* head)
{
 	Node*temp = head;

    if(temp->Next==NULL)
    {
        cout<<temp->val;
        cout<<endl;
    }

    else
    {
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }

        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->prev;
        }
	cout<<endl;
	}
}
