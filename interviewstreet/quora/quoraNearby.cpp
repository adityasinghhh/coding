
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

double distance(double x1, double y1, double x2, double y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
	int T = SI, Q = SI, N = SI;

	VI tid;
	vector<double> tx, ty;
	REP(i,T) { tid.PB(SI); tx.PB(SLF); ty.PB(SLF); }

	VI qid, qsz;
	VVI qn;
	REP(i,Q)
	{
		qid.PB(SI);
		qsz.PB(SI);
		VI v;
		REP(j,qsz[i])
		{
			v.PB(SI);
		}
		qn.PB(v);
	}

	char a[5];
	while(N--)
	{
		string a;
		cin >> a;

		if(a == "t")
		{
			int M = SI;
			double x = SLF, y = SLF;

			priority_queue<pair<double, int> > pq;

			REP(i,T)
			{
				double d = distance(x, y, tx[i], ty[i]);
				pq.push(MP(-d, tid[i]));
			}

			pair<double, int> p;
			while(M-- && !pq.empty())
			{
				p = pq.top(); pq.pop();

				printf("%d ", p.second);
			}
			printf("\n");
		}
		else
		{
			int M = SI;
			double x = SLF, y = SLF;

			priority_queue<pair<double, int> > pq;

			vector<double> D;
			REP(i,T)
			{
				D.PB(distance(x, y, tx[i], ty[i]));
			}

			REP(i,Q)
			{
				if(qsz[i] == 0) { continue; }

				double mini = (double)LLONG_MAX;
				REP(j,qsz[i])
				{
					double d = D[qn[i][j]];
					mini = min(mini, d);
				}

				pq.push(MP(-mini, i));
			}

			pair<double, int> p;
			while(M-- && !pq.empty())
			{
				p = pq.top(); pq.pop();

				printf("%d ", p.second);
			}
			printf("\n");
		}
	}

	return 0;
}

