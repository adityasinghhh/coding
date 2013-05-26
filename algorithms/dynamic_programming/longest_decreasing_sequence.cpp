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
	int N;
	iscan(N);

	int a[N+1], i, dp[N+1];

	FOR(i,0,N)
	{
		iscan(a[i]);
		dp[i] = 1;
	}

	int j, maxi = -1;
	FOR(i,0,N)
	{
		FOR(j,0,i)
			if(a[i] >= a[j] && dp[i] < dp[j]+1)
				dp[i] = dp[j]+1;

		maxi = max(maxi, dp[i]);
	}

	FOR(i,0,N)
		printf("%d:%d ", a[i], dp[i]);
	printf("\n");
	
	printf("%d\n", maxi);

	return 0;
}
