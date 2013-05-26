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

#define LL long long int
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define lfscan(n) scanf("%lf",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=b-1;i>=a;--i)
#define REP(i,b) for(int i=0;i<b;++i)
#define REPD(i,b) for(int i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

class Over9000Rocks {
public:
	int countPossibilities(vector <int>, vector <int>);
};

bool mark[16000000];

int Over9000Rocks::countPossibilities(vector <int> l, vector <int> u) {
	vector<PI> v;
	REP(i,l.size())
	{
		vector<PI> v1;
		REP(j,v.size())
		{
			v1.PB(MP(v[j].first+l[i], v[j].second+u[i]));
		}

		REP(j,v1.size())
		{
			v.PB(v1[j]);
		}

		v.PB(MP(l[i], u[i]));
	}

	SORT(v);

	FILL(mark,0);
	int till = -1;
	REP(i,v.size())
	{
		if(till < v[i].first)
		{
			FOR(j,v[i].first,v[i].second+1)
			{
				mark[j] = 1;
			}
		}
		else if(till <= v[i].second)
		{
			FOR(j,till,v[i].second+1)
			{
				mark[j] = 1;
			}
		}

		till = max(till, v[i].second);
	}

	int cnt = 0;
	FOR(i,9001,16000000)
	{
		if(mark[i])
		{
			++cnt;
		}
	}

	return cnt;
}


double test0() {
	int t0[] = {9000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9001};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	int t0[] = {9000, 1, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9000, 2, 20};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 15;
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
	int t0[] = {1001, 2001, 3001, 3001};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1003, 2003, 3003, 3003};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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
	int t0[] = {9000,90000,1,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9000,90000,3,15};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 38;
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
//	int t0[] = {1,1,1,1,1,1};
	int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
//	int t1[] = {3,4,5,6,7,8};
	int t1[] = {1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
