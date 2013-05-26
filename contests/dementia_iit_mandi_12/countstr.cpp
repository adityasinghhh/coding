
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
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define LL long long int
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define PI(x) printf("%d",&x)
#define PC(x) printf("%c",&x)
#define PLL(x) printf("%lld",&x)
#define PLF(x) printf("%lf",&x)
#define PS(x) printf("%s",&x)
#define PSP() printf(" ")
#define PN() printf("\n")
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

char *ipos, *opos, InpFile[20000000], OutFile[20000000], DIP[20];
inline int input(int flag=0) {

	while(*ipos <= 32) ++ipos;
	if ( flag  ) return (*ipos++ - '0'); /* For getting Boolean Characters */
	int x=0, neg = 0;char c;
	while( true ) {
		c=*ipos++; if(c == '-') neg = 1;
		else {
			if (c<=32) return neg?-x:x;
			x=(x<<1)+(x<<3)+c-'0';
		}
	}
}
inline void output(int x,int flag) {
	int y,dig=0;
	while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
	while (dig--) *opos++=DIP[dig];
	*opos++= flag ? '\n' : ' ';
}
inline void InitFASTIO() {
	ipos = InpFile; opos = OutFile;
	fread_unlocked(InpFile,20000000,1,stdin);
}
inline void FlushFASTIO() {
	fwrite_unlocked(OutFile,opos-OutFile,1,stdout);
}
inline string inputS()
{
	while(*ipos <= 32) ++ipos;
	string ret = "";
	while(true) { ret += *ipos; *ipos++; if(*ipos <= 32) { return ret; } }
}

VVI tree;

int read(int i, int j) { if(i == 0 || j == 0) { return 0; } int sum = 0; while(i > 0) { int k = j; while(k > 0) { sum += tree[i][k]; k -= (k&-k); } i -= (i&-i); } return sum; }

void update(int i, int j, int val) { while(i <= tree.size()) { int k = j; while(k <= tree[i].size()) { tree[i][k] += val; k += (k&-k); } i += (i&-i); } }

int main()
{
	InitFASTIO();

	int N = input(), M = input();

	REP(i,N+2) { VI v; REP(j,M+2) { v.PB(0); } tree.PB(v); }

	REP(i,N)
	{
		REP(j,M)
		{
			int x = input();
			update(i+1, j+1, x);
		}
	}
		
//	REP(i,N+1) { REP(j,N+1) { printf("(%d,%d) = %d\n", i+1, j+1, read(i+1, j+1)); } printf("\n"); }

	int T = input();
	while(T--)
	{
		int x1 = input()-1, y1 = input()-1, x2 = input(), y2 = input();

		printf("%d\n", read(x2, y2) + read(x1, y1) - read(x1, y2) - read(x2, y1));
	}


	return 0;
}
