
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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define LL long long int
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define lfscan(n) scanf("%lf",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=b-1;i>=a;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define ABS(a) a<0?-a:a
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int T[10000], P[10001][20], L[10001];

int query(int x, int y)
{
	if(L[x] < L[y]) { swap(L[x], L[y]); }

	int i;
	for(i=1; (1<<i) <= L[x]; ++i);
	--i;
	int log = i;

	printf("LOG: %d\n", log);

	for(i=log; i>=0; --i)
	{
		if(L[x]-(1<<i) >= L[y])
		{
			x = P[x][i];
		}
	}

	if(x == y) { return x; }

	for(i=log; i>=0; --i)
	{
		if(P[x][i] != -1 && P[x][i] != P[y][i])
		{
			x = P[x][i];
			y = P[y][i];			
		}
	}
	return T[x];
}

int main()
{
	int N = SI, M = SI;
	vector<PI> v;
	FILL(L, -1);
	while(M--)
	{
		int x = SI, y = SI;
		v.PB(MP(x, y));
		T[y] = x;

		if(x == -1) { L[y] = 1; }
	}

	int cnt = 1;
	while(cnt < N)
	{
		int i;
		REP(i,N+1)
		{
			if(L[v[i].first] != -1 && L[v[i].second] == -1)
			{
				L[v[i].second] = L[v[i].first]+1;
				++cnt;
			}
		}
	}

	int i;
	REP(i,N+1)
	{
		printf("%d -> %d\n", i, L[i]);
	}

	int j;
	for(i=0; i<=N; ++i)
	{
		for(j=0; 1<<j < N; ++j)
		{
			P[i][j] = -1;
		}
	}

	REP(i,N+1)
	{
		P[i][0] = T[i];
	}

	for(j = 1; (1<<j) < N; ++j)
	{
		for(i=0; i<=N; ++i)
		{
			if(P[i][j-1] != -1)
			{
				P[i][j] = P[P[i][j-1]][j-1];
			}
		}
	}

	int t = SI;
	while(t--)
	{
		int x = SI, y = SI;
		printf("LCA of (%d,%d) = %d\n", x, y, query(x, y));
	}

	return 0;
}
