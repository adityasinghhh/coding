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
#include<climits>

using namespace std;

class CorrectMultiplicationTwo {
public:
	int getMinimum(int, int, int);
};

#define MIN(a,b) a<b?a:b
#define ABS(a) a<0?-a:a

int abs(int a) { return a<0?-a:a; }

map<pair<pair<int, int>, int>, int> dp;

int CorrectMultiplicationTwo::getMinimum(int a, int b, int c) {

	if(a*b == c) { return 0; }

	pair<pair<int, int>, int> p = make_pair(make_pair(a, b), c); 

	if(dp[p]) { return dp[p]; }

	if(a*b < c) { int r1 = f(a+1, b, c); int r2 = f(a, b+1, c); int mini = MIN(r1, r2); return dp[p] = MIN(mini, c-a*b); }
	
	int r1 = f(a-1, b, c); int r2 = f(a, b-1, c); int mini = MIN(r1, r2); return dp[p] = MIN(mini, a*b-c); }
}

/*	if(a > b) { swap(a, b); }
	int cnt = 0;
	if(a*b == c) { return 0; } else
	if(a*b < c) 
	{
		while((a+1)*b < c) { ++a; ++cnt; printf("%d %d %d %d\n", a, b, a*b, c); }
		while(a*(b+1) < c) { ++b; ++cnt; printf("%d %d %d %d\n", a, b, a*b, c); }
		return cnt + (c-a*b);
	}

	while((a-1)*b > c) { --a; ++cnt; printf("%d %d %d %d\n", a, b, a*b, c); }
	while(a*(b-1) > c) { --b; ++cnt; printf("%d %d %d %d\n", a, b, a*b, c); }

	return cnt + (a*b-c);
}*/


double test0() {
	int p0 = 19;
	int p1 = 28;
	int p2 = 522;
	CorrectMultiplicationTwo * obj = new CorrectMultiplicationTwo();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
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
	int p0 = 10;
	int p1 = 30;
	int p2 = 500;
	CorrectMultiplicationTwo * obj = new CorrectMultiplicationTwo();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 11;
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
	int p0 = 111;
	int p1 = 111;
	int p2 = 12321;
	CorrectMultiplicationTwo * obj = new CorrectMultiplicationTwo();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
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
double test3() {
	int p0 = 1000;
	int p1 = 100;
	int p2 = 10;
	CorrectMultiplicationTwo * obj = new CorrectMultiplicationTwo();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1089;
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
double test4() {
	int p0 = 399;
	int p1 = 522;
	int p2 = 199999;
	CorrectMultiplicationTwo * obj = new CorrectMultiplicationTwo();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 24;
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
