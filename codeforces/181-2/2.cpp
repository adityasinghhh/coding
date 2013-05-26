
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
	int N = SI, M = SI;
	set<int> S[N+1];
	REP(i,M)
	{
		int x = SI, y = SI;
		S[x].insert(y);
		S[y].insert(x);
	}

	FOR(i,1,N+1)
	{
		if(S[i].size() > 2)
		{
			printf("-1\n");
			return 0;
		}
	}

	VI T[N/3];
	int z=0;
	queue<int> lone;
	FOR(i,1,N+1)
	{
		if(S[i].size() == 0)
		{
			lone.push(i);
		}
	}

	int mark[N+1];
	FILL(mark,0);
	FOR(i,1,N+1)
	{
		if(mark[i])
		{
			continue;
		}

		if(S[i].size() == 1)
		{
			if(lone.empty())
			{
				printf("-1\n");
				return 0;
			}
			
			T[z].PB(i);
			mark[i] = 1;
			TR(it,S[i])
			{
				mark[*it] = 1;
				T[z].PB(*it);
			}
			T[z].PB(lone.front());
			mark[lone.front()] = 1;
			lone.pop();
			++z;
		}
		else if(S[i].size() == 2)
		{
			T[z].PB(i);
			mark[i] = 1;
			TR(it,S[i])
			{
				mark[*it] = 1;
				T[z].PB(*it);
			}
			++z;
		}
	}

	while(!lone.empty())
	{
		REP(i,3)
		{
			if(lone.empty())
			{
				printf("-1\n");
				return 0;
			}

			T[z].PB(lone.front());
			lone.pop();
		}
		++z;
	}

	REP(i,N/3)
	{
		REP(j,3)
		{
			printf("%d ", T[i][j]);
		}
		printf("\n");
	}

	return 0;
}
