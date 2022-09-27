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


void average_level(Node* root)
{
	if (root == NULL) return;

	queue<Node *> q;

	double level = 0.00;
	double sum = 0.00;

	q.push(root);
	q.push(NULL);


	while (!q.empty())
  	{
    	Node* chkNode = q.front();
    	q.pop();

    	double av = sum/level;

    	if(chkNode != NULL)
        {
            sum += chkNode->data;
            level++;

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
            {
                cout<<av<<" ";
                q.push(NULL);
                level=0;
                sum=0;
            }
        }
    }
    double av = sum/level;
    cout<<av<<"  ";
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

    //string invert = "";
    average_level(allNodes[0]);

    //cout<<s<<endl;

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



