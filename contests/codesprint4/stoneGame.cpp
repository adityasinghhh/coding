
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

VI v;
int N;
LL BASE = 1000000007ll;

map<pair<VI,int>, LL> m;
map<pair<VI,int>, LL>::iterator it;
LL f(VI &v, int val, VI print)
{
	it = m.find(MP(v,val));
	if(it != m.end())
	{
//		return it->second;
	}

	if(v.size() == 0)
	{
		if(val == 0)
		{
			printf("1: ");
			REP(i,print.size())
			{
				cout << print[i] << " ";
			}
			printf("\n");
			return m[MP(v,val)] = 1ll;
		}
		
		printf("0: ");
		REP(i,print.size())
		{
			cout << print[i] << " ";
		}
		printf("\n");
		return m[MP(v,val)] = 0ll;
	}

	VI w;
	FOR(i,1,v.size())
	{
		w.PB(v[i]);
	}

	LL ret = 0ll;
	print.PB(0);
	REP(i,v[0]+1)
	{
		print[print.size()-1] = i;
		ret += f(w, val^i, print);
		ret %= BASE;
	}

/*	printf("Value:%d\tV: ", val);
	REP(i,v.size())
	{
		cout << v[i] << " ";
	}
	cout << ": " << ret << endl;
*/
	return m[MP(v,val)] = ret;
}

int main()
{
	N = SI;
	int tot = 0;
	REP(i,N)
	{
		v.PB(SI);
		tot ^= v[i];
	}

	SORT(v);
	
	LL ans = 0ll;
	REP(i,v.size())
	{
		VI w;
		REP(k,v.size())
		{
			if(k == i)
			{
				continue;
			}

			w.PB(v[k]);
		}

		VI print;
		print.PB(v[i]);
		ans += f(w, v[i], print);
		ans %= BASE;
	}

	if(tot == 0)
	{
		ans -= (v.size()-1);
		ans += BASE;
		ans %= BASE;
	}

	printf("%lld\n", ans);

	return 0;
}
