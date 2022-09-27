#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int val)
    {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void zigzag_order(Node* root)
{

	if (root==NULL)
    {
        return;
    }

	stack<Node*> q;
	stack< Node*> p;

	q.push(root);

	bool l2r = true;

	while (!q.empty())
  	{
     	Node* chkNode = q.top();
    	q.pop();

    	if (chkNode!=NULL)
    	{
        	cout << chkNode->data << " ";

        	if(l2r == true)
        	{
        	    if (chkNode->rightChild!=NULL)
                {
                    p.push(chkNode->rightChild);
                }
            	if (chkNode->leftChild!=NULL)
                {
                    p.push(chkNode->leftChild);
                }
        	}

        	else
        	{
            	if (chkNode->rightChild)
                {
                    p.push(chkNode->rightChild);
                }

            	if (chkNode->leftChild)
                {
                    p.push(chkNode->leftChild);
                }

        	}
    	}

    	if (q.empty())
    	{
        	l2r = !l2r;
        	swap(q, p);
    	}
	}
}


int main()
{
    int n;
    cin>>n;

    Node* allNodes[n];

    for(int i=0; i<n; i++)
    {
        allNodes[i] = new Node(-1);
    }

    for(int i=0; i<n; i++)
    {
        int value, left, right;
        cin>>value>>left>>right;
        allNodes[i]->data = value;

        if(left>n-1 || right>n-1)
        {
            cout<< "Invalid Index" <<endl;
            break;
        }

        if(left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }

        if(right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    string zo = "";

    zigzag_order(allNodes[0]);

    cout<<zo;

    return 0;
}

/*

9
0  1  2
1  3  4
2  5  6
3 -1 -1
4 -1 -1
5  7  8
6 -1 -1
7 -1 -1
8 -1 -1

*/
