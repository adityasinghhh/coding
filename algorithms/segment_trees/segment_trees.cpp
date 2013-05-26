
#include<algorithm>
#include<assert.h>
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

#define LL long long int
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=b-1;i>=a;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define ABS(a) a<0?-a:a
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))

int N, size;
VI A, M;

void print() { int i; REP(i,N) { printf("%d ", A[i]); } printf("\n"); }

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

void segment_tree()
{
	size = 4*(1<<((int)log(N)+1)); 

	int i; REP(i,size+1) { M.PB(-1); }

	init(1, 0, N-1);
}

int main()
{
	int x, i;
	
	N = SI;
	REP(i,N) 
	{ 
		x = SI; 
		A.PB(x); 
	} 
	print();

	segment_tree();

	printf("%d\n", size); 
	REP(i,size) 
	{ 
		printf("%d ", M[i]); 
	} 
	printf("\n");

	int T = SI; 
	while(T--) 
	{ 
		int i = SI, j = SI; 
	
		int x = query(1, 0, N-1, i, j);

		printf("%d %d: A[%d] = %d\n", i, j, x, A[x]); 
	}

	return 0;
}
