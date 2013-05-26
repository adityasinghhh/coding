
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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
	int N = SI, Q = SI;
	VI x, y;
	REP(i,N)
	{
		x.PB(SI);
		y.PB(SI);
	}

	while(Q--)
	{
		int M = SI;
		VI tx, ty;
		REP(i,M)
		{
			tx.PB(SI);
			ty.PB(SI);
		}

		int cnt = 0;
		REP(i,N)
		{
			bool flag = false;
			REP(j,M)
			{
				if((tx[j] == tx[(j+1)%M] && tx[j] == x[i] && ((ty[j] <= y[i] && y[i] <= ty[(j+1)%M]) || (ty[j] >= y[i] && y[i] >= ty[(j+1)%M]))) || (ty[j] == ty[(j+1)%M] && ty[j] == y[i] && ((tx[j] <= x[i] && x[i] <= tx[(j+1)%M]) || (tx[j] >= x[i] && x[i] >= tx[(j+1)%M]))))
				{
					flag = true;
					break;
				}
			}

			if(flag) { ++cnt; continue; }

			int cnt1 = 0;
			REP(j,M)
			{
				if(ty[j] == ty[(j+1)%M]) { continue; }
				if(tx[j] > x[i]) { continue; }

				if((ty[j] < y[i] && y[i] < ty[(j+1)%M]) || (ty[j] > y[i] && y[i] > ty[(j+1)%M]))
				{
					++cnt1;
				}
			}

			int cnt2 = 0;
			REP(j,M)
			{
				if(tx[j] == tx[(j+1)%M]) { continue; }
				if(ty[j] > y[i]) { continue; }

				if((tx[j] < x[i] && x[i] < tx[(j+1)%M]) || (tx[j] > x[i] && x[i] > tx[(j+1)%M]))
				{
					++cnt2;
				}
			}

			if(cnt1&1 || cnt2&1) { ++cnt; }
		}

		printf("%d\n", cnt);
	}
	
	return 0;
}
