
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
#define PI(x) printf("%d",x)
#define PC(x) printf("%c",x)
#define PLL(x) printf("%lld",x)
#define PLF(x) printf("%lf",x)
#define PS(x) printf("%s",x)
#define P32() printf(" ")
#define P10() printf("\n")
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

vector<int> tree[30];

int read(int i, int idx) { int sum = 0; while(idx > 0) { sum += tree[i][idx]; idx -= (idx&-idx); } return sum; }

void update(int i, int idx, int val) { while(idx <= tree[i].size()) { tree[i][idx] += val; idx += (idx&-idx); } }

int findG(int z, int freq)
{
	int sz = tree[z].size(), i=0; while(sz) { sz >>= 1; ++i; }
	int bitMask = (1<<(i-1)), idx = 0;

	while((bitMask != 0) && (idx < tree[z].size()))
	{
		int tIdx = idx + bitMask;

		if (freq >= tree[z][tIdx]) { idx = tIdx; freq -= tree[z][tIdx]; }

		bitMask >>= 1;
	}

	if (freq != 0) { return -1; } else { return idx; }
}

int main()
{
	int K = SI;
	string s;
	cin >> s;

	int l = s.length();

	REP(i,K*l+10) 
	{
		REP(j,30)
		{
			tree[j].PB(0);
		}
	}

	REP(i,K)
	{
		REP(j,l)
		{
			update(s[j]-'a', i*l+j+1, 1);
		}
	}

/*	REP(j,30)
	{
		printf("%c: ", j+'a');
		FOR(i,1,K*l+10)
		{
			printf("%d ", read(j, i));
		}
		printf("\n");
	}
*/
	int T = SI, len = l;
	while(T--)
	{
		int x = SI - 1;
		string a;
		cin >> a;
		int y = a[0]-'a';

//		printf("Need to remove the %dth %c\n", x, y+'a');

//		int Tidx = findG(y, x);
	
		int sz = tree[y].size(), i=0; 
		while(sz) { sz >>= 1; ++i; }
		int bitMask = (1<<(i-1)), idx = 0;

		while((bitMask != 0) && (idx < tree[y].size()))
		{
			int tIdx = idx + bitMask;

			if (x >= tree[y][tIdx]) { idx = tIdx; x -= tree[y][tIdx]; }

			bitMask >>= 1;
		}

//		printf("Removing %c at %d which has value %d\n", y+'a', l+1, read(y, l));
		update(y, idx+1, -1);
	}

	VPI v;
	REP(j,30)
	{
		int last = 0;
//		printf("%c: ", j+'a');
		FOR(i,1,K*l+10)
		{
			int curr = read(j, i);
//			printf("%d ", curr);
			if(last < curr)
			{
				v.PB(MP(i, j+'a'));
			}
			last = curr;
		}
//		printf("\n");
	}

	SORT(v);
	int sz = v.size();
	string ret = "";
	REP(i,sz)
	{
		ret += v[i].second;
	}
	
	printf("%s\n", ret.c_str());

	return 0;
}
