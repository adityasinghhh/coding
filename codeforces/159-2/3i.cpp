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

double angle(int x, int y)
{
	if(x == 0)
	{
		return y > 0 ? M_PI/2.0 : -M_PI/2.0; 
	}

	if(x < 0)
	{
		return y >= 0 ? atan((double)y/(double)x) + M_PI : atan((double)y/(double)x) - M_PI;
	}

	return atan((double)y/(double)x);
}

double angle2(int x, int y)
{
	double ang = atan2(x, y);

	if(ang < 0.0)
	{
		ang += 2.0*M_PI;
	}

	return ang;
}

bool compare(PI p1, PI p2)
{
	double ang1 = angle2(p1.first, p1.second);
	double ang2 = angle2(p2.first, p2.second);

	return ang1 < ang2;
}

int main()
{
	int N = SI;
	VPI v;
	REP(i,N)
	{
		int x = SI, y = SI;
		v.PB(MP(x,y));
	}

	sort(v.begin(), v.end(), compare);

	double ang[N+1];
	REP(i,N)
	{
		ang[i] = angle2(v[i].first, v[i].second);

//		printf("(%d, %d): %lf\n", v[i].first, v[i].second, ang[i]);
	}

	double maxi = (double)INT_MAX, diff;
	REP(i,N)
	{
		if(i == 0)
		{
			diff = ang[0] - ang[N-1];
			diff = ABS(diff);
		}
		else
		{
			diff = ang[i] - ang[i-1];
			diff = 2.0*M_PI - diff;
		}

		maxi = MIN(maxi, diff);
	}

	printf("%lf\n", 180.0*maxi/M_PI);

	return 0;
}
