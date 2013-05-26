
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
	int T = SI;
	while(T--)
	{
		int xe = SI, ye = SI, de;
		getchar();
		de = getchar();

		int N = SI;
/*		VI x, y, d;
		REP(i,N)
		{
			x.PB(SI);
			y.PB(SI);
			getchar();
			int x1 = getchar();
			d.PB(x1);
		}
*/
		VI x, y, d;
		int mini = INT_MAX;
		REP(i,N)
		{
			x.PB(SI);
			y.PB(SI);
			getchar();
			int x1 = getchar();
			d.PB(x1);

			if(de == 'R')
			{
				if(d[i] == 'R')
				{
//					printf("No collision\n");
				}
				else if(d[i] == 'L')
				{
					if(y[i] == ye && x[i] > xe)
					{
						mini = MIN(mini, x[i]-xe);
//						printf("Colliding in %.1lf\n", ((double)(x[i]-xe))/2.0);
					}
					else
					{
//						printf("No collision\n");
					}
				}
				else if(d[i] == 'D')
				{
					if(x[i] > xe  && x[i]-xe == y[i]-ye)
					{
						mini = MIN(mini, 2*(x[i]-xe));
//						printf("Colliding in %d.0\n", x[i]-xe);
					}
					else
					{
//						printf("No collision\n");
					}
				}
				else
				{
					if(x[i] > xe && x[i]-xe == ye-y[i])
					{
						mini = MIN(mini, 2*(x[i]-xe));
//						printf("Colliding in %d.0\n", x[i]-xe);
					}
					else
					{
//						printf("No collision\n");
					}
				}
			}
			else if(de == 'L')
			{
				if(d[i] == 'R')
				{
					if(y[i] == ye && xe > x[i])
					{
						mini = MIN(mini, xe-x[i]);
//						printf("Colliding in %.1lf\n", ((double)(x[i]-xe))/2.0);
					}
					else
					{
//						printf("No collision\n");
					}
				}
				else if(d[i] == 'L')
				{
//					printf("No collision\n");
				}
				else if(d[i] == 'D')
				{
					if(xe > x[i] && xe-x[i] == y[i]-ye)
					{
						mini = MIN(mini, 2*(xe-x[i]));
//						printf("Colliding in %d.0\n", xe-x[i]);
					}
					else
					{
//						printf("No collision\n");
					}
				}
				else
				{
					if(xe > x[i] && xe-x[i] == ye-y[i])
					{
						mini = MIN(mini, 2*(xe-x[i]));
//						printf("Colliding in %d.0\n", xe-x[i]);
					}
					else
					{
//						printf("No collision\n");
					}
				}
			}
			else if(de == 'D')
			{
				if(d[i] == 'R')
				{
					if(xe > x[i] && xe-x[i] == ye-y[i])
					{
						mini = MIN(mini, 2*(xe-x[i]));
//						printf("Colliding in %d.0\n", xe-x[i]);
					}
					else
					{
//						printf("No collision\n");
					}
				}
				else if(d[i] == 'L')
				{
					if(x[i] > xe && x[i]-xe == ye-y[i])
					{
						mini = MIN(mini, 2*(x[i]-xe));
//						printf("Colliding in %d.0\n", x[i]-xe);
					}
					else
					{
//						printf("No collision\n");
					}
				}
				else if(d[i] == 'D')
				{
//					printf("No collision\n");
				}
				else
				{
					if(xe == x[i] && ye > y[i])
					{
						mini = MIN(mini, ye-y[i]);
//						printf("Colliding in %.1lf\n", ((double)(ye-y[i]))/2.0);
					}
					else
					{
//						printf("No collision\n");
					}
				}
			}
			else
			{
				if(d[i] == 'R')
				{
					if(xe > x[i] && xe-x[i] == y[i]-ye)
					{
						mini = MIN(mini, 2*(xe-x[i]));
//						printf("Colliding in %d.0\n", xe-x[i]);
					}
					else
					{
//						printf("No collision\n");
					}
				}
				else if(d[i] == 'L')
				{
					if(x[i] > xe && x[i]-xe == y[i]-ye)
					{
						mini = MIN(mini, 2*(x[i]-xe));
//						printf("Colliding in %d.0\n", x[i]-xe);
					}
					else
					{
//						printf("No collision\n");
					}
				}
				else if(d[i] == 'D')
				{
					if(xe == x[i] && y[i] > ye)
					{
						mini = MIN(mini, y[i]-ye);
//						printf("Colliding in %.1lf\n", ((double)(y[i]-ye))/2.0);
					}
					else
					{
//						printf("No collision\n");
					}
				}
				else
				{
//					printf("No collision\n");
				}
			}
		}

		if(mini == INT_MAX)
		{
			printf("SAFE\n");
		}
		else
		{
			printf("%d", mini/2);
			if(mini&1)
			{
				printf(".5\n");
			}
			else
			{
				printf(".0\n");
			}
		}
	}
	return 0;
}
