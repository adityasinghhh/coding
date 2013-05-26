
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

char A[1000001], B[1000001];
int la, lb;

int main()
{
	gets(A);
	gets(B);

	la = strlen(A);
	lb = strlen(B);

	if(la != lb)
	{
		printf("-1 -1\n");
		return 0;
	}

	if(A[0] != B[lb-1])
	{
		printf("-1 -1\n");
		return 0;
	}

	int i, j, k;
	bool flag = false;

	for(i=0; A[i] && A[i] == B[lb-1-i]; ++i);

	for(;i>=0; --i)
	{
		for(j=0; A[i+j] && B[j] == A[i+j]; ++j)
		{
			for(k=1; i+j+k<la; ++k)
				if(A[la-k] != B[k+j])
					break;

			if(i+j+k == la)
			{
				flag = true;
				break;
			}
		}

		if(flag)
			break;
	}

	if(flag)
		printf("%d %d\n", i-1, i+j+1);
	else
		printf("-1 -1\n");

	return 0;
}
