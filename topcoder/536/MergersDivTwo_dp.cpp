#include<algorithm>
#include<assert.h>
#include<bitset>
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
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define LL long long int

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define PI(x) printf("%d",x)
#define PC(x) printf("%c",x)
#define PLL(x) printf("%lld",x)
#define PLF(x) printf("%lf",x)
#define PS(x) printf("%s",x)
#define P32() printf(" ")
#define P10() printf("\n")
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
#define TR(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)


class MergersDivTwo {
	public:
		double findMaximum(vector <int>, int);
};

#define MINI -100000000.00

double MergersDivTwo::findMaximum(vector <int> revenues, int k) {
	vector<double> v;
	int N = revenues.size();
	int K = k;
	REP(i,N)
	{
		v.PB((double)revenues[i]);
	}

	while(true)
	{
		SORT(v);

		int sz = v.size();

		REP(i,sz)
		{
			printf("%lf ", v[i]);
		}
		printf("\n");

		if(sz < 2*K-1)
		{
			double s = 0;
			REP(i,sz)
			{
				s += v[i];
			}
			s /= sz;
			return s;
		}
		else if(sz == 2*K-1)
		{
			double maxi = MINI;
			REP(i,sz-K+1)
			{
				double s1 = 0.0, s2 = 0.0;
				REP(j,i)
				{
					s1 += v[j];
				}
				REP(j,K)
				{
					s2 += v[i+j];
				}
				s2 /= K;
				s1 += s2;
				FOR(j,i+K,sz)
				{
					s1 += v[j];
				}
				s1 /= K;
				maxi = MAX(maxi, s1);
			}
			return maxi;
		}
		else 
		{
			double s = 0.0;
			REP(i,K)
			{
				s += v[i];
			}
			s /= K;

			vector<double> w;
			FOR(i,K,sz)
			{
				w.PB(v[i]);
			}
			w.PB(s);
			v = w;
		}

		if(v.size() == 1)
		{
			return v[0];
		}
	}
}


double test0() {
	int t0[] = {5, -7, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	MergersDivTwo * obj = new MergersDivTwo();
	clock_t start = clock();
	double my_answer = obj->findMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.5;
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
	int t0[] = {5, -7, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	MergersDivTwo * obj = new MergersDivTwo();
	clock_t start = clock();
	double my_answer = obj->findMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.3333333333333333;
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
	int t0[] = {1, 2, 2, 3, -10, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	MergersDivTwo * obj = new MergersDivTwo();
	clock_t start = clock();
	double my_answer = obj->findMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 2.9166666666666665;
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
	int t0[] = {-100, -100, -100, -100, -100, 100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	MergersDivTwo * obj = new MergersDivTwo();
	clock_t start = clock();
	double my_answer = obj->findMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = -66.66666666666667;
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
	int t0[] = {869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 510, -965, -826, 808, 890,
		-233, -881, 255, -709, 506, 334, -184, 726, -406, 204, -912, 325, -445, 440, -368};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 7;
	MergersDivTwo * obj = new MergersDivTwo();
	clock_t start = clock();
	double my_answer = obj->findMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 706.0369290573373;
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

