
#include<iostream>
#include<sstream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SL ({long long _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define MP make_pair
#define PB push_back
#define LL long long
#define _MAX 10000
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a

typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef pair<int,int> PI; 
typedef pair <LL, PI> PLPI;
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

map <VI,int> grundy;

int findGrundy(VI& v)
{
	if(present(grundy,v)) return grundy[v];
	set <int> mex;
	set <int> s;
	s.insert(ALL(v));
	if(s.size() == 1) return grundy[v] = 1;
	int sz = SZ(v);
	TR(s,it)
	{
		int g = 0;
		int i = 0;
		while(i<sz)
		{
			VI nv;
			while(i<sz && v[i] < *it) { nv.PB(v[i]); ++i; }
			if(SZ(nv)) g ^= findGrundy(nv);
			while(i < sz && v[i] >= *it) ++i;
		}
		mex.insert(g);
	}
	int i = 0;
	TR(mex,it)
	{
		if(i != *it) return grundy[v] = i;
		++i;
	}
	return grundy[v] = i;
}

void PrintAns(VI& v, int xr, int id)
{
	int G = findGrundy(v);
//	if(G ^ xr > G) return;
	int target = G ^ xr;
	set <int> s;
	s.insert(ALL(v));
	int sz = SZ(v);
	TR(s,it)
	{
		int g = 0;
		int i = 0;
		while(i<sz)
		{
			VI nv;
			while(i<sz && v[i] < *it) { nv.PB(v[i]); ++i; }
			if(SZ(nv)) g ^= findGrundy(nv);
			while(i < sz && v[i] >= *it) ++i;
		}
		if(target == g)
		{
			printf("(%d %d)",id,*it);
		}
	}
	return;
}

int main()
{
	int t = SI;
	REP(ii,t)
	{
		int n = SI;
		VI v[n];
		REP(i,n)
		{
			int k = SI;
			while(k--) { int x = SI; v[i].PB(x); }
		}
		int ans=0;
		REP(i,n) ans ^= findGrundy(v[i]);
		if(ans)
		{
			printf("Case %d: Aladdin\n",ii+1);
			REP(i,n) PrintAns(v[i],ans,i+1);
			printf("\n");
		}
		else printf("Case %d: Genie\n",ii+1);
	}
	return 0;
}
