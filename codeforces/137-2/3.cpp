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

#define RANGE 3500

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

	int N = SI, M = SI;
	int a[N+1], b[M+1];

	map<int, int> A, B;
	REP(i,N)
	{
		a[i] = SI;
		int x = a[i], j = 0;
		while(j < p_cnt && x != 1)
		{
			if(x%primes[j] == 0)
			{
				int cnt = 0;
				while(x%primes[j] == 0)
				{
					++cnt;
					x /= primes[j];
				}
				A[primes[j]] += cnt;
			}

			++j;
		}
		if(x != 1)
		{
			A[x] = 1;
		}
	}

	REP(i,M)
	{
		b[i] = SI;
		int x = b[i], j = 0;
		while(j < p_cnt && x != 1)
		{
			if(x%primes[j] == 0)
			{
				int cnt = 0;
				while(x%primes[j] == 0)
				{
					++cnt;
					x /= primes[j];
				}
				B[primes[j]] += cnt;
			}

			++j;
		}
		if(x != 1)
		{
			B[x] = 1;
		}
	}

	TR(it,A)
	{
		map<int, int>::iterator it1 = B.find(it->first);
		if(it1 != B.end())
		{
			if(it->second == it1->second)
			{
				A[it->first] = 0;
				B[it1->first] = 0;
			}
			else if(it->second > it1->second)
			{
				A[it->first] -= B[it1->first];
				B[it1->first] = 0;
			}
			else
			{
				B[it1->first] -= A[it->first];
				A[it->first] = 0;
			}
		}
	}

	VI va, vb;
	int x = 1, limit = 10000000;
	TR(it,A)
	{
		REP(i,it->second)
		{
			if(x > limit/it->first)
			{
				va.PB(x);
				x = 1;
			}

			x *= it->first;
		}
	}
	if(x > 1)
	{
		va.PB(x);
	}


	x = 1;
	TR(it,B)
	{
		REP(i,it->second)
		{
			if(x > limit/it->first)
			{
				vb.PB(x);
				x = 1;
			}

			x *= it->first;
		}
	}

	if(x > 1)
	{
		vb.PB(x);
	}

	if(va.size() == 0)
	{
		va.PB(1);
	}
	if(vb.size() == 0)
	{
		vb.PB(1);
	}

	printf("%d %d\n", va.size(), vb.size());

	REP(i,va.size())
	{
		printf("%d ", va[i]);
	}
	printf("\n");

	REP(i,vb.size())
	{
		printf("%d ", vb[i]);
	}
	printf("\n");

	return 0;
}
