
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
#define PI(x) printf("%d",&x)
#define PC(x) printf("%c",&x)
#define PLL(x) printf("%lld",&x)
#define PLF(x) printf("%lf",&x)
#define PS(x) printf("%s",&x)
#define PSP() printf(" ")
#define PSN() printf("\n")
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

PI C[256];
void init()
{
	C['a'] = MP(2,1);
	C['b'] = MP(2,2);
	C['c'] = MP(2,3);
	C['d'] = MP(3,1);
	C['e'] = MP(3,2);
	C['f'] = MP(3,3);
	C['g'] = MP(4,1);
	C['h'] = MP(4,2);
	C['i'] = MP(4,3);
	C['j'] = MP(5,1);
	C['k'] = MP(5,2);
	C['l'] = MP(5,3);
	C['m'] = MP(6,1);
	C['n'] = MP(6,2);
	C['o'] = MP(6,3);
	C['p'] = MP(7,1);
	C['q'] = MP(7,2);
	C['r'] = MP(7,3);
	C['s'] = MP(7,4);
	C['t'] = MP(8,1);
	C['u'] = MP(8,2);
	C['v'] = MP(8,3);
	C['w'] = MP(9,1);
	C['x'] = MP(9,2);
	C['y'] = MP(9,3);
	C['z'] = MP(9,4);
}

int sz;
LL BASE = 100000007;
VI V;
LL dp[10000000];

LL f(int i)
{
	LL &m = dp[i]; if(m != -1) { return m; }

	if(i == sz) { return m = 1ll; }

	m = 0;
	int j = i;
	while(j != sz && V[i] == V[j])
	{
		m = (m+f(j+1))%BASE;
		++j;
	}

	return m;
}

int main()
{
	init();
	int T = SI;
	while(T--)
	{
		FILL(dp,-1);
		string s; 
		cin >> s;

		int l = s.length();
		VI v;
		REP(i,l) { REP(j,C[s[i]].second) { v.PB(C[s[i]].first); } }
		V = v;
		sz = v.size();

		printf("%lld\n", f(0));
	}
	return 0;
}
