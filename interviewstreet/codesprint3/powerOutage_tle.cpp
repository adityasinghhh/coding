
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
		int N = SI, M = SI, K = SI;
		VPI v[N+1];
		REP(i,M)
		{
			int x = SI, y = SI, d = SI;

			v[x].PB(MP(y,d));
			v[y].PB(MP(x,d));
		}

		int cnt = 0, mark[N+1], ans[N+1], z = 0, marked = 0;
		FILL(mark,-1);
		while(cnt < K)
		{
			int tot = 0ll, ind;
			FOR(i,1,N+1)
			{
				if(mark[i] == -1)
				{
					ind = i;
					break;
				}
			}

			priority_queue<PI> q;
			q.push(MP(0, ind));
			int cnt1 = 0;
			while(!q.empty())
			{
				PI p = q.top();
				q.pop();

				int x = p.second, d = -p.first;
				if(mark[x] != -1)
				{
					continue;
				}

				mark[x] = d;
				++marked;
				ans[z++] = d;

				REP(i,v[x].size())
				{
					q.push(MP(-v[x][i].second, v[x][i].first));
				}
			}

/*			FOR(i,1,N+1)
			{
				cout << "(" << i << "," << mark[i] << ")" << " ";
			}
			cout << endl;
*/
			++cnt;

			if(marked == N)
			{
				break;
			}
		}

		if(marked == N)
		{
			sort(ans, ans+z);
			LL tot = 0ll;
			REP(i,z)
			{
				tot += 1ll*ans[i];
			}

			int sz = z-1;
			while(sz >= 0 && cnt < K)
			{
				++cnt;
				tot -= ans[sz];
				--sz;
			}

			printf("%lld\n", tot);
		}
		else
		{
			printf("Impossible!\n");
		}
	}

	return 0;
}
