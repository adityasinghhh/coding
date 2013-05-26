#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 1000006
int d[MX], w[MX];
LL dd[MX], ud[MX];

int main()
{

	for(int t=SI;t--;)
	{
		int n = SI;
		REP(i,n) w[i] = SI;
		REP(i,n-1) d[i] = SI;

		dd[0] = 0;
		LL sw = 0;
		for(int i=0;i<n;i++)
		{
			if(i) dd[i] = dd[i-1] + d[i-1] * sw;
			sw+=w[i];
		}

		ud[n-1] = 0;
		sw = 0;
		for(int i=n-1;i>=0;i--)
		{
			if(i<n-1) ud[i] = ud[i+1] + d[i] * sw;
			sw+=w[i];
		}

		int bi = -1; LL bs = (1LL<<62);
		REP(i,n)
		{
			LL cs = (w[i]?10:0) + dd[i] + 2*ud[i];
			if(cs<bs) bs = cs, bi = i;
			//printf("%d : %lld, %lld : %lld\n",i,dd[i],ud[i],cs);
		}

		printf("%lld %d\n",bs,bi+1);
	}	

	return 0;
}
