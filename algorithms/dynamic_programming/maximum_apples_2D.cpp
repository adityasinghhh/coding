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

int main()
{
	int N, M;
	iscan(N);
	iscan(M);

	int a[N+1][M+1], dp[N+1][M+1];

	int i, j;
	a[0][0] = 0;
	FOR(i,1,N+1)
		FOR(j,1,M+1)
			iscan(a[i][j]);

	FOR(i,0,N+1)
		dp[i][0] = 0;
	
	FOR(j,0,M+1)
		dp[0][j] = 0;

	FOR(i,1,N+1)
	{
		FOR(j,1,M+1)
		{
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}

	printf("%d\n", dp[N][M]);

	return 0;
}
