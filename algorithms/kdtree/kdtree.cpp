#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
class node 
{
	public:
		pair<int, int> point;
		node *right, *left;
};

bool sortx(pair<int, int> p1, pair<int, int> p2)
{
	return (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second));
}

bool sorty(pair<int, int> p1, pair<int, int> p2)
{
	return (p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first));
}

int k = 2;

node *kdtree(pair<int, int> *pointList, int size, int depth = 0) 
{
	if(!size)
		return NULL;

	if(size == 1) 
	{
		node *temp = new node;
		temp->point = pointList[0];

		return temp;
	}

	int axis = depth%k;
	int middle = size/2;

	if(axis)
		nth_element(pointList, pointList+middle, pointList+size, sorty);
	else
		nth_element(pointList, pointList+middle, pointList+size, sortx);

	node *temp = new node;
	temp->point = pointList[middle];

	temp->left = kdtree(pointList, middle, depth+1);
	temp->right = kdtree(pointList+middle+1, size-middle-1, depth+1);

	return temp;
}

void print(node *t, int level)
{
	if(t->left != NULL)
		print(t->left, level+1);

	printf("%d: %d %d\n", level, t->point.first, t->point.second);

	if(t->right != NULL)
		print(t->right, level+1);
}
	
int a, b, c, d;

void kdSearch(node *t, int depth = 0)
{
	if(t == NULL)
		return;

	if(t->point.first >= a && t->point.first <= c && t->point.second >= b && t->point.second <= d)
		printf("%d %d ", t->point.first, t->point.second);

	int axis = depth%k;

	if(axis)
	{
		if(t->point.second >= b)
			kdSearch(t->left, depth+1);
		if(t->point.second <= d)
			kdSearch(t->right, depth+1);
	}
	else
	{
		if(t->point.first >= a)
			kdSearch(t->left, depth+1);
		if(t->point.first <= c)
			kdSearch(t->right, depth+1);
	}
}

int main()
{
	int t, m, n, i;
	int x, y;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &m);
		scanf("%d", &n);
	
		pair<int, int> pointList[n+1];

		for(i=0; i<n; i++)
			scanf("%d %d", &(pointList[i].first), &(pointList[i].second));

		node *root  = kdtree(pointList, n, 0);

		//print(root, 0);

		while(m--)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);

			kdSearch(root, 0);
			printf("\n");
		}
	}

	return 0;
}
