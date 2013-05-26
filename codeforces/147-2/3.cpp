
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

#define RANGE 1000000

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

int mark[1000001] = {0};

void init()
{
	sieve();

	FOR(i,2,1000001)
	{
		if(!isPrime[i])
		{
			mark[i] = mark[i-1]+1;
		}
		else
		{
			mark[i] = mark[i-1];
		}
	}
}

void bf(int a, int b, int k)
{
	FOR(l,1,b-a+2)
	{
		bool flag = true;
		FOR(j,a,b-l+2)
		{
			int cnt = 0;
			REP(kk,l)
			{
				if(!isPrime[j+kk])
				{
					++cnt;
				}
			}

//			printf("(%d,%d) has %d primes\n", j,j+l-1,cnt);

			if(cnt < k)
			{
				flag = false;
				break;
			}
		}

		if(flag)
		{
			printf("%d\n", l);
			return;
		}
	}

	printf("-1\n");
}

int main()
{
	init();

	int a = SI, b = SI, k = SI;

//	bf(a, b, k);

	if(mark[b]-mark[a-1] < k)
	{
		printf("-1\n");
	}
	else if(a == b)
	{
		printf("1\n");
	}
	else
	{
		int l = 1, e = b-a+1, m;
//		printf("L: %d\tE: %d\n", l, e);
		while(l < e)
		{
			m = l + (e-l+1)/2;

			bool flag = true;
			FOR(i,a,b-m+2)
			{
//				printf("For %d-size window, (%d,%d) has %d primes\n", m, a+i+1, a+i+m, mark[a+i+m]-mark[a+i]);
				if(mark[i+m-1]-mark[i-1] < k)
				{
//					printf("%d sized window didn't work for (%d, %d)\n", m, a+i, a+i+m);
					flag = false;
					break;
				}
			}

			if(flag)
			{
//				printf("%d sized window works\n", m);
				e = m-1;
			}
			else
			{
				l = m;
			}

//			cout << l << " " << e << endl;
		}

		printf("%d\n", l+1);
	}

	return 0;
}
