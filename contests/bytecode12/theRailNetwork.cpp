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

#define MX 1000001
vector<PI> E[MX];

int R[1001];

inline int rep(int x)
{
	if(R[x]==x) return x;
	return R[x] = rep(R[x]);
}

inline bool uni(int u,int v)
{
	int ru = rep(u), rv = rep(v);
	if(ru==rv) return false;
	R[ru] = rv;
	return true;
}

int main()
{
	for(int t=SI;t--;)
	{
		int n = SI, m = SI, mxw = 0;
		LL ans = 0;
		REP(i,n) R[i+1] = i+1;
		REP(i,m)
		{
			int u = SI, v = SI, d = SI, r = SI;
			ans += min(r,d);
			if(r<=d) uni(u,v);
			else{ E[r-d].PB(MP(u,v)); mxw = max(mxw,r-d); }
		}
		REP(i,mxw+1) for(vector<PI>::iterator it = E[i].begin();it!=E[i].end();it++) 
			if(uni(it->F,it->S)) ans+=i;
		printf("%lld\n",ans);

		if(t) REP(i,mxw+1) E[i].clear();
	}	

	return 0;
}
