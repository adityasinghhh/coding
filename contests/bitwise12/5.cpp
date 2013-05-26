#include<iostream>
#include<sstream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define MP make_pair
#define PB push_back
#define LL long long
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REPD(i,b) for(int i=(b)-1;i>=0;--i)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a) ((a)<0?-(a):(a))

typedef vector<int> VI; 
typedef pair<int,int> PI; 
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define RAND(x) ((int)(((rand()*1.0)/RAND_MAX)*(x)))

LL BASE;
void init()
{
	BASE = (1<<30);
}

int dp[5000][5000];

int compute(int i, int j)
{
	if(i < 5000 && j < 5000 && dp[i][j] != -1) { return dp[i][j]; }

	int g = __gcd(i, j);

	for(int k = 2; k*k <= g; ++k)
	{
		if(g%k == 0)
		{
			if(g%(k*k) == 0)
			{
				if(i < 5000 && j < 5000) { return dp[i][j] = 0; }
				return 0;
			}
		}
	}

	if(i < 5000 && j < 5000) { return dp[i][j] = i*j/g/g; }
	return i*j/g/g;
}

int main()
{
	init();

	FILL(dp,-1);

	int T = SI;
	while(T--)
	{
		int X = SI, Y = SI;
		LL ans = 0ll;
		FOR(i,1,X+1)
		{
			FOR(j,1,Y+1)
			{
				ans += compute(i, j);
				if(ans >= BASE) { ans -= BASE; }
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}
