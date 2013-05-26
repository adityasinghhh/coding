
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

int mark[11234], lowlink[11234], N, ind, cyc[11234], cz = 1;
VI v[11234], reverseV[11234];
stack<int> s;
int marks[11234];
bool MARK[10001][10001];

void strongConnect(int n)
{
	mark[n] = ind;
	lowlink[n] = ind;
	++ind;
	s.push(n);
	marks[n] = 1;

	REP(i,v[n].size())
	{
		if(!mark[v[n][i]])
		{
			strongConnect(v[n][i]);
			lowlink[n] = MIN(lowlink[n], lowlink[v[n][i]]);
		}
		else if(marks[v[n][i]])
		{
			lowlink[n] = MIN(lowlink[n], mark[v[n][i]]);
		}
	}

	if(mark[n] == lowlink[n])
	{
		int x = s.top();
		s.pop();
		marks[x] = 0;
		if(x != n)
		{
			++cz;
			cyc[x] = cz;
		}
		
		while(x != n)
		{
			x = s.top();
			s.pop();
			marks[x] = 0;
			cyc[x] = cz;
		}
	}
}

VI v1, vN;
void dfs(int n)
{
	REP(i,v[n].size())
	{
		if(!mark[v[n][i]])
		{
			if(cyc[v[n][i]])
			{
				v1.PB(v[n][i]);
			}

			mark[v[n][i]] = 1;
			dfs(v[n][i]);
			mark[v[n][i]] = 0;
		}
	}
}

void reverseDfs(int n)
{
	REP(i,reverseV[n].size())
	{
		if(!mark[reverseV[n][i]])
		{
			if(cyc[reverseV[n][i]])
			{
				vN.PB(reverseV[n][i]);
			}

			mark[reverseV[n][i]] = 1;
			reverseDfs(reverseV[n][i]);
			mark[reverseV[n][i]] = 0;
		}
	}
}

bool cycle()
{
	ind = 1;
	FILL(mark,0);
	FILL(marks,0);
	FILL(lowlink,0);

	FOR(i,1,N+1)
	{
		if(!mark[i])
		{
			strongConnect(i);
		}
	}

	FILL(mark,0);
	mark[1] = 1;
	dfs(1);
	mark[1] = 0;
	mark[N] = 1;
	reverseDfs(N);

	SORT(v1);
	SORT(vN);

	int i = 0, j = 0;
	while(i < v1.size() && j < vN.size())
	{
		if(v1[i] == vN[j])
		{
			return true;
		}
		else if(v1[i] < vN[j])
		{
			++i;
		}
		else
		{
			++j;
		}
	}
	return false;
}

LL dp[11234], BASE = 1000000000;
LL f(int n)
{
	if(dp[n] != -1) { return dp[n]; }

	if(n == N)
	{
		return dp[n] = 1ll;
	}

	LL ret = 0ll;
	REP(i, v[n].size())
	{
		ret += f(v[n][i]);
		if(ret >= BASE) { ret %= BASE; }
	}
	return dp[n] = ret;
}

bool flag = false;
void DFS(int n)
{
	if(n == N) { flag = true; return;}

	REP(i,v[n].size())
	{
		if(!mark[v[n][i]])
		{
			mark[v[n][i]] = 1;
			DFS(v[n][i]);
			mark[v[n][i]] = 0;
			if(flag) { return; }
		}
	}
}

bool path()
{
	FILL(mark,0);
	mark[1] = 1;
	DFS(1);

	return flag;
}

int main()
{
	FILL(cyc,0);
	N = SI;
	int M = SI;
	REP(i,M)
	{
		int x = SI, y = SI;
		v[x].PB(y);
		reverseV[y].PB(x);
		MARK[x][y] = 1;
		if(MARK[y][x])
		{
			cyc[x] = cz;
			cyc[y] = cz;
			++cz;
		}
	}

	if(cycle())
	{
		printf("INFINITE PATHS\n");
	}
	else if(path())
	{
		FILL(dp,-1);
		printf("%lld\n", f(1));
	}
	else
	{
		printf("0\n");
	}

	return 0;
}
