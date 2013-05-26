
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

char a[10000000];
int T[10000000];

void solve()
{
	int l = strlen(a), i;
	
	T[0] = -1; T[1] = 0;

	int j = 0; FOR(i,2,l) { if(a[i-1] == a[j]) { ++j; T[i] = j; } else if(j > 0) { j = T[j]; --i; } else { T[i] = 0; } } 

	REP(i,l) { printf("%d ", T[i]); } printf("\n");

	bool flag = false;
	int cnt;
	int len = T[l-1];
	while(true)
	{
		cnt = i = 0; j = 1;
		while(!cnt)
		{
			if(a[j] == 0) { cnt = 2; break; }
			if(a[i] == a[j]) { ++i; ++j; if(i == len) { printf("%d %d %d\n", i, j, l); if(j == l-1) { cnt = 2; } else { cnt = 1; } } }
			else if(i > 0) { i = T[i]; }
			else { ++j; }
		}

		if(cnt == 1) { break; }
		len = T[len];
		if(len == 0) { break; }
	}
	
	if(cnt != 1) { printf("Just a legend\n"); }
	else { REP(i,len+1) { printf("%c", a[i]); } printf("\n"); }
}

int main()
{
	sscan(a);

	solve();

	return 0;
}
