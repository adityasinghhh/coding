#include<algorithm>
#include<assert.h>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=b-1;i>=a;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define LL long long int
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define ABS(a) a<0?-a:a

class SquaredSubsets {
public:
	long long countSubsets(int, vector <int>, vector <int>);
};

bool isInside(int x1, int y1, int x2, int y2, int p1, int p2) { return (x1 <= p1 && p1 <= x2 && y1 <= p2 && p2 <= y2); }

bool isNSquare(int n, int nxi, int nyi, int nxj, int nyj) { if(MAX(nxi, nyi) > n) { return false; } return n < nxj && n < nyj; }

long long SquaredSubsets::countSubsets(int n, vector <int> x, vector <int> y) {
	set<int> sx = set<int>(x.begin(), x.end());	set<int> sy = set<int>(y.begin(), y.end());
	sx.insert(INT_MAX);	sx.insert(INT_MIN);	sy.insert(INT_MAX);	sy.insert(INT_MIN);
	x = vector<int>(sx.begin(), sx.end());		y = vector<int>(sy.begin(), sy.end());






	
}


double test0() {
	int p0 = 5;
	int t1[] = {-5,0,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0,0,0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	SquaredSubsets * obj = new SquaredSubsets();
	clock_t start = clock();
	long long my_answer = obj->countSubsets(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 5LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 10;
	int t1[] = {-5,0,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0,0,0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	SquaredSubsets * obj = new SquaredSubsets();
	clock_t start = clock();
	long long my_answer = obj->countSubsets(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 5LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 100000000;
	int t1[] = {-1,-1,-1,0,1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-1,0,1,1,-1,0,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	SquaredSubsets * obj = new SquaredSubsets();
	clock_t start = clock();
	long long my_answer = obj->countSubsets(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 21LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 5;
	int t1[] = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	SquaredSubsets * obj = new SquaredSubsets();
	clock_t start = clock();
	long long my_answer = obj->countSubsets(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 66LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
	int t1[] = {-1,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0,0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	SquaredSubsets * obj = new SquaredSubsets();
	clock_t start = clock();
	long long my_answer = obj->countSubsets(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 3LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
