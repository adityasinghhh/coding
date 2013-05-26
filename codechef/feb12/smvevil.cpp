
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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define LL long long int
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
	int T = SI;
	while(T--)
	{
		string ans = "";

		int K = SI;
		while(K--)
		{
			int M = SI, N = SI;
			char a[M+1][N+1];

			PI s, e;
		
			REP(i,M)
			{
				sscan(a[i]);
				REP(j,N)
				{
					if(a[i][j] == 'S') { s = MP(i,j); }
					else if(a[i][j] == 'E') { e = MP(i,j); }
				}
			}

			int l = ans.length(), x = s.first, y = s.second;
			bool flag = false;
			REP(i,l)
			{
				if(ans[i] == 'N')
				{
					if(x > 0)
					{
						if(a[x-1][y] == '.' || a[x-1][y] == 'S') { --x; }
						else if(a[x-1][y] == 'E') { flag = true; break; }
					}
				}
				else if(ans[i] == 'W')
				{
					if(y > 0)
					{
						if(a[x][y-1] == '.' || a[x][y+1] == 'S') { --y; }
						else if(a[x][y-1] == 'E') { flag = true; break; }
					}
				}
				else if(ans[i] == 'E')
				{
					if(y < N-1)
					{
						if(a[x][y+1] == '.' || a[x][y+1] == 'S') { ++y; }
						else if(a[x][y+1] == 'E') { flag = true; break; }
					}
				}
				else if(ans[i] == 'S')
				{
					if(x < M-1)
					{
						if(a[x+1][y] == '.' || a[x+1][y] == 'S') { ++x; }
						else if(a[x+1][y] == 'E') { flag = true; break; }
					}
				}
			}

			if(flag) { continue; }

			queue<pair<PI, string> > q;
			q.push(MP(MP(x,y), ""));

			while(!q.empty())
			{
				pair<PI, string> p = q.front(); q.pop();

				if(p.first == e) 
				{
					ans += p.second;
					break;
				}

				if(p.first.first > 0 && (a[p.first.first-1][p.first.second] == '.' || a[p.first.first-1][p.first.second] == 'E' || a[p.first.first-1][p.first.second] == 'S'))
				{
					a[p.first.first-1][p.first.second] = '#';
					q.push(MP(MP(p.first.first-1, p.first.second), p.second + "N"));
				}
				
				if(p.first.second > 0 && (a[p.first.first][p.first.second-1] == '.' || a[p.first.first][p.first.second-1] == 'E' || a[p.first.first][p.first.second-1] == 'S'))
				{
					a[p.first.first][p.first.second-1] = '#';
					q.push(MP(MP(p.first.first, p.first.second-1), p.second + "W"));
				}

				if(p.first.first < M-1 && (a[p.first.first+1][p.first.second] == '.' || a[p.first.first+1][p.first.second] == 'E' || a[p.first.first+1][p.first.second] == 'S'))
				{
					a[p.first.first+1][p.first.second] = '#';
					q.push(MP(MP(p.first.first+1, p.first.second), p.second + "S"));
				}

				if(p.first.second < N-1 && (a[p.first.first][p.first.second+1] == '.' || a[p.first.first][p.first.second+1] == 'E' || a[p.first.first][p.first.second+1] == 'S'))
				{
					a[p.first.first][p.first.second+1] = '#';
					q.push(MP(MP(p.first.first, p.first.second+1), p.second + "E"));
				}
			}
		}

		printf("%s\n", ans.c_str());
	}

	return 0;
}
