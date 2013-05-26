
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

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%I64d",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=a;i>b;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define LL long long int
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

bool compare(vector<LL> a, vector<LL> b)
{
	return a[2] < b[2];
}

pair<LL,LL> dp[51][51][101];

vector<vector<LL> > V;
LL N, M, K;

void memoize() 
{
	LL i, j, k, ii, kk, maxi, iii;
	pair<LL,LL> maxi1, maxi2;

	FOR(i,0,M+1) { FOR(j,0,N+1) { FOR(k,0,101) { dp[i][j][k] = MP(-1,-1); } } }

	FOR(i,0ll,M) { FOR(k,V[i][0],V[i][1]+1) { dp[i][1][k-V[i][0]] = MP(-1,k); } }

	FOR(i,0,M) { FOR(j,1,i+1) { FOR(k,V[i][0],V[i][1]+1) {

		maxi1 = MP(-1,-1); maxi2 = MP(-1,-1); iii = -1;

		FOR(ii,1,i+1) 
		{ 
			FOR(kk,0,101) 
			{ 
				if(k == (V[ii][0]+kk)+K || k == (V[ii][0]+kk)*K)
				{ 
					if(maxi1.second < dp[ii][j][kk].second) { maxi1 = dp[ii][j][kk]; iii = ii; }
					if(maxi2.second < dp[ii][j-1][kk].second) { maxi2 = dp[ii][j-1][kk]; iii = ii; }
				}
			}
		}

		if(maxi1.second < maxi2.second) { dp[i][j][k-V[i][0]] = MP(iii,maxi2.second); } 
		else { dp[i][j][k-V[i][0]] = maxi1; }
	} } }

	j = N; maxi = -1;
	FOR(i,0,M) { FOR(k,V[i][0],V[i][1]+1) { if(maxi < dp[i][j][k-V[i][0]].second) { maxi = dp[i][j][k-V[i][0]].second; ii = i; kk = k; } } }

	if(maxi == -1) printf("NO\n");
	else 
	{
		printf("YES\n");
		printf("%lld\n", maxi);
	}
}

int main()
{
	FILL(dp,-1);
	
	LL i, x, j; 

	cin>>N>>M>>K;

	REP(i,M) { vector<LL> v; cin>>x; v.PB(x); cin>>x; v.PB(x); cin>>x; v.PB(x); v.PB(i+1); V.PB(v); }

	sort(V.begin(), V.end(), compare);

	memoize();

	return 0;
}
