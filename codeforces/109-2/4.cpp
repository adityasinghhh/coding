
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

#define RANGE 100010

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

	int H[100010] = {0};
	
	int N = SI, M = SI;
	int mark[N+1]; FILL(mark, 0);
	while(M--)
	{
		string s; cin >> s;

		if(s == "+")
		{
			int x = SI;

			if(mark[x])
			{
				printf("Already on\n");
			}
			else
			{
				bool flag = false;
				int y = x, j = 0, conf = -1;
				while(j < p_cnt && y > 1)
				{
					if(y % primes[j] == 0)
					{
						if(H[primes[j]])
						{
							flag = true;
							conf = H[primes[j]];
							break;
						}
						
						while(y % primes[j] == 0)
						{
							y /= primes[j];
						}
					}
					++j;
				}

				if(flag)
				{
					printf("Conflict with %d\n", conf);
				}
				else
				{
					y = x, j = 0;
					while(j < p_cnt && y > 1)
					{
						if(y % primes[j] == 0)
						{
							H[primes[j]] = x;

							while(y % primes[j] == 0)
							{
								y /= primes[j];
							}
						}
						++j;
					}
					mark[x] = 1;
					printf("Success\n");
				}
			}
		}
		else
		{
			int x = SI;
			if(mark[x])
			{
				int y = x, j = 0;
				while(j < p_cnt && y > 1)
				{
					if(y % primes[j] == 0)
					{
						H[primes[j]] = 0;

						while(y % primes[j] == 0)
						{
							y /= primes[j];
						}
					}
					++j;
				}
				mark[x] = 0;
				printf("Success\n");
			}
			else
			{
				printf("Already off\n");
			}
		}
	}

	return 0;
}
