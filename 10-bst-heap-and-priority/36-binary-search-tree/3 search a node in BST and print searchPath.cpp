#include<bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};


void printTree(treeNode* root, int level);
void spacePrint(int level);

void inOrder(treeNode* root,string &chk)    //left root right
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root->leftChild,chk);

    chk += (to_string(root->data)) + " ";

    inOrder(root->rightChild,chk);
}

void preOrderTraversal(treeNode* root,string &chk)   //root left right
{
    if(root == NULL)
    {
        return;
    }

    chk += to_string(root->data);

    preOrderTraversal(root->leftChild,chk);

    preOrderTraversal(root->rightChild,chk);
}

void postOrder(treeNode* root,string &chk)  //left right root
{
    if(root == NULL)
    {
        return;
    }

    postOrder(root->leftChild,chk);

    postOrder(root->rightChild,chk);

    chk += to_string(root->data);
}


void printTree(treeNode* root, int level)
{
    if(root == NULL)    //when the tree is empty
    {
        return;
    }

    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        cout<< root->data <<endl;
        return;
    }
    else    //case 2
    {
        cout<<endl;
        spacePrint(level);
        cout<< "Root: "<<root->data<<endl;
    }

    if(root->leftChild != NULL)
    {
        spacePrint(level);
        cout<< "Left: ";
        printTree(root->leftChild, level+1);
    }

    if(root->rightChild != NULL)
    {
        spacePrint(level);
        cout<< "Right: ";
        printTree(root->rightChild, level+1);
    }

}

void spacePrint(int level)
{
    for(int i=0;i<level;i++)
    {
        cout<<"  ";
    }
}

int levelOrderTraversal(treeNode* root,string &chk, int k)
{
    if(root == NULL)
    {
        return -1;
    }

    int level = 0;

    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);

    int max = -9999;

    while(!q.empty())
    {
        treeNode* chkNode = q.front();
        q.pop();
        if(chkNode != NULL)
        {
            if(level == k)
            {
                if(max<chkNode->data)
                {
                    max = chkNode->data;
                }
            }

            cout << chkNode->data<< " ";
            chk += to_string(chkNode->data);
            if(chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
            else
            {
                if(!q.empty())
                {
                    q.push(NULL);
                    level++;
                }
            }
        }
    }
    return max;
}

int searchInOrder(int inOrder[], int current, int start, int end)
{
    for(int i = start; i<=end; i++)
    {
        if(inOrder[i] == current)
        {
            return i;
        }
    }
}

treeNode* buildTreePreIn(int preOrder[], int inOrder[], int start, int end)
{
    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode* newNode = new treeNode(current);

    if(start == end)
    {
        return newNode;
    }

    int pos = searchInOrder(inOrder,current,start, end);

    newNode->leftChild  = buildTreePreIn(preOrder, inOrder, start, pos-1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos+1, end);

    return newNode;
}

void printLeaves(treeNode *root)
{
    if(root == NULL) return;

    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        cout<< root->data << " ";
        return;
    }

    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void printLeftNonLeaves(treeNode *root)
{
    if(root == NULL) return;

    if(root->leftChild != NULL)     //atkai silo 1
    {
        cout<< root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
    else if(root->rightChild != NULL)
    {
        cout<< root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
}

void printRightNonLeaves(treeNode *root)
{
    if(root == NULL) return;

        if(root == NULL) return;

    if(root->rightChild != NULL)     //atkai silo 1
    {
        cout<< root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
    else if(root->leftChild != NULL)
    {
        cout<< root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }

}

void boundaryTraversal(treeNode* root)
{
    if(root == NULL) return;
    cout << root->data << " ";

    //LB Non-leaves
    printLeftNonLeaves(root->leftChild);

    //RB leaves
    printLeaves(root->leftChild);

    //RB Leaves
    printLeaves(root->rightChild);

    //RB Non-leaves
    printRightNonLeaves(root->rightChild);
}

treeNode* insertionBST(treeNode* root, int value)
{
    treeNode* newNode = new treeNode(value);

    //case 1
    if(root == NULL)
    {
        root = newNode;
        return root;
    }

    //value< root->data
    if(value < root->data)
    {
        root->leftChild = insertionBST(root->leftChild,value);
    }

    //value> root->data
    else if(value > root->data)
    {
        root->rightChild = insertionBST(root->rightChild, value);
    }
    return root;
}

treeNode* searchBST(treeNode* root, int value)
{
    //
    if(root == NULL)
    {
        return NULL;
    }
    //
    if(root->data == value)
    {
        cout<<root->data;
        return root;
    }

    //
    else if(value<root->data)
    {
        cout<<root->data<<" -> ";
        searchBST(root->leftChild, value);
    }

    //
    else
    {
        cout<<root->data<<" -> ";
        searchBST(root->rightChild, value);
    }
}


int main()
{
    int n;
    cin>>n;

    treeNode* root = NULL;

    for(int i=0; i<n; i++)
    {
        int value;
        cin>>value;

        root = insertionBST(root, value);
    }

    string traversal = "";
    inOrder(root, traversal);

    cout<< traversal<<endl;


    int key;
    cout<<endl<<"Yout desired value : ";
    cin>>key;

    if(searchBST(root, key) == NULL)
    {
       cout<<endl<<"Value does nooooooot exist in the BST!"<<endl;
    }
    else
    {
        cout<<endl<<"Value exists in the BST!"<<endl;
    }
    cout<<endl<<endl;

    return 0;
}

/*

9
11 5 9 43 34 1 2 7 21
time -> logn
*/



