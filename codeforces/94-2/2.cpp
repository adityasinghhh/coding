
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
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define ABS(a) (a)<0?-(a):(a)
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int main()
{
	int N = SI, M = SI, i, x, y, j;

	int a[N+1][N+1], sz[N+1]; FILL(a,0); FILL(sz,0);

	REP(i,M) { x = SI; y = SI; a[x][y] = a[y][x] = 1; sz[x]++; sz[y]++; }

	int cnt = 0;

	while(true)
	{
		VI v;
		FOR(i,1,N+1) { if(sz[i] == 1) { v.PB(i); --sz[i]; } } //printf("%d ", i); } } printf("\n");

		if(!v.size()) { break; }

		++cnt;

		REP(i,v.size()) { FOR(j,1,N+1) { if(a[v[i]][j] == 1) { sz[j]--; a[v[i]][j] = a[j][v[i]] = 0; } } }

//		REP(i,N) { REP(j,N) { printf("%d ", a[i+1][j+1]); } printf("\n"); }
//		REP(i,N) { printf("%d ", sz[i+1]); } printf("\n");

	}

	printf("%d\n", cnt);

	return 0;
}
