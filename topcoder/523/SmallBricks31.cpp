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
#include<cstring>

using namespace std;

class SmallBricks31 {
public:
	int countWays(int, int);
};

long long base = 100000000;
long long dp[2][110][110], a[110][110];
long long W, H;

void print() { int i, j; for(i=0; i<H; ++i) { for(j=0; j<W; ++j) { printf("%lld ", a[i][j]); } printf("\n"); } printf("-------------\n"); }

long long f(int i, int j)
{
	if(j >= W) { ++i; j = 0; }

	if(i == H) { return 0; }

	int k = (i == 0 ? 1 : a[i-1][j]);

	long long &m = dp[k][i][j]; if(m != -1) { return m; }

	long long cnt = 0;

	if(j < W)   { if(i != 0) { if(a[i-1][j] == 1) { a[i][j] = 1; print(); cnt = 1 + f(i, j+1); } } else { a[i][j] = 1; print(); cnt = 1 + f(i, j+1); } }
	if(j < W-1) { if(i != 0) { if(a[i-1][j] == 1 && a[i-1][j+1] == 1) { a[i][j] = a[i][j+1] = 1; print(); cnt += 1 + f(i, j+2); } } else { a[i][j] = a[i][j+1] = 1; print(); cnt += 1 + f(i, j+2); } }
	if(j < W-2) { if(i != 0) { if(a[i-1][j] == 1 && a[i-1][j+1] == 1) { print(); a[i][j] = a[i][j+1] = a[i][j+2] = 1; cnt += 1 + f(i, j+3); } } else { print(); a[i][j] = a[i][j+1] = a[i][j+2] = 1; cnt += 1 + f(i, j+3); } }

	a[i][j] = a[i][j+1] = a[i][j+2] = 0; cnt += f(i, j+1);

	printf("Count for %d, %d is %lld\n", i, j, cnt);

	return m = cnt%base;
}

int SmallBricks31::countWays(int w, int h) {
	memset(dp, -1, sizeof dp);
	memset(a, 0, sizeof a);
	W = w; H = h;

	return (int)((f(0, 0)+1)%base);
}


double test0() {
	int p0 = 1;
	int p1 = 3;
	SmallBricks31 * obj = new SmallBricks31();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	int p1 = 1;
	SmallBricks31 * obj = new SmallBricks31();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 13;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	int p1 = 2;
	SmallBricks31 * obj = new SmallBricks31();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 84;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 4;
	int p1 = 9;
	SmallBricks31 * obj = new SmallBricks31();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 132976888;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 5;
	int p1 = 5;
	SmallBricks31 * obj = new SmallBricks31();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 11676046;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
