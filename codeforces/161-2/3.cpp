
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

int N;
VI v[100010];
int mark[100010] = {0};
bool flag = false;

bool exists(int i, int j)
{
	REP(k,v[i].size())
	{
		if(v[i][k] == j)
		{
			return true;
		}
	}
	return false;
}

void f(int start, int prev, int curr, int k)
{
	REP(j,v[curr].size())
	{
		if(!mark[v[curr][j]] && exists(prev, v[curr][j]))
		{
			mark[v[curr][j]] = 1;
			f(start, curr, v[curr][j], k+1);
			if(flag)
			{
				printf("%d ", v[curr][j]);
				return;
			}
			mark[v[curr][j]] = 0;
		}
		else if(k == N)
		{
			if(start == v[curr][j])
			{
				flag = true;
				return;
			}
		}
	}
}

int main()
{
	N = SI;
	REP(i,2*N)
	{
		int x = SI, y = SI;
		v[x].PB(y);
		v[y].PB(x);
	}

	FOR(i,1,N+1)
	{
		if(v[i].size() != 4)
		{
			printf("-1\n");
			return 0;
		}
	}

	flag = false;

	REP(i,v[1].size())
	{
		mark[1] = 1;
		f(1, v[1][i], 1, 1);
		if(flag)
		{
			printf("1\n");
			return 0;
		}
		mark[1] = 0;
	}

	printf("-1\n");
	
	return 0;
}
