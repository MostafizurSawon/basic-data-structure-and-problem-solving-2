#include<bits/stdc++.h>
using namespace std;

class doublyNode{
public:
    int val;
    doublyNode *next;
    doublyNode *prev;

    //constructer creator
    doublyNode(int val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtTail(doublyNode* &head,int val)
{
    doublyNode *newNode = new doublyNode(val);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    doublyNode *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtHead(doublyNode* &head,int val)
{
    // s1: newNode creation
    doublyNode * newNode = new doublyNode(val);

    //s2: update of head->prev
    head->prev = newNode;

    // s3: update of newNode->Next
    newNode->next = head;

    // s4: update of head
    head = newNode;
}

void display(doublyNode* n)
{
    while(n!=NULL)
    {
        cout<<n->val;
        if(n->next!=NULL)
        {
            cout<< " --> ";
        }
        n = n->next;
    }
    cout<<endl<<endl;
}

void displayReverse(doublyNode* &head)
{
    doublyNode* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    while(temp != NULL)
    {
        cout<<temp->val;
        if(temp->prev != NULL)
        {
            cout<< " --> ";
        }
        temp = temp->prev;
    }
    cout<<endl<<endl;
}


int countLength(doublyNode* &head)
{
    int count = 0;
    doublyNode *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}


int main()
{
    doublyNode* head = NULL;

    int value,position;

    //Choice 1: Insertion at Head
    //Choice 2: Insertion at Tail
    cout<<"Choice 1: Insertion at Head"
    <<endl<<"Choice 2: Insertion at Tail"
    <<endl<<"Choice 3: Reverse Print"


    <<endl<<"Choice 0: Exit"<<endl<<endl;

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
            displayReverse(head);
            break;

        default:
            break;
        }
        cout<<"Your Choice: ";
        cin>>choice;
    }

    cout<<"Doubly Linked List: ";

    display(head);

    cout<<endl;

    cout<<"Length of the Doubly list: "<<countLength(head)<<endl;


    return 0;
}

/*



*/






