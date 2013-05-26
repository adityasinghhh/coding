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

class KingdomAndDice {
public:
	double newFairness(vector <int>, vector <int>, int);
};

double KingdomAndDice::newFairness(vector <int> F, vector <int> S, int X) {
	SORT(F);
	SORT(S);

	int sz = F.size(), cnt = 0, cnt0 = 0;
	REP(i,sz)
	{
		if(F[i] == 0)
		{
			++cnt0;
			continue;
		}

		REP(j,sz)
		{
			if(F[i] > S[j])
			{
				++cnt;
			}
		}
	}

	if(F[0] != 0)
	{
		return (double)cnt/((double)sz*sz);
	}

	int want = sz*sz/2;

	if(cnt > want)
	{
		return (double)cnt/((double)sz*sz);
	}

	set<int> s;
	int maxi = -1;
	REP(i,sz)
	{
		s.insert(F[i]);
		s.insert(S[i]);

		maxi = MAX(maxi, F[i]);
		maxi = MAX(maxi, S[i]);
	}

	++maxi;
	maxi = MIN(maxi, X);

	REP(zz,cnt0)
	{
		if(want-cnt-sz > 0 && maxi <= X)
		{
			cnt += sz;
			s.insert(maxi);
			++maxi;
		}
		else
		{
			if(s.find(maxi) != s.end())
			{
				while(s.find(maxi) != s.end())
				{
					--maxi;
				}
			}

			int cnt1 = 0;
			REP(j,sz)
			{
				if(S[j] < maxi)
				{
					++cnt1;
				}
			}

			if(want-cnt-cnt1 > 0)
			{
				cnt += cnt1;
				s.insert(maxi);
				--maxi;
			}
			else
			{
			}
		}
	}

	return -1;
}


double test0() {
	int t0[] = {0, 2, 7, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6, 3, 8, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 12;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.4375;
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
	int t0[] = {0, 2, 7, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6, 3, 8, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 10;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.375;
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
	int t0[] = {0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5, 8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 47;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.5;
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
	int t0[] = {19, 50, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {26, 100, 37};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1000;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.2222222222222222;
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
	int t0[] = {6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 10000;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.49;
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
