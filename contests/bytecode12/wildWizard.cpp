
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
		char a[1000001];
		scanf(" %[^\n]", a);
		string s = a;

		int M = SI, K = SI;

		int l = s.length();
		
		VI dp;
		dp.PB(0);
		if(s[0] == ' ') { dp.PB(32%M); }
		else if(s[0] >= 'A' && s[0] <= 'Z') { dp.PB((s[0] - 'A' + 51) % M); }
		else { dp.PB((s[0] - 'a' + 1) % M); }

		FOR(i,1,l)
		{
			if(s[i] == ' ') { dp.PB((dp[i] + 32) % M); }
			else if(s[i] >= 'A' && s[i] <= 'Z') { dp.PB((dp[i] + s[i] - 'A' + 51) % M); }
			else { dp.PB((dp[i] + s[i] - 'a' + 1) % M); }
		}
/*
		REP(i,dp.size())
		{
			printf("%d ", dp[i]);
		}
		printf("\n");
*/
		VI v[M+1];
		REP(i,dp.size())
		{
			v[dp[i]].PB(i);
		}

/*		REP(i,M)
		{
			printf("%d: ", i);
			REP(j,v[i].size())
			{
				printf("%d ", v[i][j]);
			}
			printf("\n");
		}
*/
		int maxi = -1, maxii, maxij;
		REP(i,M)
		{
			int x = (i+K) % M;

			if(!v[i].size() || !v[x].size())
			{
				continue; 
			}

			int len = v[x][v[x].size()-1] - v[i][0];

			if(len > maxi)
			{
				maxi = len;
				maxii = v[i][0];
				maxij = v[x][v[x].size()-1];
			}
			else if(len == maxi && v[i][0] < maxii)
			{
				maxii = v[i][0];
				maxij = v[x][v[x].size()-1];
			}
		}

		if(maxi == -1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d %d\n", maxii, maxi);
		}
	}

	return 0;
}
