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

    while(temp->Next != NULL)
   	{
       	temp = temp->Next;
   	}

   	temp->Next = newNode;

    return head;
}

void delPos(Node* head, int M, int N)
{
	Node* newNode = head;
	Node* temp;

	while(newNode != NULL)
	{
    	for(int i=1; i<M; i++)
    	{
        	newNode = newNode->Next;
    	}

    	temp = newNode->Next;

    	for(int i=0;i<N; i++)
    	{
         	Node* delNode = temp;
        	temp = temp->Next;
        	delete(delNode);
    	}
    	newNode->Next = temp;
    	newNode = temp;
	}
}

void print(Node* n)
{
	while(n != NULL)
	{
    	cout<<n->val;

    	if(n->Next != NULL)
        {
            cout<<" -> ";
        }

    	n = n->Next;
	}
}

int main()
{
    Node *head=NULL;

    int X,M,N;
    cin>>X;
    cin>>M>>N;

    while(X--)
    {
       head = insertionTail(head);
    }

    delPos(head, M, N);
    print(head);

    return 0;
}
