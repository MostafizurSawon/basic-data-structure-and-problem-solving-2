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


void insertAtHead(Node* &head,int val);

void insertAtTail(Node* &head,int val);

void display(Node* n);

void insertionAtSpecificPosition(Node* &head,int pos,int val);

int countLength(Node* &head)
{
    int count = 0;
    Node *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->Next;
    }
    return count;
}


void insertionAtSpecificPosition(Node* &head,int pos,int val)
{

}


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

    int value,position;

    //Choice 1: Insertion at Head
    //Choice 2: Insertion at Tail
    cout<<"Choice 1: Insertion at Head" <<endl<<"Choice 2: Insertion at Tail"<<endl<<"Choice 3: Insertion at a specific position."<<endl<<"Choice 0: Exit"<<endl<<endl;

    cout<<"Your Choice: ";
    int choice;
    cin>>choice;

    while(choice != 0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter the value : ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter the value : ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<<"Enter your desired position: ";
            cin>>position;
            cout<<"Enter value: ";
            cin<<value;
            insertionAtSpecificPosition(head,position,value);
            break;

        default:
            break;
        }
        cout<<"Your Choice: ";
        cin>>choice;
    }

    cout<<"Linked List: ";

    display(head);

    cout<<endl;

    cout<<"Length of the list: "<<countLength(head)<<endl;


    return 0;
}

/*



*/

