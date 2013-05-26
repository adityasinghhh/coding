
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
	string s;
	cin >> s;
	int l = s.length(), cnt = 0;
	VI v;
	REP(i,l)
	{
		if(s[i] == 'R' && s[i+1] == 'L')
		{
			v.PB(i);
		}
	}
	while(true)
	{
		
		if(v.size() == 0)
		{
			break;
		}

		REP(i,v.size())
		{
			s[v[i]] = 'L';
			s[v[i]+1] = 'R';
		}

		VI v1;
		REP(i,v.size())
		{
			if(v[i])
			{
				if(s[v[i]-1] == 'R')
				{
					v1.PB(v[i]-1);
				}
			}
			if(v[i]+1 < l-1)
			{
				if(s[v[i]+2] == 'L')
				{
					v1.PB(v[i]+2);
				}
			}
		}

		v.clear();
		if(v1.size())
		{
			v.PB(v1[0]);
			FOR(i,1,v1.size())
			{
				if(v1[i] != v1[i-1])
				{
					v.PB(v1[i]);
				}
			}
		}

		++cnt;
	}

	printf("%d\n", cnt);

	return 0;
}
