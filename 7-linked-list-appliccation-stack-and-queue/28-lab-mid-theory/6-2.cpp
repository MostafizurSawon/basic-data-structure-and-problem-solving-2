#include <bits/stdc++.h>
using namespace std;

class Node{

public:
	int val;
	Node* Next;

	Node(int val)
	{
   	this->val = val;
    Next = NULL;
	}
};

void insertTail(int val,Node* &head)
{
	Node* newNode = new Node(val);

	if(head==NULL)
	{
    	head = newNode;
    	return;
	}
	Node* tmp = head;
	while(tmp->Next != NULL)
	{
    	tmp=tmp->Next;
	}
	tmp->Next = newNode;
}

void print(Node*&head)
{
    Node*n = head;
	while(n!=NULL)
	{
    	cout<<n->val<<" ";
    	n=n->Next;
	}
	cout<<endl;
}

void insert_position_value(Node*&head,int key,int value)
{
    Node*temp=head;
    Node*ptr=new Node(value);

    if(temp==NULL)
 	{
     	cout<<"Head is null"<<endl;
 	}

    while(temp->val!=key)
    {
        if(temp->Next==NULL)
        {
            cout<<"value not found"<<endl;
        }
        temp = temp->Next;
    }

 	ptr->Next = temp->Next;
	temp->Next = ptr;
}

void head_Deletion(Node*head)
{
	Node* temp=head;
	if(temp!=NULL)
	{
        head=temp->Next;
        delete(temp);
	}
	print(head);
}

int main()
{
	Node* head = NULL;
	insertTail(14,head);
	insertTail(25,head);
	insertTail(33,head);
	insertTail(47,head);

	int key=33,value=40;

    insert_position_value(head,key,value);

    head_Deletion(head);

    return 0;
}
