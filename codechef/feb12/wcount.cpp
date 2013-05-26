
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
#define TR(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

LL f[11], BASE = 1000000007;

void init()
{
	f[0] = 1ll;
	FOR(i,1,11)
	{
		f[i] = (f[i-1]*i)%BASE;
	}
}

LL mypow(LL n, int p)
{
	if(p == 0) { return 1ll; }
	else if(p == 1) { return n%BASE; }
	else if(p == 2) { return (n*n) %BASE; }
	return p&1 ? (n * mypow(n, p-1)) % BASE : mypow(mypow(n, p/2), 2);
}

int main()
{
	init();

	int T = SI;
	while(T--)
	{
		string s; cin >> s;
		int l = s.length();
		int p[128] = {0};
		REP(i,l) { ++p[s[i]]; }

		LL ans = 1ll;
		FOR(i,1,l+1) { ans = (ans * i) % BASE; }

		REP(i,128) 
		{
			if(p[i])
			{
				ans = (ans * mypow(f[p[i]], 1000000005)) % BASE; 
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}
