#include <vector>
#include <climits>
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

class TallPeople {
public:
	vector <int> getPeople(vector <string>);
};

vector <int> TallPeople::getPeople(vector <string> v) {
	vector<int> ret;

	vector<vector<int> > h;
	int r = v.size(), c;
	for(int i = 0; i<r; ++i)
	{
		vector<int> temp; h.push_back(temp);
		istringstream s(v[i]);
		int x;
		c = 0;
		while(s >> x)
		{
			h[i].push_back(x);
			++c;
		}
	}	

	int maxi = -1;
	for(int i=0; i<r; ++i)
	{
		int mini = INT_MAX;
		for(int j=0; j<c; ++j)
		{
			mini = min(mini , h[i][j]);
		}
		maxi = max(maxi, mini);
	}

	int mini = INT_MAX;
	for(int j=0; j<c; ++j)
	{
		int maxi = -1;
		for(int i=0; i<r; ++i)
		{
			maxi = max(maxi, h[i][j]);
		}
		mini = min(maxi, mini);
	}

	ret.push_back(maxi);
	ret.push_back(mini);

	return ret;
}


double test0() {
	string t0[] = {"9 2 3",
 "4 8 7"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TallPeople * obj = new TallPeople();
	clock_t start = clock();
	vector <int> my_answer = obj->getPeople(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = { 4,  7 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"1 2",
 "4 5",
 "3 6"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TallPeople * obj = new TallPeople();
	clock_t start = clock();
	vector <int> my_answer = obj->getPeople(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = { 4,  4 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"1 1",
 "1 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TallPeople * obj = new TallPeople();
	clock_t start = clock();
	vector <int> my_answer = obj->getPeople(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = { 1,  1 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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
