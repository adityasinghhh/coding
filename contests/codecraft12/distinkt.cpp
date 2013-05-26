
#include<algorithm>
#include<assert.h>
#include<bitset>
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
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define LL long long int

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define PI(x) printf("%d",x)
#define PC(x) printf("%c",x)
#define PLL(x) printf("%lld",x)
#define PLF(x) printf("%lf",x)
#define PS(x) printf("%s",x)
#define P32() printf(" ")
#define P10() printf("\n")
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define lfscan(n) scanf("%lf",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=b-1;i>=a;--i)
#define REP(i,b) for(int i=0;i<b;++i)
#define REPD(i,b) for(int i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

LL BASE = 100000007;
int dp[1000][30][30];
int N, K;

LL f(int n, int k, int i)
{
	if(n <= 0) { return 0; }

	int &m = dp[n][k][i]; if(m != -1) { return (LL)m; }

	if(n == 1)
	{
		return dp[n][k][i] = 1;
	}

	LL ret = 0;

	REP(j,k)
	{
		if(i+j < 26)
		{
			int mini = MIN(26-i-j, k);
			ret += f(n-1, mini, i+j);
			if(n != 1)
			{
				ret += f(n-2, mini, i+j);
			}
		}
	}

	return m = ret % BASE;
}

int main()
{
	N = SI, K = SI;
	
	FILL(dp, -1);

	LL ans = 0ll;
	FOR(i,1,N+1)
	{
		ans += f(i, K, 1);
		printf("%d: %d\n", i, ans);
	}

	REP(i,N+1)
	{
		REP(j,K+1)
		{
			REP(k,26)
			{
				if(dp[i][j][k] != -1)
				{
					printf("(%d, %d, %d): %d\n", i, j, k, dp[i][j][k]);
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
