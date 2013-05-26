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

int N;
int a[100001];

int main()
{
	int count, maxi = 0, i, pos;

	iscan(N);

	FOR(i,1,N+1)
		iscan(a[i]);

	FOR(i,1,N+1)
	{
		pos = i;
		count = 1;
		while(a[pos] != -1)
		{
			pos = a[pos];
			count++;
		}

		if(maxi < count)
			maxi = count;

	}		

	printf("%d\n", maxi);

	return 0;
}
