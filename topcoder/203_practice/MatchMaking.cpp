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

class MatchMaking {
public:
	string makeMatch(vector <string>, vector <string>, vector <string>, vector <string>, string);
};

string MatchMaking::makeMatch(vector <string> nw, vector <string> aw, vector <string> nm, vector <string> am, string qw) {
	int sz = nw.size(), l = aw[0].length();

	for(int i=0; i<sz; ++i)
	{
		for(int j=i+1; j<sz; ++j)
		{
			if(nw[i] > nw[j])
			{
				swap(nw[i], nw[j]);
				swap(aw[i], aw[j]);
			}

			if(nm[i] > nm[j])
			{
				swap(nm[i], nm[j]);
				swap(am[i], am[j]);
			}
		}
	}

	int mapping[sz+1];
	bool mark[sz+1]; for(int i=0; i<sz; ++i) { mark[i] = 0; }

	for(int i=0; i<sz; ++i)
	{
		int maxi = -1, maxii;
		for(int j=0; j<sz; ++j)
		{
			if(mark[j]) { continue; }

			int cnt = 0;
			for(int k=0; k<l; ++k)
			{
				if(aw[i][k] == am[j][k]) { ++cnt; }
			}
			if(maxi < cnt) { maxi = cnt; maxii = j; }
		}

//		printf("%s to %s\n", nw[i].c_str(), nm[maxii].c_str());

		mapping[i] = maxii;
		mark[maxii] = true;

		if(nw[i] == qw) { return nm[maxii]; }
	}
}


double test0() {
	string t0[] = {"Constance", "Bertha", "Alice"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"aaba", "baab", "aaaa"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"Chip", "Biff", "Abe"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"bbaa", "baaa", "aaab"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string p4 = "Bertha";
	MatchMaking * obj = new MatchMaking();
	clock_t start = clock();
	string my_answer = obj->makeMatch(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Biff";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"Constance", "Bertha", "Alice"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"aaba", "baab", "aaaa"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"Chip", "Biff", "Abe"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"bbaa", "baaa", "aaab"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string p4 = "Constance";
	MatchMaking * obj = new MatchMaking();
	clock_t start = clock();
	string my_answer = obj->makeMatch(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Chip";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"Ed", "Duff", "Chip", "Abe", "Biff"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string p4 = "Constance";
	MatchMaking * obj = new MatchMaking();
	clock_t start = clock();
	string my_answer = obj->makeMatch(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Duff";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"Ed", "Duff", "Chip", "Abe", "Biff"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string p4 = "Delilah";
	MatchMaking * obj = new MatchMaking();
	clock_t start = clock();
	string my_answer = obj->makeMatch(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Chip";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"Ed", "Duff", "Chip", "Abe", "Biff"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string p4 = "Emily";
	MatchMaking * obj = new MatchMaking();
	clock_t start = clock();
	string my_answer = obj->makeMatch(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Ed";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"anne", "Zoe"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"a", "a"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"bob", "chuck"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"a", "a"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string p4 = "Zoe";
	MatchMaking * obj = new MatchMaking();
	clock_t start = clock();
	string my_answer = obj->makeMatch(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "bob";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	string t0[] = {"F", "M", "S", "h", "q", "g", "r", "N", "U", "x", "H", "P",
 "o", "E", "R", "z", "L", "m", "e", "u", "K", "A", "w", "Q",
 "O", "v", "j", "a", "t", "p", "C", "G", "k", "c", "V", "B",
 "D", "s", "n", "i", "f", "T", "I", "l", "d", "J", "y", "b"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"abaabbbb", "bbaabbbb", "aaabaaab", "aabbaaaa", "baabbaab",
 "aaababba", "bbabbbbb", "bbbabbba", "aaabbbba", "aabbbaaa",
 "abbabaaa", "babbabbb", "aaaaabba", "aaaabbaa", "abbbabaa",
 "babababa", "abbaaaaa", "bbababba", "baaaaaba", "baaaaabb",
 "bbbbabba", "ababbaaa", "abbbabab", "baabbbaa", "bbbaabbb",
 "aababbab", "ababbabb", "abbaabba", "baabbabb", "aaabaaab",
 "aabbbaba", "aabaaabb", "abababba", "aabbaaaa", "aabbabaa",
 "bababaaa", "aabaaaab", "bbbbaabb", "baaababb", "abaabbab",
 "aabbbaaa", "baabbaba", "bbabbbaa", "aabbbbaa", "abbbaaab",
 "abababbb", "ababaaba", "bababaaa"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"f", "C", "v", "g", "Q", "z", "n", "c", "B", "o", "M", "F",
 "u", "x", "I", "T", "K", "L", "E", "U", "w", "A", "d", "t",
 "e", "R", "D", "s", "p", "q", "m", "r", "H", "j", "J", "V",
 "l", "a", "k", "h", "G", "y", "i", "P", "O", "N", "b", "S"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"bbbaabab", "bbabaabb", "ababbbbb", "bbbababb", "baababaa",
 "bbaaabab", "abbabbaa", "bbbabbbb", "aabbabab", "abbababa",
 "aababbbb", "bababaab", "aaababbb", "baabbaba", "abaaaaab",
 "bbaababa", "babaabab", "abbabbba", "ababbbab", "baabbbab",
 "babbaaab", "abbbbaba", "bbabbbba", "baaabaab", "ababbabb",
 "abbbaabb", "bbbbaabb", "bbbaaabb", "baabbaba", "bbabaaab",
 "aabbbaab", "abbbbabb", "bbaaaaba", "bbbababa", "abbaabba",
 "bababbbb", "aabaaabb", "babbabab", "baaaabaa", "ababbaba",
 "aaabaabb", "bbaaabaa", "baaaaabb", "bbaabaab", "bbababab",
 "aabaaaab", "aaaaabab", "aabbaaba"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string p4 = "U";
	MatchMaking * obj = new MatchMaking();
	clock_t start = clock();
	string my_answer = obj->makeMatch(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "x";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test7() {
	string t0[] = {"q", "M", "w", "y", "p", "N", "s", "r", "a", "H", "o", "n",
 "F", "m", "l", "b", "D", "j", "C", "u", "f", "I", "g", "L",
 "i", "x", "A", "G", "O", "k", "h", "d", "c", "E", "B", "v",
 "J", "z", "K", "e", "t"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"aabbaaabb", "baabababb", "bbaababba", "bbbaaaaaa", "abaaaabaa",
 "bababbbab", "abbaabbaa", "aabababbb", "bababaaaa", "abbababaa",
 "aabbbbbba", "bbabbabab", "babaabbba", "babbabbbb", "baaabbbbb",
 "baaabaaaa", "aaabbaaab", "abbaabbbb", "abbabbbab", "bbaaaabba",
 "babbaaabb", "aabbabbab", "baaababba", "ababaabab", "bbbaabbab",
 "aaaabbabb", "babaaaaaa", "abbbbaaab", "aabaaabba", "bbbaaaaba",
 "bbbbbbaab", "aabbaaabb", "aabaabbab", "aababaaba", "bbabbbbab",
 "abbabaaab", "babaaabbb", "bababbaaa", "aabbaabaa", "baaabbabb",
 "bbbbbbbbb"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"m", "k", "n", "q", "L", "E", "M", "l", "w", "x", "g", "e",
 "i", "z", "F", "r", "a", "h", "f", "D", "J", "K", "j", "v",
 "A", "t", "N", "y", "s", "c", "o", "p", "d", "b", "B", "G",
 "O", "I", "u", "C", "H"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"bbaaabbba", "bbaaaaaab", "abaaababb", "baaaabbbb", "abbbababa",
 "baaaaaaaa", "aabbbbbab", "aaaaabbba", "baabababb", "babaaabab",
 "baaababaa", "bbbbaabba", "bbaabbabb", "bbaaababb", "abbabbaba",
 "aababaaab", "abbbbbbaa", "aabbaabaa", "bbbaabbba", "abbabbaba",
 "aaabbbaaa", "bbaabaaaa", "aabababbb", "abbbbabab", "baaabbbba",
 "bababbbba", "aababbaab", "bbaabbaab", "bbbaaabbb", "babbbbabb",
 "ababababb", "babaaabab", "bbaaaaaba", "aaaaabaaa", "abbaaabbb",
 "bbbbababb", "baabababb", "bbaabaaaa", "aaababbbb", "abbbbbbba",
 "bbaabbaaa"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	string p4 = "o";
	MatchMaking * obj = new MatchMaking();
	clock_t start = clock();
	string my_answer = obj->makeMatch(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "C";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
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
	
	time = test7();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
