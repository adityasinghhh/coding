
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

LL M = 31, BASE = 1000000009, mypow[1000001];

void init()
{
	mypow[0] = 1ll;
	FOR(i,1,1000001)
	{
		mypow[i] = (mypow[i-1] * M) % BASE;
	}
}


int main()
{
	init();

	string s;
	cin >> s;
	int len = s.length();

	LL H[len+1], h = 0;
	REP(i,len)
	{
		h = (h * M + s[i]) % BASE;
		H[i] = h;
	}

	VI v;
	REP(i,len)
	{
		LL h1 = H[i];
		LL h2 = H[len-1] - (H[len-i-1]*mypow[i+1])%BASE;
		while(h2 >= BASE) { h2 -= BASE; }
		while(h2 < 0)     { h2 += BASE; }

		if(h1 == h2)
		{
			v.PB(i);
		}
	}

	REP(i, v.size())
	{
		printf("%d ", v[i]);
	}
	printf("\n");

	int maxi = 0;
	FOR(i,1,len)
	{
		int l = i, e = len-1, m;
		while(l < e)
		{
			m = l + (e-l+1)/2;

			LL h1 = H[m-i];
			LL h2 = H[m]-(H[i-1]*mypow[m-i+1])%BASE;
			while(h2 >= BASE) { h2 -= BASE; }
			while(h2 < 0)     { h2 += BASE; }
			if(h1 == h2)
			{
				l = m;
			}
			else
			{
				e = m-1;
			}
		}

		int match = l-i+1;
		l = 0, e = match;
		while(l < e)
		{
			m = l + (e-l+1)/2;
			LL h1 = H[m];
			LL h2 = H[len-1] - (H[len-m-1]*mypow[m+1])%BASE;
			while(h2 >= BASE) { h2 -= BASE; }
			while(h2 < 0)     { h2 += BASE; }
			if(h1 == h2)
			{
				e = m-1;
			}
			else
			{
				l = m;
			}
		}

		if(i+l == len)
		{
			continue;
		}

		printf("At index %d, matched %d\n", i, l);

		maxi = MAX(maxi, l);
	}

	if(maxi == 0)
	{
		printf("Just a legend\n");
	}
	else if(maxi == 1)
	{
		bool flag = false;
		if(s[0] == s[len-1])
		{
			FOR(i,1,len-1)
			{
				if(s[0] == s[i])
				{
					flag = true;
					break;
				}
			}
		}

		printf(flag ? "1\n" : "Just a legend\n");
	}
	else
	{
		REP(i,maxi)
		{
			printf("%c", s[i]);
		}
		printf("\n");
	}

	return 0;
}
