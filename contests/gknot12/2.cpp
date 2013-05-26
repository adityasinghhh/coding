
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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define LL long long int
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

int main()
{
	VI v; REP(i,8) { v.PB(i+1); }

	int cnt = 0;
	do
	{
		bool flag =false;
		REP(i,8)
		{
			if(v[i] == 1)
			{
				if(v[(i+1)%8] == 2 || v[(i+1)%8] == 8)     { flag = true; break; }
				if(v[(8+i-1)%8] == 2 || v[(8+i-1)%8] == 8) { flag = true; break; }
			}
			if(v[i] == 2)
			{
				if(v[(i+1)%8] == 1 || v[(i+1)%8] == 3)     { flag = true; break; }
				if(v[(8+i-1)%8] == 1 || v[(8+i-1)%8] == 3) { flag = true; break; }
			}
			if(v[i] == 3)
			{
				if(v[(i+1)%8] == 2 || v[(i+1)%8] == 4)     { flag = true; break; }
				if(v[(8+i-1)%8] == 2 || v[(8+i-1)%8] == 4) { flag = true; break; }
			}
			if(v[i] == 4)
			{
				if(v[(i+1)%8] == 3 || v[(i+1)%8] == 5)     { flag = true; break; }
				if(v[(8+i-1)%8] == 3 || v[(8+i-1)%8] == 5) { flag = true; break; }
			}
			if(v[i] == 5)
			{
				if(v[(i+1)%8] == 4 || v[(i+1)%8] == 6)     { flag = true; break; }
				if(v[(8+i-1)%8] == 4 || v[(8+i-1)%8] == 6) { flag = true; break; }
			}
			if(v[i] == 6)
			{
				if(v[(i+1)%8] == 5 || v[(i+1)%8] == 7)     { flag = true; break; }
				if(v[(8+i-1)%8] == 5 || v[(8+i-1)%8] == 7) { flag = true; break; }
			}
			if(v[i] == 7)
			{
				if(v[(i+1)%8] == 6 || v[(i+1)%8] == 8)     { flag = true; break; }
				if(v[(8+i-1)%8] == 6 || v[(8+i-1)%8] == 8) { flag = true; break; }
			}
			if(v[i] == 8)
			{
				if(v[(i+1)%8] == 7 || v[(i+1)%8] == 1)     { flag = true; break; }
				if(v[(8+i-1)%8] == 7 || v[(8+i-1)%8] == 1) { flag = true; break; }
			}
		}
		
		if(!flag) 
		{ 
	//		REP(i,8) { printf("%d ", v[i]); } printf("\n");
			++cnt; 
		}
	}
	while(next_permutation(ALL(v)));
	
	printf("%d\n", cnt);

	int f = 1; REP(i,8) { f *= (i+1); }

	int g = __gcd(f, cnt);

	double ans = (double)cnt/(double)f;
	char a[1000];
	sprintf(a, "%.100lf", ans);
	printf("%s\n", a);

	double f1 = (double)f;
	double cnt1 = (double)cnt * 4844848428.00;

	printf("%lf\n", cnt1/f1);

	printf("%d %d\n", cnt/g, f/g);

	return 0;
}
