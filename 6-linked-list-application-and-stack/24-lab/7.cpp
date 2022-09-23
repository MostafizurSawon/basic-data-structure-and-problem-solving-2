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

	if(head==NULL)
	{
        head = newNode;
    	return head;
	}
	else
    {
    	temp = head;
    }

    while(temp->Next != NULL)
   	{
       	temp =temp->Next;
   	}

   	temp->Next = newNode;
    return head;
}

Node* reverseKNodes(Node* head, int k)
{
    Node* prev = NULL;
    Node* current = head;
    int count = 0;

    if(head == NULL)
    {
        return head;
    }

    Node* Next =head->Next;

    while (current != NULL && count < k)
    {
    	Next = current->Next;
    	current->Next = prev;
    	prev = current;
    	current = Next;
    	count++;
	}

	if(Next != NULL)
    {
       head->Next= reverseKNodes(Next, k);
    }

    return prev;
}

void print(Node* n)
{
	while(n!=NULL)
	{
    	cout<<n->val;

    	if(n->Next!=NULL)
        {
            cout<<" -> ";
        }
    	n = n->Next;
	}
}

int main()
{
   Node* head = NULL;

   int n,k;
   cin>>n;

    while(n--)
    {
       head = insertionTail(head);
    }

    cin>>k;
    head=reverseKNodes(head,k);
    print(head);

    return 0;
}
