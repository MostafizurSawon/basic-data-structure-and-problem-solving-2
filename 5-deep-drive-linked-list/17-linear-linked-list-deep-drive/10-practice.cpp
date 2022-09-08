#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;

    Node (int val)
    {
        value = val;
        Next = NULL;
    }
};

void insertAtHead(Node* &head,int value)
{
    //New Node Creation
    Node * newNode = new Node(value);

    //Insert before head
    newNode->Next = head;

    //New head address
    head = newNode;
}

void insertAtTail(Node* &head,int value)
{
    Node *newNode = new Node(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
}

void display(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->Next!=NULL)
        {
            cout<<" -> ";
        }
        n=n->Next;
    }
    cout<<endl<<endl;
}

int main()
{
    Node* head = NULL;

    int value;

    cout<<"Choice 1: Insert value at head."<<endl<<"Choice 2: Insert value at tail"<<endl<<"Choice 0: Exit"<<endl<<endl;

    cout<<"Your Choice: ";
    int choice;
    cin>>choice;

    while(choice!=0)
    {
        cout<<"Enter your value: ";
        cin>>value;
        switch(choice)
        {
            case 1:
                insertAtHead(head,value);
                break;

            case 2:
                insertAtTail(head,value);
                break;
        }
        cout<<"Your choice: ";
        cin>>choice;
    }

    display(head);

    return 0;
}
