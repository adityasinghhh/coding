
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

#define maxi 10000000

int v[222][222];
char mark[222];
int N;

bool aug(int u, int T)
{
	if(u == T) { return true; }
	if(mark[u]) { return false; }

	mark[u] = true;
	REP(i,N+1)
	{   
		if(v[u][i] > 0 && aug(i,T))
		{    
			--v[u][i];
			++v[i][u];
			return true;
		}
	}   
	return false;
}

int maxFlow(int S, int T)
{
	int flow = 0;
	while(true)
	{   
		FILL(mark,0);

		if(aug(S,T))
		{   
			++flow;
		}   
		else
		{   
			break;
		}   
	}   

	return flow;
}

bool f(string &s1, string &s2)
{
	REP(i,s1.length())
	{
		if(s1[i] == s2[i] || s1[i] == '?' || s2[i] == '?')
		{
		}
		else
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int T = SI;
	REP(zz,T)
	{
		int M = SI;
		string k1, k2;
		cin >> k1 >> k2;

		M = k1.size()/M;

		VS v1, v2;
		REP(i,k1.size()/M)
		{
			string s1 = "", s2 = "";
			REP(j,M)
			{
				s1 += k1[i*M + j];
				s2 += k2[i*M + j];
			}

			v1.PB(s1);
			v2.PB(s2);
		}

		N = 2*v1.size()+1;

		FILL(v, 0);

		REP(i,v1.size())
		{
			REP(j,v2.size())
			{
				v[i+1][v1.size()+j+1] = f(v1[i], v2[j]);
			}
		}

		REP(i,v1.size())
		{
			v[0][i+1] = 1;
			v[v1.size()+i+1][N] = 1;
		}

		int flow = maxFlow(0, N);

		if(flow == v1.size())
		{
			printf("Case #%d: ", zz+1);
			VS V;
			REP(j,v2.size())
			{
				REP(i,v1.size())
				{
					if(v[v1.size()+j+1][i+1])
					{
						string s = "";
						REP(k,M)
						{
							if(v1[i][k] == v2[j][k])
							{
								s += (v1[i][k] == '?' ? 'a' : v1[i][k]);
							}
							else if(v1[i][k] == '?')
							{
								s += v2[j][k];
							}
							else if(v2[j][k] == '?')
							{
								s += v1[i][k];
							}
						}

						V.PB(s);
					}
				}
			}

			SORT(V);
			REP(i,V.size())
			{
				cout << V[i];
			}
			cout << endl;
		}
		else
		{
			printf("Case #%d: IMPOSSIBLE\n", zz+1);
		}
	}

	return 0;
}
