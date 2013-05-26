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
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define LL long long int

int N, W;

int main()
{
	int T, N, W, i, k, w, v, f, cost, value, newcost, newvalue, oldvalue, j, maxi, size, size1, size3, cost1, cost3, value1, value3;
	iscan(T);

	while(T--)
	{
		vector<pair<int, int> > dp1, dp2, dp3, dp4;
		vector<pair<int, int> >::iterator it1, it2, it3, it4;
		
		iscan(N);
		iscan(W);

		dp1.PB(MP(0,0));
		FOR(i,0,N/2)
		{
			iscan(w);
			iscan(v);
			iscan(f);

			size = dp1.size();
			FOR(j,0,size)
			{
				cost = dp1[j].first;
				value = dp1[j].second;

				FOR(k,0,f+1)
				{
					newcost = cost + k*w;

					if(newcost > W)
						break;

					newvalue = value + k*v;
					dp2.PB(MP(newcost, newvalue));
				}
			}
			
			printf("%d: %d: ", i, dp2.size());
			FOR(j,0,dp2.size())
				printf("%d:%d ", dp2[j].first, dp2[j].second);
			printf("\n");
			
			dp1 = dp2;
			dp2.clear();
		}
		
		dp3.PB(MP(0,0));
		for(; i<N; i++)
		{
			iscan(w);
			iscan(v);
			iscan(f);

			size = dp3.size();
			FOR(j,0,size)
			{
				cost = dp3[j].first;
				value = dp3[j].second;

				FOR(k,0,f+1)
				{
					newcost = cost + k*w;

					if(newcost > W)
						break;

					newvalue = value + k*v;
					dp4.PB(MP(newcost, newvalue));
				}
			}

			printf("%d: %d: ", i, dp4.size());
			FOR(j,0,dp4.size())
				printf("%d:%d ", dp4[j].first, dp4[j].second);
			printf("\n");
			
			dp3 = dp4;
			dp4.clear();
		}

		sort(dp1.begin(), dp1.end());
		sort(dp3.begin(), dp3.end());
		
		maxi = -1;
		size1 = dp1.size();
		size3 = dp3.size();
		FOR(i,0,size1)
		{
			cost1  = dp1[i].first;
			value1 = dp1[i].second;

			FOR(j,0,size3)
			{
				cost3  = dp3[j].first;
				value3 = dp3[j].second;

				if(cost1 + cost3 > W)
					break;

				if(maxi < value1 + value3)
					maxi = value1+value3;
			}
		}

		printf("%d\n", maxi);
	}

	return 0;
}
