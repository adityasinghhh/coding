
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

LL BASE = 1000000007;
int v[1000], rev[1000], fw[1000];
char color[1000];
string s;
int l;

LL dp[800][800][3][3];

LL f(int s, int e, int cleft, int cright)
{
	if(s > e) { return 1ll; }

	LL &m = dp[s][e][cleft][cright]; if(m != 1) { return m; }

	m = 0;

	if(cleft != 1)
	{
		m += (f(s+1, fw[s]-1, 1, 0) * f(fw[s]+1, e, 0, cright)) % BASE;
	}

	if(cleft != 2)
	{
		m += (f(s+1, fw[s]-1, 2, 0) * f(fw[s]+1, e, 0, cright)) % BASE;
	}

	if(fw[s] == e)
	{
		if(cright != 1)
		{
			m += f(s+1, e-1, 1, 0);
		}

		if(cright != 2)
		{
			m += f(s+1, e-1, 2, 0);
		}
	}
	else
	{
		m += (f(s+1, fw[s]-1, 0, 1) * f(fw[s]+1, e, 1, cright)) % BASE;
		m += (f(s+1, fw[s]-1, 0, 2) * f(fw[s]+1, e, 2, cright)) % BASE;
	}

	return m;
}

int main()
{
	cin >> s; l = s.length();

	FILL(rev,-1); FILL(fw,-1); FILL(dp,-1);
	int cnt = 0;
	REP(i,l)
	{
		if(s[i] == '(') { ++cnt; }
		else { --cnt; }

		v[i] = cnt;

		if(s[i] == '(')
		{
			int j = i-1;
			while(j>=0)
			{
				if(s[j] == '(' && v[j] != cnt+1)
				{
					rev[i] = j;
					break;
				}
				--j;
			}
		}
	}

	REP(i,l)
	{
		if(rev[i] == -1) { continue; }
		fw[rev[i]] = i;
	}

	cout << f(0, l-1, 0, 0) << endl;

	return 0;
}
