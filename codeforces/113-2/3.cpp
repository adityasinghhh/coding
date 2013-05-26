
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
	int N = SI, X = SI;
	VI v;
	bool flag = false;
	REP(i,N)
	{
		int x = SI;
		v.PB(x);
		if(x == X)
		{
			flag = true;
		}
	}

	int cnt = 0;
	if(!flag) { v.PB(X); ++cnt; ++N; }

	priority_queue<int> q1, q2;

	SORT(v);

	int mid = (N+1)/2;
	REP(i,mid)   { q1.push(v[i]); }
	FOR(i,mid,N) { q2.push(-v[i]); }

	while(true)
	{
		int x = q1.top();
		if(x == X)
		{
			printf("%d\n", cnt);
			return 0;
		}

		if(N%2 == 0)
		{
			int x = -q2.top();
			if(x < X)
			{
				q2.pop();
				q1.push(x);
				q2.push(-X);
			}
			else
			{
				q1.push(X);
			}
		}
		else
		{
			int x = q1.top();
			if(X < x)
			{
				q1.pop();
				q1.push(X);
				q2.push(-x);
			}
			else
			{
				q2.push(-X);
			}
		}

		++N;
		++cnt;
	}
}
