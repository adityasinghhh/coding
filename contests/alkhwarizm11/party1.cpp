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

int BASE = 10007;
int N, M, K, a[30][30], dp[30][30][30], ans;
int mark[30];

void f(int i, int k)
{
	if(N-i < K-k)
		return;

	if(k == K)
	{
		ans = (ans == BASE-1 ? 0 : ans+1);

		return;
	}

	if(i == N)
	{
		return;
	}

	int j;

	for(j=0; j<M; j++)
	{
		if(a[i][j] && !mark[j])
		{
			mark[j] = 1;
			f(i+1, k+1);
			mark[j] = 0;
		}
	}

	f(i+1, k);
}

int main()
{
	iscan(N);
	iscan(M);
	iscan(K);

	int i, j;
	FOR(i,0,N)
		FOR(j,0,M)
			iscan(a[i][j]);

	memset(dp, -1, sizeof(dp));
	memset(mark, 0, sizeof(mark));

	ans = 0;
	f(0, 0);	
	printf("%d\n", ans);

	return 0;
}
