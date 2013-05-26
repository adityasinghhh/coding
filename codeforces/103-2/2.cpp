
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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int distance(int x1, int y1, int x2, int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
	int x1 = SI, y1 = SI, x2 = SI, y2 = SI;

	if(x1 > x2) { swap(x1, x2); }
	if(y1 > y2) { swap(y1, y2); }

	char mark[4][2500]; FILL(mark, 0);

	int N = SI;
	REP(i,N)
	{
		int x = SI, y = SI, r = SI;

		FOR(i,x1,x2+1)
		{
			if(distance(i, y1, x, y) <= r*r)
			{
				mark[0][i+1000] = 1;
			}
			
			if(distance(i, y2, x, y) <= r*r)
			{
				mark[1][i+1000] = 1;
			}
		}
		
		FOR(j,y1,y2+1)
		{
			if(distance(x1, j, x, y) <= r*r)
			{
				mark[2][j+1000] = 1;
			}
			
			if(distance(x2, j, x, y) <= r*r)
			{
				mark[3][j+1000] = 1;
			}
		}
	}

	VPI v;

	FOR(i,x1,x2+1)
	{
		if(mark[0][i+1000] == 0) { v.PB(MP(i,y1)); }
		
		if(mark[1][i+1000] == 0) { v.PB(MP(i,y2)); }
	}

	FOR(j,y1,y2+1)
	{
		if(mark[2][j+1000] == 0) { v.PB(MP(x1,j)); }
		
		if(mark[3][j+1000] == 0) { v.PB(MP(x2,j)); }
	}

	if(v.size() == 0) { printf("0\n"); }
	else
	{
		SORT(v);
	
		int cnt = 1, sz = v.size();
		FOR(i,1,sz)
		{
			if(v[i] != v[i-1]) { ++cnt; }
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
