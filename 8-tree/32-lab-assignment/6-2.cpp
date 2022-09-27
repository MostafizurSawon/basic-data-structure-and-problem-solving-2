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



void swapLeftnRight(Node* root)
{
    if (!root)
    {
        swap(root->leftChild, root->rightChild);
        swapLeftnRight(root->leftChild);
        swapLeftnRight(root->rightChild);
    }
}

Node* invert_tree(Node* root)
{
    if ((root == NULL) || ((root->leftChild == NULL)
                              && (root->rightChild == NULL)))
    {
      return root;
    }

    swapLeftnRight(root);
    return root;
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

    string invert = "";

    invert_tree(allNodes[0]);

    cout<<invert<<endl;

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
