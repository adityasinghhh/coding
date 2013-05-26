
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
typedef vector<long double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<long double,long double> PD;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({long double _x; scanf("%llf",&_x); _x;})
#define PI(x) printf("%d",x)
#define PC(x) printf("%c",x)
#define PLL(x) printf("%lld",x)
#define PLF(x) printf("%llf",x)
#define PS(x) printf("%s",x)
#define P32() printf(" ")
#define P10() printf("\n")
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define llfscan(n) scanf("%llf",&n)
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
	REP(zz,T)
	{
		long double D = SLF;
		int N = SI, A = SI;
		PD p[N+1];
		REP(i,N)
		{
			long double t = SLF, x = SLF;
			p[i] = MP(t, x);
		}

		printf("Case #%d:\n", zz+1);
		REP(i,A)
		{
			long double a = SLF, v = 0.0, dist = 0.0, t = 0.0;
			bool flag = false;
			REP(j,N)
			{
				if(p[j].second > D)
				{
					if(j == 0)
					{
						break;
					}

					long double more = (D-p[j-1].second)*(p[j].first-p[j-1].first)/(p[j].second-p[j-1].second);
					dist += v*more + 0.5*a*more*more;
					v = sqrt(v*v + 2.0*a*dist);
					t += more;
				
					break;
				}

				long double d = v*p[j].first + 0.5*a*p[j].first*p[j].first;
				t = p[j].first;
				if(dist+d > p[j].second)
				{
					dist = p[j].second;
				}
				else
				{
					dist += d;
				}

				v = sqrt(v*v + 2.0*a*dist);

				printf("Distance: %llf\t Speed: %llf\t Time: %llf\n", dist, v, t);
			}

			t += (sqrt(v*v+2.0*a*(D-dist))-v)/a;

			printf("%llf\n", t);
		}
	}
	return 0;
}
