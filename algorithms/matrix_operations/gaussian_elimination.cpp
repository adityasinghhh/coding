
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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define LL long long int
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int gcd(int a, int b) 
{ 
	if(!a || !b) { return 1; } 
	
	a = ABS(a); b = ABS(b); 
	
	if(a < b) { swap(a, b); } 
	
	return a%b ? gcd(b, a%b) : b; 
}

int main()
{
	int N = SI, M = SI;

	vector<vector<PI> > V; REP(i,N) { vector<PI> v; REP(j,M) { v.PB(MP(SI,1)); } V.PB(v); }
	
	printf("Initial\n"); REP(i,N) { REP(j,M) { printf("%d/%d\t", V[i][j].first, V[i][j].second); } printf("\n"); }

	REP(i,N)
	{
		int a = V[i][i].first, b = V[i][i].second, g; 
		bool flag = false;
		REP(k,M)
		{
			V[i][k].first  *= b; 
			V[i][k].second *= a;
			g = gcd(V[i][k].first, V[i][k].second);
			V[i][k].first  /= g;
			V[i][k].second /= g;

			if(V[i][k].second < 0) { flag = true; }
		}

		if(flag) { REP(k,M) { V[i][k].first *= -1; V[i][k].second *= -1; } }

		FOR(j,i+1,N)
		{
			int a = 1, b = 1;
			int c = V[j][i].first, d = V[j][i].second, g;

			vector<PI> v = V[i]; 
			REP(k,M) 
			{
				v[k].first *= c;    v[k].second *= d;    
				g = gcd(v[k].first,    v[k].second);
				v[k].first /= g;    v[k].second /= g;

				V[j][k].first  = V[j][k].first * v[k].second - V[j][k].second * v[k].first;
				if(V[j][k].first == 0) { V[i][k].second = 1; continue; }
				V[j][k].second = V[j][k].second * v[k].second;
				g = gcd(V[j][k].first, V[j][k].second); 
				V[j][k].first  /= g;
				V[j][k].second /= g;
			}
		}
	}
	printf("\n");
	printf("Gaussian Elimination\n"); REP(i,N) { REP(j,M) { printf("%d/%d\t", V[i][j].first, V[i][j].second); } printf("\n"); }

	REPD(i,N-1)
	{
		FOR(j,i+1,N)
		{
			int c = V[i][j].first, d = V[i][j].second, g;
			vector<PI> v = V[j];
			REP(k,M)
			{
				v[k].first *= c;    v[k].second *= d;    
				g = gcd(v[k].first,    v[k].second);
				v[k].first /= g;    v[k].second /= g;

				V[i][k].first  = V[i][k].first * v[k].second - V[i][k].second * v[k].first;
				if(V[i][k].first == 0) { V[i][k].second = 1; continue; }
				V[i][k].second = V[i][k].second * v[k].second;
				g = gcd(V[i][k].first, V[i][k].second); 
				V[i][k].first  /= g;
				V[i][k].second /= g;
			}
		}
	}
	printf("\n");
	printf("Reduced Row Echelon Form\n"); REP(i,N) { REP(j,M) { printf("%d/%d\t", V[i][j].first, V[i][j].second); } printf("\n"); }

	return 0;
}
