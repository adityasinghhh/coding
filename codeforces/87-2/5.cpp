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

char **a;
int BASE = 1000003;
int N, M, counti = 0;

void f(int i, int j)
{
	if(j == M)
	{
		i++;
		j = 0;
	}

	if(i == N)
	{
		counti = (counti+1)%BASE;

		return;
	}

	if(a[i][j] == '.')
	{
		bool flag = 0, one = 1, two = 1, three = 1, four = 1;

		if(i != 0)
		{
			if(a[i-1][j] == '1' || a[i-1][j] == '4')
			{	
				one &= 0;
				two &= 1;
				three &= 1;
				four &= 0;
			}
			else if(a[i-1][j] == '2' || a[i-1][j] == '3')
			{
				one &= 1;
				two &= 0;
				three &= 0;
				four &= 1;
			}
		}

		if(j != 0)
		{
			if(a[i][j-1] == '1' || a[i][j-1] == '2')
			{	
				one &= 0;
				two &= 0;
				three &= 1;
				four &= 1;
			}
			else if(a[i][j-1] == '3' || a[i][j-1] == '4')
			{
				one &= 1;
				two &= 1;
				three &= 0;
				four &= 0;
			}
		}

		if(i != N-1)
		{
			if(a[i+1][j] == '1' || a[i+1][j] == '4')
			{	
				one &= 0;
				two &= 1;
				three &= 1;
				four &= 0;
			}
			else if(a[i+1][j] == '2' || a[i+1][j] == '3')
			{
				one &= 1;
				two &= 0;
				three &= 0;
				four &= 1;
			}
		}

		if(j != M-1)
		{
			if(a[i][j+1] == '1' || a[i][j+1] == '2')
			{	
				one &= 0;
				two &= 0;
				three &= 1;
				four &= 1;
			}
			else if(a[i][j+1] == '3' || a[i][j+1] == '4')
			{
				one &= 1;
				two &= 1;
				three &= 0;
				four &= 0;
			}
		}

		if(one)
		{
			a[i][j] = '1';
			f(i, j+1);
			a[i][j] = '.';
		}
		
		if(two)
		{
			a[i][j] = '2';
			f(i, j+1);
			a[i][j] = '.';
		}

		if(three)
		{
			a[i][j] = '3';
			f(i, j+1);
			a[i][j] = '.';
		}

		if(four)
		{
			a[i][j] = '4';
			f(i, j+1);
			a[i][j] = '.';
		}

		if(one|two|three|four == 0)
			return;
	}
	else 
		f(i, j+1);
}

bool check()
{
	int i, j;

	FOR(i,0,N)
		FOR(j,0,M)
		{
			if(a[i][j] == '1')
			{
				if(i != 0 && a[i-1][j] == '4')
					return 0;

				if(j != 0 && a[i][j-1] == '2')
					return 0;
				
				if(i != N-1 && a[i+1][j] == '4')
					return 0;

				if(j != M-1 && a[i][j+1] == '2')
					return 0;
			}
			else if(a[i][j] == '2')
			{
				if(i != 0 && a[i-1][j] == '3')
					return 0;

				if(j != 0 && a[i][j-1] == '1')
					return 0;
				
				if(i != N-1 && a[i+1][j] == '3')
					return 0;

				if(j != M-1 && a[i][j+1] == '1')
					return 0;
			}
			else if(a[i][j] == '3')
			{
				if(i != 0 && a[i-1][j] == '2')
					return 0;

				if(j != 0 && a[i][j-1] == '4')
					return 0;
				
				if(i != N-1 && a[i+1][j] == '2')
					return 0;

				if(j != M-1 && a[i][j+1] == '4')
					return 0;
			}
			else if(a[i][j] == '4')
			{
				if(i != 0 && a[i-1][j] == '1')
					return 0;

				if(j != 0 && a[i][j-1] == '3')
					return 0;
				
				if(i != N-1 && a[i+1][j] == '1')
					return 0;

				if(j != M-1 && a[i][j+1] == '3')
					return 0;
			}
		}

	return 1;
}

int main()
{
	iscan(N);
	iscan(M);

	a = new char*[N+1];

	int i;

	FOR(i,0,N)
	{
		a[i] = new char[M+1];
		sscan(a[i]);
	}

	if(!check())
	{
		printf("0\n");
		return 0;
	}

	f(0, 0);

	printf("%d\n", counti);

	return 0;
}
