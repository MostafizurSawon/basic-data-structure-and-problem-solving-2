#include <bits/stdc++.h>
using namespace std;

class Node{

public:
	int val;
	Node* Next;

	Node(int val)
	{
        this-> val= val;
    	Next = NULL;
	}
};

void insertTail(int val,Node* &head)
{
	Node* newNode = new Node(val);
	if(head == NULL)
	{
    	head = newNode;
    	return;
	}
	Node* temp = head;
	while(temp->Next != NULL)
	{
    	temp=temp->Next;
	}
	temp->Next = newNode;
}

void printNow(Node* &head)
{
	Node* temp = head;

	while(temp != NULL)
	{
    	cout<< temp->val;
    	temp = temp->Next;
    	if(temp != NULL)
        {
            cout<<"->";
        }
	}
	cout<<endl;
}

Node* delNode(Node* &head)
{
	Node* temp = head;
	Node* p;
	Node* ptr = NULL;

	while(temp)
	{
    	p = temp;
    	int sum = 0;

    	bool flag = false;

    	while(p)
    	{
        	sum += p->val;

        	if(sum==0)
        	{
            	temp = p;
            	flag = true;
        	}

        	p = p->Next;
    	}

    	if(!flag )
        {
            insertTail(temp->val,ptr);
        }


    	temp = temp->Next;
	}
	return ptr;
}

int main()
{
	Node* head = NULL;

	int n;
	cin>>n;

	while(n--)
	{
	    int value;
        cin>>value;
        insertTail(value,head);
	}

	Node* temp;
	temp = delNode(head);

	printNow(temp);

    return 0;
}
