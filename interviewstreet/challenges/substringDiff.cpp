
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

map<pair<int, PI>, int> dp;
map<pair<int, PI>, int>::iterator it;
int count(string &a, string &b, int &i, int &j, int &m, int &K)
{
	it = dp.find(MP(m, MP(i, j)));
	if(it != dp.end())
	{
		return it->second;
	}

	int cnt = 0;
	REP(k,m)
	{
		if(a[i+k] != b[j+k])
		{
			++cnt;
			if(cnt > K)
			{
				return dp[MP(m, MP(i,j))] = cnt;
			}
		}
	}
	return dp[MP(m, MP(i,j))] = cnt;
}

bool find(string &a, string &b, int &m, int &K)
{
	int l = a.length();
	REP(i,l-m+1)
	{
		REP(j,l-m+1)
		{
			if(count(a, b, i, j, m, K) <= K)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int T = SI;
	while(T--)
	{
		int K = SI;
		string a, b;
		cin >> a >> b;

		int l = K, e = a.length(), m;
		while(l < e)
		{
			int m = l + (e-l+1)/2;

			if(find(a, b, m, K))
			{
				l = m;
			}
			else
			{
				e = m-1;
			}
		}
		printf("%d\n", l);
	}
	return 0;
}
