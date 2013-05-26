
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

set<PI> MARK;
set<PI>::iterator it;
int main()
{
	int N = SI, K = SI;
	VI v[N+1];
	REP(i,N-1)
	{
		int x = SI, y = SI;
		v[x].PB(y);
		v[y].PB(x);
	}

	VI start;
	FOR(i,1,N+1)
	{
		if(v[i].size() == 1)
		{
			start.PB(i);
		}
	}

	LL ans = 0ll;
	REP(z,start.size())
	{
		queue<PI> q;
		q.push(MP(start[z], 1));
		printf("Starting at %d\n", start[z]);
		int mark[N+1];
		FILL(mark, 0);
		while(!q.empty())
		{
			PI p = q.front(); q.pop();

			int x = p.first, d = p.second;

			printf("Distance[%d] = %d\n", x, d);

			mark[x] = d;
			REP(i,v[x].size())
			{
				if(!mark[v[x][i]])
				{
					q.push(MP(v[x][i], d+1));
				}
			}
		}

		VI p[2*K+N+1];
		FOR(i,1,N+1)
		{
			p[mark[i]].PB(i);
		}

		REP(i,2*K+N+1)
		{
			REP(j,p[i].size())
			{
				REP(k,p[i+K].size())
				{
					int a = p[i][j], b = p[i+K][k];
					if(a > b) { swap(a,b); }
					PI P = MP(a,b);

					it = MARK.find(P);
					if(it == MARK.end())
					{
						printf("%d %d\n", a, b);
						MARK.insert(P);
						++ans;
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
