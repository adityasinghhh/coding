
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

bool check(int x, int y)
{
	if(x < 0 || y < 0)
	{
		return false;
	}

	return true;
}
	
VPI moves;
int dp[1001][1001];

int f(int x, int y)
{
	if(dp[x][y] != -1) { return dp[x][y]; }

	set<int> mex;
	REP(i,moves.size())
	{
		int xi = x + moves[i].first, yi = y + moves[i].second;
		if(check(xi, yi))
		{
			mex.insert(f(xi, yi));
		}
	}

	int i = 0;
	TR(it,mex)
	{
		if(i != *it)
		{
			return dp[x][y] = i;
		}
		++i;
	}
	return dp[x][y] = i;
}

void init()
{
	moves.PB(MP(-1,-3));
	moves.PB(MP(-1,-2));
	moves.PB(MP(+1,-2));
	moves.PB(MP(-2,-1));
	moves.PB(MP(-2,+1));
	moves.PB(MP(-3,-1));

	FILL(dp,-1);
	dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;

	f(500,500);
}

int main()
{
	init();

	int T = SI;
	REP(zz,T)
	{
		printf("Case %d: ", zz+1);

		int N = SI, ans = 0;
		REP(i,N)
		{
			int x = SI, y = SI;
			ans ^= dp[x][y];
		}

		printf(ans ? "Alice\n" : "Bob\n");
	}
	return 0;
}
