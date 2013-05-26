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

int N, M, size, maxi;
char a[1001][1001];
vector<pair<int, int> > X;

void f(int i, int count)
{
	if(i == size)
	{
		if(maxi < count)
			maxi = count;
		return;
	}

	int x = X[i].first;
	int y = X[i].second;

	if(x != 0)
		if(a[x-1][y] == 'P')
		{
			a[x-1][y] = '.';
			f(i+1, count+1);
			a[x-1][y] = 'P';
		}
	if(y != 0)
		if(a[x][y-1] == 'P')
		{
			a[x][y-1] = '.';
			f(i+1, count+1);
			a[x][y-1] = 'P';
		}
	if(x != N-1)
		if(a[x+1][y] == 'P')
		{
			a[x+1][y] = '.';
			f(i+1, count+1);
			a[x+1][y] = 'P';
		}
	if(y != M-1)
		if(a[x][y+1] == 'P')
		{
			a[x][y+1] = '.';
			f(i+1, count+1);
			a[x][y+1] = 'P';
		}
	f(i+1, count);
}

int main()
{
	iscan(N);
	iscan(M);

	int i, j;

	FOR(i,0,N)
		sscan(a[i]);

	FOR(i,0,N)
		FOR(j,0,M)
			if(a[i][j] == 'W')
				X.PB(make_pair(i, j));

	size = X.size();

	maxi = 0;
	f(0, 0);

	printf("%d\n", maxi);

	return 0;
}
