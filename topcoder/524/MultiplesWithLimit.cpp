#include <vector>
#include<queue>
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

class MultiplesWithLimit {
public:
	string minMultiples(int, vector <int>);
};

string s, nn;
int n;

void stringify()
{
	char a[10000];
	int x = n, i = 0;
	while(x)
	{
		a[i++] = x%10 + '0';
		x /= 10;
	}
	a[i] = 0;

	for(int j=0; j<i/2; j++)
		swap(a[i], a[j]);

	nn = a;
}

bool lless()
{
	if(s.length() > 5) return false;

	int x = 0, i = 0, l = s.length();
	
	while(i < l)
	{
		x = x*10 + s[i++] - '0';
	}

	return x < n;
}

bool divisible()
{
	if(lless()) { return false; }

	int l = s.length(), i = 0, m = 0;

	while(i < l)
	{
		m = m*10 + s[i] - '0';
		if(m > n)
		{
			m = m%n;
		}
		i++;
	}

	return m == 0;
}

char a[1000000];

string MultiplesWithLimit::minMultiples(int N, vector <int> forbiddenDigits) {

	stringify();

	n = N;
	vector<int> f;
	queue<string> q;
	int i, j;

	for(i=0; i<10; i++) 
	{ 
		for(j=0; j < forbiddenDigits.size(); j++) { if(i == forbiddenDigits[j]) { break; } }
		if(j == forbiddenDigits.size()) { f.push_back(i); }
	}

	for(i=0; i<f.size(); i++) { a[0] = f[i]+'0'; a[1] = 0; s = a; q.push(a); }

	while(!q.empty())
	{
		s = q.front(); q.pop();
		cout<<s<<endl;

		if(s.length() > 10) { continue; }

		if(divisible()) { break; }

		for(i=0; i<f.size(); i++)
		{
			a[0] = f[i] + '0'; a[1] = 0;
			s = s + a;
			q.push(s);
		}
	}

	if(q.empty()) { return "IMPOSSIBLE"; }

	if(s.length() < 9) { return s; }
	
	int l = s.length();
	a[0] = s[0]; a[1] = s[1]; a[2] = s[2];
	a[3] = '.'; a[4] = '.'; a[5] = '.';
	a[6] = s[l-3]; a[7] = s[l-2]; a[8] = s[l-1];
	a[9] = '('; 
	i = 0;
	char b[1000];
	while(l) { b[i++] = l%10 + '0'; } b[i] = 0;
	j = 10;
	for(int k = i-1; k>=0; --k) { a[j++] = b[k]; }
	a[j++] = ' ';
	a[j++] = 'd';
	a[j++] = 'i';
	a[j++] = 'g';
	a[j++] = 'i';
	a[j++] = 't';
	a[j++] = 's';
	a[j++] = ')';
	a[j] = 0;

	return s = a;
}


double test0() {
	int p0 = 8;
	int t1[] = {2,3,4,5,6,7,8,9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MultiplesWithLimit * obj = new MultiplesWithLimit();
	clock_t start = clock();
	string my_answer = obj->minMultiples(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "1000";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 9;
	int t1[] = {1,3,4,5,6,7,8,9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MultiplesWithLimit * obj = new MultiplesWithLimit();
	clock_t start = clock();
	string my_answer = obj->minMultiples(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "222...222(9 digits)";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 524;
	int t1[] = {5,2,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MultiplesWithLimit * obj = new MultiplesWithLimit();
	clock_t start = clock();
	string my_answer = obj->minMultiples(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "3668";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 10000;
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MultiplesWithLimit * obj = new MultiplesWithLimit();
	clock_t start = clock();
	string my_answer = obj->minMultiples(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 1;
	int t1[] = {0,1,2,3,4,5,6,7,8,9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MultiplesWithLimit * obj = new MultiplesWithLimit();
	clock_t start = clock();
	string my_answer = obj->minMultiples(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
