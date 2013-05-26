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
#include<sstream>
#include<utility>
#include<vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef pair<double,double> PD;

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

class TurtleSpy {
public:
	double maxDistance(vector <string>);
};

vector<int> D, V;
int sz;
LL FINAL;
void init(vector<string> &inp)
{
	D.clear();
	V.clear();
	sz = inp.size();
	REP(i,sz)
	{
		istringstream sin(inp[i]);

		string a;
		int b;
		sin >> a >> b;

		D.PB(a[0]);
		V.PB(b);
	}

	FINAL = 0ll;
	REP(i,sz)
	{
		FINAL |= (1<<i);
	}
}

double distance(double x1, double y1, double ang1, double x2, double y2, double ang2)
{
	return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

map<LL, pair<double, PD> > m;
map<LL, pair<double, PD> >::iterator it;
pair<double, PD> f(LL bitmask, double x, double y, double ang)
{
	it = m.find(bitmask);
	if(it != m.end())
	{
		return it->second;
	}

	if(bitmask == FINAL)
	{
		return MP(ang, MP(0.0, 0.0));
	}

	cout << bitmask << endl;
	double maxi = -1.0;
	pair<double, PD> ret;
	REP(i,sz)
	{
		if((bitmask&(1<<i)) == (1<<i))
		{
		}
		else
		{
			bitmask |= (1<<i);
			if(D[i] == 'r')      { ang += V[i]; }
			else if(D[i] == 'l') { ang -= V[i]; }
			else if(D[i] == 'f') { x += V[i]*cos(ang); y += V[i]*sin(ang); }
			else                 { x -= V[i]*cos(ang); y -= V[i]*sin(ang); }
			
			pair<double, PD> p = f(bitmask, x, y, ang);
			
			if(D[i] == 'r')      { ang -= V[i]; }
			else if(D[i] == 'l') { ang += V[i]; }
			else if(D[i] == 'f') { x -= V[i]*cos(ang); y -= V[i]*sin(ang); }
			else                 { x += V[i]*cos(ang); y += V[i]*sin(ang); }
			bitmask &= ~(1<<i);

			double d = distance(x, y, ang, p.second.first, p.second.second, p.first);

			printf("%lf\n", d);
			if(d > maxi)
			{
				maxi = d;
				ret = p;
			}
		}
	}

	return m[bitmask] = ret;
}

double TurtleSpy::maxDistance(vector <string> inp) {
	init(inp);

	REP(i,sz)
	{
		printf("%c %d\n", D[i], V[i]);
	}

	int dp[sz+1][360]; FILL(dp, 0);
	dp[0][0] = 1;
	int f = 0, b = 0;
	FOR(i,1,sz+1)
	{
		REP(j,360)
		{
			if(dp[i-1][j])
			{
				dp[i][j] = 1;
				if(D[i-1] == 'r')
				{
					printf("Right %d\n", V[i-1]);
					dp[i][(j+V[i-1])%360] = 1;
				}
				else if(D[i-1] == 'l')
				{
					printf("Left %d\n", V[i-1]);
					int ang = j-V[i-1];
					while(ang < 0)
					{
						ang += 360;
					}
					dp[i][ang] = 1;
				}
			}
//			printf("%d ", dp[i-1][j]);
		}
//		printf("\n");

		if(D[i-1] == 'f')
		{
			f += V[i-1];
		}
		else if(D[i-1] == 'b')
		{
			b += V[i-1];
		}

	}

	int mini = INT_MAX;
	REP(j,360)
	{
		if(dp[sz][j])
		{
			int x = ABS(180-j);
			printf("%d:%d:%d ", mini,j, x);
			mini = MIN(mini, x);
		}
	}
	printf("\n");

	if(mini == INT_MAX) { mini = 0; }

	printf("%d %d %d\n", f, b, mini);

	double x = f, y = 0.0, ang = M_PI/180.0*mini;
	x += b*cos(ang);
	y += b*sin(ang);

	printf("%lf %lf %lf %lf\n", x, y, cos(mini), sin(mini));

	double d = sqrt(x*x + y*y);

	return d;
}


double test0() {
	string t0[] = {"forward 100", "backward 100", "left 90" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TurtleSpy * obj = new TurtleSpy();
	clock_t start = clock();
	double my_answer = obj->maxDistance(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 141.4213562373095;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"left 45", "forward 100", "right 45", "forward 100"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TurtleSpy * obj = new TurtleSpy();
	clock_t start = clock();
	double my_answer = obj->maxDistance(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 200.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TurtleSpy * obj = new TurtleSpy();
	clock_t start = clock();
	double my_answer = obj->maxDistance(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 40.58520737741619;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
