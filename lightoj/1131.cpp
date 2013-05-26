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

#define LL long long int
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define SI ({LL _x; scanf("%lld",&_x); _x;})
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

LL M;

VVI power(VVI &A, int p)
{
	if(p == 1) { return A; }
	else if(p == 2)
	{
		VVI ret;
		int r = A.size();
		REP(i,r)
		{
			VI v;
			REP(j,r)
			{
				LL val = 0;
				REP(k,r)
				{
					val = (val + A[i][k]*A[k][j])%M;
				}
				v.PB(val);
			}
			ret.PB(v);
		}
		return ret;
	}
	else if(p%2 == 0)
	{
		VVI ret = power(A, p/2);
		return power(ret, 2);
	}
	else
	{
		VVI ans = power(A, p-1), ret;
		int r = A.size();
		REP(i,r)
		{
			VI v;
			REP(j,r)
			{
				LL val = 0;
				REP(k,r)
				{
					val = (val+A[i][k]*ans[k][j])%M;
				}
				v.PB(val);
			}
			ret.PB(v);
		}
		return ret;
	}
}

int main()
{
	int T = SI;
	REP(zz,T)
	{
		LL a1 = SI, b1 = SI, c1 = SI;
		LL a2 = SI, b2 = SI, c2 = SI;

		VVI A;
		VI v1; v1.PB(a1); v1.PB(b1); v1.PB(0); v1.PB(0); v1.PB(0); v1.PB(c1);
		VI v2; v2.PB(1); v2.PB(0); v2.PB(0); v2.PB(0); v2.PB(0); v2.PB(0);
		VI v3; v3.PB(0); v3.PB(1); v3.PB(0); v3.PB(0); v3.PB(0); v3.PB(0);
		VI v4; v4.PB(0); v4.PB(0); v4.PB(c2); v4.PB(a2); v4.PB(b2); v4.PB(0);
		VI v5; v5.PB(0); v5.PB(0); v5.PB(0); v5.PB(1); v5.PB(0); v5.PB(0);
		VI v6; v6.PB(0); v6.PB(0); v6.PB(0); v6.PB(0); v6.PB(1); v6.PB(0);
		A.PB(v1); A.PB(v2); A.PB(v3); A.PB(v4); A.PB(v5); A.PB(v6);

		LL f0 = SI, f1 = SI, f2 = SI;
		LL g0 = SI, g1 = SI, g2 = SI;
		VI B; B.PB(f2); B.PB(f1); B.PB(f0); B.PB(g2); B.PB(g1); B.PB(g0);

		M = SI;

		int Q = SI;
		printf("Case %d:\n", zz+1);
		while(Q--)
		{
			int P = SI;

			if(P == 1) { printf("%lld %lld\n", f1%M, g1%M); }
			else if(P == 2) { printf("%lld %lld\n", f2%M, g2%M); }
			else
			{
				VVI raised = power(A, P-2);

				printf("%lld %lld\n", (raised[0][0]*f2 + raised[0][1]*f1 + raised[0][2]*f0 + raised[0][3]*g2 + raised[0][4]*g1 + raised[0][5]*g0)%M, (raised[3][0]*f2 + raised[3][1]*f1 + raised[3][2]*f0 + raised[3][3]*g2 + raised[3][4]*g1 + raised[3][5]*g0)%M);
			}
		}
	}

	return 0;
}

