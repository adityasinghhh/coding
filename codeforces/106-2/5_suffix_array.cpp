
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
	string s;
	cin >> s;

	SuffixArray SA(s);

	vector<pair<string, int> > temp = SA._SA;

	int sz = temp.size(), z = 0;
	vector<pair<string, int> > suffixes;
	VI lcp, index;
	suffixes.PB(MP(temp[0].first, temp[0].first.length()));     lcp.PB(0); index.PB(temp[0].second);
	FOR(i,1,sz)
	{
		suffixes.PB(MP(temp[i].first, suffixes[z].second + temp[i].first.length()));
		index.PB(temp[i].second);
		++z;

		int l1 = suffixes[z-1].first.length(), l2 = suffixes[z].first.length();

		int l = 0, e = MIN(l1, l2), m;
		while(l < e)
		{
			m = l + (e - l + 1)/2;

			string s1 = suffixes[z-1].first.substr(0,m);
			string s2 = suffixes[z].first.substr(0,m);

			if(s1 == s2) { l = m; }
			else { e = m-1; }
		}

		lcp.PB(l);

		suffixes[z].second -= lcp[z];
	}

/*	REP(i,sz)
	{
		cout << index[i] << " " << suffixes[i].first << " " << suffixes[i].second << " " << lcp[i] << endl;
	}
*/
	int T = SI, cnt = 0;
	while(T--)
	{
		string p; cin >> p;
		int lp = p.length();

		FOR(i,1,lp)
		{
			string s1 = p.substr(0,i), s2 = p.substr(i,lp-i);
			
//			cout << s1 << " " << s2 << endl;

			int l = -1, e = sz-1, m;
			while(l < e)
			{
				m = l + (e-l+1)/2;

				if(suffixes[m].first < s1) { l = m; }
				else { e = m-1; }
			}

			++l;
			if(l == sz || suffixes[l].first.substr(0,i) != s1) { continue; }
			
//			cout << s1 << " " << l << ": " << suffixes[l].first << endl;

			int mini = index[l];
			while(l < sz && suffixes[l].first.substr(0,i) == s1)
			{
//				printf("%s at index %d\n", s1.c_str(), index[l]);
				mini = MIN(mini, index[l]);
				++l;
			}
			
			l = -1, e = sz-1, m;
			while(l < e)
			{
				m = l + (e-l+1)/2;

				if(suffixes[m].first < s2) { l = m; }
				else { e = m-1; }
			}

			++l;
			if(l == sz || suffixes[l].first.substr(0,lp-i) != s2) { continue; }
			
//			cout << s2 << " " << l << ": " << suffixes[l].first << endl;

			int maxi = index[l];
			while(l < sz && suffixes[l].first.substr(0,lp-i) == s2)
			{
//				printf("%s at index %d\n", s2.c_str(), index[l]);
				maxi = MAX(maxi, index[l]);
				++l;
			}

			if(mini + s1.length() <= maxi) 
			{ 
//				printf("Success: %d and %d\n", mini, maxi);
				++cnt; 
				break; 
			}
/*			else
			{
				printf("Check failed as %d and %d\n", mini, maxi);
			}
*/		}
	}

	printf("%d\n", cnt);

	return 0;
}
