
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

vector<int> tree[100010];

int read(int n, int idx) { int sum = 0; while(idx > 0) { sum += tree[n][idx]; idx -= (idx&-idx); } return sum; }

void update(int n, int idx, int val) { while(idx <= tree[n].size()) { tree[n][idx] += val; idx += (idx&-idx); } } 

int N;
VI v[100010];
int mark[100010], D[100010], branch[100010];
void dfs(int n, int num, int depth)
{
	branch[n] = num;
	D[n] = depth;
	bool flag = true;
	REP(i,v[n].size())
	{
		if(!mark[v[n][i]])
		{
			flag = false;
			mark[v[n][i]] = 1;
			dfs(v[n][i], num, depth+1);
		}
	}

	if(flag)
	{
		REP(i,depth+1)
		{
			tree[num].PB(0);
		}
	}
}

int main()
{
	N = SI;
	int Q = SI;
	REP(i,N)
	{
		int x = SI, y = SI;
		v[x].PB(y);
		v[y].PB(x);
	}

	mark[1] = 1;
	D[1] = 0;
	REP(i,v[1].size())
	{
		mark[v[1][i]] = 1;
		dfs(v[1][i], i+1, 1);
	}

	while(Q--)
	{
		int x = SI;
		if(x)
		{
			x = SI;
			printf("%d\n", read(branch[x], x));
		}
		else
		{
			x = SI;
			int y = SI, z = SI;

		}
	}

	return 0;
}
