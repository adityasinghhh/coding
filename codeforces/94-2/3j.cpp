
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
#define lfscan(n) scanf("%lf",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=b-1;i>=a;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define ABS(a) (a)<0?-(a):(a)
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

char a[10][10], b[10][10];
int dp[2][10][10], mark[10][10];

void print() { int i; REP(i,8) { printf("%s\n", a[i]); } printf("\n"); }

int cnt;

void restore() { int i, j; REP(i,8) { REP(j,8) { a[i][j] = b[i][j]; } } }

bool find() { int i, j; REP(i,8) { REP(j,8) { if(a[i][j] == 'S') { return false; } else if(a[i][j] == 'M') { return true; } } } return false; }

int f(int turn, int i, int j)
{
	int &m = dp[turn][i][j]; if(m != -1) { return m; }

	if(cnt == 0) { return m = 1; }

	if(find()) { return m = 1; }

	if(turn&1)
	{
		int ii, jj, prevcnt = cnt;
		
		REP(ii,8) { REP(jj,8) { b[ii][jj] = a[ii][jj]; } }

		REP(jj,8) { if(a[7][jj] == 'S') { a[7][jj] = '.'; --cnt; } }
		REPD(ii,7) { REP(jj,8) { if(a[ii][jj] == 'S') { if(a[ii+1][jj] == 'M') { restore(); cnt = prevcnt; return m = 0; } a[ii][jj] = '.'; a[ii+1][j] = 'S'; } } }

		int m = f(0, i, j);
		cnt = prevcnt; restore();
		return m;
	}
	else
	{
		if(i == 0 && j == 7) { return m = 1; }
	
		if(i != 0 && a[i-1][j] != 'S') { swap(a[i][j], a[i-1][j]); if(f(1, i-1, j)) { return m = 1; } swap(a[i][j], a[i-1][j]); }
		if(j != 0 && a[i][j-1] != 'S') { swap(a[i][j], a[i][j-1]); if(f(1, i, j-1)) { return m = 1; } swap(a[i][j], a[i][j-1]); }
		if(i != 7 && a[i+1][j] != 'S') { swap(a[i][j], a[i+1][j]); if(f(1, i+1, j)) { return m = 1; } swap(a[i][j], a[i+1][j]); }
		if(j != 7 && a[i][j+1] != 'S') { swap(a[i][j], a[i][j+1]); if(f(1, i, j+1)) { return m = 1; } swap(a[i][j], a[i][j+1]); } 
		if(i != 0 && j != 0 && a[i-1][j-1] != 'S') { swap(a[i][j], a[i-1][j-1]); if(f(1, i-1, j-1)) { return m = 1; } swap(a[i][j], a[i-1][j-1]); }
		if(i != 0 && j != 7 && a[i-1][j+1] != 'S') { swap(a[i][j], a[i-1][j+1]); if(f(1, i-1, j+1)) { return m = 1; } swap(a[i][j], a[i-1][j+1]); }
		if(i != 7 && j != 0 && a[i+1][j-1] != 'S') { swap(a[i][j], a[i+1][j-1]); if(f(1, i+1, j-1)) { return m = 1; } swap(a[i][j], a[i+1][j-1]); }
		if(i != 7 && j != 7 && a[i+1][j+1] != 'S') { swap(a[i][j], a[i+1][j+1]); if(f(1, i+1, j+1)) { return m = 1; } swap(a[i][j], a[i+1][j+1]); }

		if(f(1, i, j)) { return m = 1; }

		return m = 0;
	}
}

int main()
{
	FILL(dp,-1); FILL(mark,0);

	cnt = 0; int i, j; REP(i,8) { sscan(a[i]); REP(j,8) { if(a[i][j] == 'S') { ++cnt; } } }

	printf(f(0, 7, 0) ? "WIN\n" : "LOSE\n");

	return 0;
}
