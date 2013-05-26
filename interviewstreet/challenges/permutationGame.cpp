
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

map<VI, int> m;
map<VI, int>::iterator it;
int N;

int findGrundy(VI &v)
{
	it = m.find(v); if(it != m.end()) { return m[v]; }
	
	int sz = v.size(); 
	set<int> mex;
	set<int>::iterator it;
	REP(i,sz)
	{
		VI temp;
		REP(j,sz) { if(i == j) { continue; } temp.PB(v[j]); }
		mex.insert(findGrundy(temp));
	}

	int i = 0;
	for(it = mex.begin(); it != mex.end(); ++it, ++i)
	{
		if(i != (*it)) { return m[v] = i; }
	}
	return m[v] = i;
}

int main()
{
	VI v1; REP(i,15) { v1.PB(i+1); }
	int K = 1<<15;
	FOR(i,1,K)
	{
		VI temp;
		int x = i, j = 0;
		while(x)
		{
			if(x&1) { temp.PB(v1[j]); }
			x >>= 1;
			++j;
		}
		m[temp] = 0;
	}

	int T = SI;
	while(T--)
	{
		N = SI;
		VI v; REP(i,N) { v.PB(SI); }

		VI v1; FOR(i,1,N+1) { v1.PB(i); }

		printf(findGrundy(v)? "Alice\n" : "Bob\n");
		
		/*for(it = m.begin(); it != m.end(); ++it)
		{
			VI v = (*it).first;
			int sz = v.size();
			printf("%d: ", (*it).second); REP(i,sz) { printf("%d ", v[i]); } printf("\n");
		}*/
	}
	return 0;
}
