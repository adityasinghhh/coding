#include<iostream>
#include<sstream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define MP make_pair
#define PB push_back
#define LL long long
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REPD(i,b) for(int i=(b)-1;i>=0;--i)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a) ((a)<0?-(a):(a))

typedef vector<int> VI; 
typedef pair<int,int> PI; 
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define RAND(x) ((int)(((rand()*1.0)/RAND_MAX)*(x)))

LL BASE = 1000000007;
LL mypow(LL A, int p)
{
	if(p == 0) { return 1ll; }
	else if(p == 1) { return A; }
	else if(p == 2) { return (A*A)%BASE; }
	return p&1 ? (A*mypow(A,p-1))%BASE : mypow(mypow(A, p/2),2); 
}

LL mod = 10000007;
string s[300];
char a[10001];
LL H[300][11234], HS[11234];
int N, M;

int find(int i, int j)
{
	if(s[i][0] != s[i][j]) { return 0; }

	int l = 1, e = N-j, m;

	m = e;

	LL h1 = H[i][m-1];
	LL h2 = (H[i][j+m-1] - (H[i][j-1] * HS[m]) % BASE) % BASE;
	while(h2 < 0) { h2 += BASE; }

	if(h1 == h2) { return m; }

	while(l+1 < e)
	{
		m = (l+e)/2;

		LL h1 = H[i][m-1];
		LL h2 = (H[i][j+m-1] - ((H[i][j-1] * HS[m]) % BASE) + BASE) % BASE;
		while(h2 < 0) { h2 += BASE; }

		if(h1 == h2) { l = m; }
		else { e = m; }
	}
	return l;
}

int main()
{
	HS[0] = 1ll;
	FOR(i,1,10001)
	{
		HS[i] = (HS[i-1] * mod) % BASE;
	}

	N = SI, M = SI;
	REP(i,M)
	{
		sscan(a);
		s[i] = a;

//		cout << s[i] << ": ";
		LL h = 0ll;
		REP(j,N)
		{
			h = (h * mod + s[i][j]-'a') % BASE;
			H[i][j] = h;
//			cout << H[i][j] << " ";
		}
//		cout << endl;
	}

	string ret = "";
	LL ans = 1ll;
	REP(j,N)
	{
		VI v;
		int maxi = -1;
		REP(i,M)
		{
			int match = find(i, j); 
			if(maxi < match)
			{
				v.clear();
				v.PB(s[i][j]);
				maxi = match;
			}
			else if(maxi == match)
			{
				v.PB(s[i][j]);
			}
		}

		SORT(v);
		int cnt = 1;
		FOR(i,1,v.size())
		{
			if(v[i] != v[i-1])
			{
				++cnt;
			}
		}

//		printf("maxi = %d for characters: ", maxi);
//		REP(k,v.size()) { printf("%c, ", v[k]); }
//		printf("\n");

		ret += v[0];
		ans = (ans * cnt) % mod;
	}

	printf("%lld %s\n", ans, ret.c_str());

	return 0;
}

