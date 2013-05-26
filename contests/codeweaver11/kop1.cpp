
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

int main()
{
	int T = SI, i, l, j;

	while(T--)
	{
		char a[100];
		
		sscan(a);

		l = strlen(a); 

		for(i = l-1; i >= 0; --i)
		{
			if(a[i] != '0') { --a[i]; break; }

			a[i] = '9';
		}

//		printf("%s\n", a);

		REP(i,l) { if(a[i] == '7') { a[i] = '6'; break; } else if(a[i] == '3' || a[i] == '4') { a[i] = '2'; break; } }
		FOR(j,i+1,l) { a[j] = '9'; }
		
//		printf("%s\n", a);

		i = 0; while(a[i] == '0') { ++i; }

		FOR(j,i,l) { printf("%c", a[j]); } printf("\n");
	}

	return 0;
}
