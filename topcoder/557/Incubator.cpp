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

class Incubator {
	public:
		int r, c;
		vector<string> v;
		VI mark;
		vector<set<int> > w;

		void f(int i)
		{
			if(mark[i] == 1)
			{
				return;
			}

			mark[i] = 1;

			REP(j,c)
			{
				if(v[i][j] == 'Y')
				{
					w[i].insert(j);
					f(j);
				}
			}

			mark[i] = 0;
		}

		void g(int s, int i)
		{
			if(mark[i] == 1)
			{
				return;
			}

			mark[i] = 1;
			REP(j,c)
			{
				if(v[i][j] == 'Y')
				{
					TR(it,w[j])
					{
						w[s].insert((*it));
						g(s, j);;
					}
				}
			}
			mark[i] = 0;
		}

		int dp[55][55];
		int h(int i, int n)
		{
			int &m = dp[i][n];
			if(m != -1)
			{
				return m;
			}

			if(i == r)
			{
				return dp[i][n] = n;
			}

			int ret = h(i+1, n);
			TR(it, w[i])
			{
				mark[(*it)] = 1;
			}
			if(!mark[i])
			{
				ret = MAX(ret, h(i+1, n+1));
			}
			TR(it, w[i])
			{
				mark[(*it)] = 0;
			}

			return m = ret;
		}

		int maxMagicalGirls(vector <string> love) {
			v = love;
			r = v.size();
			c = v[0].length();

			REP(i,r)
			{
				mark.PB(0);
				set<int> temp;
				w.PB(temp);
			}

			REP(i,r)
			{
				f(i);
			}

			REP(i, r)
			{
				g(i, i);
			}

			FILL(dp, -1);
			return h(0, 0);
		}
};

