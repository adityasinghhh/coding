#include<iostream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

int main()
{
	int k, n;

	iscan(k);
	iscan(n);

	int i = 0;
	while(n%k == 0)
	{
		i++;
		n /= k;
	}

	if(n == 1)
	{
		printf("YES\n%d\n", i-1);
	}
	else
		printf("NO\n");

	return 0;
}
