
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
#define PN() printf("\n")
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

VVI tree;

int read(int i, int j) { int sum = 0; while(i > 0) { int k = j; while(k > 0) { sum += tree[i][k]; k -= (k&-k); } i -= (i&-i); } return sum; }

void update(int i, int j, int val) { while(i <= tree.size()) { int k = j; while(k <= tree[i].size()) { tree[i][k] += val; k += (k&-k); } i += (i&-i); } }

int matrix[1124][1124];

int main()
{
	int N = SI, M = SI, K = SI;
	REP(i,N)
	{
		VI v;
		REP(j,M)
		{
			v.PB(0);
		}
		tree.PB(v);
	}

	REP(i,N)
	{
		REP(j,M)
		{
			int x = SI;
			update(i,j,x*MAX(0,K-ABS(i-x)-ABS(j-y)));
		}
	}

	int maxi = INT_MIN, maxx = 0, maxy = 0;
	FOR(x,K,N-K+2)
	{
		FOR(y,K,M-K+2)
		{
			int val = read(x,y);
			if(maxi < val)
			{
				val = maxi;
				maxx = x;
				maxy = y;
			}
		}
	}

	printf("%d %d\n", maxx, maxy);

	return 0;
}
