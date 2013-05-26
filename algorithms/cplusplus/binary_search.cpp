
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

int main()
{
	vector<int> V;

	V.PB(1);V.PB(2);V.PB(1);V.PB(2);V.PB(2);V.PB(1);V.PB(4);V.PB(3);V.PB(1);V.PB(3);V.PB(1);V.PB(5);

	int i;
	REP(i,V.size())
		printf("%d:%d ", i, V[i]);
	printf("\n");
	
	sort(V.begin(), V.end());

	REP(i,V.size())
		printf("%d:%d ", i, V[i]);
	printf("\n");
	
	vector<int>::iterator low, up;

	low = lower_bound(V.begin(), V.end(), 2);
	up = upper_bound(V.begin(), V.end(), 2);

	printf("Low: %d\n", (int)(low-V.begin()));
	printf("Up: %d\n", (int)(up-V.begin()));

	vector<int>::iterator it;

	if(binary_search(V.begin(), V.end(), 3))
		printf("Yes\n");
	else
		printf("No\n");

	if(binary_search(V.begin(), V.end(), 7))
		printf("Yes\n");
	else
		printf("No\n");


	return 0;
}
