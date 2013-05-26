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

class FoxAndPhotography {
public:
	int getMinimumSwaps(vector <int>, vector <int>);
};

VI f, b;
int sz, dp[20];
int F(int i)
{
	if(dp[i] != -1)
	{
		return dp[i];
	}

	VI f1, b1;
	int c = 0;
	FOR(j,i,sz)
	{
		if(f[j] < b[j])
		{
			++c;
		}

		f1.PB(f[j]);
		b1.PB(b[j]);
	}

	if(c == sz-i)
	{
		return dp[i] = 0;
	}

	int sz1 = f1.size();
	SORT(f1);
	SORT(b1);
	REP(j,sz1)
	{
		if(f1[j] >= b1[j])
		{
			return dp[i] = -2;
		}
	}

	VI prev = f;
	int mini = INT_MAX;
	FOR(j,i,sz)
	{
		c = 0;
		if(f[j] < b[i])
		{
			FORD(k,i+1,j+1)
			{
				++c;
				swap(f[k], f[k-1]);
			}
		}

		int x = F(i+1);
		if(x != -2)
		{
			mini = MIN(mini, x+c);
		}
	}

	if(mini == INT_MAX)
	{
		return dp[i] = -2;
	}

	return dp[i] = mini;
}

int FoxAndPhotography::getMinimumSwaps(vector <int> hf, vector <int> hb) {
	f = hf; b = hb;
	sz = b.size();

	FILL(dp,-1);

	return F(0);
}


double test0() {
	int t0[] = {140, 150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {160, 150};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FoxAndPhotography * obj = new FoxAndPhotography();
	clock_t start = clock();
	int my_answer = obj->getMinimumSwaps(p0, p1);
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
	int t0[] = {140, 140, 140, 140};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {190, 190, 190, 190};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FoxAndPhotography * obj = new FoxAndPhotography();
	clock_t start = clock();
	int my_answer = obj->getMinimumSwaps(p0, p1);
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
	int t0[] = {170, 170, 170};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {160, 170, 180};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FoxAndPhotography * obj = new FoxAndPhotography();
	clock_t start = clock();
	int my_answer = obj->getMinimumSwaps(p0, p1);
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
	int t0[] = {140, 141, 142, 143};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {144, 143, 142, 141};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FoxAndPhotography * obj = new FoxAndPhotography();
	clock_t start = clock();
	int my_answer = obj->getMinimumSwaps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int t0[] = {140, 170, 140, 170, 140, 170, 140, 170, 140, 170}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {180, 180, 180, 180, 180, 150, 150, 150, 150, 150};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FoxAndPhotography * obj = new FoxAndPhotography();
	clock_t start = clock();
	int my_answer = obj->getMinimumSwaps(p0, p1);
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
