#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TheSimpleGame {
public:
	int count(int, vector <int>, vector <int>);
};

#define MIN(a,b) (a)<(b)?(a):(b)
#define ABS(a) (a)<0?-(a):(a)
#define REP(i,n) for(i=0;i<n;++i)

int f(int n, int i, int j)
{
	return MIN(ABS(n-i+n-j), MIN(ABS(n-i+j-1), MIN(ABS(i-1+n-j), ABS(i-1+j-1))));
}

int TheSimpleGame::count(int n, vector <int> x, vector <int> y) {
	
	int tot = 0, i;
	REP(i,x.size()) 
	{ 
		tot += f(n, x[i], y[i]);
	}	
	return tot;
}


double test0() {
	int p0 = 4;
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TheSimpleGame * obj = new TheSimpleGame();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int t1[] = {2, 2, 1, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2, 2, 3, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TheSimpleGame * obj = new TheSimpleGame();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 7;
	int t1[] = {7, 1, 7, 7, 1, 7, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {7, 1, 1, 1, 1, 7, 7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TheSimpleGame * obj = new TheSimpleGame();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
