
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

PD XIntersection(double x, double y)
{
	return MP(x - sqrt(16.0*y), x + sqrt(16.0*y));	
}

double linePointDistance(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double x = x1-x2, y = y1-y2;

	x2 -= x1; y2 -= y1;
	x3 -= x1; y3 -= y1;

	return fabs((x2*y3 - y2*x3)/sqrt(x*x+y*y));
}

double distance(double x, double y, double vx, double vy)
{
	double a = -1.0/16.0;
	double b = 2.0*vx/16.0;
	double c = -(vx*vx - 16.0*vy)/16.0;
	double D = b*b - 4.0*a*c;

	double fx = vx, fy = (1.0 - D)/4.0/a;

	double p = linePointDistance(fx, fy, vx, vy, x, y);

	double h = p/2.0;

	double f = 4.0; //sqrt((fx-vx)*(fx-vx) + (fy-vy)*(fy-vy));

	double q = sqrt(f*f + h*h);

	double s = h*q/f + f * log((h+q)/f);

	return s;
}

PD parabolicIntersection(double x1, double y1, double x2, double y2)
{
	double x = (16.0*y2 - 16.0*y1 + x1*x1 - x2*x2)/2.0/(x1-x2);
	double y = -(x-x1)*(x-x1)/16.0 + y1;

	return MP(x,y);
}

int main()
{
//	printf("%lf\n", linePointDistance(-5.0, 5.0, 5.0, 5.0, 1.0, 1.0));
	int T = SI;
	while(T--)
	{
		int N = SI;
		vector<PD> v;
		REP(i,N)
		{
			double x = SLF, y = SLF;
			v.PB(MP(x,y));
		}

		PD p = XIntersection(v[0].first, v[0].second);
//		printf("Ground meeting points: (%lf, 0.0) and (%lf, 0.0)\n", p.first, p.second);
		double ans = distance(p.first, 0.0, v[0].first, v[0].second);

		FOR(i,1,v.size())
		{
			PD q = parabolicIntersection(v[i-1].first, v[i-1].second, v[i].first, v[i].second);

//			printf("Intersection: (%lf, %lf)\n", q.first, q.second);

			if(q.second < 0.0)
			{
				p = XIntersection(v[i-1].first, v[i-1].second);
//				printf("Ground meeting points: (%lf, 0.0) and (%lf, 0.0)\n", p.first, p.second);
				ans += distance(p.second, 0.0, v[i-1].first, v[i-1].second);

				p = XIntersection(v[i].first, v[i].second);
//				printf("Ground meeting points: (%lf, 0.0) and (%lf, 0.0)\n", p.first, p.second);
				ans += distance(p.first, 0.0, v[i].first, v[i].second);
			}
			else
			{
				ans += distance(q.first, q.second, v[i-1].first, v[i-1].second);
				ans += distance(q.first, q.second, v[i].first, v[i].second);
			}
		}

		p = XIntersection(v[v.size()-1].first, v[v.size()-1].second);
		ans += distance(p.second, 0.0, v[v.size()-1].first, v[v.size()-1].second);

		printf("%.2lf\n", ans);
	}

	return 0;
}
