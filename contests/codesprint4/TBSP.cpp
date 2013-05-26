
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

double Distance(double x1, double y1, double x2, double y2)
{
	double x = x1-x2, y = y1-y2;
	return sqrt(x*x + y*y);
}
	
int N;
double C, D;
VPI v;
vector<double> dist, S;

vector<pair<double, int> > V[N+1];
int depth(int i, int num_visited)
{
	int best = V[i][V[i].size()-1].second;
	double d = Distance(v[i].first, v[i].second, v[j].first, v[j].second);
	if(V[i][V[i].size()-1].second
}

int main()
{
	N = SI;
	C = SLF, D = SLF;
	REP(i,N)
	{
		int x = SI, y = SI;
		double s = SLF;
		v.PB(MP(x,y));
		S.PB(s);
		dist.PB(Distance(0.0, 0.0, (double)x, (double)y));
	}

	REP(i,N)
	{
		REP(j,N)
		{
			double d = Distance(v[i].first, v[i].second, v[j].first, v[j].second);
			if(d * S[j] > 0.0)
			{
				V[i].PB(MP(d*S[j], j));
			}
		}

		SORT(V[i]);
	}

	VI carry;
	REP(i,N)
	{
		carry.PB(depth(i, 0));
	}

	int num_visited = 0;
	while(true)
	{
		vector<pair<double, PI> > profits;
		REP(i,N)
		{
			double profit = dist[i] * (2 + C * V[i].size());
			double profit = l * S[i] - dist[i] * (2 + C * l);
			if(profit > 0.0)
			{
				profits.PB(MP(profit, MP(l, i)));
			}
		}

		if(profits.size() == 0)
		{
			break;
		}

		SORT(profits);

		int ind = profits[profits.size()-1].second.second;
		printf("%d %d %d\n", v[ind].first, v[ind].second, profits[profits.size()-1].second.first);
		++num_visited;

		if(num_visited == N/10)
		{
			num_visited = 0;
			REP(i,N)
			{
				S[i] *= D;
			}
		}
	}

	return 0;
}
