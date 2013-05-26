
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

vector<vector<vector<int> > > V;
void make(int i)
{
	VVI vvi;
	REP(j,i)
	{
		REP(k,V[j].size())
		{
			VI v;
			int maxi = -1;
			REP(l,V[j][k].size())
			{
				maxi = MAX(maxi, V[j][k][l]);
				v.PB(V[j][k][l]);
			}

			if(maxi == V[j][k][V[j][k].size()-1] && maxi <= i-j)
			{
				v.PB(i-j);
				vvi.PB(v);
			}
		}
	}

	VI v;
	v.PB(i);
	vvi.PB(v);
	V.PB(vvi);
}

void init()
{
	VVI v;
	V.PB(v);

	FOR(i,1,9)
	{
		make(i);

		cout << i << " " << V[i].size() << endl;
		cout << "{";
		REP(j,V[i].size())
		{
			cout << "{";
			REP(k,V[i][j].size())
			{
				cout << V[i][j][k];
				if(k!=V[i][j].size()-1)
				{
					cout << ",";
				}
			}
			cout << "}";
			if(j!=V[i].size()-1)
			{
				cout << ",";
			}
		}
		cout << "}\n";
		
	}
}

LL nCr(int n, int r)
{
	if(r == 0)
	{
		return 1ll * n;
	}

	return 1ll* n * nCr(n-1, r-1) / r;
}
	
int p[10] = {0};
LL fill(int i)
{
	LL ret = 0ll;
	REP(j,i)
	{
		REP(k,V[j].size())
		{
			if(V[j][k].size > 6)
			{
				continue;
			}

			int q[10] = {0};
			q[0] = 6-V[j][k].size();
			REP(l,V[j][k].size())
			{
				++q[V[j][k][l]];
			}

			LL val = 720ll;
			REP(l,10)
			{
				if(q[l])
				{
					val *= nCr(p[l], q[l]);
				}
			}

			ret += val;
		}
	}
}

int main()
{
	init();

	int M = SI;
	VI v;
	v.PB(0);
	int i = 0;
	while(i < v.size())
	{
		if(v[i]*10+4 <= M)
		{
			v.PB(v[i]*10+4);
		}
		
		if(v[i]*10+7 <= M)
		{
			v.PB(v[i]*10+7);
		}

		++i;
	}

	FOR(i,1,v.size())
	{
		int cnt = 0, x = v[i];
		while(x)
		{
			++cnt;
			x /= 10;
		}

		++p[cnt];
	}

	p[0] = M;
	FOR(i,1,10)
	{
		p[0] -= p[i];
	}

	LL mod = 1000000007ll, ans = 0ll;
	FOR(i,1,10)
	{
		ans += 1ll*p[i] * fill(i); 
	}

	return 0;
}
