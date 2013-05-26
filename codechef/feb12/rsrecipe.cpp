
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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define LL long long int
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

int main()
{
	int N = SI, M = SI;
	
	vector<LL> v; REP(i,N+1) { v.PB(1ll*INT_MIN); }

	priority_queue<pair<PI, LL> > pq;
	while(M--)
	{
		int x = SI, y = SI; LL d = SLL;
		printf("%d %d %lld\n", x, y, d);
		pq.push(MP(MP(-x, -y), d));
	}

	while(!pq.empty())
	{
		pair<PI, LL> p = pq.top(); pq.pop();
		int x1 = -p.first.first, y1 = -p.first.second; LL d1 = p.second;

		if(x1 == y1) { v[x1] = d1; continue; }

		if(pq.empty())
		{
			LL s = 0; FOR(i,x1,y1) { if(v[i] == INT_MIN) { v[i] = 0; } else { s += v[i]; } }
			v[y1] = d1-s;
			break;
		}

		pair<PI, LL> q = pq.top(); pq.pop();
		int x2 = -q.first.first, y2 = -q.first.second; LL d2 = q.second;

		if(x1 == x2 && y1 == y2 && d1 != d2) 
		{ 
			printf("(%d,%d):%lld and (%d,%d):%lld\n", x1, y1, d1, x2, y2, d2);
			printf("-1\n"); return 0; 
		}

		if(x2 == y2) { v[x2] = d2; pq.push(p); continue; }

		if(y1 < x2)
		{
			if(x2 - y1 > 1) { printf("-1\n"); return 0; }

			LL s = 0; FOR(i,x1,y1) { if(v[i] == INT_MIN) { v[i] = 0; } else { s += v[i]; } }
			v[y1] = d1-s;

			pq.push(q);
		}
		else if(y1 == x2)
		{
			printf("Here\n");
			if(v[y1] == INT_MIN)
			{
				printf("And\n");
				LL s = 0; FOR(i,x1,y1) { if(v[i] == INT_MIN) { v[i] = 0; } else { s += v[i]; } }
				v[y1] = d1-s;
				printf("Pushing: (%d,%d):%lld\n", x2+1, y2, d2-v[y1]);
				pq.push(MP(MP(-(x2+1), -y2), d2-v[y1]));
			}
			else
			{
				printf("v[%d] = %lld\n", y1, v[y1]);
				pq.push(MP(MP(-x1, -(y1-1)), d1-v[y1]));
				pq.push(MP(MP(-(x2+1), -y2), d2-v[y1]));
			}
		}
		else
		{
			LL s = 0; FOR(i,x1,x2) { if(v[i] == INT_MIN) { v[i] = 0; } else { s += v[i]; } }

			pq.push(MP(MP(-x2, -y1), d1-s));
			pq.push(MP(MP(-(y1+1), -y2), d2-(d1-s)));
		}		

		printf("(%d,%d):%lld and (%d,%d):%lld\n", x1, y1, d1, x2, y2, d2);
		LL s = 0;
		FOR(i,1,N+1)
		{
			s += v[i];
			printf("%lld:%lld ", v[i], s); 
		}
		printf("\n");
	}

	FOR(i,1,N+1) { if(v[i] == INT_MIN) { printf("-1\n"); return 0; } }

//	int s = 0;
	FOR(i,1,N+1)
	{
//		s += v[i];
//		printf("%d:%d ", v[i], s); 
		printf("%lld ", v[i]);
	}
	printf("\n");

	return 0;
}
