#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int val;
	Node* Next;
};

Node* insertionTail (Node* head)
{
	int val;
	cin>>val;

	Node* newNode = new Node();

	newNode->val = val;
	newNode->Next = NULL;

	Node* temp;

	if(head == NULL)
	{
        head = newNode;
    	return head;
	}
	else
    {
        temp = head;
    }

    while(temp->Next!=NULL)
   	{
       	temp = temp->Next;
   	}
   	temp->Next = newNode;
    return head;
}

Node* changeN(Node* head)
{
    if(head == NULL)
    {
        return head;
    }

	Node* temp = head;

	while(temp != NULL)
	{
    	if(temp->val%2==0)
    	{
        	temp->val = -1;
    	}
    	temp=temp->Next;

	}
	return head;

}

void print(Node* n)
{
	while(n!=NULL)
	{
    	cout<<n->val;
    	if(n->Next!=NULL)
        {
            cout<<"  ->  ";
        }
    	n = n->Next;
	}
	cout<<endl<<endl;
}

int main(){

    Node* head=NULL;

    int n;
    cin>>n;

    while(n--)
    {
        head = insertionTail(head);
    }

    head = changeN(head);

    print(head);

    return 0;
}
