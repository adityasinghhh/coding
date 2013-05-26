
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

int kruskal(int &N, vector<VPI> &v, priority_queue<pair<int, PI> > pq, int flag)
{
	set<int> s[N+1];
	int P[N+1];
	REP(i,N+1) { s[i].insert(i); P[i] = i; }

	int cnt = N, span = 0;

	while(cnt)
	{
		pair<int, PI> p = pq.top(); pq.pop();

		int d = flag*p.first, x = p.second.first, y = p.second.second;

//		printf("(%d,%d): %d\n", x, y, d);

		if(P[x] == P[y]) { continue; }

//		printf("Merging sets: %d in %d and %d in %d\n", x, P[x], y, P[y]);

		--cnt;

		span += d;

		int r = P[y];
		TR(it, s[r])
		{
			s[P[x]].insert(*it);
			P[*it] = P[x];
		}
		s[r].clear();

/*		REP(i,N+1)
		{
			if(s[i].size())
			{
				printf("%d: ", i);
				TR(it,s[i])
				{
					printf("%d ", *it);
				}
				printf("\n");
			}
		}
*/	}

	return span;
}

int main()
{
	int T = SI;
	REP(zz,T)
	{
		int N = SI;
		vector<VPI> v;
		REP(i,N+1) { VPI temp; v.PB(temp); }
		priority_queue<pair<int, PI> > pq1, pq2;
		while(true)
		{
			int x = SI, y = SI, d = SI;

			if(!(x+y+d)) { break; }

			v[x].PB(MP(y,d));
			v[y].PB(MP(x,d));
			pq1.push(MP(-d,MP(MIN(x,y),MAX(x,y))));
			pq2.push(MP(d,MP(MIN(x,y),MAX(x,y))));
		}

		int mini = kruskal(N, v, pq1, -1);
		int maxi = kruskal(N, v, pq2, 1);

		printf("Case %d: ", zz+1);
		if((mini+maxi)&1) { printf("%d/2\n", mini+maxi); }
		else { printf("%d\n", (mini+maxi)/2); }
	}

	return 0;
}
