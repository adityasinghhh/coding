
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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define LL long long int
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

int main()
{
	int T = SI;
	while(T--)
	{
		int N = SI, M = SI;
		VI v; REP(i,N) { v.PB(SI); }

		VVI A; 
		REP(i,N) 
		{ 
			VI v; A.PB(v);
			if(i == 0) { REP(j,N) { A[i].PB(1); } }
			else { REP(j,N) { A[i].PB(i == j ? 1 : 0); } }
		}

		FOR(i,1,N)
		{
			VVI B;
			REP(j,N)
			{
				VI v; B.PB(v);
				if(i == j)
				{
					REP(k,N) { B[j].PB(1); }
				}
				else
				{
					REP(k,N) { B[j].PB(j == k ? 1 : 0); }
				}
			}

			VVI C;
			REP(j,N)
			{
				VI v; C.PB(v);
				REP(k,N)
				{
					C[j].PB(0);
					REP(l,N)
					{
						C[j][k] += A[j][l]*B[l][k];
					}
				}
			}

			A = C;
		}

		REP(i,N) { REP(j,N) { printf("%d ", A[i][j]); } printf("\n"); }
	}

	return 0;
}
