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

class EllysRivers {
public:
	double getMin(int, int, vector <int>, vector <int>);
};

int L, W, N;
VI w, s;
double dp[100001][51];
int mark[100001][51];

double f(int i, int j)
{
	if(mark[i][j] != -1)
	{
		return dp[i][j];
	}
	
	if(j == N)
	{
		mark[i][j] = 1;
		return dp[i][j] = ((double)(L-i))/((double)W);
	}

	double mini = (double)INT_MAX;
	FOR(k,i,L+1)
	{
		double x = (double)abs(k-i);
		double y = (double)w[j];
		double d = sqrt(x*x + y*y);
		double t = d/((double)s[j]) + f(k, j+1);

		mini = min(mini, t);

		if(k != i)
		{
			t = ((double)(k-i))/((double)W) + f(k, j);

			mini = min(mini, t);
		}
	}

	mark[i][j] = 1;
	return dp[i][j] = mini;
}

double EllysRivers::getMin(int length, int walk, vector <int> width, vector <int> speed) {
	L = length;
	W = walk;
	w = width;
	N = w.size()+1;
	s = speed;

	FILL(mark, -1);

	REP(i,L+1)
	{
		dp[i][N] = ((double)(L-i))/((double)W);
	}

	REPD(j,N)
	{
		dp[L][j] = dp[L][j+1] + ((double)w[j])/((double)s[j]);
		REPD(i,L)
		{
			double t1 = dp[i+1][j] + ((double)1.0)/((double)W);
			double t2 = dp[i][j+1] + ((double)w[j])/((double)s[j]);

			dp[i][j] = min(t1, t2);
		}
	}

	REP(j,N+1)
	{
		REP(i,L+1)
		{
			printf("%lf ", dp[i][j]);
		}
		printf("\n");
	}

	return dp[0][0];
}


double test0() {
	int p0 = 10;
	int p1 = 3;
	int t2[] = {5, 2, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {5, 2, 7};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.231651964071508;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 10000;
	int p1 = 211;
	int t2[] = {911};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {207};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 48.24623664712219;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 1337;
	int p1 = 2;
	int t2[] = {100, 200, 300, 400};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {11, 12, 13, 14};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 128.57830549575695;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 77;
	int p1 = 119;
	int t2[] = {11, 12, 13, 14};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {100, 200, 300, 400};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.3842077071089629;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 7134;
	int p1 = 1525;
	int t2[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 214.6509731258811;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
