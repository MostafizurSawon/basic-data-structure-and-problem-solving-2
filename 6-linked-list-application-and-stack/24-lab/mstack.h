#include <bits/stdc++.h>
//#include”SawonStack.h
using namespace std;

template <typename n>
class Node
{
public:
	n val;
	Node* Next;
	Node* Prev;

	Node(n val)
	{
        this->val = val;
    	Next = NULL;
    	Prev = NULL;
	}
};

template <typename s>
class Stack
{
  Node<s>*head;
  Node<s>*top;

  int count=0;

  public:
    Stack()
  	{
        head = NULL;
        top = NULL;
  	}

  	void push(s val)
  	{
        Node<s>*newNode=new Node<s>(val);

        if(head==NULL)
        {
            head = top = newNode ;
            count++;
            return ;
        }
        else
        {
            top->Next = newNode;
            newNode->Prev = top;
            top = newNode;
            count++;
        }
  	}

    s pop()
    {
        Node<s>*delNode;
        delNode = top;

        s chk;

        if(top == head)
        {
            head = top = NULL;
        }

        else
        {
            top = delNode->Prev;
            top->Next = NULL;
        }

        chk = delNode->val;
        delete delNode;
        count--;

        return chk;
    }

    bool empty()
    {
        if(head == NULL)
        {
            return true;
        }
        else
        {
            return false ;
        }
    }

    s Top()
    {
        s chk;
        if(top==NULL)
        {
            cout<<"Sorry No element Found :("<<endl;
        }

        else
        {
           chk=top->val;
        }

    	return chk;
    }

    int size()
    {
       return  count;
    }

    s mid()
    {
        s chk;
        if(head==NULL)
        {
            cout<<"Sorry No Element Found :("<<endl;
        }
        Node<s>*slow = head;
        Node<s>*fast = head;

        while(fast != NULL && fast->Next != NULL)
        {
            slow = slow->Next;
            fast = fast->Next->Next;
        }

        chk= slow->val;
        return chk;
    }

};
