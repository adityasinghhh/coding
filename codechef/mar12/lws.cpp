
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
	int T = SI;
	while(T--)
	{
		string s;
		cin >> s;
		string r = "";
		int l = s.length();
		REPD(i,l)
		{
			r += s[i];
		}

		string t = s;
		SORT(t);

		printf("%s\n", s.c_str());
		printf("%s\n", r.c_str());
		printf("%s\n", t.c_str());

		int S[l+1][l+1], R[l+1][l+1];
		FILL(S,0); FILL(R,0);

		FOR(i,1,l+1)
		{
			FOR(j,1,l+1)
			{
				if(s[i] == t[j])
				{
					S[i][j] = S[i-1][j-1] + 1;
				}
				else
				{
					S[i][j] = MAX(S[i-1][j], S[i][j-1]);
				}
			}
		}
		
		FOR(i,1,l+1)
		{
			FOR(j,1,l+1)
			{
				if(r[i] == t[j])
				{
					R[i][j] = R[i-1][j-1] + 1;
				}
				else
				{
					R[i][j] = MAX(R[i-1][j], R[i][j-1]);
				}
			}
		}

		REP(i,l+1) { REP(j,l+1) { printf("%d ", S[i][j]); } printf("\n"); } 
		printf("\n");
		REP(i,l+1) { REP(j,l+1) { printf("%d ", R[i][j]); } printf("\n"); }
		printf("\n");

		int maxi = -1;
		REP(i,l+1)
		{
			maxi = MAX(maxi, S[i][i] + R[l-i+1][l-i+1]);
		}

		printf("%d\n", maxi);
	}

	return 0;
}
