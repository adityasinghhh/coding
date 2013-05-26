
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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int main()
{
	string s, p;
	cin >> s;
	cin >> p;

	int ls = s.length(), lp = p.length();

	if(lp > ls) { printf("0\n"); return 0; }

	int c[26] = {0}, d[26] = {0}, q = 0;
	REP(i,lp) 
	{ 
		++c[p[i]-'a']; 
		
		if(s[i] == '?') { ++q; } 
		else { ++d[s[i]-'a']; } 
	}

	int cnt = 0, q1 = 0;
	bool flag = false;
	REP(i,26) 
	{ 
		if(c[i] < d[i]) { flag = true; break; }
		else if(c[i] == d[i]) { continue; }
		{
			q1 += c[i]-d[i];
		}
	}
	if(!flag && q == q) { ++cnt; }

	REP(i,ls-lp)
	{
		if(s[i] == '?') { --q; }
		else { --d[s[i]-'a']; }

		if(s[i+lp] == '?') { ++q; }
		else { ++d[s[i+lp]-'a']; }
	
		int q1 = 0;
		bool flag = false;
		REP(j,26) 
		{ 
			if(c[j] < d[j]) { flag = true; break; }
			else if(c[j] == d[j]) { continue; }
			{
				q1 += c[j]-d[j];
			}
		}
		if(!flag && q == q) { ++cnt; }
	}

	printf("%d\n", cnt);

	return 0;
}
