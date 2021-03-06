#include<algorithm>
#include<sstream>
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

class EllysFiveFriends {
public:
	int getZero(vector <int>);
};

LL BASE =  1000000007ll;
map<string, int> m;
map<string, int>::iterator it;
VI v;
int f()
{
	ostringstream s(ostringstream::out);
	REP(i,5)
	{
		s << v[i] << ",";
	}

	//it = m.find(v); if(it != m.end()) { return it->second; }
	it = m.find(s.str()); if(it != m.end()) { return it->second; }

	REP(i,5)
	{
		if(!v[i] && v[(i+1)%5] && !v[(i+2)%5])
		{
			return m[s.str()] = 0;
		}
	}

	bool flag = false;
	REP(i,5)
	{
		if(v[i])
		{
			flag = true;
			break;
		}
	}

	if(!flag)
	{
		return m[s.str()] = 1;
	}

	LL cnt = 0ll;
	REP(i,5)
	{
		if(v[i] && v[(i+1)%5])
		{
			if(v[i]&1)
			{
				if(v[(i+1)%5]&1)
				{
					--v[i];
					--v[(i+1)%5];
					cnt += f();
					++v[i];
					++v[(i+1)%5];

					v[i] /= 2;
					v[(i+1)%5] /= 2;
					cnt += f();
					v[i] *= 2;
					++v[i];
					v[(i+1)%5] *= 2;
					++v[(i+1)%5];
				}
				else
				{
					v[i] /= 2;
					v[(i+1)%5] /= 2;
					cnt += f();
					v[i] *= 2;
					++v[i];
					v[(i+1)%5] *= 2;
				}
			}
			else
			{
				if(v[(i+1)%5]&1)
				{
					v[i] /= 2;
					v[(i+1)%5] /= 2;
					cnt += f();
					v[i] *= 2;
					v[(i+1)%5] *= 2;
					++v[(i+1)%5];
				}
				else
				{
					v[i] /= 2;
					v[(i+1)%5] /= 2;
					cnt += f();
					v[i] *= 2;
					v[(i+1)%5] *= 2;
				}
			}
		}
	}
	
	return m[s.str()] = (int)(cnt%BASE);
}

int EllysFiveFriends::getZero(vector <int> numbers) {

	v = numbers;

	return f();	
}


double test0() {
	int t0[] = {5, 1, 1, 2, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysFiveFriends * obj = new EllysFiveFriends();
	clock_t start = clock();
	int my_answer = obj->getZero(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {2, 1, 1, 1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysFiveFriends * obj = new EllysFiveFriends();
	clock_t start = clock();
	int my_answer = obj->getZero(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {3, 4, 1, 4, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysFiveFriends * obj = new EllysFiveFriends();
	clock_t start = clock();
	int my_answer = obj->getZero(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 520;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {42, 666, 1337, 666, 42};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysFiveFriends * obj = new EllysFiveFriends();
	clock_t start = clock();
	int my_answer = obj->getZero(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 549119981;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {8792, 9483, 6787, 9856, 6205};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysFiveFriends * obj = new EllysFiveFriends();
	clock_t start = clock();
	int my_answer = obj->getZero(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 165501353;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {10000, 10000, 10000, 10000, 10000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysFiveFriends * obj = new EllysFiveFriends();
	clock_t start = clock();
	int my_answer = obj->getZero(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 952019520;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
