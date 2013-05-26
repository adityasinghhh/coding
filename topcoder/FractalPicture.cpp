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

class FractalPicture {
public:
	double getLength(int, int, int, int);
};

double X1, Y1, X2, Y2;

double distance(double x1, double y1, double x2, double y2)
{
	double x = x1-x2, y = y1-y2;
	return sqrt(x*x + y*y);
}

double f(int level, int flag, double x1, double y1, double x2, double y2)
{
	if(level > 500)
	{
		return 0.0;
	}

	if(flag == 1)
	{
	}
	else if(flag == -1)
	{
	}
	else
	{
		double ret = 0.0;

		if(Y2 < y2 || Y1 > y1)
		{
			ret = 0.0;
		}
		else
		{
			if(X1 < x1 && Y1 < y1 && X2 > x2 && Y2 > y2)
			{
				ret = distance(x1, y2, x2, y2);
			}
		}

		return ret + f(level+1,  0, x1, y1+2.0*(y2-y1)/3.0, x2, y2) 
		           + f(level+1, -1, x1, y1+2.0*(y2-y1)/3.0, x1-(y2-y1)/3.0, y1+2.0*(y2-y1)/3.0) 
		           + f(level+1, -1, x1, y1+2.0*(y2-y1)/3.0, x1+(y2-y1)/3.0, y1+2.0*(y2-y1)/3.0);
	}				
}

double FractalPicture::getLength(int x1, int y1, int x2, int y2) {
	X1 = x1;
	X2 = x2;
	Y1 = y1;
	Y2 = y2;
	
	return f(0, 0, 0.0, 0.0, 0.0, 81.0);
}


double test0() {
	int p0 = -1;
	int p1 = 0;
	int p2 = 1;
	int p3 = 53;
	FractalPicture * obj = new FractalPicture();
	clock_t start = clock();
	double my_answer = obj->getLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 53.0;
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
	int p0 = 1;
	int p1 = 1;
	int p2 = 10;
	int p3 = 10;
	FractalPicture * obj = new FractalPicture();
	clock_t start = clock();
	double my_answer = obj->getLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.0;
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
	int p0 = -10;
	int p1 = 54;
	int p2 = 10;
	int p3 = 55;
	FractalPicture * obj = new FractalPicture();
	clock_t start = clock();
	double my_answer = obj->getLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 21.0;
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
	int p0 = 14;
	int p1 = 45;
	int p2 = 22;
	int p3 = 54;
	FractalPicture * obj = new FractalPicture();
	clock_t start = clock();
	double my_answer = obj->getLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 2999.0;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
