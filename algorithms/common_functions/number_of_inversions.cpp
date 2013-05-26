
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

VI v;
int cnt;

void print() { int i; REP(i,v.size()) { printf("%d ", v[i]); } printf("\n"); }

void merge(int p, int q, int r)
{
	VI temp; int i, j;
 	for(i=p, j=q+1; i<=q && j<=r;) { cnt += (v[i] < v[j] ? 0 : q-i+1); temp.PB(v[i] < v[j] ? v[i++] : v[j++]); }
	while(i<=q) { temp.PB(v[i++]); }
	while(j<=r) { temp.PB(v[j++]); }
	REP(i,temp.size()) { v[i+p] = temp[i]; }
}

void mergesort(int p, int r) { if(p<r) { int q = (p+r)/2; mergesort(p, q); mergesort(q+1, r); merge(p, q, r); } }

int main()
{
	int T = SI, N, i, x;

	while(T--)
	{
		N = SI;
		
		v.clear();
		REP(i,N) { x = SI; v.PB(x); }

		print();

		cnt = 0; mergesort(0, v.size()-1); printf("Number of inversions: %d\n", cnt);

		print();
	}

	return 0;
}
