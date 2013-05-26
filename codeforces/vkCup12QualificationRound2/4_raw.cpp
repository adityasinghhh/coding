
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

LL M = 31, BASE = 1000000009, mypow[2001];

void init()
{
	mypow[0] = 1ll;
	FOR(i,1,2001)
	{
		mypow[i] = (mypow[i-1] * M) % BASE;
	}
}

void bf(string &s)
{
	int l = s.length();
	VPI v;
	REP(i,l)
	{
		FOR(j,i,l+1)
		{
			int ii, jj;
			for(ii=i, jj=j; ii<jj; ++ii, --jj)
			{
				if(s[ii] != s[jj])
				{
					break;
				}
			}
			if(ii < jj) { continue; }
			v.PB(MP(i,j));
		}
	}
	
	LL cnt = 0ll;
	int sz = v.size();
/*	printf("Total palindromes: %d\n",sz);
	REP(i,sz)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
*/
	REP(i,sz)
	{
//		printf("%d %d\t", v[i].first, v[i].second);
		int j = i+1;
		for(; j < sz; ++j)
		{
			if(v[j].first > v[i].second)
			{
				break;
			}
		}

//		if(j == sz) { printf("=> Nothing\n"); continue; }
		if(j == sz) { continue; }

//		printf("=> (%d). %d %d\n", j, v[j].first, v[j].second);
//		printf("Adding %d\n", sz-j);

		cnt += (sz-j);
	}

	printf("%lld\n", cnt);
}

int main()
{
	init();

	string s, r = "";
	cin >> s;
	int l = s.length();
	REPD(i,l)
	{
		r += s[i];
	}

	bf(s);

	LL hs[l+1], hr[l+1];
	LL h1 = 0, h2 = 0;
	REP(i,l)
	{
		h1 = (h1 * M + s[i]) % BASE;
		hs[i] = h1;

		h2 = (h2 * M + r[i]) % BASE;
		hr[i] = h2;
	}

	VPI v;
	REP(i,l)
	{
		v.PB(MP(i,i));
		FOR(j,i+1,l)
		{
			int len = j-i+1, mid = len/2;
			LL h1 = hs[i+mid-1];
			if(i)
			{
				h1 -= (hs[i-1] * mypow[mid])%BASE;
			}
			while(h1 < 0)
			{
				h1 += BASE;
			}

			LL h2 = hr[l-j-1 + mid -1];
			if(j != l-1)
			{
				h2 -= (hr[l-j-2] * mypow[mid])%BASE;
			}
			while(h2 < 0)
			{
				h2 += BASE;
			}

			if(h1 == h2)
			{
				v.PB(MP(i,j));
			}
		}
	}

	LL cnt = 0ll;
	int sz = v.size();
/*	printf("Total palindromes: %d\n", sz);
	REP(i,sz)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
*/
	REP(i,sz)
	{
//		printf("%d %d\t", v[i].first, v[i].second);
		int l = v[i].second, e = sz-1, m;
		while(l < e)
		{
			m = l + (e-l+1)/2;
			if(v[m].first <= v[i].second)
			{
				l = m;
			}
			else
			{
				e = m-1;
			}
		}

		++l;

//		if(l >= sz) { printf("=> Nothing\n"); continue; }
		if(l >= sz) { continue; }

//		printf("=> (%d). %d %d\n", l, v[l].first, v[l].second);

//		printf("Adding %d\n", sz-l);

		cnt += (sz-l);
	}

	cout << cnt << endl;

	return 0;
}
