
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
	vector<double> blimp_price;
	REP(i,N)
	{
		int x = SI, y = SI;
		v.PB(MP(x, y));
		blimp_price.PB(SLF);
	}

	vector<double> dist[N+1];
	vector<pair<double, int> > V[N+1];
	REP(i,N)
	{
		REP(j,N)
		{
			dist[i].PB(Distance(v[i].first, v[i].second, v[j].first, v[j].second));
			V[i].PB(MP(blimp_price[j] * dist[i][j], j));
		}

		SORT(V[i]);
	}

	bool flag = false;
	int M = MAX(2, N/10), num_visited = 0, tot_num_visited = 0;
	int mark[N+1];
	FILL(mark, 0);

	bool breakFlag = false;
	while(true)
	{
		vector<pair<double, int> > profits;
		REP(i,N)
		{
			if(mark[i])
			{
				continue;
			}

			double profit = M * blimp_price[i] - (2 + C * M) * Distance(0.0, 0.0, v[i].first, v[i].second);
//			printf("%d:%lf ", i, profit);
			if(profit > 0.0)
			{
				profits.PB(MP(profit, i));
			}
		}
//		printf("\n");

		if(profits.size() == 0)
		{
			break;
		}
		
		if(flag)
		{
			printf("0 0\n");
			if(breakFlag)
			{
				break;
			}
		}
			
		flag = true;

		SORT(profits);
		int start = profits[profits.size()-1].second;
		printf("%d %d %d\n", v[start].first, v[start].second, M);
		mark[start] = 1;
		++num_visited;
		++tot_num_visited;
		if(num_visited == N/10)
		{
			num_visited = 0;
			REP(i,N)
			{
				blimp_price[i] *= D;
			}
		}

		int zz = 0, curr = start;
		while(zz < M-1)
		{	
			if(V[curr].size() == 0)
			{
				while(mark[curr] || V[curr].size() == 0)
				{
					curr = rand()%N;
				}
			}
			else
			{
				int prevCurr = curr;
				REPD(i,V[curr].size())
				{
					if(mark[V[curr][i].second] == 0)
					{
						curr = V[curr][i].second;
					}
				}

				if(prevCurr == curr)
				{
					curr = rand()%N;
					while(mark[curr] || V[curr].size() == 0)
					{
						curr = rand()%N;
					}
				}
			}

			printf("%d %d\n", v[curr].first, v[curr].second);
			mark[curr] = 1;
			++num_visited;
			++tot_num_visited;
			if(num_visited == N/10)
			{
				num_visited = 0;
				REP(i,N)
				{
					blimp_price[i] *= D;
				}
			}

			if(tot_num_visited >= 8*N/10)
			{
				breakFlag = true;
			}


			++zz;
		}

/*		REP(i,N)
		{
			cout << blimp_price[i] << " ";
		}
		cout << endl;
*/	}

	return 0;
}
