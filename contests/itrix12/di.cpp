
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

map<int, int> m;
map<int, int>::iterator it;
void init()
{
	m[1] = 1;
	m[2] = 1;
	m[4] = 3;
	m[8] = 6;
	m[16]= 11;
	m[32]= 25;
	m[64]= 42;
	m[128]= 98;
	m[256]= 163;
	m[512]= 381;
	m[1024]= 638;
	m[2048]= 1485;
	m[4096]= 2510;
	m[8192]= 5811;
	m[16384]= 9908;
	m[32768]= 22818;
	m[65536]= 39203;
	m[131072]= 89845;
	m[262144]= 155382;
	m[524288]= 354521;
	m[1048576]= 616666;
	m[2097152]= 1401291;
	m[4194304]= 2449868;
	m[8388608]= 5546381;
	m[16777216]= 9740686;
	m[33554432]= 21977515;
	m[67108864]= 38754732;
}

int main()
{
	int N = 100000000;
	int last = 0, curr;
	FOR(i,1,N+1)
	{
		int x = i, p[100], z = 0;
		while(x)
		{
			p[z++] = x%2;
			x /= 2;
		}

		int cnte = 0, cnto = 0;
		REP(j,z)
		{
			if(j&1) { cnto += p[j]; }
			else { cnte += p[j]; }
		}

		curr = last;
		if(cnte >= cnto)
		{
			++curr;
		}
		last = curr;

		if(i%50000 == 0)
		{
			printf("m[%d] = %d;\n", i, curr);
		}
	}
	return 0;
}


