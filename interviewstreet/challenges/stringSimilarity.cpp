
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

LL M = 31, BASE = 10000007;

LL mypow(LL A, int p)
{
	if(p == 0) { return 1ll; }
	else if(p == 1) { return A%BASE; }
	else if(p == 2) { return (A*A)%BASE; }
	return p&1 ? (A * mypow(A, p-1)) % BASE : mypow(mypow(A, p/2), 2);
}

int main()
{
	LL B[100001];
	B[0] = 1ll;
	FOR(i,1,100001)
	{
		B[i] = (B[i-1] * M) % BASE;
	}

	int T = SI;
	while(T--)
	{
		string s; cin >> s;

		int L = s.length();

		LL H[L+1], h = 0ll;

		REP(i,L)
		{
			h = (h * M + s[i]) % BASE;
			H[i] = h;

//			cout << h << " ";
		}
//		cout << endl;

		int ans = L;
		FOR(i,1,L)
		{
			if(s[i] != s[0]) { continue; }

			int l = 1, e = L-i, m;
			while(l < e)
			{
				m = l + (e-l+1)/2;

				LL h1 = H[m-1];
				LL h2 = (H[i+m-1] - (H[i-1] * B[m]) % BASE) % BASE;
				while(h2 < 0) { h2 += BASE; }
				while(h2 >= BASE) { h2 -= BASE; }

//				printf("I:%d, M:%d, H1:%lld, H2:%lld\n", i, m, h1, h2);
				if(h1 == h2)
				{
					l = m;
				}
				else
				{
					e = m-1;
				}
			}

			ans += l;

//			printf("At index %d = %d\n", i, l);
		}

		printf("%d\n", ans);
	}

	return 0;
}
