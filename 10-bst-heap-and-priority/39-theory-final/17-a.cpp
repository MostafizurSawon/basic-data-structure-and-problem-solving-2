void printLeaves(Node* root)
{
	if (root == nullptr)
    {
        return;
    }

	printLeaves(root->left);

	if(!(root->left) && !(root->right))
    {
        cout << root->data << " ";
    }

	printLeaves(root->right);
}

void printBoundaryLeft(Node* root)
{
	if (root == nullptr)
    {
        return;
    }

	if (root->left)
    {
    	cout << root->data << " ";
    	printBoundaryLeft(root->left);
	}

	else if (root->right)
    {
    	cout << root->data << " ";
    	printBoundaryLeft(root->right);
	}
}

void printBoundaryRight(Node* root)
{
	if (root == nullptr)
    {
        return;
    }

	if (root->right)
    {
    	printBoundaryRight(root->right);
    	cout << root->data << " ";
	}

	else if(root->left)
    {
    	printBoundaryRight(root->left);
    	cout << root->data << " ";
	}
}

void printBoundary(Node* root)
{
	if (root == nullptr)
    {
        return;
    }

	cout << root->data << " ";

	printBoundaryLeft(root->left);

	printLeaves(root->left);

	printLeaves(root->right);

	printBoundaryRight(root->right);
}
