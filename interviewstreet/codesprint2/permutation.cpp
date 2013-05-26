
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

int main()
{
	int N = SI;

	VVI V;
	REP(i,N)
	{
		VI v;
		REP(j,N)
		{
			v.PB(SI);
		}
		V.PB(v);
	}

	int T = N/9, n = N-T*9;

	REP(zz,T+1)
	{
		if(zz != T)
		{
			VI v, maxper;
			REP(i,9) { v.PB(i); }
			int maxi = INT_MIN;
			do
			{
				int sum = 0;
				REP(i,8)
				{
					sum += V[9*zz+v[i]][9*zz+v[i+1]];
				}

				if(maxi < sum)
				{
					maxi = sum;
					maxper.clear();
					REP(i,9)
					{
						maxper.PB(v[i]);
					}
				}
			}
			while(next_permutation(v.begin(), v.end()));

			REP(i,9)
			{
				printf("%d ", 9*zz + maxper[i]);
			}
		}
		else
		{
			if(n)
			{
				VI v, maxper;
				REP(i,n) { v.PB(i); }
				int maxi = INT_MIN;
				do
				{
					int sum = 0;
					REP(i,n-1)
					{
						sum += V[9*zz+v[i]][9*zz+v[i+1]];
					}

					if(maxi < sum)
					{
						maxi = sum;
						maxper.clear();
						REP(i,n)
						{
							maxper.PB(v[i]);
						}
					}
				}
				while(next_permutation(v.begin(), v.end()));

				REP(i,n)
				{
					printf("%d ", 9*zz + maxper[i]);
				}
			}
		}
	}
	printf("\n");

	return 0;
}
