
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

vector<LL> tree;
LL read(int idx) { LL sum = 0; while(idx > 0) { sum += tree[idx]; idx -= (idx&-idx); } return sum; }
void update(int idx, LL val) { while(idx <= tree.size()) { tree[idx] += val; idx += (idx&-idx); } }

vector<int> tree1;
int read1(int idx) { int sum = 0; while(idx > 0) { sum += tree1[idx]; idx -= (idx&-idx); } return sum; }
void update1(int idx, int val) { while(idx <= tree1.size()) { tree1[idx] += val; idx += (idx&-idx); } }

LL BASE = 1000000007;

int main()
{
	int T = SI;
	while(T--)
	{
		int N = SI;
		tree.clear(); tree1.clear();
		REP(i,2*N) { tree.PB(0ll); tree1.PB(0); }
		
		priority_queue<pair<int, int> > pq;
		vector<LL> p1; p1.PB(0ll); FOR(i,1,N+1) { p1.PB(SLL); }
		vector<int> p2; p2.PB(0); FOR(i,1,N+1) { p2.PB(SI); }
		vector<pair<LL, int> > pos;
		REP(i,N+1)
		{
			pos.PB(MP(p1[i],p2[i]));
		}

		SORT(pos);

		FOR(i,1,N+1)
		{
			update(i, pos[i].first);
			pq.push(MP(pos[i].second, i)); 
			update1(i, 1);
		}
		
		
		
		LL ans = 0, v1, v2, v3;
		int left = N, val, l, g;
		pair<int, int> p;
		while(!pq.empty())
		{
			p = pq.top(); pq.pop();

//			printf("%d %d\n", p.first, p.second);

			val = read1(p.second);
			l = val-1;
			g = left-val;
			--left;

//			printf("val:%d\tl:%d\tg:%d\n", val, l, g);
//			printf("Adding %lld\n", pos[p.second]*p.first*(l-g));
			ans = (ans + ((pos[p.second].first*p.first)%BASE)*(l-g));
			if(ans >= BASE) { ans %= BASE; } 

			update1(p.second, -1);

			if(p.second-1) { v1 = read(p.second-1); }
			else { v1 = 0ll; }

			v2 = read(p.second);
			v3 = read(N);

//			printf("v1:%lld\tv2:%lld\tv3:%lld\n", v1, v2, v3);
//			printf("Adding %lld\n", (v3-v2-v1)*p.first);
			ans = (ans + (v3-v2-v1)*p.first);
			if(ans >= BASE) { ans %= BASE; } 
			
			update(p.second, -pos[p.second].first);
		}

		while(ans < 0) { ans += BASE; }
		ans %= BASE;

		printf("%lld\n", ans);
	}

	return 0;
}
