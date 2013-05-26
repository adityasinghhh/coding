
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

		priority_queue<pair<LL, int> > pq;
		pair<LL, int> p;
		pq.push(MP(1ll*W[0], A[0]));
		FOR(i,1,N)
		{
			vector<pair<LL, int> > temp;

			while(!pq.empty())
			{
				p = pq.top(); pq.pop();

				if(p.second < A[i])
				{
					pq.push(MP(p.first+W[i], A[i]));
					temp.PB(p);
					break;
				}
				else if(p.second == A[i])
				{
					if(p.first < 1ll*W[i])
					{
						pq.push(MP(1ll*W[i], A[i]));
						break;
					}
				}
				temp.PB(p);
			}

			int sz = temp.size();
			REP(j,sz) { pq.push(temp[j]); }
		}

		LL maxi = -1ll;
		while(!pq.empty())
		{
			p = pq.top(); pq.pop();
			maxi = MAX(maxi, p.first);
		}

		printf("%lld\n", maxi);
	}

	return 0;
}
