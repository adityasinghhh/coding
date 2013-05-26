
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

int x, y, maxi, R, C;
bool flag;
void f1(int i, int j, int d)
{
	if(i == x && j == y) { if(d < maxi) { maxi = d; } flag = true; return; }

	if(i != R-1 && a[i+1][j] != '#') { f(i+1, j, d+1); if(flag) { return; } }
	if(j != C-1 && a[i][j+1] != '#') { f(i, j+1, d+1); if(flag) { return; } }
	if(i != 0 && a[i-1][j] != '#') { f(i-1, j, d+1); if(flag) { return; } }
	if(j != 0 && a[i][j-1] != '#') { f(i, j-1, d+1); if(flag) { return; } }
}

int f(int si, int sj, int di, int dj)
{
	x = di; y = dj; maxi = -1; flag = false; 
	f1(si, sj, 0);
	return maxi;
}

int main()
{
	int T = SI, zz;

	FOR(zz,1,T+1)
	{
		R = SI; C = SI;

		REP(i,R) { sscan(a[i]); }

		vector<PI> food;

		REP(i,R) { REP(i,C) { if(a[i][j] == 'F') { food.PB(MP(i,j)); } else if(a[i][j] == 'H') { hr = i; hc = j; } } }

		VI dist; REP(i,food.size()) { dist.PB(hr, hc, food[i].first, food[i].second); }
	}

	return 0;
}
