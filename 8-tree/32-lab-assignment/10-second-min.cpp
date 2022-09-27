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

int second_minimum(Node *root)
{
    if(root == NULL)
    {
        return true;
    }

    int secondMin = INT_MAX;
    int minV = INT_MAX;
	queue<Node *> q;

    q.push(root);

    Node* temp = q.front();
	while(!q.empty())
  	{
    	Node* chkNode=q.front();
    	q.pop();

    if(chkNode!=NULL)
    {
        if (chkNode->data < minV)
        {
            secondMin = minV;
            minV = chkNode->data;
        }
        else if (chkNode->data < secondMin && chkNode->data != minV)
        {
            secondMin = chkNode->data;
        }
    }

    if(chkNode->rightChild != NULL)
	{
        q.push(chkNode->rightChild) ;
	}

 	if(chkNode->leftChild != NULL)
   	{
    	q.push(chkNode->leftChild) ;
   	}

 	}
 	if(secondMin == INT_MAX)
 	{
     	return -1;
 	}
 	else
    {
       return secondMin;
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

    //string invert = "";
    int s = second_minimum(allNodes[0]);

    cout<<s<<endl;

    return 0;
}

/*

9
2  1  2
1  3  4
2  5  6
3 -1 -1
4 -1 -1
5  7  8
6 -1 -1
7 -1 -1
8 -1 -1

*/
