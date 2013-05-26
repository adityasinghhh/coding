
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
#define lfscan(n) scanf("%lf",&n)
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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int bst[10000], L[10000], P[10000], T[10000];

void insert(int node, int level, int x) { if(!bst[node]) { bst[node] = x; printf("Inserted %d at %d\n", x, node); L[node] = level; } else { insert(bst[node] > x ? 2*node : 2*node+1, level+1, x); } }

void dfs(int node, int nr) 
{ 
	if(!bst[node]) { return; }

	if(L[node] < nr) { P[node] = nr; } 
	else 
	{ 
		if(!(L[node]%nr)) { P[node] = node/2; } 
		else { P[node] = P[node/2]; } 
	} 

	dfs(2*node, nr);
	dfs(2*node+1, nr);
}

int lca(int x, int y) 
{ 
	while(P[x] != P[y]) { if(L[x] > L[y]) { x = P[x]; } else { y = P[y]; } }

	while(x != y) { if(L[x] > L[y]) { x /= 2; } else { y /= 2; } }

	return x;
}

void print(int node) { if(bst[2*node]) { print(2*node); } printf("%d ", bst[node]); if(bst[2*node+1]) { print(2*node+1); } }

void printp(int node) { if(P[2*node]) { printp(2*node); } printf("%d ", P[node]); if(P[2*node+1]) { printp(2*node+1); } }

void printl(int node) { if(L[2*node]) { printl(2*node); } printf("%d ", L[node]); if(L[2*node+1]) { printl(2*node+1); } }

int main()
{
	int N, i, x, nr;
	while(iscan(N) != EOF)
	{
		FILL(bst, 0); FILL(L, 0); FILL(P, 0); FILL(T, 0);
		REP(i,N) { x = SI; insert(1, 0, x); }

		printf("Inorder: "); print(1); printf("\n");

		nr = sqrt(N); dfs(1, nr); 
		
		printf("P: "); printp(1); printf("\n");
		
		printf("L: "); printl(1); printf("\n");

		printf("LCA of %d and %d is %d\n", bst[5], bst[6], bst[lca(5, 6)]);
		printf("LCA of %d and %d is %d\n", bst[1], bst[9], bst[lca(1, 9)]);
		printf("LCA of %d and %d is %d\n", bst[3], bst[10], bst[lca(3, 10)]);
		printf("LCA of %d and %d is %d\n", bst[8], bst[4], bst[lca(8, 4)]);
	}
	return 0;
}
