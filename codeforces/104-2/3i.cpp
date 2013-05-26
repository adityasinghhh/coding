
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
	
string a, b;
int l, cnt = 0;
int dp[1000001][2];

int f(int i, int z)
{
	int &m = dp[i][z]; if(m != -1) { return m; }

	if(i >= l) { return m = 0; }

	if(a[i] == b[i])
	{
		return m = f(i+1, z);

		int ch = a[i];
		a[i] = (a[i] == '4' ? '7' : '4');

		m = MIN(m, 1 + f(i, (z+1)%2));

		return m;
	}
	else
	{
		int mini = INT_MAX;
		if(i < l-1 && a[i] == b[i+1] && a[i+1] == b[i])
		{
			swap(a[i], a[i+1]);
			mini = MIN(mini, 1 + f(i+1));
			swap(a[i], a[i+1]);
		}
		
		char ch = a[i];
		a[i] = b[i];
		mini = MIN(mini, 1 + f(i+1));
		a[i] = ch;
		
		return m = mini;
	}
}

int main()
{
	cin >> a >> b;

	FILL(dp, -1);

	l = a.length();

	int z = (a[0] == '4' ? 0 : 1);
	int mini = f(0, z);
	mini = MIN(mini, 1 + f(0, (z+1)%2));

	printf("%d\n", f(0));

	return 0;
}
