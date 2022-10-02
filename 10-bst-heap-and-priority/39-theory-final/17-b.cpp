void zigzag_order(Node* root)
{
	if(root == NULL)
    {
        return;
    }

	stack<Node*> q;
	stack<Node*> p;

	q.push(root);

	bool lefttoright = true;

	while(!q.empty())
  	{
     	Node* current = q.top();
    	q.pop();

    	if(current != NULL)
    	{
        	cout<<current->val<< " ";

        	if(lefttoright)
        	{
            	if (current->leftChild!=NULL)
                {
                    p.push(current->leftChild);
                }

            	if (current->rightChild!=NULL)
                {
                    p.push(current->rightChild);
                }
        	}

        	else
        	{
            	if(current->rightChild)
                {
                	    p.push(current->rightChild);
                }

            	if(current->leftChild)
                {
                    p.push(current->leftChild);
                }
        	}
    	}

    	if (q.empty())
    	{
        	lefttoright = !lefttoright;
        	swap(q, p);
    	}
	}
}
