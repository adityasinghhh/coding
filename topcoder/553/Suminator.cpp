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

class Suminator {
public:
	int findMissing(vector <int>, int);
};

int eval(VI &v, int w)
{
	stack<int> s;
	REP(i, 100)
	{
		s.push(0);
	}

	int sz = v.size();
	REP(i,sz)
	{
		if(v[i] == 0)
		{
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();

			s.push(x+y);
		}
		else
		{
			s.push(v[i]);
		}
	}

	return s.top();
}

bool check(VI v, int w, int m, int index)
{
	v[index] = m;

	int top = eval(v, w);

	printf("%d: %d: %d\n", w, m, top);

	return top < w;
}

bool put(VI v, int w, int index)
{
	v[index] = 0;

	int top = eval(v, w);

	return top == w;
}


int Suminator::findMissing(vector <int> v, int w) {

	int sz = v.size();
	if(sz == 1)
	{
		return w;
	}

	if(sz == 2)
	{
		if(v[0] == -1)
		{
			if(v[1] == 0)
			{
				return w;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			if(v[0] == w)
			{
				return 0;
			}
			else
			{
				return w;
			}
		}
	}

	int index = 0;
	REP(i,sz)
	{
		if(v[i] == -1)
		{
			index = i;
			break;
		}
	}

	int cnt = 0;
	FOR(i, index+1, sz)
	{
		if(v[i] > 0)
		{
			++cnt;
		}
	}

	if(cnt >= 2)
	{
		return -1;
	}

	v[index] = 0;
	int ret = eval(v, w);
	if(ret == w)
	{
		return 0;
	}


}


double test0() {
	int t0[] = {7,-1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 10;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
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
double test1() {
	int t0[] = {100, 200, 300, 0, 100, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 600;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
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
double test2() {
	int t0[] = {-1, 7, 3, 0, 1, 2, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 13;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
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
double test3() {
	int t0[] = {-1, 8, 4, 0, 1, 2, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 16;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
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
double test4() {
	int t0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1000000000;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
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
double test5() {
	int t0[] = {7, -1, 3, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
