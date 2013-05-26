#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, t, i, j, x;

	while(scanf("%d %d", &t, &n) != EOF)
	{
		vector<int> v[t+1];

		for(i=0; i<n; i++)
		{
			vector<int> a;

			for(j=0; j<t; j++)
			{
				scanf("%d", &x);
				a.push_back(x);
			}

			v[i] = a;
		}

		sort(v, v+n);

		for(i=0; i<n; i++)
		{
			for(j=0; j<t; j++)
				printf("%d ", v[i][j]);
			printf("\n");
		}
	}

	return 0;
}
