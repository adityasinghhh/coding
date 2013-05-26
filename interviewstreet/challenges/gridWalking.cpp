
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

int N, M;
VI v, D;
int dp[15][310];
LL BASE = 1000000007;

int f(int i, int m)
{
//	if(dp[i][m] != -1) { return dp[i][m]; }

	if(m == 0) { return dp[i][m] = 1; }

//	printf("(%d,%d)\n", i, m);

	if(i == N-1)
	{
		if(D[i] == 1) { return dp[i][m] = 0; }

		LL ret = 0ll;
		if(v[i] > 1)
		{
			--v[i];
			ret += 1ll*f(i, m-1);
			if(ret >= BASE) { ret %= BASE; }
			++v[i];
		}

		if(v[i] < D[i])
		{
			++v[i];
			ret += 1ll*f(i, m-1);
			if(ret >= BASE) { ret %= BASE; }
			--v[i];
		}

//		printf("(%d,%d): %d\n", i, m, (int)ret);
		return dp[i][m] = (int)ret;
	}

	LL ret = 0ll;
	if(v[i] > 1)
	{
		--v[i];
		ret *= 1ll*f(i, m-1);
		if(ret >= BASE) { ret %= BASE; }
		ret *= 1ll*f(i+1, m-1);
		if(ret >= BASE) { ret %= BASE; }
		++v[i];
	}

	if(v[i] < D[i])
	{
		++v[i];
		ret *= 1ll*f(i, m-1);
		if(ret >= BASE) { ret %= BASE; }
		ret *= 1ll*f(i+1, m-1);
		if(ret >= BASE) { ret %= BASE; }
		--v[i];
	}

	return dp[i][m] = (int)ret;
}

int main()
{
	int T = SI;
	while(T--)
	{
		v.clear(); D.clear(); FILL(dp,-1);
		
		N = SI; M = SI;
		REP(i,N) { v.PB(SI); }
		REP(i,N) { D.PB(SI); }

		printf("%d\n", f(0, M));

		REP(i,N)
		{
			REP(j,M)
			{
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
