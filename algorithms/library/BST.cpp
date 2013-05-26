class node
{
	public:
		int data;
		node *left, *right;
};

node *insert(node *t, int x)
{
	if(t == NULL)
	{
		t = new node;
		t->data = x;
		t->left = t->right = NULL;
	}
	else if(t->data > x)
	{
		t->left = insert(t->left, x);
	}
	else
	{
		t->right = insert(t->right, x);
	}

	return t;
}

void inorder(node *t)
{
	if(t == NULL)
	{
		return;
	}

	inorder(t->left);
	printf("%d ", t->data);
	inorder(t->right);
}

void postorder(node *t)
{
	if(t == NULL)
	{
		return;
	}

	postorder(t->left);
	postorder(t->right);
	printf("%d ", t->data);
}

void preorder(node *t)
{
	if(t == NULL)
	{
		return;
	}

	printf("%d ", t->data);
	preorder(t->left);
	preorder(t->right);
}

void print(node *t)
{
	inorder(t);
	printf("\n");
}
