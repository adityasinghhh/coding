
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
	int N = SI, a = SI, b = SI, x = N-(a+b), y = x, s = 0;

	VI v; v.PB(1); ++s;

	int i = 0; ++s; while(i < b) { if(s > 50000) { printf("-1\n"); return 0; } v.PB(s); s = 2*s; ++i; }

	i = 0; s /= 2; ++s;
	while(i < a)   { v.PB(s); ++i; ++s; }

	i = 0; while(i < x-1) { v.PB(1); ++i; }

	s = v[0];
	int maxi = v[0], cnt1 = 0, cnt2 = 0;
	FOR(i,1,N)
	{
		if(v[i] > s) { ++cnt2; }
		else if(v[i] > maxi) { ++cnt1; }

		s += v[i];
		maxi = MAX(maxi, v[i]);
	}

	if(cnt1 == a && cnt2 == b)
	{
		REP(i,N)
		{
			printf("%d ", v[i]);
		}
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}

	return 0;
}
