
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

LL BASE = 1000000007ll;
LL **mypow(LL **a, LL p)
{
	LL **ret = new LL*[2];
	ret[0] = new LL[2];
	ret[1] = new LL[2];

	if(p == 0ll)
	{
		ret[0][0] = 1ll;
		ret[0][1] = 0ll;
		ret[1][0] = 0ll;
		ret[1][1] = 1ll;

		return ret;
	}
	else if(p == 1ll)
	{
		return a;
	}
	else if(p == 2ll)
	{
		REP(i,2)
		{
			REP(j,2)
			{
				ret[i][j] = 0ll;
				REP(k,2)
				{
					ret[i][j] += a[i][k]*a[k][j];
					ret[i][j] %= BASE;
				}
			}
		}

		return ret;
	}
	else if(p&(1ll))
	{
		LL **b = mypow(a, p-1ll);
		REP(i,2)
		{
			REP(j,2)
			{
				ret[i][j] = 0ll;
				REP(k,2)
				{
					ret[i][j] += b[i][k]*a[k][j];
					ret[i][j] %= BASE;
				}
			}
		}

		return ret;
	}
	else
	{
		LL **b = mypow(a, p/2ll);
		LL **ret = mypow(b, 2ll);
		
		return ret;
	}
}

LL f(LL N)
{
	LL **A = new LL*[2];
	A[0] = new LL[2];
	A[1] = new LL[2];

	A[0][0] = 2ll;
	A[0][1] = 1ll;
	A[1][0] = 1ll;
	A[1][1] = 0ll;

	LL **ret = mypow(A, N);

	delete(A[0]);
	delete(A[1]);
	delete(A);

	LL ans = ret[0][0];

	delete(ret[0]);
	delete(ret[1]);
	delete(ret);

	return ans;
}

int main()
{
	int Q = SI;
	while(Q--)
	{
		LL N = SLL;

		if(N == 0ll)
		{
			printf("0\n");
		}
		else if(N == 1ll)
		{
			printf("1\n");
		}
		else
		{
			printf("%lld\n", f(N-1ll));
		}
	}

	return 0;
}
