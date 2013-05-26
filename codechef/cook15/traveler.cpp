
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

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=b-1;i>=a;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define LL long long int
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define ABS(a) a<0?-a:a
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))

int main()
{
	LL N, i; char a[100]; llscan(N); map<string, bool> city; REP(i,N) { sscan(a); city[a] = 1; }
	LL M, x; char b[100]; llscan(M); map<pair<string, string>, LL> dist; REP(i,M) { sscan(a); sscan(b); llscan(x); dist[MP(a, b)] = x; }
	LL T, K, tot;
	map<string, LL>::iterator it; 
	map<pair<string, string>, LL>::iterator it1;
	pair<string, string> p;
	llscan(T);
	while(T--)
	{ 
		bool flag = true;
		map<string, bool> mark;

		llscan(K);
		sscan(a);
	
		mark[a] = 1;
		tot = 0;
		REP(i,K-1)
		{
			sscan(b);

			if(!flag) { continue; }

			if(mark[b]) { flag = false; continue; } mark[b] = 1;

			p = MP(a, b);
			it1 = dist.find(p);

			if(it1 == dist.end()) { flag = false; continue; }

			tot += (*it1).second;
			strcpy(a, b);
		}

		if(flag) { printf("%lld\n", tot); } else { printf("ERROR\n"); }
	}

	return 0;
}
