
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

LL BASE = 1000000009, M = 31;
int main()
{
	int N = SI;
	vector<pair<string, int> > v;
	REP(i,N)
	{
		string inp;
		cin >> inp;

		int x = SI;

		v.PB(MP(inp, x));
	}

	SORT(v);

	int H[N+1][1001];
	REP(i,N)
	{
		int l = v[i].first.length();
		LL h = 0ll;
		REP(j,l)
		{
			h = (h*M + v[i].first[j]) % BASE;
			H[i][j] = h;
		}
		
		FOR(j,l,1001)
		{
			H[i][j] = -1ll;
		}
	}

	int Q = SI;
	while(Q--)
	{
		string inp;
		cin >> inp;

		int l = inp.length();
		LL h = 0ll;
		REP(j,l)
		{
			h = (h*M + inp[j]) % BASE;
		}

		string out;
		int maxi = INT_MIN;
		REP(i,N)
		{
			if(H[i][l-1] == h)
			{
				if(maxi < v[i].second)
				{
					maxi = v[i].second;
					out = v[i].first;
				}
			}
		}

		if(maxi == INT_MIN)
		{
			printf("NO\n");
		}
		else
		{
			cout << out << endl;
		}
	}

	return 0;
}
