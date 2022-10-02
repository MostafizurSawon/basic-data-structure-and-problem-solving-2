#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* leftChild;
    Node*rightChild;

    Node(int val)
    {
        this->val = val;
        leftChild = NULL;
        rightChild = NULL;
    }

};

int counter = 0;

void checking(vector<int> vctr, string str)
{

    int x = 0;

    for (int i = vctr.size()-1; i>=0; i--)
    {
        int a = vctr[i];
        int b = vctr[(vctr.size()-1)-i];

        if (str[a] != str[b])
        {
            x = 1;
            break;
        }
    }

    if(x == 0)
    {
        counter++;
    }
}


void palindrome(Node *root, vector<int> vctr, string check)
{
    if(root == NULL)
    {
        return;
    }

    vctr.push_back(root->val);

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        //No leaf
        checking(vctr, check);
    }

    else
    {
        palindrome(root->leftChild, vctr, check);
        palindrome(root->rightChild, vctr, check);
    }
}


int main()
{
    string st;
    cin>>st;

    int n;
    cin>>n;

    Node* root=new Node(n);
    queue<Node*>q;

    q.push(root);

    while(!q.empty())
    {
        Node* current = q.front() ;
        q.pop();

        int x,y;
        cin>>x>>y;

        Node* a = NULL;
        Node* b = NULL;

        if(x != -1)
        {
            b = new Node(x);
        }

        if(y!=-1)
        {
            a = new Node(y);
        }

        current->leftChild = b;
        current->rightChild = a;

        if(b != NULL)
        {
            q.push(b);
        }

        if(a != NULL)
        {
            q.push(a);
        }
    }

    vector<int>vctr;
    palindrome(root, vctr, st);

    cout<<counter<<endl;

    return 0;
}
