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


void level_order(Node *root)
{
	if (root == NULL)
    {
        return;
    }

	queue<Node *> q;

	q.push(root);
	q.push(NULL);

	while (!q.empty())
  	{
    	Node*chkNode=q.front();
    	q.pop();

    	if(chkNode!=NULL)
      	{
        	cout<<chkNode->data<<" ";
        	if(chkNode->leftChild != NULL)
        	{
            	q.push(chkNode->leftChild) ;
        	}

        	if(chkNode->rightChild!=NULL)
        	{
            	q.push(chkNode->rightChild) ;
        	}
    	}
    	else
    	{
        	if(!q.empty())
         	q.push(NULL);
    	}
	}
	cout<<endl<<endl;
}

void level_order_reverse(Node *root)
{
	if (root == NULL)
    {
        return;
    }

	queue<Node *> q;
	stack<int> p;

	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{
    	Node* chkNode = q.front();
    	q.pop();

    	if(chkNode != NULL)
    	{
        	p.push(chkNode->data);

        	if(chkNode->rightChild!=NULL)
        	{
            	q.push(chkNode->rightChild) ;
        	}

        	if(chkNode->leftChild!=NULL)
        	{
            	q.push(chkNode->leftChild) ;
        	}
     	}

        else
        {
            if(!q.empty())
            q.push(NULL);
        }
	}

    while(!p.empty())
    {
        int reverse = p.top();
        cout<<reverse<<" ";
        p.pop();
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

    string levelorderreversetraversal = "";

    level_order_reverse(allNodes[0]);

    cout<<levelorderreversetraversal;

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
