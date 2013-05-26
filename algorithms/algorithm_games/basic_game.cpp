/* 'n' coins; at each step a player can remove 1, 3, 4 coins.
   Given n, who wins */

#include<cstdio>
#define FOR(i, j, n) for(i=j; i<n; i++)
#define REP(i, n) FOR(i, 0, n)
int dp[10001];

int f(int n)
{
	if(dp[n] != -1)
		return dp[n];

	if((f(n-1)&f(n-3)&f(n-4)) == 0)
	{
		dp[n] = 1;
	}
	else
	{
		dp[n] = 0;
	}

	return dp[n];
}

int main()
{
	int n, i;

	REP(i, 10001)
		dp[i] = -1;

	dp[0] = dp[2] = 0;
	dp[1] = dp[3] = dp[4] = 1;

	while(scanf("%d", &n) != EOF)
	{
		if(f(n) == 1)
			printf("W\n");
		else 
			printf("L\n");
	}

	return 0;
}
