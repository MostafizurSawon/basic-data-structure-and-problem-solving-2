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

bool isMirror( Node* root1, Node* root2)
{

	if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 && root2 && root1->val == root2->val)
    {
        return isMirror(root1->left, root2->right)
        && isMirror(root1->right, root2->left);
    }

	return false;
}

bool isSymmetric(Node* root)
{

	return isMirror(root, root);
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
