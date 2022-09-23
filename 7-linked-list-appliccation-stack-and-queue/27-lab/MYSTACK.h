#include<bits/stdc++.h>
using namespace std;

template<typename N>class Node{
public:
    N value;
    Node *next;
    Node *prev;

    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }

};

//Stack <float> st;
template <typename S>class Stack
{
    Node <S> *head;
    Node <S> *top;
    int count = 0;

public:

    Stack()
    {
        head = NULL;
        top = NULL;
    }

    //Push
    void push(S val)
    {
        Node <S> *newNode = new Node <S> (val);

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
    S pop()
    {
        Node <S> *delNode;
        delNode = top;
        S chk;

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
    S Top()
    {
        S chk;
        if(top == NULL)
        {
            cout<<"Stack Underflow. There is no element in TOP."<<endl;

        }
        else
        {
            chk = top->value;
        }
        return chk;
    }

};



