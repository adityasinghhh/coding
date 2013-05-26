
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

int main()
{
	int N = SI;
	VI v;

	REP(i,N)
	{
		v.PB(SI);
	}

	VI factors;
	for(int i = 1; i*i <= N; ++i)
	{
		if(N%i == 0)
		{
			factors.PB(i);
			if(i != N/i)
			{
				factors.PB(N/i);
			}
		}
	}

	SORT(factors);

	int sz = factors.size(), maxii = INT_MIN;
	REP(i,sz)
	{
		FOR(j,i,sz)
		{
			int k = factors[i]-1, s = 0, cnt = 0;
			while(k < N)
			{
				++cnt;
				s += v[k];
				k += (factors[j]-1);
				++k;
			}
			
			if(factors[i]-1 == k % N && cnt > 2)
			{
//				printf("Valid: ");
//				printf("Start at %d and jump %d: %d\n", factors[i]-1, factors[j]-1, s);
				maxii = MAX(maxii, s);
			}
		}
	}

	printf("%d\n", maxii);
/*
	int maxi = INT_MIN;
	sz = v.size();
	REP(i,sz)
	{
		REP(j,sz)
		{
			int k = i, s = 0, cnt = 0;
			while(k < sz)
			{
				++cnt;
				s += v[k];
				k += j;
				++k;
			}

			if(i == k % sz && cnt > 2)
			{
				printf("Valid: ");
				printf("Start at %d and jump %d: %d\n", i, j, s);
				maxi = MAX(maxi, s);
			}
		}
	}

	printf("%d\n", maxi);
*/
	return 0;
}
