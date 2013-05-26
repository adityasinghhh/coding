
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

bool check(string &s)
{
	int cnt1 = 0, cnt2 = 0;
	REP(i,9)
	{
		if(s[i] == 'x') { ++cnt1; }
		if(s[i] == 'o') { ++cnt2; }
	}

	return cnt1 == cnt2 || cnt1 == cnt2+1;
}

map<string, int> m;
map<string, int>::iterator it;
int f(string &s)
{
	it = m.find(s); if(it != m.end()) { return it->second; }

	int cnt1 = 0, cnt2 = 0;
	REP(i,9)
	{
		if(s[i] == 'x') { ++cnt1; }
		if(s[i] == 'o') { ++cnt2; }
	}

	if(cnt1 == cnt2)
	{
		set<int> mex;
		REP(i,9)
		{
			if(s[i] == '.')
			{
				s[i] = 'x';
				mex.insert(f(s));
				s[i] = '.';
			}
		}

		set<int>::iterator it;
		it = mex.find(2); if(it != mex.end()) { return m[s] = 2; }
		it = mex.find(1); if(it != mex.end()) { return m[s] = 1; }
		return m[s] = 0;
	}
	else
	{
		set<int> mex;
		REP(i,9)
		{
			if(s[i] == '.')
			{
				s[i] = 'o';
				mex.insert(f(s));
				s[i] = '.';
			}
		}

		set<int>::iterator it;
		it = mex.find(2); if(it != mex.end()) { return m[s] = 2; }
		it = mex.find(1); if(it != mex.end()) { return m[s] = 1; }
		return m[s] = 0;
	}
}

int main()
{
	int T = SI;
	while(T--)
	{
		string s = "";
		string s1;
		cin >> s1; s += s1;
		cin >> s1; s += s1;
		cin >> s1; s += s1;

		if(check(s))
		{
			int ret = f(s);
			printf(ret ? ret == 1 ? "tie\n" : "win\n" : "lose\n");
		}
		else
		{
			printf("invalid\n");
		}
	}

	return 0;
}
