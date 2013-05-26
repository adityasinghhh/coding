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
#include<stdlib.h>
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

char a[100001];
int l1, dig, y;

int left(int x)
{
	sprintf(a, "%d", x);
	l1 = strlen(a);

	dig = pow(10, l1-1);
	y = x/dig;
	x = x%dig;

	x = x*10 + y;

	return x;
}

int right(int x)
{
	sprintf(a, "%d", x);
	l1 = strlen(a);

	y = x%10;
	x /= 10;

	x = y*pow(10, l1-1) + x;

	return x;
}

int main()
{
	int T, N, maxi, x, l, r;

	iscan(T);
	
	while(T--)
	{
		iscan(N);

		map<int, bool> mark;
		queue<int> q;

		q.push(N);

		maxi = 0;

		while(!q.empty())
		{
			x = q.front();
			q.pop();

			l = left(x);

			if(!mark[l])
			{
				if(l > maxi)
					maxi = l;

				if(l)
				{
					q.push(l);
					mark[l] = 1;
				}
			}

			r = right(x);

			if(!mark[r])
			{
				if(r > maxi)
					maxi = r;

				if(r)
				{
					q.push(r);
					mark[r] = 1;
				}
			}
		}

		printf("%d\n", maxi);
	}
	return 0;
}
