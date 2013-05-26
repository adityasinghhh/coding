#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
class node 
{
	public:
		pair<double, double> point;
		node *right, *left;
};

bool sortx(pair<double, double> p1, pair<double, double> p2)
{
	return (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second));
}

bool sorty(pair<double, double> p1, pair<double, double> p2)
{
	return (p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first));
}

int k = 2;

node *kdtree(pair<double, double> *pointList, int size, int depth = 0) 
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

	printf("%d: %lf %lf\n", level, t->point.first, t->point.second);

	if(t->right != NULL)
		print(t->right, level+1);
}
	
double a, b, c, d;

void kdSearch(node *t, int depth = 0)
{
	if(t == NULL)
		return;

	printf("Checking: %lf %lf\n", t->point.first, t->point.second);
	if(t->point.first >= a && t->point.first <= c && t->point.second >= b && t->point.second <= d)
		printf("%lf %lf\n", t->point.first, t->point.second);

	int axis = depth%k;

	if(axis)
	{
		if(t->point.second >= b)
			kdSearch(t->left, depth+1);
		else if(t->point.second <= d)
			kdSearch(t->right, depth+1);
	}
	else
	{
		if(t->point.first >= a)
			kdSearch(t->left, depth+1);
		else if(t->point.first <= c)
			kdSearch(t->right, depth+1);
	}
}

int main()
{
	int t, m, n, i;
	double x, y, a, b, c, d;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &m);
		scanf("%d", &n);
	
		pair<double, double> pointList[n+1];

		for(i=0; i<n; i++)
		{
			scanf("%lf %lf", &(pointList[i].first), &(pointList[i].second));
		}

//		sort(pointList.begin(), pointList.end(), sortx);

		node *root  = kdtree(pointList, n, 0);

		print(root, 0);

		while(m--)
		{
			scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

			kdSearch(root, 0);
		}

		printf("\n");
	}

	return 0;
}
