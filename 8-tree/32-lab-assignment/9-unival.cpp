

bool isUnivalTree(Node* root)
{

    if(!root)
    {
        return true;
    }

    if(root->leftChild != NULL && root->data != root->leftChild->data)
    {
        return false;
    }

    if(root->rightChild != NULL && root->data != root->rightChild->data)
    {
        return false;
    }

    return isUnivalTree(root->leftChild) && isUnivalTree(root->rightchild);
}
