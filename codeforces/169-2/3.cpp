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

int A[10000001];
void update(int node, int b, int e, int i, int j, int value)
{
	if(i > e || j < b) { return; }

	if(i <= b && e <= j) 
	{
		A[node] += value;
		return;
	}

	update(2*node, b, (b+e)/2, i, j, value);
	update(2*node+1, (b+e)/2+1, e, i, j, value);
}

int query(int node, int b, int e, int i, int j)
{
	if(i > e || j < b) { return 0; }

	if(b == i && e == j)
	{
		return A[node];
	}

	int ret = 0;
	if(b <= i && j <= e) 
	{
		ret += A[node]; 
	}

	ret += query(2*node, b, (b+e)/2, i, j);
	ret += query(2*node+1, (b+e)/2+1, e, i, j);
	
	return ret;
}

void segment_tree(int N)
{
//	int size = 4*(1<<((int)log(N)+1)); 

//	int i; REP(i,size+1) { A.PB(0); }
}

int main()
{
	int N = SI, Q = SI;
	VI v;
	REP(i,N)
	{
		int x = SI;
		v.PB(x);
	}
	
	segment_tree(N);

	SORT(v);
	
	while(Q--)
	{
		int x = SI, y = SI;
		update(1, 0, N-1, x-1, y-1, 1);
	}

	VI w;
	REP(i,N)
	{
		w.PB(query(1, 0, N-1, i, i));
	}

	SORT(w);

	LL ans = 0ll;
	REP(i,N)
	{
		ans += 1ll*v[i]*w[i];
	}

	cout << ans << endl;

	return 0;
}
