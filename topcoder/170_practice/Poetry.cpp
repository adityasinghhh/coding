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

class Poetry {
public:
	string rhymeScheme(vector <string>);
};

bool check(char ch, int i, int l)
{
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') { return true; }

	if(ch == 'y' && i != 0 && i != l-1) { return true; }

	return false;
}

string Poetry::rhymeScheme(vector <string> p) {
	int sz = p.size();
	int mark[sz+1];
	for(int i=0; i<sz; ++i) { mark[i] = -1; }

	for(int i=0; i<sz; ++i)
	{
		int l = p[i].length();
		for(int j=0; j<l; ++j)
		{
			if(p[i][j] >= 'A' && p[i][j] <= 'Z')
			{
				p[i][j] += 32;
			}
		}
	}

	for(int i=0; i<sz; ++i)
	{
		istringstream s(p[i]);
		string s1;

		bool flag = false; while(s >> s1) { flag = true; }

		if(!flag) { p[i] = ""; }
		else
		{
			int l = s1.length(), j=l-1;

			while(j >= 0 && !check(s1[j], j, l))
			{
				--j;
			}

			if(j == -1) { p[i] == ""; }
			else
			{
				while(j >= 0 && check(s1[j], j, l)) { --j; }

				if(j == -1)
				{
					p[i] = s1;
				}
				else
				{
					p[i] = s1.substr(j+1, l);
				}
			}
		}
	}

	int ch = 'a';
	for(int i = 0; i<sz; ++i)
	{
		printf("%d: %s\n", i, p[i].c_str());

		if(p[i].length() == 0) { mark[i] = 0; continue; }

		if(mark[i] != -1) { continue; }

		for(int j = i; j<sz; ++j)
		{
			if(p[i] == p[j])
			{
				mark[j] = ch;
			}
		}

		++ch;
		if(ch == 'z'+1) { ch = 'A'; }
	}

	string ret = "";
	for(int i = 0; i<sz; ++i)
	{
		if(mark[i]) { ret += mark[i]; }
		else
		{
			ret += " ";
		}
	}

	return ret;
}


double test0() {
	string t0[] = {"I hope this problem",
 "is a whole lot better than",
 "this stupid haiku"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Poetry * obj = new Poetry();
	clock_t start = clock();
	string my_answer = obj->rhymeScheme(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "abc";
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
	string t0[] = {"     ",
 "Measure your height",
 "AND WEIGHT      ",
 "said the doctor",
 "",
 "And make sure to take your pills",
 "   to   cure   your    ills",
 "Every",
 "DAY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Poetry * obj = new Poetry();
	clock_t start = clock();
	string my_answer = obj->rhymeScheme(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = " aab ccde";
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
	string t0[] = {"One bright day in the middle of the night",
 "Two dead boys got up to fight",
 "Back to back they faced each other",
 "Drew their swords and shot each other",
 "",
 "A deaf policeman heard the noise",
 "And came to arrest the two dead boys",
 "And if you dont believe this lie is true",
 "Ask the blind man he saw it too"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Poetry * obj = new Poetry();
	clock_t start = clock();
	string my_answer = obj->rhymeScheme(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "aabb cdef";
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
	string t0[] = {"",
 "",
 "",
 ""};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Poetry * obj = new Poetry();
	clock_t start = clock();
	string my_answer = obj->rhymeScheme(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "    ";
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
	string t0[] = {"This poem has uppercase letters",
 "In its rhyme scheme",
 "Alpha", "Blaster", "Cat", "Desert", "Elephant", "Frog", "Gulch", 
 "Horse", "Ireland", "Jam", "Krispy Kreme", "Loofah", "Moo", "Narf",
 "Old", "Pink", "Quash", "Rainbow", "Star", "Tour", "Uvula", "Very",
 "Will", "Xmas", "Young", "Zed", "deception", "comic", "grout",
 "oval", "cable", "rob", "steal", "steel", "weak"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Poetry * obj = new Poetry();
	clock_t start = clock();
	string my_answer = obj->rhymeScheme(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "abcdefghibjkblmnopqrstcuvwxyzABCbDEFG";
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
	string t0[] = {" ",
 "     ",
 "This poem",
 "         ",
 " ",
 " ",
 "",
 "Has lots of blank lines",
 " ",
 "      ",
 "                                            ",
 "         ",
 " ",
 "              ",
 "                                                  ",
 "  in      it           "};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Poetry * obj = new Poetry();
	clock_t start = clock();
	string my_answer = obj->rhymeScheme(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "  a    b       c";
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
	string t0[] = {"too bad   your",
 "     solution went   sour"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Poetry * obj = new Poetry();
	clock_t start = clock();
	string my_answer = obj->rhymeScheme(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "aa";
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
