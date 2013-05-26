
#include<algorithm>
#include<assert.h>
#include<bitset>
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
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define LL long long int

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define PI(x) printf("%d",x)
#define PC(x) printf("%c",x)
#define PLL(x) printf("%lld",x)
#define PLF(x) printf("%lf",x)
#define PS(x) printf("%s",x)
#define P32() printf(" ")
#define P10() printf("\n")
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define lfscan(n) scanf("%lf",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=b-1;i>=a;--i)
#define REP(i,b) for(int i=0;i<b;++i)
#define REPD(i,b) for(int i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int main()
{
	int N = SI, M = SI;
	VI v[M+1];
	int cnt = 0;
	FOR(i,1,N+1)
	{
		int K = SI;
		if(K == 0)
		{
			++cnt;
		}

		while(K--)
		{
			int x = SI;
			v[x].PB(i);
		}
	}

	if(cnt == N)
	{
		printf("%d\n", N);
		return 0;
	}

	set<int> s[N+1];
	VI w[N+1];
	REP(i,M+1)
	{
		REP(j,v[i].size())
		{
			FOR(k,j+1,v[i].size())
			{
				if(s[v[i][j]].find(v[i][k]) == s[v[i][j]].end())
				{
					s[v[i][j]].insert(v[i][k]);
					w[v[i][j]].PB(v[i][k]);
				}

				if(s[v[i][k]].find(v[i][j]) == s[v[i][k]].end())
				{
					s[v[i][k]].insert(v[i][j]);
					w[v[i][k]].PB(v[i][j]);
				}
			}
		}
	}

/*	printf("Graph\n");
	FOR(i,1,N+1)
	{
		cout << i << ": ";
		REP(j,w[i].size())
		{
			cout << w[i][j] << " ";
		}
		cout << endl;
	}
*/
	int ans = 0, mark[N+1];
	FILL(mark,0);
	while(true)
	{
		int start = -1;
		FOR(i,1,N+1)
		{
			if(!mark[i])
			{
				start = i;
				break;
			}
		}

		if(start == -1)
		{
			break;
		}

		queue<int> q;
		q.push(start);
		while(!q.empty())
		{
			int p = q.front();
			q.pop();

			mark[p] = 1;

			REP(i,w[p].size())
			{
				if(!mark[w[p][i]])
				{
					q.push(w[p][i]);
				}
			}
		}

		++ans;
	}

	cout << MAX(ans-1,0) << endl;

	return 0;
}

