
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

int main()
{
	int T = SI;
	while(T--)
	{
		int N = SI;
		VI v[N+1];
		int cnt[N+1];
		FILL(cnt, 0);
		int cnt1[N+1];
		FILL(cnt1, 0);
		int S[N+1];
		FILL(S,0);
		REP(i,N)
		{
			REP(j,N)
			{
				int x = SI;
				if(x)
				{
					++cnt1[j+1];
					++cnt[i+1];
					v[j+1].PB(i+1);
				}
			}
		}

		VI sources;
		queue<PI> q;
		int mark[N+1];
		FILL(mark, 0);
		FOR(i,1,N+1)
		{
			if(cnt[i] == 0)
			{
				mark[i] = 1;
				q.push(MP(i, 1));
			}

			if(cnt1[i] == 0)
			{
				S[i] = 1;
				sources.PB(i);
			}
		}

		while(!q.empty())
		{
			queue<PI> Q;
			while(!q.empty())
			{
				PI p = q.front();
				q.pop();

				int x = p.first, d = p.second;
				REP(i,v[x].size())
				{
					--cnt[v[x][i]];
					mark[v[x][i]] = d+1;
					if(cnt[v[x][i]] == 0)
					{
//						printf("%d gives %d to %d\n", x, d+1, v[x][i]);
						Q.push(MP(v[x][i], d+1));
					}
				}
			}
				
			q = Q;
		}

		FILL(cnt, 0);
		FILL(cnt1, 0);
		FOR(i,1,N+1)
		{
//			printf("%d: %d\n", i, mark[i]);
			++cnt[mark[i]];
			if(S[i] == 1)
			{
				++cnt1[mark[i]];
			}
		}

		int maxi = 0, maxVal = 0;
		REP(i,N+1)
		{
			if(maxi < cnt[i])
			{
				maxVal = i;
				maxi = cnt[i];
			}
			else if(maxi == cnt[i] && cnt1[maxVal] > cnt1[i])
			{
				maxVal = i;
			}
		}

//		printf("Sources: ");
		REP(i,sources.size())
		{
//			printf("%d ", sources[i]);
			if(mark[sources[i]] < maxVal)
			{
				++maxi;
			}
		}
//		printf("\n");

		printf("%d\n", maxi);
	}

	return 0;
}
