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

class MagicalGirl {
public:
	double maxExpectation(int, vector <int>, vector <int>, vector <int>);
};
int sz;
double f(int i, int strength, int M, VI &day, VI &win, VI &gain)
{
	if(i == sz)
	{
		return day[sz-1]+strength;
	}

	if(i == 0) 
	{
		strength -= day[i];
		if(strength <= 0)
		{
			strength += day[i];
			return strength;
		}
	}
	else
	{
		strength -= (day[i]-day[i-1]);
		if(strength <= 0)
		{
			strength += (day[i]-day[i-1]);
			return strength;
		}
	}

	double p1 = ((double)win[i])/100.00 * f(i+1, MIN(strength+gain[i], M), M, day, win, gain) + (1.0 - ((double)win[i])/100.00) * day[i];

	double p2 = f(i+1, strength, M, day, win, gain);

	return max(p1, p2);
}

double MagicalGirl::maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain) {
	sz = day.size();
	REP(i,sz)
	{
		FOR(j,i+1,sz)
		{
			if(day[i] > day[j] || (day[i] == day[j] && win[i] < win[j]))
			{
				swap(day[i], day[j]);
				swap(win[i], win[j]);
				swap(gain[i], gain[j]);
			}
		}
	}

/*	REP(i,sz)
	{
		cout << day[i] << " " << win[i] << " " << gain[i] << endl;
	}
*/
	return f(0, M, M, day, win, gain);
}


double test0() {
	int p0 = 2;
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {75};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	MagicalGirl * obj = new MagicalGirl();
	clock_t start = clock();
	double my_answer = obj->maxExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 2.5;
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
	int p0 = 10;
	int t1[] = {5,5,5,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100,100,100,100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,1,1,1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	MagicalGirl * obj = new MagicalGirl();
	clock_t start = clock();
	double my_answer = obj->maxExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 14.0;
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
	int p0 = 10;
	int t1[] = {5,5,5,5,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {40,80,60,20,0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {10,10,10,10,10};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	MagicalGirl * obj = new MagicalGirl();
	clock_t start = clock();
	double my_answer = obj->maxExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 13.0;
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
	int p0 = 2;
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	MagicalGirl * obj = new MagicalGirl();
	clock_t start = clock();
	double my_answer = obj->maxExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 2.0;
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
	int p0 = 20;
	int t1[] = {2,13,8,7,9,4,6,21};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {18,83,75,23,45,23,10,98};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {10,9,8,10,7,16,13,20};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	MagicalGirl * obj = new MagicalGirl();
	clock_t start = clock();
	double my_answer = obj->maxExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 35.908;
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
double test5() {
	int p0 = 11;
	int t1[] = {10,20,30,40,50,60,70,80,90};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100,100,100,100,100,100,100,100,100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {10,10,10,10,10,10,10,10,10};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	MagicalGirl * obj = new MagicalGirl();
	clock_t start = clock();
	double my_answer = obj->maxExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 101.0;
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
double test6() {
	int p0 = 100000;
	int t1[] = {1000000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {100000};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	MagicalGirl * obj = new MagicalGirl();
	clock_t start = clock();
	double my_answer = obj->maxExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 100000.0;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
