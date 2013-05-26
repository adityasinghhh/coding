
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

int W, H, **a, **mark, ***dp, zeroes = 0, sx, sy, ex, ey, X[4] = {-1,1,0,0}, Y[4] = {0,0,-1,1};
bool valid(int x, int y)
{
	if(x < 0 || y < 0 || x >= W || y >= H)
	{
		return false;
	}

	return true;
}

int f(int x, int y, int zeroesLeft)
{
	int &m = dp[x][y][zeroesLeft];
	//printf("%d %d %d: %d\n", x, y, zeroesLeft, m);
	if(m != -1)
	{
		return m;
	}

	if(x == sx && y == sy)
	{
	        printf("At start: %d %d %d\n", x, y, zeroesLeft);

		if(zeroesLeft == 0)
		{
			return m = 1;
		}
			
		return m = 0;
	}

	m = 0;
	REP(i,4)
	{
		//printf("Checking: (%d,%d)\n", x+X[i], y+Y[i]);
		if(valid(x+X[i], y+Y[i]) && (a[x+X[i]][y+Y[i]] == 0 || a[x+X[i]][y+Y[i]] == 2) && !mark[x+X[i]][y+Y[i]])
		{
			printf("From (%d,%d), to (%d,%d) with %d zeroes left.\n", x, y, x+X[i], y+Y[i], zeroesLeft -(a[x+X[i]][y+Y[i]] == 2 ? 0 : 1));
			mark[x+X[i]][y+Y[i]] = 1;
			m += f(x+X[i], y+Y[i], zeroesLeft-(a[x+X[i]][y+Y[i]] == 2 ? 0 : 1));
			mark[x+X[i]][y+Y[i]] = 0;
		}
	}

	return m;
}

int main()
{
	W = SI, H = SI;
	a = new int*[W+1];
	mark = new int*[W+1];
	REP(i,W)
	{
		a[i] = new int[H+1];
		mark[i] = new int[H+1];
		REP(j,H)
		{
			a[i][j] = SI;
			if(a[i][j] == 0)
			{
				++zeroes;
			}
			else if(a[i][j] == 2)
			{
				sx = i;
				sy = j;
			}
			else if(a[i][j] == 3)
			{
				ex = i;
				ey = j;
			}
		}
	}

	printf("Start point: (%d,%d)\n", sx, sy);
	printf("End point: (%d,%d)\n", ex, ey);
	printf("Number of Data Centers: %d\n", zeroes);

	dp = new int**[W+1];
	REP(i,W+1)
	{
		dp[i] = new int*[H+1];
		REP(j,H+1)
		{
			dp[i][j] = new int[zeroes];
			REP(k,zeroes+1)
			{
				dp[i][j][k] = -1;
			}
		}
	}

	mark[ex][ey] = 1;
	printf("%d\n", f(ex, ey, zeroes));
	mark[ex][ey] = 0;

	return 0;
}
