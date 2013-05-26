#include<stdio.h>

using namespace std;

class node 
{
	public:
		int data;
		node *left, *right;
};

void inorder(node*);
node *insert(node*, int);
void preorder(node*);
void postorder(node*);
