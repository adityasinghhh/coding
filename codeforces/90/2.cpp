
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
#define llscan(n) scanf("%lld",&n)
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

int main()
{
	int N, K;

	iscan(N);
	iscan(K);

	vector<int> V;

	int i, x, cnt=0;
	REP(i,N)
	{
		iscan(x);
		V.PB(x);
	}

	int Q;
	iscan(Q);

	int r = N/K;
	double s, maxi = -1.0, mini=10000.0;
	int p[1000] = {0};
	bool flag;
	
	while(Q--)
	{
		s = 0.0;
		flag = false;
		REP(i,r)
		{
			iscan(x);
			--x;
			if(!p[x])
				flag = true;

			p[x] = 1;

			s += (double)V[x];
		}

		if(flag)
			++cnt;

		s /= (double)r;

		if(mini > s)
			mini = s;
		if(maxi < s)
			maxi = s;
	}

	vector<int> V1;

	REP(i,N)
	{
		if(!p[i])
			V1.PB(V[i]);
	}

	int sz = V1.size();

	if(cnt != K && r <= sz)
	{
		sort(V1.begin(), V1.end());

		s = 0.0;
		REP(i,r)
		{
			s += (double)V1[i];
		}
		s /= (double)r;

		if(mini > s)
			mini = s;
		if(maxi < s)
			maxi = s;

		s = 0.0;
		REP(i,r)
		{
			s += (double)V1[sz-i-1];
		}
		s /= (double)r;

		if(mini > s)
			mini = s;
		if(maxi < s)
			maxi = s;
	}

	printf("%lf %lf\n", mini, maxi);

	return 0;
}
