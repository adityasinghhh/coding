
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

LL dp[51][51][101];

vector<vector<LL> > V;
vector<LL> print, fprint;
LL N, M, K, maxi = -1;

void f(LL i, LL cost, LL k, LL last)
{
	if(k == N)
	{
		LL tot = 0, ii;
		for(ii=1; ii<2*N; ii+=2)
			tot += print[ii];

		if(tot > maxi)
		{
			for(ii=0; ii<2*N; ++ii)
				fprint[ii] = print[ii];
			maxi = tot;
		}

		return;
	}

	if(i == M)
		return;

	if(last != V[i][2] && K*cost >= V[i][0] && K*cost <= V[i][1])
	{
		print[2*k] = V[i][3];
		print[2*k+1] = K*cost;
		f(i+1, K*cost, k+1, last);
	}

	if(last != V[i][2] && K+cost >= V[i][0] && K+cost <= V[i][1])
	{
		print[2*k] = V[i][3];
		print[2*k+1] = K+cost;
		f(i+1, K+cost, k+1, last);
	}
	
	f(i+1, cost, k, last);
}

int main()
{
	FILL(dp,-1);

	cin>>N>>M>>K;

	LL i;
	REP(i,2*N)
	{
		fprint.PB(0ll);
		print.PB(0ll);
	}

	LL x;
	REP(i,M)
	{
		vector<LL> v;
		cin>>x;
		v.PB(x);
		cin>>x;
		v.PB(x);
		cin>>x;
		v.PB(x);

		v.PB(i+1);

		V.PB(v);
	}

	sort(V.begin(), V.end(), compare);

	LL j;
	REP(i,M)
	{
		FOR(j,V[i][0],V[i][1]+1)
		{
			print[0] = V[i][3];
			print[1] = j;
			f(i+1, j, 1, V[i][2]);
		}
	}

	if(maxi != -1)
	{
		printf("YES\n");
		REP(i,N)
			cout<<fprint[2*i]<<" "<<fprint[2*i+1]<<endl;
	}
	else
		printf("NO\n");

	return 0;
}
