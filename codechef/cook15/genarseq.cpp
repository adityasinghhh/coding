
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

int X[1001];

int main()
{
	int T, A, B, N, i, j, jj, k;
	iscan(T);
	while(T--)
	{
		iscan(A); iscan(B); iscan(N);

		X[0] = 1;
		FOR(i,1,N) 
		{ 
			k = X[i-1]+1; 
			while(true)
			{
				REP(j,i) 
				{ 
					REP(jj,i)
					{ 
						if(A*X[j]-B*X[jj] == k)
						{ 
							break; 
						} 
					} 
					
					if(jj != i) 
					{ 
						break; 
					}
				} 
				
				if(j == i) 
				{ 
					break; 
				} 
				
				++k;
			} 
			
			X[i] = k; 
		}
		
		REP(i,N) { printf("%d ", X[i]); } printf("\n");
	}

	return 0;
}
