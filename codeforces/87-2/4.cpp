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

int main()
{
	int N, M;

	iscan(N);
	iscan(M);

	char a[N+1][M+1];
	int first[N+1], maxi;
	int i, j, last [N+1];
	bool flag, flag1 = 0;

	FOR(i,0,N)
	{
		sscan(a[i]);

		first[i] = last[i] = -1;

		flag = 0;
		FOR(j,0,M)
		{
			if(a[i][j] == 'W')
			{
				maxi = i;
				flag1 = 1;
				if(!flag)
					first[i] = j;
				flag = 1;
				last[i] = j;
			}
		}
	}

	if(!flag1)
	{
		printf("0\n");
		return 0;
	}

	int moves = 0;
	int current = 0;
	int m;

	FOR(i,0,maxi)
	{
		if(i%2 == 0)
		{
			if(last[i] == -1 && last[i+1] == -1)
			{
				moves++;
			}
			else if(last[i+1] == -1)
			{
				m = last[i];
				moves += (m-current+1);
				current = m;
			}
			else if(last[i] == -1)
			{
				m = last[i+1];
				moves += (m-current+1);
				current = m;
			}
			else
			{
				m = (last[i] > last[i+1] ? last[i] : last[i+1]);
				moves += (m - current+1);
				current = m;
			}
		}
		else
		{
			if(first[i] == -1 && first[i+1] == -1)
			{
				moves++;
			}
			else if(first[i+1] == -1)
			{
				m = first[i];
				moves += (current-m+1);
				current = m;
			}
			else if(first[i] == -1)
			{
				m = first[i+1];
				moves += (current-m+1);
				current = m;
			}
			else
			{
				m = (first[i] < first[i+1] ? first[i] : first[i+1]);
				moves += (current - m+1);
				current = m;
			}
		}
	}

	moves += (i%2 == 0 ? last[i]-current : current-first[i]);

	printf("%d\n", moves);

	return 0;
}
