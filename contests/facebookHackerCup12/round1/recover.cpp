
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

int f(VI &v)
{
	int sz = v.size();
	int ret = 1;
	REP(i,sz)
	{
		ret = (31*ret + v[i]) % 1000003;
	}
	return ret;
}

int main()
{
	VI v; v.PB(1); v.PB(2); v.PB(3); v.PB(4); v.PB(5);

	do
	{
		printf("%d: ", f(v));
		REP(i,v.size()) { printf("%d ", v[i]); } printf("\n");
	}
	while(next_permutation(ALL(v)));

	int T = SI;
	REP(zz,T)
	{
		int N = SI;
		string s; cin >> s;

		int l = s.length();

		int v[N+1];
		int mid = N/2, i = mid-1, j = N-1, k = l-1, curr = N;

		while(i >= 0 && j >= mid)
		{
			if(s[k] == '2')
			{
				v[i] = curr;
				--i;
			}
			else 
			{
				v[j] = curr;
				--j;
			}
			--curr;
			--k;
		}

		while(i >= 0) { v[i] = curr; --i; --curr; }
		while(j >= mid) { v[j] = curr; --j; --curr; } 

		REP(i,N) { printf("%d ", v[i]); } printf("\n");

	}
	return 0;
}
