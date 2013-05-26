
#include<algorithm>
#include<assert.h>
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
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define LL long long int
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

bool compare(pair<int, LL> p1, pair<int, LL> p2)
{
	return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
}

int main()
{
	int T = SI;
	while(T--)
	{
		int N = SI;
		VI A; REP(i,N) { A.PB(SI); }
		VI W; REP(i,N) { W.PB(SI); }

		map<int, LL> m;
		map<int, LL>::iterator it;
		REP(i,N)
		{
			it = m.find(A[i]);
			if(it == m.end()) { m[A[i]] = W[i]; }
			else { m[A[i]] = MAX(W[i], m[A[i]]); }
			
			for(it = m.begin(); it != m.end(); ++it)
			{
				if((*it).first >= A[i])
				{
					break;
				}
				else
				{
					m[A[i]] = MAX((*it).second+W[i], m[A[i]]);
				}
			}
		
			/*for(it = m.begin(); it != m.end(); ++it)
			{
				printf("%d:%lld ", (*it).first, (*it).second);
			}
			printf("\n");
			*/
		}

		LL maxi = -1ll;
		for(it = m.begin(); it != m.end(); ++it)
		{
			maxi = MAX(maxi, (*it).second);
		}
		printf("%lld\n", maxi);
	}

	return 0;
}
