
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

int main()
{
	int N = SI;
	double C = SLF, D = SLF;
	VPI v;
	vector<double> blimp_cost;
	REP(i,N)
	{
		int x = SI, y = SI;
		v.PB(MP(x,y));
		blimp_cost.PB(SLF);
	}

	int totalProfit = 0.0;
	int mark[N+1];
	FILL(mark,0);
	int num_visited = 0;
	bool flag = false;
	while(true)
	{
		vector<pair<double, int> > profits;
		REP(i,N)
		{
			if(mark[i])
			{
				continue;
			}

			double profit = blimp_cost[i] - (1 + C) * Distance(0.0, 0.0, v[i].first, v[i].second);
			if(profit > 0.0)
			{
				profits.PB(MP(profit, i));
			}
		}

		if(profits.size() == 0)
		{
			break;
		}

		SORT(profits);

		int last = profits.size()-1, curr = profits[last].second;
		double cost = profits[last].first, distanceTravelled = Distance(0.0, 0.0, v[last].first, v[last].second);
		VI print;
		print.PB(profits[last].second);
		mark[curr] = 1;
		++num_visited;
		if(num_visited == N/10)
		{
			num_visited = 0;
			REP(i,N)
			{
				blimp_cost[i] *= D;
			}
		}
		
		while(true)
		{
			double additionalCost = C * distanceTravelled;
			vector<pair<double, int> > profits;
			REP(i,N)
			{
				if(mark[i] || i == curr)
				{
					continue;
				}

				double profit = blimp_cost[i] - additionalCost - (1 + C) * Distance(v[curr].first, v[curr].second, v[i].first, v[i].second);
				if(profit > 0.0)
				{
					profits.PB(MP(profit, i));
				}
			}

			if(profits.size() == 0)
			{
				break;
			}

			SORT(profits);

			last = profits.size()-1;
			distanceTravelled += Distance(v[curr].first, v[curr].second, v[profits[last].second].first, v[profits[last].second].second);
			print.PB(profits[last].second);
			curr = profits[last].second;
			mark[curr] = 1;
			++num_visited;
			if(num_visited == N/10)
			{
				num_visited = 0;
				REP(i,N)
				{
					blimp_cost[i] *= D;
				}
			}
		}
		
		double profitTillNow = totalProfit;
		totalProfit += blimp_cost[print[0]] - (1+print.size()) * Distance(0.0, 0.0, v[print[0]].first, v[print[0]].second);
		FOR(i,1,print.size())
		{
			totalProfit += blimp_cost[print[0]] - (1+print.size()-i) * Distance(v[print[i]].first, v[print[i]].second, v[print[i-1]].first, v[print[i-1]].second);
		}
		
		if(profitTillNow > totalProfit)
		{
			break;
		}

		if(flag)
		{
			printf("0 0\n");
		}

		flag = true;

		printf("%d %d %d\n", v[print[0]].first, v[print[0]].second, (int)print.size());
		FOR(i,1,print.size())
		{
			printf("%d %d\n", v[print[i]].first, v[print[i]].second);
		}
	}

	return 0;
}
