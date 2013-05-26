
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
#define PI(x) printf("%d",&x)
#define PC(x) printf("%c",&x)
#define PLL(x) printf("%lld",&x)
#define PLF(x) printf("%lf",&x)
#define PS(x) printf("%s",&x)
#define PSP() printf(" ")
#define PSN() printf("\n")
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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int main()
{
	int N = SI, M = SI;

	if(M < N) { swap(N, M); }

	if(N == 1) { printf("%d\n", M); }
	else if(N == 2)
	{
		int v1 = M/4, v2 = M%4;

		printf("%d\n", v1*4 + (v2 == 0 ? 0 : v2 == 1 ? 2 : 4));
	}
	else
	{
		if(N%2 == 0)
		{
			if(M%2 == 0)
			{
				int n = N/2, m = M/2;
				int maxi = MAX(n*M, N*m);
				printf("%d\n", maxi);
			}
			else
			{
				int val1 = M * (N/2);
				int val2 = N * (M/2) + N/2;
				int maxi = MAX(val1, val2);
				printf("%d\n", maxi);
			}
		}
		else
		{
			if(M%2 == 0)
			{
				int val1 = N * (M/2);
				int val2 = M * (N/2) + M/2;
				int maxi = MAX(val1, val2);
				printf("%d\n", maxi);
			}
			else
			{
				int val1 = N * (M/2) + (N+1)/2;
				int val2 = M * (N/2) + (M+1)/2;
				int maxi = MAX(val1, val2);
				printf("%d\n", maxi);
			}
		}
	}

	return 0;
}
