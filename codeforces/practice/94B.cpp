
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
#define TR(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

class SuffixArray
{
	public:
	int sz;
	string S;
	vector<pair<string, PI> > _SA;

	SuffixArray(string &s)
	{
		S = s;

		int l = S.length();
		REP(i,l)
		{
			string s = S.substr(i,l);
			int pos = i;

			_SA.PB(MP(s, MP(pos, 0)));
		}

		SORT(_SA);

		sz = _SA.size();

		FOR(i,1,sz)
		{
			int l = 0, e = MIN(_SA[i].first.length(), _SA[i-1].first.length()), m;
			while(l < e)
			{
				m = l + (e-l+1)/2;

				if(_SA[i].first.substr(0,m) == _SA[i-1].first.substr(0,m)) { l = m; }
				else { e = m-1; }
			}

			_SA[i].second.second = l;
		}
	}

	bool check(int m, string &s)
	{
		return _SA[m].first < s;
	}

	int find_substring(string &s)
	{
		int l = -1, e = _SA.size()-1, m;
		while(l < e)
		{
			m = l + (e-l+1)/2;

			if(check(m, s)) { l = m; }
			else { e = m-1; }
		}

		if(l == _SA.size()-1) { return -1; }

		return _SA[l+1].first.substr(0, s.length()) == s ? _SA[l+1].second.first : -1;
	}
};

int main()
{
	string s;
	cin >> s;

	SuffixArray SA(s);

	VI v; v.PB(SA._SA[0].first.length());
		
	printf("%d: %d: %d: %s\n", v[0], SA._SA[0].second.first, SA._SA[0].second.second, SA._SA[0].first.c_str());
	FOR(i,1,SA.sz)
	{
		v.PB(v[i-1] + SA._SA[i].first.length());
		printf("%d: %d: %d: %s\n", v[i], SA._SA[i].second.first, SA._SA[i].second.second, SA._SA[i].first.c_str());
	}

	int K = SI;

	if(K > v[SA.sz-1]) { printf("No such line.\n"); return 0; }

	int l = -1, e = SA.sz-1, m;
	while(l < e)
	{
		m = l + (e-l+1)/2;

		if(v[m] < K) { l = m; }
		else { e = m-1; }
	}

	int r;
	if(l != -1) { r = v[l]; }
	else { r = 0; }

	++l;

	//printf("%d: %d: %s\n", SA._SA[l].second.first, SA._SA[l].second.second, SA._SA[l].first.c_str());

	printf("%s\n", SA._SA[l].first.substr(0, K - r).c_str());

	return 0;
}
