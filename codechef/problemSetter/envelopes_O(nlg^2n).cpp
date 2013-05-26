
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

#define LL long long int

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

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
#define TR(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

vector<vector<int> > tree;

int read(int x, int y) 
{ 
	int sum = 0, y_ = y; 
	while(x > 0) 
	{ 
		y = y_;
		while(y > 0)
		{
			sum += tree[x][y]; 
			y -= (y&-y);
		}
	
		x -= (x&-x);
	}
	
	return sum;
}

void update(int x, int y, int val) 
{ 
	int y_ = y; 
	while(x <= tree.size()) 
	{ 
		y = y_; 
		while(y <= tree[x].size()) 
		{ 
			tree[x][y] += val; 
			y += (y&-y); 
		} 
		
		x += (x&-x); 
	} 
}

void init()
{
	REP(i, 5010)
	{
		VI v;
		REP(i, 5010)
		{
			v.PB(0);
		}

		tree.PB(v);
	}
}

void bf(VPI &v, int N)
{
	int maxi = -1;
	REP(i,N)
	{
		int cnt = 0;
		REP(j,N)
		{
			if(v[j].first <= v[i].first && v[j].second <= v[i].second)
			{
				++cnt;
			}
		}

		maxi = MAX(maxi, cnt);
	}

	printf("%d\n", maxi);
}

int main()
{
	init();

	int N = SI;
	VPI v;
	REP(i,N)
	{
		int x = SI, y = SI;
		v.PB(MP(x, y));
		update(x, y, 1);
	}

	bf(v, N);

	int maxi = -1;
	REP(i, N)
	{
		maxi = MAX(maxi, read(v[i].first, v[i].second));

	//	cout << v[i].first << " " << v[i].second << ": " << read(v[i].first, v[i].second) << ", " << maxi << endl;
	}

	printf("%d\n", maxi);

	return 0;
}
