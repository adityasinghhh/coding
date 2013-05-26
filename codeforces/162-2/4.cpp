
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

int N, M;
VPI v[210];

double f()
{
	bool mark[N+1]; FILL(mark,0);
	int dist[N+1];  REP(i,N+1) { dist[i] = INT_MAX; } // Fill with 'INT_MAX'

	PI p;
	priority_queue<PI> pq; 

	pq.push(MP(0,1)); dist[1] = 0;
	while(!pq.empty())
	{
		p = pq.top(); pq.pop(); 

		int d = -p.second, x = p.first;

		if(mark[x]) { continue; }

		REP(i,v[x].size()) 
		{ 
			p = v[x][i];
			int y = p.second, dxy = p.first;

			if(dist[y] > d + dxy) 
			{ 
				dist[y] = d + dxy; 
				pq.push(MP(-dist[y], y)); 
			}
		}

		mark[x] = 1;
	}

	sort(dist+1, dist+N+1);

	REP(i,N+1)
	{
		cout << i << " " << dist[i] << endl;
	}

	double maxi = dist[N], maxi2 = dist[N-1];
	
	if(v[1].size() == 1)
	{
		return maxi / 2.0;
	}
	else
	{
		return (maxi + maxi2) / 2.0;
	}
}

VI path;
int mark[210];
void dfs(int n, int d)
{
//	cout << n << " is at distance " << d << " from 1\n";
	bool flag = true;
	REP(i,v[n].size())
	{
		if(!mark[v[n][i].second])
		{
			mark[v[n][i].second] = d+v[n][i].first;
			dfs(v[n][i].second, d+v[n][i].first);
			flag = false;
		}
	}

	if(flag)
	{
		path.PB(d);
	}
}

int main()
{
	N = SI, M = SI;
	REP(i,M)
	{
		int x = SI, y = SI, d = SI;
		v[x].PB(MP(d,y));
		v[y].PB(MP(d,x));
	}

	REP(i,N+1)
	{
		SORT(v[i]);
	}

	mark[1] = 1;
	dfs(1, 1);

	FOR(i,1,N+1)
	{
		cout << i << " " << mark[i]-1 << endl;
	}

	SORT(path);

/*	REP(i,path.size())
	{
		cout << path[i] << " ";
	}
	cout << endl;
*/
	if(path.size() == 1)
	{
		double maxi = path[0]-1;
		printf("%lf\n", maxi/2.0);
	}
	else
	{
		double maxi = path[path.size()-1]-1, maxi2 = path[path.size()-2]-1;
		printf("%lf\n", (maxi+maxi2)/2.0);
	}

	return 0;
}
