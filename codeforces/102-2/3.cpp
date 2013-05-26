
/* Wrong method: All factor divisions not possible. See 3i.cpp for correct method. */

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

#define RANGE 100000

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

int main()
{
	sieve();

	LL N;
	cin >> N;
	LL M = N;
	int tot = 0;

	VPI factor;
	REP(i,p_cnt)
	{
		if(N%primes[i] == 0)
		{
			int cnt = 0;
			while(N%primes[i] == 0)
			{
				N /= primes[i];
				++cnt;
			}
			factor.PB(MP(primes[i], cnt));
			tot += cnt;
		}
	}

	if(N != 1) { factor.PB(MP(N, 1)); ++tot; }

	N = M;

	int sz = factor.size();
//	REP(i,sz) { printf("%d: %d\n", factor[i].first, factor[i].second); }

	LL maxi = LLONG_MIN, mini = LLONG_MAX;
	REP(i,tot+1)
	{
		LL a = 1ll;
		int j = 0, x = i, left = 0;
		bool flag = false;
		while(x)
		{
			if(x >= factor[j].second) { REP(r,factor[j].second) { a *= factor[j].first; } x -= factor[j].second; ++j; }
			else { REP(r,x) { a *= factor[j].first; } flag = true; left = factor[j].second-x; x = 0; }
		}

		FOR(ii,i,tot+1)
		{
			LL b = 1ll;
			x = ii-i;
			int jj = j;
			if(flag) 
			{
				if(x >= left) { REP(r,left) { b *= factor[jj].first; } x -= left; ++jj; }
				else { REP(r,x) { b *= factor[jj].first; } x = 0; }
			}

			while(x)
			{
//				printf("FACTOR[jj].second:%d\n", factor[jj].second);
				if(x >= factor[jj].second) { REP(r,factor[jj].second) { b *= factor[jj].first; } x -= factor[jj].second; ++jj; }
				else { REP(r,x) { b *= factor[jj].first; } x = 0; }
			}

			LL c = (N/a)/b;

			LL val1 = (a+1)*(b+2)*(c+2); 
			LL val2 = (a+2)*(b+1)*(c+2); 
			LL val3 = (a+2)*(b+2)*(c+1); 

			printf("%lld %lld %lld\n", a, b, c);

			printf("%lld\t%lld\t%lld\n", val1-N, val2-N, val3-N);

			//printf("VALUE: %lld\n", val);

			maxi = MAX(maxi, MAX(val1, MAX(val2, val3)));
			mini = MIN(mini, MIN(val1, MIN(val2, val3)));
		}
	}

	cout << mini-N << " " << maxi-N << endl;

	return 0;
}
