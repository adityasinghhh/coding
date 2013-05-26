
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
int N;
int f(string &w, string &b)
{
	it = dp.find(w+b); 
	if(it != dp.end()) 
	{ 
		return it->second; 
	}

	cout << w << " " << b << endl;

	bool flag = false;
	set<int> mex;
	set<int>::iterator it1;
	REP(i,N)
	{
		if(w[i]+1 < b[i])
		{
			flag = true;
			w[i] += 1;
			mex.insert(f(w, b));
			w[i] -= 1;
		}
	}

	if(flag)
	{
		int j = 0;
		TR(it1, mex)
		{
			if(*it1 != j)
			{
				return dp[w+b] = j;
			}
			++j;
		}
		return dp[w+b] = j;
	}

	return dp[w+b] = 0;
}

int main()
{
	int T = SI;
	REP(zz, T)
	{
		dp.clear();

		printf("Case %d: \n", zz+1);

		N = SI;
		string w = "";
		REP(i,N)
		{
			int x = SI;
			w += x + '0';
		}
	
		string b = "";
		REP(i,N)
		{
			int x = SI;
			b += x + '0';
		}

		cout << w << " " << b << endl;

		int ans = 0;
		REP(i,N)
		{
			if(w[i]+1 < b[i])
			{
				w[i] += 1;
				ans ^= f(w, b);
				w[i] -= 1;
			}
		}

		printf(ans ? "white wins\n" : "black wins\n");
	}
	
	return 0;
}