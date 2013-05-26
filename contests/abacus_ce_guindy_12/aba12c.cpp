
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
#define PI(x) printf("%d",&x)
#define PC(x) printf("%c",&x)
#define PLL(x) printf("%lld",&x)
#define PLF(x) printf("%lf",&x)
#define PS(x) printf("%s",&x)
#define PSP() printf(" ")
#define PSN() printf("\n")
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

int N, K, minCost;
VPI v;
int dp[101][101];
int sz;
void f1()
{
	dp[0][0] = 1;
	REP(ii,N)
	{
		REP(i,sz)
		{
//			printf("%d %d\n", v[i].first, v[i].second);
			REP(j,N+1)
			{
				REP(k,K+1)
				{
					if(k+v[i].first > K) { break; }

					if(dp[j][k])
					{
						if(dp[j+1][k+v[i].first])
						{
							dp[j+1][k+v[i].first] = MIN(dp[j+1][k+v[i].first], dp[j][k] + v[i].second);
						}
						else
						{
							dp[j+1][k+v[i].first] = dp[j][k] + v[i].second;
						}
						
						//printf("Can buy %d packets weighing %d kgs apples at minCost of %d\n", j+1, k+v[i].first, dp[j+1][k+v[i].first]);
					}
				}
			}
		}
	}
}

int main()
{
	int T = SI;
	while(T--)
	{
		FILL(dp,0);

		N = SI; K = SI;

		v.clear(); 
		FOR(i,1,K+1) 
		{ 
			int x = SI; 
			if(x == -1) { continue; } 
			v.PB(MP(i,x)); 
		}

		sz = v.size();

		if(sz == 0) { printf("-1\n"); continue; }

		f1();

		int mini = INT_MAX;
		REP(i,N+1)
		{
			if(dp[i][K])
			{
				mini = MIN(mini, dp[i][K]);
			}
		}

		printf(mini == INT_MAX ? "-1\n": "%d\n", mini-1);
	}
	return 0;
}
