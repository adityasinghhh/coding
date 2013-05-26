
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
	
char a[1000];

int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int month()
{
	if(a[3] == 'J' && a[4] == 'A' && a[5] == 'N') { return 1; }
	if(a[3] == 'F' && a[4] == 'E' && a[5] == 'B') { return 2; }
	if(a[3] == 'M' && a[4] == 'A' && a[5] == 'R') { return 3; }
	if(a[3] == 'A' && a[4] == 'P' && a[5] == 'R') { return 4; }
	if(a[3] == 'M' && a[4] == 'A' && a[5] == 'Y') { return 5; }
	if(a[3] == 'J' && a[4] == 'U' && a[5] == 'N') { return 6; }
	if(a[3] == 'J' && a[4] == 'U' && a[5] == 'L') { return 7; }
	if(a[3] == 'A' && a[4] == 'U' && a[5] == 'G') { return 8; }
	if(a[3] == 'S' && a[4] == 'E' && a[5] == 'P') { return 9; }
	if(a[3] == 'O' && a[4] == 'C' && a[5] == 'T') { return 10; }
	if(a[3] == 'N' && a[4] == 'O' && a[5] == 'V') { return 11; }
	return 12;
}

int main()
{
	int T = SI, zz, cnt, d, m, y, i;

	FOR(zz,1,T+1)
	{
		sscan(a);

		d = 0; REP(i,2) { d = d*10+a[i]-'0'; } //printf("%d\n", d); }
		y = 0; FOR(i,7,11) { y = y*10+a[i]-'0'; }

//		printf("Day: %d\n", d);
		m = month();
//		printf("Month: %d\n", m);

		cnt = d;
		REP(i,m) { cnt += day[i]; }

		if(y%400 == 0 || (y%4 == 0 && y%100 != 0)) { if(m > 2) { ++cnt; } }

//		printf("Count: %d\n", cnt);

		if(cnt <= 300) { printf("Case %d: %d Hundreds\n", zz, cnt); } else
		if(cnt <= 360) { printf("Case %d: %d Tens\n", zz, cnt-300); } else
		printf("Case %d: %d Ones\n", zz, cnt-360);
	}

	return 0;
}
