
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
typedef vector<VI> VVI;
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

LL BASE = 1000000007;

VVI mypow(VVI &A, int p)
{
	if(p == 0)
	{
		VVI ret;
		int N = A.size();
		REP(i,N)
		{
			VI row; ret.PB(row);
			REP(j,N)
			{
				ret[i].PB(i == j ? 1 : 0);
			}
		}
		return ret;
	}
	else if(p == 1) { return A; }
	else if(p == 2)
	{
		VVI ret;
		int N = A.size();
		REP(i,N)
		{
			VI row;
			REP(j,N)
			{
				LL c = 0;
				REP(k,N)
				{
					c = (c + 1ll*A[i][k]*A[k][j]) % BASE;
				}
				row.PB((int)c);
			}
			ret.PB(row);
		}
		return ret;
	}
	else if(p&1)
	{
		VVI ret, B = mypow(A, p-1);
		int N = A.size();
		REP(i,N)
		{
			VI row;
			REP(j,N)
			{
				LL c = 0;
				REP(k,N)
				{
					c = (c + 1ll*A[i][k]*B[k][j]) % BASE;
				}
				row.PB((int)c);
			}
			ret.PB(row);
		}
		return ret;
	}

	VVI B = mypow(A, p/2);
	return mypow(B, 2);
}

VI multiply(VVI &A, VI &B)
{
	VI ret;
	int M = A.size(), N = A[0].size();
	REP(i,M)
	{
		LL c = 0ll;
		REP(j,N)
		{
			c = (c + 1ll*A[i][j]*B[j]) % BASE;
		}
		ret.PB((int)c);
	}

	return ret;
}

void print(VVI &A)
{
	int M = A.size(), N = A[0].size();
	REP(i,M)
	{
		REP(j,N)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int T = SI;
	while(T--)
	{
	}

	return 0;
}
