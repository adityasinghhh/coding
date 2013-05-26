#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
class node
{
	public:
		int z;
		char ch;
		vector <node*> children;
};

node *root = NULL;
int l;
char a[10000];

void store(node **t, int i)
{
	if(i == l)
		return;
//	printf("%c\n", a[i]);

	int j;

	for(j=0; j<(*t)->z; j++)
		if((*t)->children[j]->ch == a[i])
		{
			store(&((*t)->children[j]), i+1);
			return;
		}

	if(j == (*t)->z)
	{
		node *temp = new node;

		temp->ch = a[i];
		temp->z = 0;

		(*t)->children.push_back(temp);

		if(i != l)
			store(&temp, i+1);

		(*t)->z++;
	}
}

void print_trie(node **t, int i)
{
	int j;

	for(j=0; j<i; j++)
		printf("\t");
	printf("%c\n", (*t)->ch);

	if((*t)->z == 0)
	{
		printf("\n");
		return;
	}

	for(j=0; j<(*t)->z; j++)
		print_trie(&((*t)->children[j]), i+1);
}

int main()
{
	root = new node;
	root->ch = ' ';
	root->z = 0;

	int i;
	node **temp1;

	while(scanf("%s", a) != EOF)
	{
		l = strlen(a);
		printf("%s\n", a);
		//printf("%d\n", l);
		//printf("%d\n", root->z);

		for(i=0; i<root->z; i++)
			if(root->children[i]->ch == a[0])
			{
				//printf("now");

				temp1 = &(root->children[i]);

				store(temp1, 1);
				break;
			}

		if(i == root->z)
		{
			node *temp = new node;
			temp->ch = a[0];
			store(&temp, 1);
			root->children.push_back(temp);
			root->z = root->z+1;
		}
	}

	//printf("here\n");
	print_trie(&root, 0);
}
