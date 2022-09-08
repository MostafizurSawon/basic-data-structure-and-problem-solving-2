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

void insertionAtSpecificPosition(Node* &head,int pos,int val);

int searchByValueUniqe(Node* &head,int key);

void searchByValueDuplicate(Node* &head,int key);

Test searchByValueDuplicateReturn(Node* &head,int key);

void searchByValueUniqe(Node* &head, int searchValue, int value);



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

int searchByValueUniqe(Node* &head,int key)
{
    Node *temp = head;
    int count = 1;

    if(temp == NULL)
        {
            return -1;
        }

    while(temp->value != key)
    {
        if(temp->Next == NULL)
        {
            return -1;
        }
        count++;
        temp = temp->Next;
    }
    return count;
}

void searchByValueDuplicate(Node* &head,int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size+1], k=1;
    int count = 1;
    int flag = 0;

    while(temp != NULL)
    {
        if(temp->value == key)
        {
            //cout<<count<<" ";
            position[k]=count;
            k++;
            flag=1;
        }
        temp = temp->Next;
        count++;
    }
    cout<<endl;

    if(flag==0)
    {
        cout<<"Not Found!"<<endl;
    }
    else{
        position[0] = k;
        cout<<"The value is found at position: ";
        for(int i=1; i<position[0];i++)
        {
            cout<<position[i];
            if(i<position[0]-1)
            {
                cout<<",";
            }
        }
        cout<<endl;
    }
}

Test searchByValueDuplicateReturn(Node* &head,int key)
{
    Node *temp = head;
    Test T;
    int k=1;
    int count = 1;

    while(temp != NULL)
    {
        if(temp->value == key)
        {
            //cout<<count<<" ";
            T.position[k]=count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void searchByValueUniqe(Node* &head, int searchValue, int value)
{
    //Step 1: Search the position of the value
    int position;
    position = searchByValueUniqe(head, searchValue);

    //Step 2: Insert the value at the position + 1;
    insertionAtSpecificPosition(head, position+1,value);

}


int main()
{
    Node* head = NULL;

    int value,position;

    //Choice 1: Insertion at Head
    //Choice 2: Insertion at Tail
    cout<<"Choice 1: Insertion at Head" <<endl
    <<"Choice 2: Insertion at Tail"<<endl
    <<"Choice 3: Insertion at a specific position."
    <<endl<<"Choice 4: Search a Specific Value (Uniqe list)"
    <<endl<<"Choice 5: Search a Specific Value (Duplicate list)"
    <<endl<<"Choice 6: Insertion after a Specific Value (Uniqe list)"
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
            cout<<"Enter your value for searching: ";
            cin>>value;
            position = searchByValueUniqe(head,value);
            if(position != -1)
            {
                cout<<"The number is at position: "<<position<<endl;
            }
            else{
                cout<<"The number is not yet in the List."<<endl;
            }
            break;

        case 5:
            cout<<"Enter your value for searching: ";
            cin>>value;
            //searchByValueDuplicate(head,value);
            Test T;
            T = searchByValueDuplicateReturn(head,value);
            if(T.position[0]==1){
                cout<<"The Searched value is not yet in the list."<<endl;
            }
            else{
                int size = T.position[0];
                cout<<"The value is found at Position: "<<endl;
                for(int i=1;i<size;i++)
                {
                    cout<<T.position[i];
                    if(i<size-1)
                    {
                        cout<<", ";
                    }

                }
            }
            break;

        case 6:
            cout<<"Enter the value to search: ";
            int searchValue;
            cin>>searchValue;
            cout<<"Enter the value to insert: ";
            cin>>value;
            searchByValueUniqe(head,searchValue, value);
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


