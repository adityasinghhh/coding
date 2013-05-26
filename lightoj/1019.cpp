
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
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=b-1;i>=a;--i)
#define REP(i,b) for(int i=0;i<b;++i)
#define REPD(i,b) for(int i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define ABS(a) a<0?-a:a
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int dijkstra()
{
	int N = SI, M = SI; 
	
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
	
	pq.push(MP(0,1)); dist[1] = 0;
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

	return dist[N];
}

int main()
{
	int T = SI, zz;
	REP(zz, T)
	{
		int d = dijkstra();
		printf("Case %d: ", zz+1);
		printf(d == INT_MAX ? "Impossible\n" : "%d\n", d);
	}

	return 0;
}
