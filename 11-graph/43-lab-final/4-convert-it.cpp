#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node* leftChild;
    Node* rightChild;

    Node(int val)
    {
        this->value = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};


int main()
{
    int n;
    cin>>n;

    priority_queue<int,vector<int> >q;
    q.push(n);

    priority_queue<int,vector<int> >p;
    p.push(n);

    while(!q.empty())
    {
        int current = q.top() ;
        q.pop();

        int a, b;
        cin>>a>>b;

        if(a != -1)
        {
            q.push(a);
            p.push(a);
        }

        if(b != -1)
        {
            q.push(b);
            p.push(b);
        }
    }

    int Q;
    cin>>Q;

    while(Q--)
    {
        int typ;
        cin>>typ;

        if(typ == 1)
        {
            int key;
            cin>>key;

            p.push(key);
        }

        else if(typ == 2)
        {
            cout<<p.top()<<endl;
            p.pop();
        }
    }

    return 0;
}
