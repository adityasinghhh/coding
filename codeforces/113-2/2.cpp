
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

double dist(double x1, double y1, double x2, double y2)
{
	double x = x1-x2, y = y1-y2;
	return sqrt(x*x + y*y);
}

double f(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double d1 = dist(x1, y1, x2, y2);
	double d2 = dist(x1, y1, x3, y3);
	double d3 = dist(x2, y2, x3, y3);

	double ang = (d1*d1 + d2*d2 - d3*d3)/2.0/d1/d2;
	return ang;
}

double f1(PI p1, PI p2, PI p3)
{
	return f((double)p1.first, (double)p1.second, (double)p2.first, (double)p2.second, (double)p3.first, (double)p3.second);
}

PI p;
double angle(PI p1)
{
	if(p1.first == p.first)
	{
		return M_PI/2.0;
	}

	return atan((double)(p1.second-p.second)/(double)(p1.first-p.first));
}

set<PI> s;
set<PI>::iterator it;
map<PI, int> m;
bool FLAG = true;
bool compare(PI p1, PI p2)
{
	double ang1 = angle(p1), ang2 = angle(p2);

	if(ang1 < 0.0) { ang1 += M_PI; }
	if(ang2 < 0.0) { ang2 += M_PI; }

	if(abs(ang1-ang2) < 0.0000001)
	{
		printf("Angles equal for (%d,%d) and (%d,%d)\n", p1.first, p1.second, p2.first, p2.second);
		it = s.find(p1); 
		if(it != s.end()) 
		{ 
			printf("(%d,%d) in s\n", p1.first, p1.second);
			FLAG = false; 
		}
		
		it = s.find(p2); 
		if(it != s.end()) 
		{ 
			printf("(%d,%d) in s\n", p2.first, p2.second);
			FLAG = false; 
		}
	}

	return ang1 <= ang2;
}

int main()
{
	int N = SI;
	VPI v;
	int x[N+1], y[N+1];
	REP(i,N)
	{
		x[i] = SI;
		y[i] = SI;
		s.insert(MP(x[i],y[i]));
		m[MP(x[i], y[i])] = i+1;
		v.PB(MP(x[i], y[i]));
	}

	int M = SI;
	int X[M+1], Y[M+1];
	bool flag = false;
	REP(i,M)
	{
		X[i] = SI;
		Y[i] = SI;

		it = s.find(MP(X[i], Y[i]));
		if(it != s.end())
		{
			flag = true;
		}
		
		v.PB(MP(X[i], Y[i]));
	}

	if(flag)
	{
		printf("NO\n");
		return 0;
	}

	p = v[0];
	int sz = v.size();
	FOR(i,1,sz)
	{
		if(p.second > v[i].second)
		{
			p = v[i];
		}
		else if(p.second == v[i].second && p.first > v[i].first)
		{
			p = v[i];
		}
	}

	it = s.find(p);
	if(it == s.end())
	{
		printf("NO\n");
		return 0;
	}

	VPI w;
	REP(i,sz)
	{
		if(v[i] == p) { continue; }
		w.PB(v[i]);
	}

	sort(w.begin(), w.end(), compare);

	if(FLAG == false)
	{
		printf("NO\n");
		return 0;
	}

	v.clear();
	v.PB(p);
	REP(i,sz-1)
	{
		v.PB(w[i]);
	}

/*	REP(i,sz)
	{
		printf("%d,%d ", v[i].first, v[i].second);
	}
	printf("\n");
*/

	stack<PI> st;
	st.push(v[0]); st.push(v[1]);
	flag = true;
	FOR(i,2,sz)
	{
		while(st.size() >= 2)
		{
			PI p1 = st.top(); st.pop();
			PI p2 = st.top(); st.pop();

			int d = (p1.first-p2.first)*(v[i].second-p2.second) - (p1.second-p2.second)*(v[i].first-p2.first);

//			printf("(%d,%d), (%d,%d), (%d,%d)\n", p2.first, p2.second, p1.first, p1.second, v[i].first, v[i].second);

			if(d == 0)
			{
//				printf("Here\n");
				st.push(p2);
				int cnt = 0;
				it = s.find(p1);   if(it != s.end()) { ++cnt; }
				it = s.find(p2);   if(it != s.end()) { ++cnt; }
				it = s.find(v[i]); if(it != s.end()) { ++cnt; }

				if(cnt == 2)
				{
					flag = false;
					break;
				}
			}
			else if(d < 0)
			{
				st.push(p2);
			}
			else
			{
				st.push(p2);
				st.push(p1);
				st.push(v[i]);
				break;
			}
		}
	}

	if(!flag)
	{
		printf("NO\n");
	}
	else if(st.size() == N)
	{
		while(!st.empty())
		{
			PI p = st.top(); st.pop();

			it = s.find(p);
			if(it == s.end())
			{
				printf("NO\n");
				return 0;
			}
		}
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}
