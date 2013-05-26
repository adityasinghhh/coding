
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

LL dp[101][101][101][3], a[101], b[101];
int A[101], B[101], N, M;
LL f(int i, int j, int k, int l)
{
	LL &m = dp[i][j][k][l];
	if(m != -1ll)
	{
		return m;
	}
	
	if(i == N || j == M)
	{
		return m = 0ll;
	}

	if(l == 0)
	{
		if(A[i] == B[j])
		{
			LL r;
			if(a[i] < b[j])
			{
				r = a[i] + f(i+1, j, j, 2);
			}
			else if(a[i] == b[j])
			{
				r = a[i] + f(i+1, j, k, 0);
			}
			else
			{
				r = b[j] + f(i, j+1, i, 1);
			}
			return m = r;
		}
		else
		{
			LL r1 = f(i+1, j, k, l), r2 = f(i, j+1, k, l);
			return m = MAX(r1, r2);
		}
	}
	else
	{
	}
}

int main()
{
	int T = SI;
	REP(zz,T)
	{
		N = SI; M = SI;
		REP(i,N)
		{
			a[i] = SLL;
			A[i] = SI;
		}

		REP(j,M)
		{
			b[j] = SLL;
			B[j] = SI;
		}

		FILL(dp, -1);

		printf("Case #%d: ", zz+1);
		printf("%lld\n", f(0, 0, K+1, 0));
	}
	return 0;
}
