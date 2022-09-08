#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }

};

class Stack
{
    Node *head;
    Node *top;
    int count = 0;

public:

    Stack()
    {
        head = NULL;
        top = NULL;
    }

    //Push
    void push(int val)
    {
        Node *newNode = new Node(val);

        if(head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }

    //Pop
    int pop()
    {
        Node* delNode;
        delNode = top;
        int chk = -1;

        // There is no element in the stack     <<Underflow
        if(head == NULL)
        {
            cout<<"Stack Underflow"<<endl;
            return chk;
        }


        if(top == head)     //There is only one element
        {
            head = top = NULL;
        }

        else        //There is more than one element
        {
            top = delNode->prev;
            top->next =NULL;
        }
        chk = delNode->value;
        delete delNode;
        count--;
        return chk;
    }

    //Empty
    bool empty()
    {
        if(head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //Size
    int size()
    {
        return count;
    }

    //Top
    int Top()
    {
        int chk;
        if(top == NULL)
        {
            cout<<"Stack Underflow. There is no element in TOP."<<endl;
            chk = -1;
        }
        else
        {
            chk = top->value;
        }
        return chk;
    }

};



