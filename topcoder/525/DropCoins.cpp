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

class DropCoins {
public:
	int getMinimum(vector <string>, int);
};

int DropCoins::getMinimum(vector <string> board, int K) {
	map<vector<string>, int> m;
	map<vector<string>, int>::iterator it;
	int r = board.size();
	int c = board[0].length();

	queue<pair<vector<string>, int> > q;
	pair<vector<string>, int> p;
	q.push(make_pair(board, 0));
	int i, j, cnt, n;
	vector<string> a, b;

	while(!q.empty())
	{
		p = q.front(); q.pop();
		a = p.first; n = p.second;

		cnt = 0;
		for(i=0; i<r; i++)
		{	
			printf("%s\n", a[i].c_str());
			for(j=0; j<c; j++)
				if(a[i][j] == 'o')
					++cnt;
		}
		printf("\n");

		if(cnt < K) { continue; }
		else if(cnt == K) { return n; }

		b = a;
		for(i = r-1; i>0; --i) { b[i] = b[i-1]; }
		for(j=0; j<c; ++j) { b[0][j] = '.'; }
		it = m.find(b); if(it == m.end()) { q.push(make_pair(b, n+1)); } m[b] = 1;

		b = a;
		for(i = 0; i<r-1; ++i) { b[i] = b[i+1]; }
		for(j=0; j<c; ++j) { b[r-1][j] = '.'; }
		it = m.find(b); if(it == m.end()) { q.push(make_pair(b, n+1)); } m[b] = 1;

		b = a;
		for(j = 0; j<c-1; ++j) 
			for(i=0; i<r; i++)
				b[i][j] = b[i][j+1];
		for(i=0; i<r; ++i) { b[i][c-1] = '.'; }
		it = m.find(b); if(it == m.end()) { q.push(make_pair(b, n+1)); } m[b] = 1;

		b = a;
		for(j = c-1; j>0; --j) 
			for(i=0; i<r; i++)
				b[i][j] = b[i][j-1];
		for(i=0; i<r; ++i) { b[i][0] = '.'; }
		it = m.find(b); if(it == m.end()) { q.push(make_pair(b, n+1)); } m[b] = 1;
	}

	return -1;
}


double test0() {
	string t0[] = {".o.."
,"oooo"
,"..o."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string t0[] = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 12;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = {"...."
,".oo."
,".oo."
,"...."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	string t0[] = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 12;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
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
double test4() {
/*	string t0[] = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
;*/
	string t0[] = {"oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooooooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo", "oooooooooooooo.ooooooooooooooo"};

	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1; //58;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 43; // 6;
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
