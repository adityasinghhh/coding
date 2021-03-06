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
	map<int, int>::iterator it, it1, it3;
	
	int T, N, W, i, k, w, v, f, cost, value, newcost, newvalue, oldvalue, j, maxi;
	int ww[10000], vv[10000], ff[10000], z, c, d;
	
	iscan(T);

	while(T--)
	{
		map<int, int> dp1, dp2, dp3, dp4;
		
		iscan(N);
		iscan(W);

		z = 0;
		FOR(i,0,N)
		{
			iscan(w);
			iscan(v);
			iscan(f);

			c = 1;
			while(c < f)
			{
				ww[z] = c*w;
				vv[z] = c*v;
				ff[z++] = c;
				c *= 2;
			}

			c /= 2;

			if(f-c)
			{
				ww[z] = (f-c)*w;
				vv[z] = (f-c)*v;
				ff[z++] = f-c;
			}
		}

		FOR(i,0,z)
			printf("%d %d %d\n", ww[i], vv[i], ff[i]);

		continue;

		dp1[0] = 1;
		FOR(i,0,N/2)
		{
			dp2.clear();
			
			iscan(w);
			iscan(v);
			iscan(f);

			for(it = dp1.begin(); it != dp1.end(); it++)
			{
				cost = (*it).first;
				value = (*it).second;

				FOR(j,0,f+1)
				{
					newcost = cost + j*w;

					if(newcost > W)
						break;

					it1 = dp1.find(newcost);
					newvalue = value + j*v;

					if(it1 == dp1.end())
						dp2[newcost] = newvalue;
					else
					{
						oldvalue = (*it1).second;
						dp2[newcost] = (oldvalue < newvalue ? oldvalue : newvalue);
					}
				}
			}
			
			dp1 = dp2;
		}

		dp3[0] = 1;
		for(; i<N; i++)
		{
			dp4.clear();
			
			iscan(w);
			iscan(v);
			iscan(f);
			
			for(it = dp3.begin(); it != dp3.end(); it++)
			{
				cost = (*it).first;
				value = (*it).second;

				FOR(j,0,f+1)
				{
					newcost = cost + j*w;

					if(newcost > W)
						break;

					it1 = dp3.find(newcost);
					newvalue = value + j*v;

					if(it1 == dp3.end())
						dp4[newcost] = newvalue;
					else
					{
						oldvalue = (*it1).second;
						dp4[newcost] = (oldvalue < newvalue ? oldvalue : newvalue);
					}
				}
			}
			
			dp3 = dp4;
		}

		maxi = -1;
		for(it1 = dp2.begin(); it1 != dp2.end(); it1++)
		{
			for(it3 = dp4.begin(); it3 != dp4.end(); it3++)
			{
				if((*it1).first + (*it3).first > W)
					break;

				if(maxi < (*it1).second + (*it3).second)
					maxi = (*it1).second + (*it3).second;
			}
		}

		printf("%d\n", maxi-2);
	}

	return 0;
}
