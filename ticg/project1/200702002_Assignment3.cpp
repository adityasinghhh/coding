#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
bool sortx(vector<int> p1, vector<int> p2)
{
	return (p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]) || (p1[0] == p2[0] && p1[1] == p2[1] && p1[2] < p2[2]));
}

bool sorty(vector<int> p1, vector<int> p2)
{
	return (p1[1] < p2[1] || (p1[1] == p2[1] && p1[0] < p2[0]) || (p1[0] == p2[0] && p1[1] == p2[1] && p1[2] < p2[2]));
}

bool sortz(vector<int> p1, vector<int> p2)
{
	return (p1[2] < p2[2] || (p1[2] == p2[2] && p1[0] < p2[0]) || (p1[2] == p2[2] && p1[0] == p2[0] && p1[1] < p2[1]));
}

/* Node Definition */
class RMQnode
{
	public:
		int start, end, max, pos;		
		RMQnode *left, *right;
};

class node
{
	public:
		vector<vector<int> > S;
		vector<int> child, position;
		node *left, *right;
		RMQnode *RMQroot;
};

vector<vector<node*> > tree;
int MAX;

/* Creates the Range Maxima Query Tree */
RMQnode *createRMQ(RMQnode *t, vector<vector<int> > S, int i, int j)
{
	t = new RMQnode;

	t->start = i;
	t->end = j;

	int ii, maxi = -1, pos;

//	printf("S[%d,%d]: ", i, j);
	for(ii=i; ii<=j; ii++)
	{
//		printf("(%d,%d,%d) ", S[ii][0], S[ii][1], S[ii][2]);
		if(maxi < S[ii][1])
		{
			maxi = S[ii][1];
			pos = ii;
		}
	}
//	printf("\n");

	t->max = maxi;
	t->pos = pos;

//	printf("Start: %d\tEnd: %d\tMaximum: %d\tPosition: %d\n", t->start, t->end, t->max, t->pos);
	
	t->left = t->right = NULL;

	if(i < j)
	{
//		printf("Going Left\n");
		t->left = createRMQ(t->left, S, i, (i+j)/2);
//		printf("Going Right\n");
		t->right = createRMQ(t->right, S, (i+j)/2+1, j);
	}

	return t;
}

/* Returns the index with maximum value in the given range */
int RangeMaxima(RMQnode *t, vector<vector<int> > S, int i, int j)
{
	if(i == j)
		return i;

	if(t->pos >= i && t->pos <= j)
		return t->pos;

	if(j <= (t->start + t->end)/2)
		return RangeMaxima(t->left, S, i, j);

	if(i > (t->start + t->end)/2)
		return RangeMaxima(t->right, S, i, j);

	int k1 = RangeMaxima(t->left, S, i, (t->start + t->end)/2);
	int k2 = RangeMaxima(t->right, S, (t->start + t->end)/2+1, j);

	return S[k1] > S[k2] ? k1 : k2;
}

/* Function to report the points in the range that have greater y-coordinate than 'yq' */
void Report(node *t, int i, int j, int yq)
{
	if(i > j)
		return;

//	printf("Checking for Range Maxima between %d and %d.\n", i, j);
	int k = RangeMaxima(t->RMQroot, t->S, i, j);
//	printf("Maximum 'y' occured at %d.\n", k);

	if(t->S[k][1] < yq)
		return;

	printf("%d %d %d ", t->S[k][0], t->S[k][1], t->S[k][2]);

	Report(t, i, k-1, yq);
	
	Report(t, k+1, j, yq);
}

void print(RMQnode *t)
{
	if(t->left != NULL)
		print(t->left);

	printf("Start: %d\tEnd: %d\tMaximum: %d\tPosition: %d\n", t->start, t->end, t->max, t->pos);

	if(t->right != NULL)
		print(t->right);			
}

int main()
{
	int no;

	scanf("%d", &no);

	while(no--)
	{
		tree.clear();

		vector<vector<int> > points;
		int i, n, x, y, z, j, k;

		int m;

		/* No. of queries */
		scanf("%d", &m);

		/* Scanning points */

		/* No. of input points */
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			vector<int> point;

			scanf("%d %d %d", &x, &y, &z);

			point.push_back(x);
			point.push_back(y);
			point.push_back(z);

			points.push_back(point);
		}

		/* Sort the points on z-coordinate */
		sort(points.begin(), points.end(), sortz);

		//	for(i=0; i<n; i++)
		//		printf("%d %d %d\n", points[i][0], points[i][1], points[i][2]);

		k = (int)log2(n)+1;
		MAX = 1<<k;

		//if(MAX != n)
		//	MAX = MAX<<1;

		//	printf("%d: %d\n", k, MAX);

		/* Create the tree structure */
		for(i=0; i<k; i++)
		{
			vector<node*> row;

			for(j=0; j<(1<<i); j++)
			{
				node *temp = new node;

				row.push_back(temp);
			}

			tree.push_back(row);
		}

		/* Create the lowest row of the tree, or the leaf row */

		vector<node*> row;
		for(j=0; j<(1<<k); j++)
		{
			node *temp = new node;

			if(j < n)
				temp->S.push_back(points[j]);

			row.push_back(temp);
		}
		tree.push_back(row);

		for(j=0; j<(1<<k); j++)
		{
			if(j < n)
			{
				//			printf("Creating Range Maxima Tree at %d,%d\n", i, j);
				tree[i][j]->RMQroot = createRMQ(tree[i][j]->RMQroot, tree[i][j]->S, 0, tree[i][j]->S.size()-1);
			}
		}

		/* From the leaf row, move upwards, filling in the values of the intermediate nodes */

		int left, right, leftSize, rightSize, ii, jj;
		for(i=k-1; i>=0; i--)
		{
			for(j=0; j<(1<<i); j++)
			{
				left = 2*j;
				right = 2*j+1;

				vector<vector<int> > leftS = tree[i+1][left]->S, rightS = tree[i+1][right]->S;

				/* Sort the points in the left and right children on x-coordinates */
				sort(leftS.begin(), leftS.end(), sortx);
				sort(rightS.begin(), rightS.end(), sortx);

				/* Merge the points */

				leftSize = leftS.size();
				rightSize = rightS.size();

				//			printf("left Size: %d\n", leftSize);
				//			printf("right Size: %d\n", rightSize);

				for(ii=0, jj=0; ii<leftSize && jj<rightSize;)
				{
					//				printf("Comparing (%d,%d,%d) and (%d,%d,%d)\n", leftS[ii][0], leftS[ii][1], leftS[ii][2], rightS[jj][0], rightS[jj][1], rightS[jj][2]);
					if(leftS[ii][0] < rightS[jj][0])
					{
						tree[i][j]->S.push_back(leftS[ii]);
						tree[i][j]->child.push_back(0);
						tree[i][j]->position.push_back(ii);
						//					printf("Pushed (%d,%d,%d)\n", leftS[ii][0], leftS[ii][1], leftS[ii][2]);
						ii++;
					}
					else
					{
						tree[i][j]->S.push_back(rightS[jj]);
						tree[i][j]->child.push_back(1);
						tree[i][j]->position.push_back(jj);
						//					printf("Pushed (%d,%d,%d)\n", rightS[jj][0], rightS[jj][1], rightS[jj][2]);
						jj++;
					}
				}

				while(ii != leftSize)
				{
					tree[i][j]->S.push_back(leftS[ii]);
					tree[i][j]->child.push_back(0);
					tree[i][j]->position.push_back(ii);
					//				printf("Pushed (%d,%d,%d)\n", leftS[ii][0], leftS[ii][1], leftS[ii][2]);
					ii++;
				}

				while(jj != rightSize)
				{
					tree[i][j]->S.push_back(rightS[jj]);
					tree[i][j]->child.push_back(1);
					tree[i][j]->position.push_back(jj);
					//				printf("Pushed (%d,%d,%d)\n", rightS[jj][0], rightS[jj][1], rightS[jj][2]);
					jj++;
				}

				//			printf("Creating Range Maxima Tree at %d,%d\n", i, j);
				/* Creates Range Maxima Tree at the tree node (i,j) */
				tree[i][j]->RMQroot = createRMQ(tree[i][j]->RMQroot, tree[i][j]->S, 0, tree[i][j]->S.size()-1);
			}
		}

		int size = tree[0][0]->S.size();
		/*
		   for(i=0; i<k; i++)
		   {
		   for(j=0; j<(1<<i); j++)
		   {
		   for(ii=0; ii<tree[i][j]->S.size(); ii++)
		   printf("%d,%d:(%d,%d,%d,%d) ", i, j, tree[i][j]->S[ii][0], tree[i][j]->S[ii][1], tree[i][j]->S[ii][2], tree[i][j]->child[ii]);
		   printf("\n");
		   }
		   }
		   */
		/*	print(tree[0][0]->RMQroot);

			printf("Done\n");
			printf("%d\n", tree[0][0]->S.size());
			for(i=0; i<n; i++)
			printf("%d %d %d\n", tree[0][0]->S[i][0], tree[0][0]->S[i][1], tree[0][0]->S[i][2]);
			*/
		/* Tree Constructed */

		/* Query Part */

		while(m--)
		{
			scanf("%d %d %d", &x, &y, &z);

			//		printf("Query: %d %d %d\n", x, y, z);

			/* continue if the maximum z-coordinate point has z-coordinate less than the z-coordinate of the query point */
			if(points[n-1][2] < z)
			{
				printf("\n");
				continue;
			}

			/* binary search on the points to determine the point in the sorted list below which all points have lower z-coordinate than the query z-coordinate */
			int l = 0, e = n-1, mid;

			while(l <= e)
			{
				mid = (l+e)/2;

				if(points[mid][2] < z && points[mid+1][2] >= z)
					break;

				else if(points[mid+1][2] < z)
					l = mid+1;
				else
					e = mid-1;
			}

			i = mid+1;

			//		printf("i: %d\t%d,%d,%d\n", i, points[i][0], points[i][1], points[i][2]);

			/* trace the path from the leaf determined above to the root of the tree */
			vector<pair<int, int> > path;

			int level = k-1;
			i /= 2;

			while(level != 0)
			{
				path.push_back(make_pair(level, i));
				i/=2;
				level--;
			}

			path.push_back(make_pair(level, i));

			int size = path.size(), size1;

			/*		printf("Path: ");
					for(i=0; i<size; i++)
					printf("%d,%d ", path[i].first, path[i].second);
					printf("\n");
					*/
			/* Go back on the path from root to the leaf, searching for on the right children (if that right child is not on the path, to avoid duplicate printing) */
			for(j=size-1; j>=0; j--)
			{
				int right = path[j].second*2+1;

				/* continue if the right child exists in the path */
				if(path[j-1].second == right)
					continue;

				size1 = tree[path[j].first][path[j].second]->S.size();

				/* search for the index of the point in the right child, below which all points have lower x-coordinate than the query x-coordinate */
				i=0;
				while(i != size1 && tree[path[j].first][path[j].second]->S[i][0] < x)
				{
					//				printf("%d:%d ", tree[path[j].first][path[j].second]->S[i][0], tree[path[j].first][path[j].second]->child[i]);
					i++;
				}
				//			printf("\n");

				while(i != size1 && tree[path[j].first][path[j].second]->child[i] != 1)
				{
					//				printf("%d:%d ", tree[path[j].first][path[j].second]->S[i][0], tree[path[j].first][path[j].second]->child[i]);
					i++;
				}
				//			printf("\n");

				/* if no point in the right child has x-coordinate greater than the query x-coordinate, continue */
				if(i == size1)
					continue;

				//			printf("i: %d\n", i);
				//			printf("Going for RMQ with %d,%d\n", path[j].first+1, right);

				/* Go into the Range Maxima Tree for the right child from the index determined above to the end of the point list in the right child */
				Report(tree[path[j].first+1][right], tree[path[j].first][path[j].second]->position[i], tree[path[j].first+1][right]->S.size()-1, y);
			}
			printf("\n");
		}
	}

	return 0;
}
