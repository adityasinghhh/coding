
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

int dp[2][1001][1001];
int f(int z, int o, int e)
{
	int &m = dp[z][o][e];
	if(m != -1)
	{
		return m;
	}

	if(o <= 1)
	{
		if(z)
		{
			return m = 0;
		}
		else
		{
			return m = 1;
		}
	}

	if(z)
	{
		bool flag = true;
		flag &= f(1-z, o-1, e);
		flag &= f(1-z, o, e-1);
		
		return m = flag;
	}
	else
	{
		bool flag = false;
		flag |= f(1-z, o-1, e);
		flag |= f(1-z, o, e-1);

		return m = flag;
	}
}

int main()
{
	string s;
	cin >> s;
	int p[30] = {0};
	REP(i,s.length())
	{
		++p[s[i]-'a'];
	}

	int odd = 0, even = 0;
	REP(i,30)
	{
		if(p[i])
		{
			if(p[i]&1)
			{
				++odd;
			}
			else
			{
				++even;
			}
		}
	}

	FILL(dp,-1);

	printf(f(0, odd, even) ? "First\n" : "Second\n");

	return 0;
}
