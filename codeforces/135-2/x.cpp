
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

class RotatingBot {
	public:
		int minArea(vector <int>);
};

int RotatingBot::minArea(vector <int> v) {
	int mark[200][200] = {0};
	int x = 100, y = 100;
	mark[x][y] = 1;
	int sz = v.size();
	int d = 0;
	int maxx = -1, maxy= -1, minx = INT_MAX, miny = INT_MAX;
	REP(i,sz)
	{
		if(d == 0)
		{
			REP(j,v[i])
			{
				++x;
				if(mark[x][y] == 1)
				{
					return -1;
				}
				maxx = MAX(maxx, x);
				minx = MIN(minx, x);
				mark[x][y] = 1;
			}
			if(i != sz-1 && mark[x+1][y] == 0 && x != maxx)
			{
				return -1;
			}
			d = 1;
		}
		else if(d == 1)
		{
			REP(j,v[i])
			{
				--y;
				if(mark[x][y] == 1)
				{
					return -1;
				}
				maxy = MAX(maxy, y);
				miny = MIN(miny, y);
				mark[x][y] = 1;
			}
			if(i != sz-1 && mark[x][y-1] == 0 && y != miny)
			{
				return -1;
			}
			d = 2;
		}
		else if(d == 2)
		{
			REP(j,v[i])
			{
				--x;
				if(mark[x][y] == 1)
				{
					return -1;
				}
				maxx = MAX(maxx, x);
				minx = MIN(minx, x);
				mark[x][y] = 1;
			}
			if(i != sz-1 && mark[x-1][y] == 0 && x != minx)
			{
				return -1;
			}
			d = 3;
		}
		else
		{
			REP(j,v[i])
			{
				++y;
				if(mark[x][y] == 1)
				{
					return -1;
				}
				maxy = MAX(maxy, y);
				miny = MIN(miny, y);
				mark[x][y] = 1;
			}
			if(i != sz-1 && mark[x][y+1] == 0 && y != maxy)
			{
				return -1;
			}
			d = 0;
		}
	}

	maxx = -1, maxy= -1, minx = INT_MAX, miny = INT_MAX;
	REP(i,200)
	{
		REP(j,200)
		{
			if(mark[i][j])
			{
				maxx = MAX(maxx, i);
				minx = MIN(minx, i);
				maxy = MAX(maxy, j);
				miny = MIN(miny, j);
			}
		}
	}
	
	cout << maxx << " " << minx << " " << maxy << " " << miny << endl;

	cout << d << " " << x << " " << y << endl;

	return (maxx-minx+1)*(maxy-miny+1);
}
