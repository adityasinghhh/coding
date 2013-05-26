
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

LL p = 13, base = 1000000009;
char a[10000001];

int main()
{
	sscan(a);

	LL ha = 1, hb = 1, hc, l = strlen(a), k, kk, i, j, ii = -1; 

	for(i=0, j=l-1; i<l-1; ++i, --j)
	{
		ha = (ha*a[i])%base;
		hb = (hb*a[j])%base;

		printf("%lld %lld\n", ha, hb);

		if(ha == hb) { printf("HERE\n"); FOR(k,1,i+1) { hc = 1; REP(kk,l) { hc = (hc*a[kk+k])%base; } if(hc == ha) { ii = i; break; } } }
	}

	if(ii == -1) { printf("Just a legend\n"); return 0; }
	REP(i,ii+1) { printf("%c", a[i]); } printf("\n");

	return 0;
}
