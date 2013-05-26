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

int N, a[10001], dp[100001];
int f(int s)
{
	if(dp[s] != 10000000)
		return dp[s];

	int i;
	FOR(i,0,N)
		if(s-a[i] >= 0)
			dp[s] = min(dp[s], f(s-a[i])+1);

	return dp[s];
}

int main()
{
	iscan(N);
	
	int i;
	dp[0] = 0;
	FOR(i,0,N)
		iscan(a[i]);

	int S;
	iscan(S);

	FOR(i,0,S+1)
		dp[i] = 10000000;
	
	dp[0] = 0;

	f(S);
	FOR(i,0,S+1)
		printf("%d:%d ", i, dp[i]);
	printf("\n");

	printf("%d\n", f(S));
	
	return 0;
}
