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

int main()
{
	int T = SI;
	char a[1000], b[10000], c[10000];
	while(T--)
	{
		sscan(a);
		sscan(b);
		sscan(c);

		int la = strlen(a), lb = strlen(b), lc = strlen(c);
		int pa[30] = {0}, pb[30] = {0}, pc[30] = {0};
		int qa[30][1001] = {0}, qb[30][1001] = {0};
		REP(i,la)
		{
			qa[a[i]-'a'][pa[a[i]-'a']++] = i;
		}
		REP(i,lb)
		{
			qb[b[i]-'a'][pb[b[i]-'a']++] = i;
		}

//		printf("%s\n%s\n%s\n", a, b, c);
		REP(i,lc)
		{
			if(pa[c[i]-'a'])
			{
				int x = pc[c[i]-'a'] % pa[c[i]-'a'], cnt = 0;
				int y = pc[c[i]-'a'] / pa[c[i]-'a'];

				int ii = qa[c[i]-'a'][x];
				int z = y*la+ii;
			//	printf("%d:",z);
				printf("%c", b[z%lb]);
/*				REP(j,la)
				{
					if(c[i] == a[j])
					{
						++cnt;
					}
					if(cnt == x)
					{
						int z = y*lb+j;
						printf("%c", b[z%lb]);
						break;
					}
				}*/
			}
			else
			{
				int x = pc[c[i]-'a'] % pb[c[i]-'a'], cnt = 0;
				int y = pc[c[i]-'a'] / pb[c[i]-'a'];
				int ii = qb[c[i]-'a'][x];
				int z = y*lb+ii;
			//	printf("%d:",z);
				printf("%c", a[z%la]);
				/*REP(j,lb)
				{
					if(c[i] == b[j])
					{
						++cnt;
					}
					if(cnt == x)
					{
						int z = y*la+j;
						printf("%c", a[z%la]);
						break;
					}
				}*/
			}
			++pc[c[i]-'a'];
		}
		printf("\n");
	}

	return 0;
}
