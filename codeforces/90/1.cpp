
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

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	if(a%b == 0)
		return b;
	return gcd(b, a%b);
}

int main()
{
	int A, B, N;
	iscan(A);
	iscan(B);
	iscan(N);
	int i, r;

	for(i=0; ; ++i)
	{
		if(i%2==0)
		{
			r = gcd(MAX(A,N), MIN(A, N));
		}
		else
		{
			r = gcd(MAX(B,N), MIN(B, N));
		}

		N-=r;

		if(N<0)
		{
			printf("%d\n", !(i%2));
			break;
		}
	}



	return 0;
}
