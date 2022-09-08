#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;

    //constructer creator
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void insertAtTail(Node* &head,int val)
{
    Node *newNode = new Node(val);

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

void insertAtHead(Node* &head,int val)
{
    // s1: newNode creation
    Node * newNode = new Node(val);
    // s2: update of newNode->Next
    newNode->Next = head;
    // s3: update of head
    head = newNode;
}

void display(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->Next!=NULL)
        {
            cout<< " -> ";
        }
        n = n->Next;
    }
    cout<<endl<<endl;
}

int main()
{
    Node* head = NULL;

    int value;

    //Choice 1: Insertion at Head
    //Choice 2: Insertion at Tail
    cout<<"Choice 1: Insertion at Head" <<endl<<"Choice 2: Insertion at Tail"<<endl<<"Choice 0: Exit"<<endl<<endl;

    cout<<"Your Choice: ";
    int choice;
    cin>>choice;

    while(choice != 0)
    {
        cout<<"Enter the value : ";
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
        cout<<"Your Choice: ";
        cin>>choice;
    }

    display(head);

    return 0;
}

/*



*/
