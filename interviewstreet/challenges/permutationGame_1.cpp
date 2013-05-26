
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

int dp[10000007];

LL BASE = 10000007, B = 31;
LL HASH(VI &v)
{
	int sz = v.size();
	LL h = 0ll;
	REP(i,sz)
	{
		h = (h * B + v[i]) % BASE;
	}
	return h;
}

int f(VI &v)
{
	LL h = HASH(v);

	if(dp[h] != -1) { return dp[h]; }

	int sz = v.size();
	bool flag = false;
	REP(i,sz-1)
	{
		if(v[i] > v[i+1])
		{
			flag = true;
			break;
		}
	}

	if(!flag) { return dp[h] = 0; }

	set<int> mex;
	REP(i,sz)
	{
		VI v1 = v;
		v1.erase(v1.begin()+i);
		mex.insert(f(v1));
	}

	int i = 0;
	for(set<int>::iterator it = mex.begin(); it != mex.end(); ++it)
	{
		if(i != *it) { break; }
		++i;
	}
	return dp[h] = i;	
}

int main()
{
	FILL(dp,-1);
	int T = SI;
	while(T--)
	{
		int N = SI;
		VI v;
		REP(i,N)
		{
			v.PB(SI);
		}

		printf(f(v) ? "Alice\n" : "Bob\n");
	}

	return 0;
}
