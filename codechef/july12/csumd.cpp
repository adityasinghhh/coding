
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

LL BASE = 1000000007, p = 31;

/*LL f(int i)
{
	if(i < 0) { return 0; }
	if(i == 0) { return 1; }
	if(i == 1) { return 2; }

	return (2ll*(f(i-1)+f(i-2)))%BASE;
}

void init()
{
	LL a[10001];
	REP(i,1000)
	{
		a[i] = (f(i-1) + f(i-2)) % BASE;
		printf("%lld\n", a[i]);
	}
}*/

map<pair<LL, int>, VVLL> m;

LL hash(VVLL &A)
{
	return ((A[0][0] * 995699404ll) % BASE + (A[0][1] * 599939ll) % BASE + (A[1][0] * 100003ll) % BASE + A[1][1]) % BASE;
}

VVLL mypow(VVLL A, int N)
{
	LL H = hash(A);
	pair<LL, int> P = MP(H, N);
	map<pair<LL, int>, VVLL>::iterator it = m.find(P);
	if(it != m.end())
	{
		return it->second;
	}

	if(N == 0)
	{
		VVLL ret;
		REP(i,2)
		{
			VLL temp;
			REP(j,2)
			{
				temp.PB(i == j ? 1ll : 0ll);
			}
			ret.PB(temp);
		}
//		return ret;
		return m[P] = ret;
	}
	else if(N == 1)
	{
//		return A;
		return m[P] = A;
	}
	else if(N == 2)
	{
		VVLL ret;
		REP(i,2)
		{
			VLL temp;
			REP(j,2)
			{
				LL c = 0ll;
				REP(k,2)
				{
					c += (A[i][k]*A[k][j])%BASE;
					c %= BASE;
				}
				temp.PB(c);
			}
			ret.PB(temp);
		}
//		return ret;
		return m[P] = ret;
	}
	else if(N&1)
	{
		VVLL mult = mypow(A, N-1), ret;
		REP(i,2)
		{
			VLL temp;
			REP(j,2)
			{
				LL c = 0ll;
				REP(k,2)
				{
					c += (mult[i][k]*A[k][j])%BASE;
					c %= BASE;
				}
				temp.PB(c);
			}
			ret.PB(temp);
		}
//		return ret;
		return m[P] = ret;
	}
	else
	{
		VVLL mult = mypow(A, N/2);
//		return mypow(mult, 2);
		return m[P] = mypow(mult, 2);
	}
}

LL f(int N)
{
	VLL x; x.PB(2ll); x.PB(2ll);
	VLL y; y.PB(1ll); y.PB(0ll);
	VVLL A; A.PB(x); A.PB(y);
	VVLL a = mypow(A, N-2);

	return (3ll*a[0][0]+a[0][1])%BASE;
}

int main()
{
	int T = SI;
	while(T--)
	{
		int N = SI;
		if(N == 1)
		{
			printf("1\n");
		}
		else if(N == 2)
		{
			printf("3\n");
		}
		else
		{
			printf("%lld\n", f(N));
		}
	}

	return 0;
}
