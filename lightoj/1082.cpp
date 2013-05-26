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

int M[1000000], A[1000000];
void init(int node, int b, int e)
{
	if(b == e) { M[node] = b; }
	else
	{
		init(2*node, b, (b+e)/2);
		init(2*node+1, (b+e)/2+1, e);

		if(A[M[2*node]] <= A[M[2*node+1]]) { M[node] = M[2*node]; }
		else { M[node] = M[2*node+1]; }
	}
}

int query(int node, int b, int e, int i, int j)
{
	if(i > e || j < b) { return -1; }

	if(i <= b && e <= j) { return M[node]; }

	int p1 = query(2*node, b, (b+e)/2, i, j);
	int p2 = query(2*node+1, (b+e)/2+1, e, i, j);

	if(p1 == -1) { return p2; }
	if(p2 == -1) { return p1; }
	if(A[p1] <= A[p2]) { return p1; }
	return p2;
}

void segment_tree(int &N)
{
	FILL(M,-1);

	init(1, 0, N-1);
}

int main()
{
	int T = SI;
	REP(zz,T)
	{
		printf("Case %d:\n", zz+1);
		
		int N = SI, Q = SI;
		REP(i,N) 
		{
			A[i] = SI;
		} 

		segment_tree(N);

		while(Q--) 
		{ 
			int i = SI-1, j = SI-1; 

			int x = query(1, 0, N-1, i, j);

			printf("%d\n", A[x]); 
		}
	}

	return 0;
}
