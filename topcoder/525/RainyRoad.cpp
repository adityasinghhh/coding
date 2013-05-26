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

class RainyRoad {
public:
	string isReachable(vector <string>);
};
vector<string> a;
int N;

bool mark[2][1000];

bool f(int i, int j)
{
	if(j == N-1)
	{
		if(i == 0) { return true; }
		if(a[0][j] == '.') { return true; }
		return false;
	}

	bool flag = false;

	if(i == 0)
	{
		if(!mark[i][j+1] && a[i][j+1] == '.') { mark[i][j+1] = 1; flag |= f(i, j+1); }
		if(!mark[i+1][j] && a[i+1][j] == '.') { mark[i+1][j] = 1; flag |= f(i+1, j); }
		if(!mark[i+1][j+1] && a[i+1][j+1] == '.') { mark[i+1][j+1] = 1; flag |= f(i+1, j+1); }
	}
	else
	{
		if(!mark[i][j+1] && a[i][j+1] == '.') { mark[i][j+1] = 1; flag |= f(i, j+1); }
		if(!mark[i-1][j] && a[i-1][j] == '.') { mark[i-1][j] = 1; flag |= f(i-1, j); }
		if(!mark[i-1][j+1] && a[i-1][j+1] == '.') { mark[i-1][j+1] = 1; flag |= f(i-1, j+1); }
	}

	return flag;
}

string RainyRoad::isReachable(vector <string> road) {
	a = road;
	N = road[0].length();

	for(int i=0; i<2; i++)
		for(int j=0; j<1000; j++)
			mark[i][j] = 0;

	if(f(0, 0)) { return "YES"; }
	return "NO";
	
}


double test0() {
	string t0[] = {".W.."
,"...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RainyRoad * obj = new RainyRoad();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {".W.."
,"..W."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RainyRoad * obj = new RainyRoad();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {".W..W.."
,"...WWW."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RainyRoad * obj = new RainyRoad();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {".."
,"WW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RainyRoad * obj = new RainyRoad();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {".WWWW."
,"WWWWWW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RainyRoad * obj = new RainyRoad();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {".W.W.W."
,"W.W.W.W"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RainyRoad * obj = new RainyRoad();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	string t0[] = {".............................................W."
,".............................................W."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RainyRoad * obj = new RainyRoad();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
