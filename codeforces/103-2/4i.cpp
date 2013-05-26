
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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int main()
{
	int N = SI, M = SI, C = SI;
	VPI v[N+1];
	REP(i,M)
	{
		int x = SI, y = SI, d = SI;
		
		v[x].PB(MP(y, d));
		v[y].PB(MP(x, d));
	}

	int d = SI;

	bool mark[N+1]; FILL(mark,0);
	int dist[N+1];  REP(i,N+1) { dist[i] = INT_MAX; } // Fill with 'INT_MAX'

	PI p;
	priority_queue<PI> pq;

	pq.push(MP(0,C)); dist[C] = 0;
	while(!pq.empty())
	{
		p = pq.top(); pq.pop();

		int d = -p.first, x = p.second;

		if(mark[x]) { continue; }

		REP(i,v[x].size())
		{
			p = v[x][i];
			int y = p.first, dxy = p.second;

			if(dist[y] > d + dxy)
			{
				dist[y] = d + dxy;
				pq.push(MP(-dist[y], y));
			}
		}

		mark[x] = 1;
	}

//	REP(i,N+1) { printf("%d: %d\n", i, dist[i]); }

	int cnt = 0;
	FILL(mark,0);
	pq.push(MP(d,C));
	map<PI, int> m;
	map<PI, int>::iterator it;
	while(!pq.empty())
	{
		p = pq.top(); pq.pop();

		int d = -p.first, x = p.second;

		if(mark[x]) { continue; }

		REP(i,v[x].size())
		{
			p = v[x][i];
			int y = p.first, dxy = p.second;

			if(dxy < d)
			{
				pq.push(MP(-d+dxy, y));
			}
			else if(dxy == d)
			{
				if(dist[y] == d)
				{
					printf("Planting bomb at %d\n", y);
					++cnt;
				}
			}
			else
			{
				int x1 = x, y1 = y, d1 = d;
				
				if(x1 > y1) { swap(x1, y1); d1 = dxy-d1; }

				it = m.find(MP(x1,y1));

				if(it == m.end())
				{
					printf("Planting bomb at %d between %d and %d\n", d1, x1, y1);
					++cnt;
					m[MP(x1,y1)] = d1;
				}
				else
				{
					if((*it).second != d1)
					{
						printf("Planting bomb at %d between %d and %d\n", d1, x1, y1);
						++cnt;
						m[MP(x1,y1)] = d1;
					}
				}
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
