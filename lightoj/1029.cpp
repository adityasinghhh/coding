
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
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define ABS(a) (a)<0?-(a):(a)
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int gcd(int a, int b) { return a%b ? gcd(b,a%b) : b; }

int N, M, X;
vector<PI> v[1000];

int prims(int sign)
{
	X = 0;

	int mark[N+1]; FILL(mark,0); mark[X] = 1;

	priority_queue<pair<int, PI> > pq;
	pair<int, PI> p;
	int i, x, d, y, dist = 0;

	REP(i,v[X].size()) { pq.push(MP(sign*v[X][i].first, MP(X, v[X][i].second))); }

	while(!pq.empty())
	{
		p = pq.top(); pq.pop(); if(mark[p.second.second]) { continue; }

		x = p.second.first; y = p.second.second; mark[y] = 1; d = sign*p.first;

		dist += d;

		REP(i,v[y].size()) { if(!mark[v[y][i].second]) { pq.push(MP(sign*v[y][i].first, MP(y, v[y][i].second))); } } 
	}

	return dist;
}

void solve()
{
	N = SI;

	int i; REP(i,N+1) { v[i].clear(); }
	
	while(true) 
	{ 
		int x = SI, y = SI, d = SI; if(!(x+y+d)) { break; }

		v[x].PB(MP(d,y)); 
		v[y].PB(MP(d,x)); 
	}

	int maxi = prims(1), mini = prims(-1);

	if((maxi+mini)%2) { printf("%d/2\n", maxi+mini); }
	else { printf("%d\n", (maxi+mini)/2); }
}

int main()
{
	int T = SI, zz;
	REP(zz, T)
	{
		printf("Case %d: ", zz+1);

		solve();
	}

	return 0;
}
