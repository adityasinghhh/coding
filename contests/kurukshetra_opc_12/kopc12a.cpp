
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

void bf(vector<pair<LL, LL> > &v)
{
	int N = v.size(), maxi = -1;
	REP(i,N)
	{
		maxi = MAX(maxi, v[i].first);
	}

	LL mincost = LLONG_MAX;
	REP(i,maxi+1)
	{
		LL cost = 0ll;
		REP(j,N)
		{
			cost += v[j].second*ABS(v[j].first-i);
		}
		mincost = MIN(mincost, cost);
	}
	printf("Brute force: %lld\n", mincost);

}

int main()
{
	int T = SI;
	while(T--)
	{
		vector<pair<LL, LL> > v;
		int N = SI;
		LL a[N+1];
		REP(i,N) { a[i] = SLL; }
		REP(i,N) { LL x = SLL; v.PB(MP(a[i], x)); }

		SORT(v);

//		REP(i,N) { printf("%lld:%lld ", v[i].first, v[i].second); } printf("\n");

//		bf(v);

		LL s1[N+1], s2[N+1];
		s1[0] = v[0].second; 	FOR(i,1,N)    { s1[i] = s1[i-1] + v[i].second; }
		s2[N-1] = v[N-1].second; FORD(i,0,N-1) { s2[i] = s2[i+1] + v[i].second; }

//		REP(i,N) { printf("%lld ", s1[i]); } printf("\n");
//		REP(i,N) { printf("%lld ", s2[i]); } printf("\n");

		LL s3[N+1], s4[N+1];
		s3[0] = 0ll;   FOR(i,1,N)    { s3[i] = s3[i-1] + ABS(v[i-1].first-v[i].first)*s1[i-1]; }
		s4[N-1] = 0ll; FORD(i,0,N-1) { s4[i] = s4[i+1] + ABS(v[i+1].first-v[i].first)*s2[i+1]; }
		
//		REP(i,N) { printf("%lld ", s3[i]); } printf("\n");
//		REP(i,N) { printf("%lld ", s4[i]); } printf("\n");

		LL mini = 0;
		REP(i,N)
		{
			if(s3[i] + s4[i] < s3[mini] + s4[mini])
			{
				mini = i;
			}
		}

		printf("%lld\n", s3[mini] + s4[mini]);
	}

	return 0;
}
