
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
	int N = SI;
	vector<pair<double,double> > v;
	REP(i,N) { pair<double, double> p; p.first = SLF; p.second = SLF; v.PB(p); }

	double mini = (double)LLONG_MAX, minii = (double)LLONG_MAX;

	int i1;
	REP(i,N)
	{
		if(v[i].first < mini)
		{
			mini = v[i].first;
			minii = v[i].second;
			i1 = i;
		}
		else if(v[i].first == mini)
		{
			if(minii < v[i].second)
			{
				minii = v[i].second;
				i1 = i;
			}
		}
	}

	int i2;
	double maxi = (double)LLONG_MIN, maxii = (double)LLONG_MIN;
	REP(i,N)
	{
		if(v[i].first > maxi)
		{
			maxi = v[i].first;
			maxii = v[i].second;
			i2 = i;
		}
		else if(v[i].first == maxi)
		{
			if(maxii > v[i].second)
			{
				maxii = v[i].second;
				i2 = i;
			}
		}
	}

	int i3;
	maxi = (double)LLONG_MIN; minii = (double)LLONG_MAX;
	REP(i,N)
	{
		if(v[i].second > maxi)
		{
			maxi = v[i].second;
			minii = v[i].first;
			i3 = i;
		}
		else if(v[i].second == maxi)
		{
			if(minii < v[i].first)
			{
				minii = v[i].first;
				i3 = i;
			}
		}
	}

	int i4;
	mini = (double)LLONG_MIN; maxii = (double)LLONG_MAX;
	REP(i,N)
	{
		if(v[i].second < mini)
		{
			mini = v[i].first;
			minii = v[i].second;
			i1 = i;
		}
		else if(v[i].first == mini)
		{
			if(minii < v[i].second)
			{
				minii = v[i].second;
				i1 = i;
			}
		}
	}

	return 0;
}
