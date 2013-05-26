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

class FeudaliasBattle {
public:
	double getMinimumTime(vector <int>, vector <int>, vector <int>, vector <int>, int, int, int);
};

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double FeudaliasBattle::getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed) {
	int sz = siloX.size();
	double dist1[sz+1], dist2[sz+1];

	REP(i,sz)
	{
		dist1[i] = distance(baseX[0], baseY[0], siloX[i], siloY[i]);
		dist2[i] = distance(baseX[1], baseY[1], siloX[i], siloY[i]);
	}	

	double time[4];

	time[0] = takeOffTime + min(max(60.0*dist1[0]/missileSpeed, 60.0*rechargeTime + takeOffTime + 60.0*dist2[0]/missileSpeed), max(60.0*dist2[0]/missileSpeed, 60.0*rechargeTime + takeOffTime + 60.0*dist1[0]/missileSpeed));
	time[1] = takeOffTime + max(60.0*dist1[0]/missileSpeed, 60.0*dist2[1]/missileSpeed);
	time[2] = takeOffTime + max(60.0*dist2[0]/missileSpeed, 60.0*dist1[1]/missileSpeed);
	time[3] = takeOffTime + min(max(60.0*dist1[1]/missileSpeed, 60.0*rechargeTime + takeOffTime + 60.0*dist2[1]/missileSpeed), max(60.0*dist2[1]/missileSpeed, 60.0*rechargeTime + takeOffTime + 60.0*dist1[1]/missileSpeed));

	double mini = (double)LLONG_MAX;
	REP(i,4)
	{
		mini = min(time[i], mini);
		printf("%lf\n", time[i]/60.0);
	}
	return mini/60.0;
}


double test0() {
	int t0[] = {100, 500};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {100, 100};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100, 500};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {300, 300};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 6;
	int p5 = 10;
	int p6 = 1;
	FeudaliasBattle * obj = new FeudaliasBattle();
	clock_t start = clock();
	double my_answer = obj->getMinimumTime(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p7 = 200.1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {100, 100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {100, 500};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100, 500};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {300, 300};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 6;
	int p5 = 10;
	int p6 = 1;
	FeudaliasBattle * obj = new FeudaliasBattle();
	clock_t start = clock();
	double my_answer = obj->getMinimumTime(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p7 = 210.2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {100, 100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {100, 500};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100, 500};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {300, 300};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 6;
	int p5 = 20;
	int p6 = 20;
	FeudaliasBattle * obj = new FeudaliasBattle();
	clock_t start = clock();
	double my_answer = obj->getMinimumTime(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p7 = 22.4606797749979;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {401, 208};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {622, 603};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {51, 387};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {411, 828};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 59;
	int p5 = 518;
	int p6 = 1941;
	FeudaliasBattle * obj = new FeudaliasBattle();
	clock_t start = clock();
	double my_answer = obj->getMinimumTime(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p7 = 1.1111118724871378;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
