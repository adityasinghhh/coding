
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

int main()
{
	int N = SI;
	VVI R;
	REP(i,N) { VI v; v.PB(SI); v.PB(SI); v.PB(SI); R.PB(v); }

	int M = SI;
	VVI P;
	REP(i,M) { VI v; v.PB(SI); v.PB(SI); v.PB(SI); P.PB(v); }

	int ans = 0;
	REP(i,N)
	{
		int peri = 2*(R[i][0]+R[i][1]), h = R[i][2];

		int mini = INT_MAX;
		REP(j,M)
		{
			if(P[j][0] >= h)
			{
				int x = P[j][0]/h;
				int cnt = peri/P[j][1]; if(peri%P[j][1]) { ++cnt; }

				if(cnt%x) { cnt /= x; ++cnt; }
				else { cnt /= x; }

				mini = MIN(mini, cnt*P[j][2]);
			}
			else
			{
				int x = h/P[j][0]; if(h%P[j][0]) { ++x; }
				int cnt = peri/P[j][1]; if(peri%P[j][1]) { ++cnt; }
				cnt *= x;

				mini = MIN(mini, cnt*P[j][2]);
			}
		}
			/*
//			printf("Page %d: %d %d %d\n", j, P[j][0], P[j][1], P[j][2]);
			if(P[j][0] >= h)
			{
				if(P[j][1] >= peri) { mini = MIN(mini, P[j][2]); }///printf("Costing: %d\n", P[j][2]); }
				else
				{
//					printf("Perimeter: %d\n", peri);
//					printf("Page width: %d\n", P[j][1]);
					int cover = peri/P[j][1]; if(peri%P[j][1]) { ++cover; }

//					printf("To cover %d\n", cover);

					int cnt = 0, cnt1 = 0, cnt2 = 0;

					while(cnt1 < cover)
					{
						++cnt2;
						cnt = P[j][0];

						cnt1 += cnt/h;
//						cn %= h;
					}
						
					mini = MIN(mini, cnt2*P[j][2]);
//					printf("Costing: %d\n", cnt2*P[j][2]);
				}
			}
			else
			{
				if(P[j][1] >= peri) { mini = MIN(mini, 2*P[j][2]); }
				else
				{
					int cover = peri/P[j][1]; if(peri%P[j][1]) { ++cover; }

					int cnt = 0, cnt1 = 0, cnt2 = 0;
					while(cnt1 < cover)
					{
						++cnt2;
						cnt += P[j][0];

						if(cnt >= h) { ++cnt1; cnt %= h; }
					}

					mini = MIN(mini, cnt2*P[j][2]);
//					printf("Costing: %d\n", cnt2*P[j][2]);
				}
			}*/

		ans += mini;
	}

	printf("%d\n", ans);

	return 0;
}
