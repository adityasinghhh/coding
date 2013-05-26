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

map<VI, bool> m;
map<VI, bool>::iterator it;

VI v[101];
int N, mark[101], cnt;
bool flag;
void f(int i)
{
	if(i == N)
	{
		FOR(j,1,N+1) { if(!mark[j]) { return; } }

//		FOR(j,1,N+1) { printf("%d ", mark[j]); } printf("\n");
		++cnt;
		if(cnt > 1) { flag = true; }
		return;
	}

	if(mark[i]) { f(i+1); }
	else
	{
//		printf("FOR: %d < %d\n", i, N);
		REP(j,v[i].size())
		{
			if(v[i][j] < i || mark[v[i][j]]) { continue; }

			mark[v[i][j]] = i;
			mark[i] = v[i][j];
			f(i+1);
			if(flag) { return; }
			mark[i] = 0;
			mark[v[i][j]] = 0;
		}
	}
}

int main()
{
	int T = SI;
	while(T--)
	{
		m.clear();
		N = SI;
		FOR(i,1,N+1)
		{
			v[i].clear();
			int M = SI;
			while(M--)
			{
				v[i].PB(SI);
			}
		}

		if(N&1) { printf("NO\n"); continue; }

/*		FOR(i,1,N+1)
		{
			REP(j,v[i].size())
			{
				printf("%d ", v[i][j]);
			}
			printf("\n");
		}
*/
		FILL(mark,0);
		
		cnt = 0;
		flag = false;
		f(1);

		if(cnt == 0) { printf("NO\n"); }
		else 
		{
			printf(flag ? "NO\n" : "YES\n");
		}
	}

	return 0;
}
