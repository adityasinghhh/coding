
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

void bf(VI &v1, VI &v2, int K)
{
	VI v;
	REP(i,v1.size())
	{
		v.PB(v1[i]);
	}
	REP(i,v2.size())
	{
		v.PB(v2[i]);
	}

	int k = (1<<v.size()), cnt = 0;
	FOR(i,1,k)
	{
		int x = i, j = 0, s = 0;
		while(x)
		{
			if(x&1)
			{
				s += v[j];
			}
			x /=2;
			++j;
		}
		if(s == K)
		{
			++cnt;
		}
	}

	printf("%d\n", cnt);

}

int main()
{
	int T = SI;
	while(T--)
	{
		int N = SI, mid = N/2;
		VI v1, v2;
		REP(i,mid)
		{
			v1.PB(SI);
		}
		FOR(i,mid,N)
		{
			v2.PB(SI);
		}

		map<LL, int> m1, m2;
		m1[0]++;
		m2[0]++;
		int k = (1<<mid);
		FOR(i,1,k)
		{
			int x = i, j = 0, s = 0;
			while(x)
			{
				if(x&1)
				{
					s += v1[j];
				}
				x /= 2;
				++j;
			}
			m1[s]++;
		}
		
		k = (1<<(N-mid));
		FOR(i,1,k)
		{
			int x = i, j = 0, s = 0;
			while(x)
			{
				if(x&1)
				{
					s += v2[j];
				}
				x /= 2;
				++j;
			}
			m2[s]++;
		}

		int K = SI, cnt = 0;
//		bf(v1, v2, K);
		map<LL,int>::iterator it1 = m1.begin();
		map<LL,int>::reverse_iterator it2 = m2.rbegin();
		for(; it1 != m1.end() && it2 != m2.rend();)
		{
			int s = it1->first + it2->first;
			if(s == K)
			{
				cnt += (it1->second * it2->second);
				++it1;
				++it2;
			}
			else if(s < K)
			{
				++it1;
			}
			else
			{
				++it2;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
