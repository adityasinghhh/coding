
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
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=b-1;i>=a;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define ABS(a) a<0?-a:a
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))

vector<LL> Q;

void init()
{
	Q.PB(0l); 

	LL i = 0l;

	while(i<Q.size())
	{
		Q.PB(Q[i]*10l+4l);
		Q.PB(Q[i]*10l+7l);
		if(Q[i] > 1000000000l) { break; }
		++i;
	}

	//REP(i,Q.size()) { printf("%lld ", Q[i]); } printf("\n");
}

int main()
{
	init();

	LL L, R, s = 0l, i, l, r;

	cin>>L>>R;

	i = 0; while(Q[i] < L) { ++i; } l = i;
	i = 0; while(Q[i] <= R) { ++i; } r = i;

	//printf("%lld %lld\n", l, r);
	//printf("%lld %lld\n", Q[l], Q[r]);

	LL mini = MIN(Q[l],R);
	s += (mini - L + 1)*Q[l]; //cout<<s<<endl; 
	FOR(i,l+1,r) { s += (Q[i]-Q[i-1])*Q[i]; } //cout<<s<<endl;
	LL maxi = MAX(Q[r-1],L);
	s += (R - maxi)*Q[r]; //cout<<s<<endl;

	cout<<s<<endl;

	return 0;
}
