
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

int a[100010], N;

bool isIncreasing()
{
	int cnt = 0;
	FOR(i,1,N)
	{
		if(a[i-1] <= a[i])
		{
			++cnt;
		}
	}

	return cnt == N-1;
}

bool isDecreasing()
{
	int cnt = 0;
	FOR(i,1,N)
	{
		if(a[i-1] >= a[i])
		{
			++cnt;
		}
	}

	return cnt == N-1;
}

int main()
{
	N = SI;
	REP(i,N)
	{
		a[i] = SI;
	}

	if(N == 1 || N == 2)
	{
		printf("-1\n");
		return 0;
	}
	else if(N == 3)
	{
		if(a[0] != a[1])
		{
			swap(a[0], a[1]);
			if(!isIncreasing() && !isDecreasing())
			{
				printf("1 2\n");
				return 0;
			}
			swap(a[0], a[1]);
		}

		if(a[0] != a[2])
		{
			swap(a[0], a[2]);
			if(!isIncreasing() && !isDecreasing())
			{
				printf("1 3\n");
				return 0;
			}
			swap(a[0], a[2]);
		}

		if(a[1] != a[2])
		{
			swap(a[1], a[2]);
			if(!isIncreasing() && !isDecreasing())
			{
				printf("2 3\n");
				return 0;
			}
		}

		printf("-1\n");
		return 0;
	}

	bool flag1 = isIncreasing();
	bool flag2 = isDecreasing();

	if(flag1 && flag2)
	{
		printf("-1\n");
	}
	else if(flag1 || flag2)
	{
		int j = N-1;
		while(j > 0 && a[j] == a[j-1])
		{
			--j;
		}

		printf("%d %d\n", j, j+1);
	}
	else
	{
		int i = rand()%N, j;
		do
		{
			j = rand()%N;
		}
		while(a[i] == a[j]);

		printf("%d %d\n", i+1, j+1);
	}

	return 0;
}
