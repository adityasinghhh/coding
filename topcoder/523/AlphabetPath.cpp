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

class AlphabetPath {
public:
	string doesItExist(vector <string>);
};

vector<string> a;
int r, c;

bool f(int i, int j)
{
	if(a[i][j] == 'Z') { return true; }

	if(i != 0 && a[i-1][j] != '.' && a[i-1][j] == a[i][j]+1) { if(f(i-1, j)) { return true; } }
	if(j != 0 && a[i][j-1] != '.' && a[i][j-1] == a[i][j]+1) { if(f(i, j-1)) { return true; } }
	if(i != r-1 && a[i+1][j] != '.' && a[i+1][j] == a[i][j]+1) { if(f(i+1, j)) { return true; } }
	if(j != c-1 && a[i][j+1] != '.' && a[i][j+1] == a[i][j]+1) { if(f(i, j+1)) { return true; } }

	return false;
}

string AlphabetPath::doesItExist(vector <string> letterMaze) {
	r = letterMaze.size(); c = letterMaze[0].length();
	int i, j;

	a = letterMaze;

	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			if(letterMaze[i][j] == 'A') 
			{
				if(f(i, j))
				{
					return "YES";
				}
			}
		}
	}

	return "NO";
}


double test0() {
	string t0[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AlphabetPath * obj = new AlphabetPath();
	clock_t start = clock();
	string my_answer = obj->doesItExist(p0);
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
	string t0[] = {"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AlphabetPath * obj = new AlphabetPath();
	clock_t start = clock();
	string my_answer = obj->doesItExist(p0);
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
	string t0[] = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AlphabetPath * obj = new AlphabetPath();
	clock_t start = clock();
	string my_answer = obj->doesItExist(p0);
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
	string t0[] = {"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AlphabetPath * obj = new AlphabetPath();
	clock_t start = clock();
	string my_answer = obj->doesItExist(p0);
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
double test4() {
	string t0[] = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AlphabetPath * obj = new AlphabetPath();
	clock_t start = clock();
	string my_answer = obj->doesItExist(p0);
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
