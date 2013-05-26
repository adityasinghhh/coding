#include<algorithm>
#include<assert.h>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define LL long long int
#define MAX(a,b) a>b?a:b

int BASE = 1000000007;
int dp[101][101];
int N, M, chef[101][2];

int solve(int n, int i)
{
	if(i == M-1)
		return ((n >= chef[i][0] && n<=chef[i][1]) ? 1 : 0);

	if(n < chef[i][0])
		return 0;

	int &m = dp[n][i];

	if(m != -1)
		return m;

	int j, ret=0, maxi = MAX(chef[i][1],n);
	for(j=chef[i][0]; j<=maxi; ++j)
	{
		ret += solve(n-j, i+1);
		
		ret = (ret >= BASE ? ret-BASE : ret);
	}

	return m=ret;
}

int main()
{
	int T, i, x, y;
	iscan(T);

	while(T--)
	{
		iscan(N);
		iscan(M);

		FOR(i,0,M)
		{
			iscan(x);
			iscan(y);

			chef[i][0] = x;
			chef[i][1] = y;
		}

		memset(dp,-1,sizeof dp);

		printf("%d\n", solve(N, 0));
	}

	return 0;
}
