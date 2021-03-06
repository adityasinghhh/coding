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

int main()
{
	int T = SI;
	while(T--)
	{
		int N = SI;
		VI v[N+1];
		FOR(i,1,N+1)
		{
			int M = SI;
			while(M--)
			{
				v[i].PB(SI);
			}
		}

		if(N&1) { printf("NO\n"); continue; }

		queue<VI> q;
		VI V; V.PB(-1); REP(i,N) { V.PB(0); }
		q.push(V);
		
		int cnt = 0;
		while(!q.empty())
		{
//			REP(i,N+1) { printf("%d ", q.front()[i]); } printf("\n");

			int i = 1; while(i <= N && q.front()[i]) { ++i; }

			if(i > N) { ++cnt; if(cnt > 1) { break; } q.pop(); continue; }

			REP(j,v[i].size())
			{
				if(q.front()[v[i][j]]) { continue; }

				q.front()[i] = v[i][j];
				q.front()[v[i][j]] = i;
				q.push(q.front());				
				q.front()[i] = 0;
				q.front()[v[i][j]] = 0;
			}
			
			q.pop();
		}

		printf(cnt != 1 ? "NO\n" : "YES\n");
	}

	return 0;
}
