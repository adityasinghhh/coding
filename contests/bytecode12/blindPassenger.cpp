/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<sstream>
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

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define MP make_pair
#define PB push_back
#define LL long long
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REPD(i,b) for(int i=(b)-1;i>=0;--i)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a) ((a)<0?-(a):(a))

typedef vector<int> VI; 
typedef pair<int,int> PI; 
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define RAND(x) ((int)(((rand()*1.0)/RAND_MAX)*(x)))

int main()
{
	int t = SI;
	while(t--)
	{
		int n = SI;
		if(n == 1) { printf("poor conductor\n"); continue; }
		n-=2;
		int row = n/5 + 1;
		int t = n%5;
		char seat,dir;
		if(row&1)
		{
			if(t == 0 || t == 4) seat = 'W';
			else if(t == 1 || t==2) seat = 'A';
			else seat = 'M';
			if(t == 0 || t == 1) dir = 'L';
			else dir = 'R';
		}
		else
		{
			if(t == 0 || t == 4) seat = 'W';
			else if(t == 2 || t == 3) seat = 'A';
			else seat = 'M';
			if(t < 3) dir = 'R';
			else dir = 'L';
		}
		printf("%d %c %c\n",row,seat,dir);
	}
	return 0;
}
