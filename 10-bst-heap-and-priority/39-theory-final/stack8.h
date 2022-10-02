#include<bits/stdc++.h>
using namespace std;

template<typename N>
class Node
{
public:
    N data;
    Node* next;
    Node* prev;

    Node(N data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};


template<typename S>
class Stack
{
public:
    Node<S>* head;
    Node<S>* top;
    int size;

    Stack()
    {
        this->head = NULL;
        this->top = NULL;
        this->size = 0;
    }

    void push(S val)
    {
        Node<S>* newNode = new Node<S>(val);
        if(head == NULL){
            head = newNode;
            top = newNode;
            this->size++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        this->size++;
    }

    S pop()
    {
        S chk;
        if(head == NULL){
            cout<<"Empty stack!"<<endl;
            return chk;
        }
        if(this->size == 1)
        {
            S retVal = top->data;
            this->head = NULL;
            this->top = NULL;
            this->size--;
            return retVal;
        }

        Node<S>* delNode = top;
        top = delNode->prev;
        top->next = NULL;
        S returnVal = delNode->data;
        this->size--;
        delete delNode;

        return returnVal;
    }

    bool isEmpty(){
        return this->size == 0;
    }

    int getSize()
    {
        return this->size;
    }

    S getTop()
    {
        S topVal = top->data;
        return topVal;
    }

    S mid()
    {
        if(this->getSize() == 0)
        {
            cout<<"Sorry Empty Stack!"<<endl;
            return -1;
        }
        Node<S>* slowPtr = head;
        Node<S>* fastPtr = head;

        while(fastPtr!=NULL && fastPtr->next != NULL)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return slowPtr->data;
    }

    void iterateStack()
    {
        Node<S>* current = this->head;
        while(current!=this->top)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<current->next<<endl;
    }
};
