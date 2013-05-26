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
int markm[30], markf[30], size;
vector<pair<int, int> > pairs;

void F(int i, int k)
{
	if(k == K)
	{
		ans = (ans == BASE-1 ? 0 : ans+1);
		return;
	}

	if(i == size)
		return;

	int m = pairs[i].first, f = pairs[i].second;
	if(!markm[m] && !markf[f])
	{
		markm[m] = 1;
		markf[f] = 1;
		F(i+1, k+1);
		markm[m] = 0;
		markf[f] = 0;
	}

	F(i+1, k);
}

int main()
{
	iscan(N);
	iscan(M);
	iscan(K);

	int i, j;
	FOR(i,0,N)
	{
		FOR(j,0,M)
		{
			iscan(a[i][j]);

			if(a[i][j])
				pairs.PB(make_pair(i, j));
		}
	}

	memset(markm, 0, sizeof(markm));
	memset(markf, 0, sizeof(markf));

	size = pairs.size();
	FOR(i,0,size)
		printf("%d %d\n", pairs[i].first, pairs[i].second);

	F(0, 0);

	printf("%d\n", ans);

	return 0;
}
