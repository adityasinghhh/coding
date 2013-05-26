
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

map<string, int> dp;
map<string, int>::iterator it;

int f(string &s)
{
	it = dp.find(s); if(it != dp.end()) { return it->second; }

	int ca = 0, cb = 0, cc = 0, l = s.length();
	REP(i,l) { if(s[i] == 'a') { ++ca; } else if(s[i] == 'b') { ++cb; } else { ++cc; } }

	if(ca+cb == 0 || ca+cc == 0 || cb+cc == 0) 
	{
		return dp[s] = l;
	}

	if(l == 2) { return dp[s] = 1; }

	int mini = INT_MAX;
	REP(i,l-1)
	{
		if(i == 0)
		{
			string s1 = "";
			
			if(s[i] == 'a')      { if(s[i+1] == 'b') { s1 += 'c'; } else { s1 += 'b'; } }
			else if(s[i] == 'b') { if(s[i+1] == 'c') { s1 += 'a'; } else { s1 += 'c'; } }
			else                 { if(s[i+1] == 'a') { s1 += 'b'; } else { s1 += 'a'; } }
			
			s1 += s.substr(i+2, l-2);
			mini = MIN(mini, f(s1));
		}
		else if(i == l-2)
		{
			string s1 = s.substr(0, l-2);
			
			if(s[i] == 'a')      { if(s[i+1] == 'b') { s1 += 'c'; } else { s1 += 'b'; } }
			else if(s[i] == 'b') { if(s[i+1] == 'c') { s1 += 'a'; } else { s1 += 'c'; } }
			else                 { if(s[i+1] == 'a') { s1 += 'b'; } else { s1 += 'a'; } }

			mini = MIN(mini, f(s1));
		}
		else
		{
			string s1, s2;
			s1 = s.substr(0, i-1);
			
			if(s[i] == 'a')      { if(s[i+1] == 'b') { s1 += 'c'; } else { s1 += 'b'; } }
			else if(s[i] == 'b') { if(s[i+1] == 'c') { s1 += 'a'; } else { s1 += 'c'; } }
			else                 { if(s[i+1] == 'a') { s1 += 'b'; } else { s1 += 'a'; } }

			s1 += s.substr(i+2, l-i-2);

			mini = MIN(mini, f(s1));
		}
	}

	return dp[s] = mini;
}

int main()
{
	int T = SI;
	while(T--)
	{
		string s;
		cin >> s;

		printf("%d\n", f(s));
	}
	return 0;
}
