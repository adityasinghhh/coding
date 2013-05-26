
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
		string S;
		vector<pair<string, int> > _SA;

		SuffixArray(string &s)
		{
			S = s;

			int l = S.length();
			REP(i,l)
			{
				string s = S.substr(i,l);
				int pos = i;

				_SA.PB(MP(s, pos));
			}

			SORT(_SA);
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

			return _SA[l+1].first.substr(0, s.length()) == s ? _SA[l+1].second : -1;
		}
};

int main()
{
	int T = SI;
	REP(zz,T)
	{
		string s1, s2, s3;

		cin >> s1 >> s2 >> s3;

		SuffixArray sa1(s1), sa2(s2), sa3(s3);

		int sz = sa1._SA.size(), maxi = -1;
		REP(i,sz)
		{
			int l = sa1._SA[i].first.length();
			FOR(j,1,l+1)
			{
				if(j < maxi) { continue; }

				string s = sa1._SA[i].first.substr(0,j);

				if(sa2.find_substring(s) != -1 && sa3.find_substring(s) != -1)
				{
					maxi = MAX(maxi, j);
				}
			}
		}

		printf("Case %d: %d\n", zz+1, maxi);
	}
	
	return 0;
}
