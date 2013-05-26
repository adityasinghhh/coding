#include<iostream>
#include<sstream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define MP make_pair
#define PB push_back
#define LL long long
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REPD(i,b) for(int i=(b)-1;i>=0;--i)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a) ((a)<0?-(a):(a))

typedef vector<int> VI; 
typedef pair<int,int> PI; 
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define RAND(x) ((int)(((rand()*1.0)/RAND_MAX)*(x)))

int dijkstra()
{
	int N = SI, M = SI, start = SI; 
	vector<PI> V[N+1];
	REP(i,M) 
	{ 
		int x = SI, y = SI, z = SI; 
		V[x].PB(MP(y,z)); 
		V[y].PB(MP(x,z)); // Remove this if the edges are directed
	}
	bool mark[N+1]; FILL(mark,0);
	int dist[N+1];  REP(i,N+1) { dist[i] = INT_MAX; } // Fill with 'INT_MAX'
	PI p;
	priority_queue<PI> pq; 
	pq.push(MP(0,start)); dist[start] = 0;
	while(!pq.empty())
	{
		p = pq.top(); pq.pop(); 
		int d = -p.first, x = p.second;
		if(mark[x]) { continue; }
		REP(i,V[x].size()) 
		{ 
			p = V[x][i];
			int y = p.first, dxy = p.second;
			if(dist[y] > d + dxy) 
			{ 
				dist[y] = d + dxy; 
				pq.push(MP(-dist[y], y)); 
			}
		}
		mark[x] = 1;
	}

	int T = SI;
	LL ans = 0ll;
	while(T--)
	{
		int end = SI, w = SI;
		ans += dist[end]*w;
	}

	printf("%lld\n", ans);

}

int main()
{
	dijkstra();

	return 0;
}

