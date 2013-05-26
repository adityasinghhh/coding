
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
#define SI ({int _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%lld",&n)
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

LL maxim = 1000000000, ii, jj;
LL A[501][501], B[501][501], N;
		
void init(LL m) { LL i, j; FOR(i,1,N+1) { FOR(j,1,i+1) { B[i][j] = A[i][j]; } } B[ii][jj] = m; }

bool binary_search(LL m, LL MAXI)
{
	LL i, j, maxi;
	FOR(i,2,N+1)
	{
		FOR(j,1,i+1)
		{
			maxi = MAX(B[i-1][j-1], B[i-1][j]);
			B[i][j] += MAX(maxi, 0);
		}
	}

	maxi = B[N][1]; FOR(j,1,N+1) { maxi = MAX(maxi, B[N][j]); }

//	printf("maxi: %lld, MAXI: %lld\n", maxi, MAXI);
	return maxi <= MAXI;
}

void solve(LL MAXI)
{
	LL l = 0, e = maxim, m;
	while(l<e) { m = l + (e-l+1)/2; init(m); if(binary_search(m, MAXI)) { l = m; } else { e = m-1; } } //printf("%lld\n", m); }
	printf("%lld\n", l);
}

int main()
{
	LL T = SLL, i, j, n, flag, ch, maxi;

	while(T--)
	{
		N = SLL;
		getchar();

		FILL(A, 0); FILL(B, 0);

		FOR(i,1,N+1)
		{
			ch = getchar();
			FOR(j,1,i+1)
			{
				n = 0; flag = 1;
				do 
				{ if(ch == '?') { n = INT_MIN; ii = i; jj = j; } else if(ch == '-') { flag = -1; } else { n = n*10 + ch - '0'; } }
				while((ch = getchar()) != '\n' && ch != ' ');
				
				A[i][j] = flag * n;
				if(ch == ' ') { while((ch=getchar()) == ' '); }
			}
		}

		init(INT_MIN);

		FOR(i,2,N+1)
		{
			FOR(j,1,i+1)
			{
				maxi = MAX(B[i-1][j-1], B[i-1][j]);
				B[i][j] += MAX(maxi, 0);
			}
		}
	
		maxi = B[N][1]; FOR(j,1,N+1) { maxi = MAX(maxi, B[N][j]); }

		solve(maxi);
		
/*		FOR(i,1,N+1)
		{
			FOR(j,1,i+1)
			{
				printf("%lld ", A[i][j]);
			}
			printf("\n");
		}
*/	}

	return 0;
}
