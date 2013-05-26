
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
	int a1 = SI, a2 = SI, a3 = SI, a4 = SI;

	if(ABS(a3-a4) > 1) { printf("-1\n"); return 0; }

	string s = "";
	
	if(a3 == a4-1)
	{
		if(a1 < a3 || a2 < a3) { printf("-1\n"); return 0; }

		printf("7"); --a2;
		
		while(a1-a3 > 1) { printf("4"); --a1; }

		while(a3)
		{
			if(a1 == 0 || a2 == 0) { printf("-1\n"); return 0; }

			printf("47");
			--a3;
			--a1;
			--a2;
		}

		while(a2) { printf("7"); --a2; }

		printf("4\n"); --a1;
	}
	else if(a3 == a4)
	{
		if(a1 < a3+1 || a2 < a3) { printf("-1\n"); return 0; }

		while(a1-a3 > 1) { printf("4"); --a1; }
		
		while(a3)
		{
			if(a1 == 0 || a2 == 0) { printf("-1\n"); return 0; }

			printf("47");
			--a3;
			--a1;
			--a2;
		}
		
		while(a2) { printf("7"); --a2; }

		printf("4\n");
	}
	else 
	{
		if(a1 < a4 || a2 < a4) { printf("-1\n"); return 0; }

		while(a1-a4) { printf("4"); --a1; }
		
		while(a4)
		{
			if(a1 == 0 || a2 == 0) { printf("-1\n"); return 0; }

			printf("74");
			--a4;
			--a1;
			--a2;
		}

		while(a2) { printf("7"); --a2; }
		printf("\n");
	}

	return 0;
}
