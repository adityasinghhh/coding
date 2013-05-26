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

#define MAX(a,b) a<b?b:a
using namespace std;

class PointErasingTwo {
public:
	int getMaximum(vector <int>);
};

int PointErasingTwo::getMaximum(vector <int> y) {

	int maxi = -1, sz = y.size(), cnt, i, j, k;
	for(i=0; i<sz; ++i) 
	{ 
		for(j=i+1; j<sz; ++j)
		{
			if(y[i] < y[j]) { continue; }

			cnt = 0;
			for(k=i+1; k<j; ++k)
			{
				if(y[j] < y[k] && y[k] < y[i])
					++cnt;
			}
			maxi = MAX(maxi, cnt);
		}
	}
	
	for(i=0; i<sz; ++i) 
	{ 
		for(j=i+1; j<sz; ++j)
		{
			if(y[i] > y[j]) { continue; }

			cnt = 0;
			for(k=i+1; k<j; ++k)
			{
				if(y[j] > y[k] && y[k] > y[i])
					++cnt;
			}
			maxi = MAX(maxi, cnt);
		}
	}

	return maxi;
}


double test0() {
	int t0[] = { 1, 2, 1, 1, 0, 4, 3 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PointErasingTwo * obj = new PointErasingTwo();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	int t0[] = { 0, 1 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PointErasingTwo * obj = new PointErasingTwo();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	int t0[] = { 0, 1, 2, 3, 4 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PointErasingTwo * obj = new PointErasingTwo();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
double test3() {
	int t0[] = { 10, 19, 10, 19 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PointErasingTwo * obj = new PointErasingTwo();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
double test4() {
	int t0[] = { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PointErasingTwo * obj = new PointErasingTwo();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
