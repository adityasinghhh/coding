
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
#define TR(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int main()
{
	int T = SI;
	VI v[10001];
	while(T--)
	{
		int N = SI, k1 = SI, k2 = SI, k3 = SI;

		v[0].clear(); int x = SI; v[0].PB(x);

		FOR(i,1,N)
		{
			v[i].clear();

			int x = SI, sz = v[i-1].size();

			sz = MIN(sz, k3);

			int j = 0;
			while(j < sz && v[i-1][j] > 0)
			{
				v[i].PB(v[i-1][j]+x);
				++j;
			}
			v[i].PB(x);
			while(j < sz)
			{
				v[i].PB(v[i-1][j]+x);
				++j;
			}
		}

		priority_queue<PI> pq;
		int P[N+1]; FILL(P,0);

		REP(i,N) { pq.push(MP(v[i][0], i)); }

		int cnt = 1;
		while(!pq.empty())
		{
			PI p = pq.top(); pq.pop();

			int t = p.first, i = p.second;

			if(cnt == k1 || cnt == k2) { printf("%d ", t); }
			else if(cnt == k3) { printf("%d\n", t); break; }

			++cnt;

			if(P[i] < v[i].size()-1) 
			{
				++P[i];
				pq.push(MP(v[i][P[i]], i));
			}
		}
	}

	return 0;
}
