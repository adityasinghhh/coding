
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

#define RANGE 1001

char isPrime[RANGE+10];
int primes[RANGE/10 + 10], p_cnt;

void sieve()
{
	isPrime[0] = isPrime[1] = 1;
	p_cnt = 0;

	REP(i,RANGE+10)
	{
		if(isPrime[i]) { continue; }

		primes[p_cnt++] = i;

		for(int j=2; j<RANGE/i; ++j)
		{
			isPrime[j*i] = 1;
		}
	}
}

PI p[1000001];
VI Klucky;

void init()
{
	REP(i,1000001) { p[i] = MP(-1,-1); }

	REP(i,p_cnt)
	{
		if(primes[i] == 1) { continue; }

		int j = primes[i], cnt = 1;
		while(j < 1000001/primes[i])
		{
		//	printf("%d = %d**%d\n", j, primes[i], cnt);
			p[j] = MP(primes[i], cnt);
			++cnt;
			j *= primes[i];
		}
	}


	REP(i,1000001)
	{
		if(p[i].first != -1)
		{
			if(!isPrime[(i-1)/(p[i].first-1)])
			{
				Klucky.PB(i/p[i].first);
			}
//			printf("%d = %d**%d\n", i, p[i].first, p[i].second);
		}
	}

	SORT(Klucky);

	int sz = Klucky.size();
	REP(i,sz)
	{
		printf("%d\n", Klucky[i]);
	}
}

int main()
{
	sieve();

	init();

	int sz = Klucky.size();

	int T = SI;
	while(T--)
	{
		int A = SI, B = SI, cnt = 0;
		REP(i,sz)
		{
			if(A <= Klucky[i] && Klucky[i] <= B)
			{
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}
