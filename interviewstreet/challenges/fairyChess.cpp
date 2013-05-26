
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

LL dp[201][201][201];
bool mark[201][201];

int N, M, S;
bool valid(int i, int j)
{
	if(i < 0 || j < 0 || i >= N || j >= N) { return false; }
	return mark[i][j] == 0;
}

LL BASE = 1000000007;
LL f(int i, int j, int m)
{
//	printf("(%d,%d,%d)\n", i, j, m);
	if(dp[i][j][m] != -1) { return dp[i][j][m]; }

	if(m == 0) { return dp[i][j][m] = 1ll; }

	LL ret = 0ll;
	REP(ii,S+1)
	{
		REP(jj,S-ii+1)
		{
			if(ii == 0 && jj == 0)
			{
//				printf("Total move = (%d,%d) = %d\n", ii, jj, ii+jj);
				ret += f(i, j, m-1);
				if(ret >= BASE) { ret %= BASE; }
			}
			else
			{
				if(valid(i+ii, j+jj))
				{
//					printf("Total move = (%d,%d) = %d\n", ii, jj, ii+jj);
					ret += f(i+ii, j+jj, m-1);
					if(ret >= BASE) { ret %= BASE; }
				}

				if(valid(i-ii, j-jj))
				{
//					printf("Total move = (%d,%d) = %d\n", ii, jj, ii+jj);
					ret += f(i-ii, j-jj, m-1);
					if(ret >= BASE) { ret %= BASE; }
				}
			}
		}
	}
	return dp[i][j][m] = ret % BASE;
}

int main()
{
	int T = SI;
	while(T--)
	{
		FILL(mark,0);
		N = SI, M = SI, S = SI;

		int s, e;
		REP(i,N)
		{
			string a; cin >> a;
			REP(j,N)
			{
				if(a[j] == 'P')
				{
					mark[i][j] = 1;
				}
				else if(a[j] == 'L')
				{
					s = i;
					e = j;
				}
			}
		}

		FILL(dp,-1);
		printf("%lld\n", f(s, e, M));
	}

	return 0;
}