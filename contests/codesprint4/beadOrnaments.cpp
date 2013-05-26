
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

LL BASE = 1000000007ll;
LL mypow(LL n, LL p)
{
	if(p == 0)
	{
		return 1ll;
	}
	else if(p == 1)
	{
		return n;
	}
	else if(p == 2)
	{
		return (n*n)%BASE;
	}

	return p&1 ? (n * mypow(n, p-1))%BASE : mypow(mypow(n, p/2), 2);
}

VLL factorial;
void init()
{
	factorial.PB(1ll);
	FOR(i,1,32)
	{
		factorial.PB(factorial[i-1] * i);
		factorial[i] %= BASE;
	}

	LL prod = mypow(2ll, BASE-2);
	FOR(i,2,32)
	{
		factorial[i] *= prod;
		factorial[i] %= BASE;

		printf("%d: %lld\n", i, factorial[i]);
	}
}

map<vector<pair<LL, LL> >, LL> m;
map<vector<pair<LL, LL> >, LL>::iterator it;
LL f(vector<pair<LL,LL> > v)
{
	REP(i,v.size())
	{
		cout << v[i].first << "," << v[i].second << " ";
	}
	cout << endl;

	if(v.size() == 0)
	{
		return 1ll;
	}

	if(v.size() == 1)
	{
		printf("Returning: %lld\n", v[0].second);
		return v[0].second;
	}

	it = m.find(v);
	if(it != m.end())
	{
		printf("Returning: %lld\n", it->second);
		return it->second;
	}

	LL ret = 0ll;
	REP(i,v.size())
	{
		FOR(j,i+1,v.size())
		{
			vector<pair<LL,LL> > w;
			REP(k,v.size())
			{
				if(k != i && k != j)
				{
					w.PB(v[k]);
				}
			}

			w.PB(MP(v[i].first+v[j].first, (((v[i].first*v[j].first)%BASE)*((v[i].second*v[j].second)%BASE)%BASE)));

			SORT(w);

			ret += f(w);
		}
	}

	return m[v] = ret;
}

int main()
{
	init();

	int T = SI;
	while(T--)
	{
		int N = SI;
		vector<pair<LL, LL> > v;

		REP(i,N)
		{
			LL x = SLL;
			v.PB(MP(x, factorial[x]));
		}

		SORT(v);

		priority_queue<pair<LL, LL> > pq;
		REP(i,N)
		{
			pq.push(v[i]);
		}

		while(pq.size() > 1)
		{
			pair<LL, LL> p1 = pq.top();
			pq.pop();
			pair<LL, LL> p2 = pq.top();
			pq.pop();

			pq.push(MP(p1.first+p2.first, (((p1.second*p2.second)%BASE)*(p1.first+p2.first))%BASE));
		}

		printf("%lld\n", pq.top().second);
	}

	return 0;
}
