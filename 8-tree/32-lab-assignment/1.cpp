bool isSame(node* root1, node* root2)
{

    if (root1 == NULL && root2 == NULL)
   	 return true;


    if (root1 != NULL && root2 != NULL)
    {
   	 return
   	 (
   		 root1->data == root2->data &&
   		 isSame(root1->left, root2->left) &&
   		 isSame(root1->right, root2->right)
   	 );
    }


    return true;
}

