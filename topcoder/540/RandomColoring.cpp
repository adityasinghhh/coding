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

class RandomColoring {
public:
	double getProbability(int, int, int, int, int, int, int, int, int);
};

int N, d1, d2, mr, mg, mb, sr, sg, sb;
//map<pair<pair<int, int>, pair<int, int> >, double> dp;
int dp[41][51][51][51], dp1[41][51][51][51];

int f(int i, int r, int g, int b)
{
//	pair<pair<int, int>, pair<int, int> > p = MP(MP(i,r), MP(g,b));
	if(dp[i][r][g][b] != -1)
	{
		return dp[i][r][g][b];
	}

	if(i == N)
	{
		if(abs(r-sr) > d2 || abs(g-sg) > d2 || abs(b-sb) > d2)
		{
			return dp[i][r][g][b] = 0;
		}

		if(abs(r-sr) >= d1 || abs(g-sg) >= d1 || abs(b-sb) >= d1)
		{
			return dp[i][r][g][b] = 1;
		}

		return dp[i][r][g][b] = 0;
	}

	dp[i][r][g][b] = 0;
	REP(ir,mr)
	{
		if(abs(ir-r) > d2)
		{
			continue;
		}

		REP(ig,mg)
		{
			if(abs(ig-g) > d2)
			{
				continue;
			}

			REP(ib,mb)
			{
				if(abs(ib-b) > d2)
				{
					continue;
				}

				if(abs(ir-r) >= d1 || abs(ig-g) >= d1 || abs(ib-b) >= d1)
				{					
					dp[i][r][g][b] += f(i+1, ir, ig, ib);
				}
			}
		}
	}

	return dp[i][r][g][b];
}

int f1(int i, int r, int g, int b)
{
	printf("%d %d %d %d\n", i, r, g, b);
//	pair<pair<int, int>, pair<int, int> > p = MP(MP(i,r), MP(g,b));
	if(dp1[i][r][g][b] != -1)
	{
		return dp1[i][r][g][b];
	}

	if(i == N)
	{
		return dp1[i][r][g][b] = 1;
	}

	dp1[i][r][g][b] = 0;
//	printf("%d: ", i);
//	printf("mr:%d, mg:%d, mb:%d\n", mr, mg, mb);

	REP(ir,mr)
	{
//		printf("ir = %d, mr = %d\n", ir, mr);
		if(abs(ir-r) > d2)
		{
//			printf("Continuing for ir = %d\n", ir);
			continue;
		}

		REP(ig,mg)
		{
//			printf("ig = %d\n", ig);
			if(abs(ig-g) > d2)
			{
//				printf("Continuing for ig= %d\n", ig);
				continue;
			}

			REP(ib,mb)
			{
//				printf("ib = %d\n", ib);
				if(abs(ib-b) > d2)
				{
//					printf("Continuing for ib = %d\n", ib);
					continue;
				}

//				printf("Checking (%d, %d, %d)\n", ir, ig, ib);
				if(abs(ir-r) >= d1 || abs(ig-g) >= d1 || abs(ib-b) >= d1)
				{					
					dp1[i][r][g][b] += f1(i+1, ir, ig, ib);
				}
			}
		}
	}

	return dp1[i][r][g][b];
}

double RandomColoring::getProbability(int n, int maxR, int maxG, int maxB, int startR, int startG, int startB, int D1, int D2) {
	N = n;
	d1 = D1;
	d2 = D2;
	mr = maxR;
	mg = maxG;
	mb = maxB;
	sr = startR;
	sg = startG;
	sb = startB;
	
	FILL(dp, -1);
	FILL(dp1, -1);

	int good = f(0, startR, startG, startB);
	int tot = f1(0, startR, startG, startB);

	printf("%d %d\n", good, tot);

	return (double)good/(double)tot;
}


double test0() {
	int p0 = 2;
	int p1 = 5;
	int p2 = 1;
	int p3 = 1;
	int p4 = 2;
	int p5 = 0;
	int p6 = 0;
	int p7 = 0;
	int p8 = 1;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 5;
	int p2 = 1;
	int p3 = 1;
	int p4 = 2;
	int p5 = 0;
	int p6 = 0;
	int p7 = 0;
	int p8 = 1;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.22222222222222227;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 7;
	int p1 = 4;
	int p2 = 2;
	int p3 = 2;
	int p4 = 0;
	int p5 = 0;
	int p6 = 0;
	int p7 = 3;
	int p8 = 3;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 10;
	int p1 = 7;
	int p2 = 8;
	int p3 = 9;
	int p4 = 1;
	int p5 = 2;
	int p6 = 3;
	int p7 = 0;
	int p8 = 10;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 10;
	int p1 = 7;
	int p2 = 8;
	int p3 = 9;
	int p4 = 1;
	int p5 = 2;
	int p6 = 3;
	int p7 = 4;
	int p8 = 10;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.37826245943967396;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 3;
	int p1 = 3;
	int p2 = 2;
	int p3 = 2;
	int p4 = 1;
	int p5 = 0;
	int p6 = 0;
	int p7 = 1;
	int p8 = 2;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.09090909090909148;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
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
