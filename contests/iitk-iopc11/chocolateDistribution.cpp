#include<cstdio>
#include<map>
#include<utility>
using namespace std;
map<pair<int, int>, int> dp;
int dp1[1001][1001];
int f(int i, int j)
{
	if(dp1[i][j] != -1)
		return dp1[i][j];
	
	if(i == 0 || j == 0)
	{
		dp1[i][j] = 0;
		return 0;
	}

	if(i == j)
	{
		dp1[i][j] = 1;
		return 1;
	}
	else if(i<j)
	{
		int v = f(i, j%i) + j/i;
		dp1[i][j] = v;
		return v;
	}
	else
	{
		int v = f(i%j, j) + i/j;
		dp1[i][j] = v;
		return v;
	}
}

int main()
{
	int t, i, j, m, n, p, q, total;

	for(i=0; i<=1000; i++)
		for(j=0; j<=1000; j++)
			dp1[i][j] = -1;

	for(i=0; i<=1000; i++)
		for(j=0; j<=1000; j++)
			dp1[i][j] = f(i, j);

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d %d %d", &m, &n, &p, &q);

		total = 0;

		for(j=q; j>=p; j--)
			total += f(i, j);

		printf("%d\n", total);
	}

	return 0;
}
