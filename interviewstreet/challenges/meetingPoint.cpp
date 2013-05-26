
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

bool compare(PI p1, PI p2)
{
	return p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first);
}

map<PI, int> m;
int main()
{
	int N = SI;
	VPI vx, vy;
	REP(i,N)
	{
		int x = SI, y = SI;
		vx.PB(MP(x, y));
		vy.PB(vx[i]);

		++m[vx[i]];
	}

	int limit = 100;

	if(N < limit)
	{
		LL mini = LLONG_MAX;
		REP(i,N)
		{
			LL ans = 0ll;
			REP(j,N)
			{
				ans += MAX(ABS(vx[i].first-vx[j].first), ABS(vx[i].second-vx[j].second));
			}
			mini = MIN(ans, mini);
		}
		printf("%lld\n", mini);
		return 0;
	}
	
	SORT(vx);
	sort(vy.begin(), vy.end(), compare);

//	REP(i,N) { printf("(%d,%d) ", vx[i].first, vx[i].second); } printf("\n");
//	REP(i,N) { printf("(%d,%d) ", vy[i].first, vy[i].second); } printf("\n");

	int cnt = N, xi = 0, xj = N-1, yi = 0, yj = N-1;
	while(cnt > limit)
	{
		while(xi < xj && !m[vx[xi]]) { ++xi; }

		if(xi < xj)
		{
//			printf("Removing (%d,%d)\n", vx[xi].first, vx[xi].second);
			--m[vx[xi]];
			++xi;
			--cnt;
		}

		if(cnt == limit) { break; }

		while(yi < yj && !m[vy[yi]]) { ++yi; }

		if(yi < yj)
		{
//			printf("Removing (%d,%d)\n", vy[yi].first, vy[yi].second);
			--m[vy[yi]];
			++yi;
			--cnt;
		}

		if(cnt == limit) { break; }

		while(xi < xj && !m[vx[xj]]) { --xj; }

		if(xi < xj)
		{
//			printf("Removing (%d,%d)\n", vx[xj].first, vx[xj].second);
			--m[vx[xj]];
			--xj;
			--cnt;
		}

		if(cnt == limit) { break; }

		while(yi < yj && !m[vy[yj]]) { --yj; }

		if(yi < yj)
		{
//			printf("Removing (%d,%d)\n", vy[yj].first, vy[yj].second);
			--m[vy[yj]];
			--yj;
			--cnt;
		}
	}

	PI p[limit];
	int j = 0;
	REP(i,N) { if(m[vx[i]]) { p[j] = vx[i]; ++j; } }

	LL ans[limit]; FILL(ans, 0);
	REP(i,N)
	{
		REP(j,limit)
		{
			ans[j] += MAX(ABS(vx[i].first-p[j].first), ABS(vx[i].second-p[j].second));
		}
	}

	LL mini = LLONG_MAX;
	REP(i,limit) { mini = MIN(mini, ans[i]); }

	printf("%lld\n", mini);

	return 0;
}
