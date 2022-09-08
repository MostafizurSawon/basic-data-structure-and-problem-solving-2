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


struct Test{
    int position[1000];
};

void insertAtHead(Node* &head,int val);

void insertAtTail(Node* &head,int val);

void display(Node* n);

void insertionByValueUniqe(Node* &head, int searchValue, int value);

void deletionAtHead(Node* &head);

void deletionAtTail(Node* &head);

void deletionAtSpecificPosition(Node* &head,int position);

void deletionByValueUniqe(Node* &head,int value);



void insertAtTail(Node* &head,int val)
{
    Node *newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }

    Node *temp = head;

    while(temp->Next != head)
    {
        temp = temp->Next;
    }
    newNode->Next = head;   //// or, newNode->Next = temp->Next;
    temp->Next = newNode;
}

void insertAtHead(Node* &head,int val)
{
    // s1: newNode creation
    Node * newNode = new Node(val);

    // s2: update of newNode->Next
    newNode->Next = head;

    //Update the tail with New Head
    if(head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }


    Node* temp = head;
    while(temp->Next != head)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;

    // s4: update of head
    head = newNode;
}

void display(Node* head)
{
    if(head == NULL)
    {
        cout<<"The linked list is empty!"<<endl;
        return;
    }

    Node* temp = head;

    do
    {
        cout<<temp->value;
        temp = temp->Next;
        if(temp!=head)
        {
            cout<< " ---> ";
        }
    }while(temp != head);
    cout<<endl<<endl;
}

int countLength(Node* &head)
{
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp=temp->Next;
    }while(temp != head);

    return count;
}


void insertionAtSpecificPosition(Node* &head,int pos,int val)
{
    int i=0;
    Node* temp = head;

    while(i<pos-2)
    {
        temp = temp->Next;// 2 3
        i++; //1 2
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}


void deletionAtHead(Node* &head)
{
    Node* temp = head;
    if(temp != NULL)
    {
        //Step 1
        Node* delNode = temp;

        //Step 2
        while(temp ->Next != head)
        {
            temp = temp->Next;
        }

        //Step 3
        temp->Next = delNode->Next;

        //Step 4
        head = delNode->Next;
        delete delNode;
    }
    else
    {
       cout<<"There is no value in the Linked list"<<endl;
    }

}

void deletionAtTail(Node* &head)
{
    Node* temp = head;

    if(temp != NULL && temp->Next != head)
    {
        while(temp->Next->Next != head)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
    }

    else
    {
        //Head is NULL
        if(temp == NULL)
        {
            cout<<"There is no value in the Linked list"<<endl;
        }

        //Head is tail
        else{
            deletionAtHead(head);
        }
    }
}

void deletionAtSpecificPosition(Node* &head,int position)
{
    Node* temp = head;
    if(position<=countLength(head))
    {
        if(position == 1)
        {
            deletionAtHead(head);
        }
        else if(position==countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
        int i=1;
        while(i<position-1)
        {
            temp = temp->Next;
            i++;
        }
        Node* delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
        }

    }
    else{
        //position is out of range
        //if(position>countLength(head))
        //{
            cout<<"Position Out of bound"<<endl;
        //}

        //Linklist is Null
        //cout<<"There is No Value in the the Linked List"<<endl;
    }
}



int main()
{
    Node* head = NULL;

    int value,position;

    //Choice 1: Insertion at Head
    //Choice 2: Insertion at Tail
    cout<<"Choice 1: Insertion at Head"
    <<endl<<"Choice 2: Insertion at Tail"
    <<endl<<"Choice 3: Insertion at a specific position."
    <<endl<<"Choice 4: Deletion at Head"
    <<endl<<"Choice 5: Deletion at Tail"
    <<endl<<"Choice 6: Deletion at a specific Position"

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
            cout<<"Enter your desired position: ";
            cin>>position;
            cout<<"Enter value: ";
            cin>>value;
            insertionAtSpecificPosition(head,position,value);
            break;

        case 4:
            deletionAtHead(head);
            break;

        case 5:
            deletionAtTail(head);
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







