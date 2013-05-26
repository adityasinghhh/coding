
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

LL a[7] = {0,1,2,5,6,8,9};
vector<LL> v;
queue<LL> q;

void init()
{
	int i;

	q.push(0);

	while(!q.empty())
	{
		LL x = q.front(); q.pop(); 

		printf("%lld\n", x);

		REP(i,7) { if(x*10+a[i] < 1000000000) { q.push(x*10+a[i]); if(!(x*10+a[i])) { v.PB(x*10+a[i]); } } else { break; } }
	}
}

bool binary_search(LL ind, LL x)
{
	return v[ind] <= x;
}

void solve(LL x)
{
	LL l = 0, e = v.size()-1, m;
	while(l<e) { m = l + (e-l+1)/2; if(binary_search(m,x)) { l = m; } else { e = m-1; } }
	printf("%lld\n", v[l]);
}

int main()
{
	init();

	int i; REP(i,100) { printf("%lld\n", v[i]); } printf("\n");

	LL T = SI; while(T--) { LL x = SLL; solve(x); }

	return 0;
}
