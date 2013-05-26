
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

LL BASE = 1000000007ll;

LL mypow(LL n, int p)
{
	if(p == 0)
	{
		return 1ll;
	}
	else if(p == 1)
	{
		return n;
	}
	else if(p == 2)
	{
		return (n*n) % BASE;
	}

	return p&1 ? (n * mypow(n, p-1))%BASE : mypow(mypow(n, p/2), 2);
}

LL f(int n, int k)
{
	k = MIN(k, n-k);

	LL ret = 1ll;
	while(k > 0)
	{
		ret *= n;
		ret %= BASE;
		ret *= mypow(k, BASE-2);
		ret %= BASE;

		--n;
		--k;
	}

	return ret;
}

int main()
{
	int T = SI;
	REP(zz, T)
	{
		int N = SI, K = SI, a[N+1];
		REP(i,N)
		{
			a[i] = SI;
		}

		sort(a, a+N);

		LL ans = 0ll, prod = 1ll;
		--K;
		int M = K, L = 0;
		while(M < N)
		{
			ans += 1ll * prod * a[M];
			if(ans >= BASE)
			{
				ans %= BASE;
			}

			++M;
			++L;

			prod *= M;
			if(prod >= BASE)
			{
				prod %= BASE;
			}
			prod *= mypow(L, BASE-2);
			if(prod >= BASE)
			{
				prod %= BASE;
			}
		}

		printf("Case #%d: %lld\n", zz+1, ans);
	}

	return 0;
}
