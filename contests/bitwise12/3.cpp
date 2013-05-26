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

#define RANGE 1000000

char isPrime[RANGE+10];
int primes[RANGE/10 + 10], p_cnt;

void sieve()
{
	isPrime[0] = isPrime[1] = 1;
	p_cnt = 0;

	REP(i,RANGE+10)
	{
		if(isPrime[i]) { continue; }

		primes[p_cnt++] = i;

		for(int j=2; j<RANGE/i; ++j)
		{
			isPrime[j*i] = 1;
		}
	}
}

int main()
{
	sieve();

	int N = SI, v[N+1], M = SI;
	vector<PI> V[N+1];
	REP(i,N)
	{
		v[i] = SI;

		int x = v[i], j = 0;
		while(x != 1)
		{
			if(x%primes[j] == 0)
			{
				int cnt = 0;
				while(x%primes[j] == 0)
				{
					x /= primes[j];
					++cnt;
				}
				V[i].PB(MP(primes[j], cnt));
			}
			++j;
		}
		if(x != 1) { V[i].PB(MP(x, 1)); } 
	}

	map<int, map<int,int> > L;
	map<int, map<int,int> >::iterator it, it1;
	REP(i,M)
	{
		REP(j,V[i].size())
		{
			++L[V[i][j].first][V[i][j].second];
		}
	}

/*	for(it = L.begin(); it != L.end(); ++it)
	{
		map<int, int>::iterator it1, it2;
		printf("%d: ", it->first);

		for(it1 = it->second.begin(); it1 != it->second.end(); ++it1)
		{
			printf("%d:%d ", it1->first, it1->second); 
		}
		printf("\n");
	}*/

	LL lcm = 1ll;
	for(it = L.begin(); it != L.end(); ++it)
	{
		int p = it->first;
		map<int, int> m = it->second;
		map<int, int>::reverse_iterator it1;
		it1 = m.rbegin();
		while(it1 != m.rend() && it1->second == 0) { ++it1; }
		if(it1 == m.rend()) { continue; }
		lcm = (lcm*mypow(p, it1->first))%BASE;
	}

	printf("%lld ", lcm);

	REP(i,N-M)
	{
		REP(j,V[i].size())
		{
			--L[V[i][j].first][V[i][j].second];
		}
		
		REP(j,V[i+M].size())
		{
			++L[V[i+M][j].first][V[i+M][j].second];
		}
		
/*		for(it = L.begin(); it != L.end(); ++it)
		{
			map<int, int>::iterator it1, it2;
			printf("%d: ", it->first);

			for(it1 = it->second.begin(); it1 != it->second.end(); ++it1)
			{
				printf("%d:%d ", it1->first, it1->second); 
			}
			printf("\n");
		}
*/
		LL lcm = 1ll;
		for(it = L.begin(); it != L.end(); ++it)
		{
			int p = it->first;
			map<int, int> m = it->second;
			map<int, int>::reverse_iterator it1;
			it1 = m.rbegin();
			while(it1 != m.rend() && it1->second == 0) { ++it1; }
			if(it1 == m.rend()) { continue; }

			lcm = (lcm*mypow(p, it1->first))%BASE;
		}

		printf("%lld ", lcm);
	}

	printf("\n");

	return 0;
}

