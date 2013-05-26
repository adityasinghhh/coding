#include <vector>
#include <cstring>
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

class MagicalSquare {
public:
	long long getCount(vector <string>, vector <string>);
};

vector<string> rs, cs;
string a[3][3];

bool check()
{
	for(int i = 0; i<3; ++i) { for(int j = 0; j<3; j++) { cout << a[i][j] << " "; } cout << endl; } 

	string s0 = a[0][0] + a[0][1] + a[0][2]; if(s0 != rs[0]) { return false; }
	string s1 = a[1][0] + a[1][1] + a[1][2]; if(s1 != rs[1]) { return false; }
	string s2 = a[2][0] + a[2][1] + a[2][2]; if(s2 != rs[2]) { return false; }

	s0 = a[0][0] + a[1][0] + a[2][0]; if(s0 != cs[0]) { return false; }
	s1 = a[0][1] + a[1][1] + a[2][1]; if(s0 != cs[1]) { return false; }
	s2 = a[0][2] + a[1][2] + a[2][2]; if(s0 != cs[2]) { return false; }

	return true;
}

long long dp[3][51][51];
long long f(int r, int ii, int jj)
{
	printf("%d %d %d\n", r, ii, jj);

	long long &m = dp[r][ii][jj]; if(m != -1) { return m; }

	if(r == 3) { if(check()) { return m = 1ll; } return m = 0ll; }

	string s = rs[r];
	int l = s.length(), i, j, k;
	long long ans = 0ll;
	printf("%s: %d\n", s.c_str(), l);
	for(i = 0; i<=l; i++)
		for(j=i; j<=l; j++)
		{
			a[r][0] = s.substr(0, i);
			a[r][1] = s.substr(i, j-i);
			a[r][2] = s.substr(j, l-j);

			cout << "(" << r << "," << i << "," << j << "): " << a[r][0] << " " << a[r][1] << " " << a[r][2] << endl; 

			ans += f(r+1, i, j);
		}

	return m = ans;
}

long long MagicalSquare::getCount(vector <string> rowStrings, vector <string> columnStrings) {
	rs = rowStrings; cs = columnStrings;

	memset(dp, -1, sizeof dp);

	return f(0, 0, 0);
}


double test0() {
	string t0[] = {"f", "o", "x"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"f", "o", "x"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MagicalSquare * obj = new MagicalSquare();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1LL;
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
	string t0[] = {"x", "x", "x"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"x", "", "xx"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MagicalSquare * obj = new MagicalSquare();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 3LL;
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
	string t0[] = {"cd", "cd", "cd"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"dvd", "dvd", "dvd"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MagicalSquare * obj = new MagicalSquare();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
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
	string t0[] = {"abab", "ab", "abab"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"abab", "ab", "abab"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MagicalSquare * obj = new MagicalSquare();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 11LL;
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
	string t0[] = {"qwer", "asdf", "zxcv"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"qaz", "wsx", "erdfcv"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MagicalSquare * obj = new MagicalSquare();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1LL;
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
