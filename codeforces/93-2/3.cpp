
#include<algorithm>
#include<assert.h>
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

#define LL long long int
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=b-1;i>=a;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define ABS(a) a<0?-a:a
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
double t1, t2, t0;
int x1, x2;

int main()
{
	t1 = SLF; t2 = SLF; x1 = SI; x2 = SI; t0 = SLF;

	if (t0 == t2)
	{
		printf("%d %d", t0 == t1 ? x1 : 0, x2);
		return 0;
	}

	int y1, y2, yy1, yy2, l, e, m;
	double mini = INT_MAX, val, maxi = INT_MIN;
	REP(y1,x1+1)
	{
		l = -1; e = x2-1; 

		while(l<e) { m = l + (e-l+1)/2; if((t1*y1+t2*m)/(y1+m) < t0) { l = m; } else { e = m-1; } }

		y2 = l+1;

		val = (t1*y1+t2*y2)/(y1+y2) - t0;

		if(val < mini) { mini = val; yy1 = y1; yy2 = y2; } else if(fabs(val-mini) < 0.0000001) { if(y1+y2 > yy1+yy2) { yy1 = y1; yy2 = y2; } }
	}

	printf("%d %d\n", yy1, yy2);

	return 0;
}
