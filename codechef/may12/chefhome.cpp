
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
	while(T--)
	{
		int N = SI;
		PI p[N+1];
		REP(i,N)
		{
			p[i].first = SI;
			p[i].second = SI;
		}

		if(N == 2)
		{
			if(p[0].first == p[1].first && p[0].second == p[1].second)
			{
				printf("1\n");
			}
			else if(p[0].first == p[1].first)
			{
				printf("%d\n", ABS(p[0].second-p[1].second)+1);
			}
			else if(p[0].second == p[1].second)
			{
				printf("%d\n", ABS(p[0].first-p[1].first)+1);
			}
			else
			{
				printf("4\n");
			}
		}
		else
		{
			int mini = INT_MAX, cnt = 0;
			REP(i,N)
			{
				int tot = 0;
				REP(j,N)
				{
					tot += ABS(p[i].first - p[j].first) + ABS(p[i].second - p[j].second);
				}

				if(tot < mini)
				{
					mini = tot;
					cnt = 1;
				}
				else if(tot == mini)
				{
					++cnt;
				}
			}

			printf("%d\n", cnt);
		}
	}
	return 0;
}
