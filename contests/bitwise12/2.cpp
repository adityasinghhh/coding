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

int mini, M;
vector<PI> V;
int a[300][300];
void f(int i)
{
	if(i == M)
	{
		int ans = 0;
		REP(i,M) 
		{
			ans += V[i].first*(V[i].first+1)/2;
		}
		mini = MIN(mini, ans);

		return;
	}

	f(i+1);
	REP(j,M)
	{
		if(V[i].first > V[j].first && a[V[i].second][V[j].second])
		{
			--V[i].first;
			++V[j].first;
			f(i);
			++V[i].first;
			--V[j].first;
		}
	}
}

int main()
{
	int T = SI;
	while(T--)
	{
		int N = SI; M = SI; int Q = SI;
		VI v[N+1];
		while(Q--)
		{
			int x = SI, y = SI;
			v[x].PB(y);
		}

		FOR(i,1,N+1) { SORT(v[i]); }

		int d[M+1];
		FILL(a,0); FILL(d,0);
		FOR(i,1,N+1)
		{
			if(v[i].size() == 0) { continue; }

			++d[v[i][0]];

			FOR(j,1,v[i].size())
			{
				++a[v[i][0]][v[i][j]];
			}			
		}

		V.clear();
		FOR(i,1,M+1)
		{
		//	printf("%d %d\n", i, d[i]);
			V.PB(MP(d[i], i));
		}

		mini = INT_MAX;
		f(0);
		printf("%d\n", mini);

		/*LL ans = 0ll;
		REP(i,M)
		{
		//	printf("%d %d\n", V[i].second, V[i].first);
			ans += V[i].first*(V[i].first+1)/2;
		}
		printf("%lld\n", ans);*/
	}
	return 0;
}
