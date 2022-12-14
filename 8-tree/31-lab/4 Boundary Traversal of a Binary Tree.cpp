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

    chk += to_string(root->data);

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

int main()
{
    int n;
    cin>>n;

    treeNode* allNodes[n];

    for(int i=0; i<n; i++)
    {
        allNodes[i] = new treeNode(-1);
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

    //printTree(allNodes[0], 0);

    string inordertraversal = "";
    string preordertraversal = "";
    string postordertraversal = "";
    string levelordertraversal = "";

//    inOrder(allNodes[0], inordertraversal);
//    preOrder(allNodes[0], preordertraversal);
//    postOrder(allNodes[0], postordertraversal);
//    int maxValueAtK = levelOrderTraversal(allNodes[0], levelordertraversal,2);

    boundaryTraversal(allNodes[0]);

//    cout<<"Inorder Traversal : "<<inordertraversal<<endl;
//    cout<<"Preorder Traversal : "<<preordertraversal<<endl;
//    cout<<"Postorder Traversal : "<<postordertraversal<<endl;

    //cout<< endl << "Max value : "<< maxValueAtK<<endl<<endl;
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


Root:  0
Left:
    Root:1
    Left:3
    Right:4
Right:
    Root:2
    Left:
        Root:5
        Left:7
        Right:8
    Right:6

*/


