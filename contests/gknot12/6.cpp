
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
	int BASE = 7, cnt1 = 0, cnt2 = 0;
	FOR(i,1,BASE+1)
	{
		FOR(j,1,BASE+1)
		{
			FOR(k,1,BASE+1)
			{
				FOR(l,1,BASE+1)
				{
					FOR(m, 1, BASE+1)
					{
						if((i+j+m) % BASE == 0) { continue; }

						FOR(n,1,BASE+1)
						{
							if((k+l+n) % BASE == 0) { continue; }
							
							FOR(o, 1, BASE+1)
							{
								if((i+k+o) % BASE == 0) { continue; }

								FOR(p,1,BASE+1)
								{
									if((j+l+p) % BASE == 0) { continue; }

									if((o+p)%BASE == (m+n)%BASE)
									{
										++cnt1;
									}
									else
									{
										++cnt2;
									}
								}
							}

						}
					}
				}
			}
		}
	}

	printf("%d %d %d\n", cnt1, cnt2, cnt1*(BASE-1)+cnt2*(BASE-2));

	return 0;
}
