
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
LL BASE = 10000007;
LL dp[10001][7];

LL f(int r, int b)
{
	//printf("%d %d\n", r, b);

	if(r <= 0) { return 1; }
	if(b == 0) { return 1; }

	LL &m = dp[r][b]; if(m != -1) { return m; }

	LL cnt = 0;
	cnt += f(r, b-1);
	cnt += f(r-1, b-1);
	cnt += f(r-2, b-1);
	cnt += f(r-3, b-1);
	cnt += f(r-4, b-1);
	cnt += f(r-6, b-1);
	cnt += f(r-1, b);
	cnt += f(r-2, b);
	cnt += f(r-3, b);
	cnt += f(r-5, b);
	cnt += f(r-1, b);
	cnt += f(r-2, b);
	cnt += f(r-5, b);
	cnt += f(r-7, b);
	cnt += f(r, b-1);

	return m = (cnt+1)%BASE;
}

int main()
{
	FILL(dp, -1);

	int T = SI, N, zz;

	FOR(zz,1,T+1)
	{
		N = SI;

		printf("Case %d: %lld\n", zz, f(N, 6));
	}

	return 0;
}
