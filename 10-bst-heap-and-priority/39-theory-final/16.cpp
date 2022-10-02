Node *invert_tree(Node *root)
{
    if (root == NULL)
    {
        return root;
    }

    invert_tree(root->left);

    swap(root->left, root->right);

    if(root->left)
    {
        if(root->left->left || root->left->right)
        {
            invert_tree(root->left);
        }
    }
    return root;
}
