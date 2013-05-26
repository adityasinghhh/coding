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

class PointyWizardHats {
public:
	int getNumHats(vector <int>, vector <int>, vector <int>, vector <int>);
};

bool valid(int th, int tr, int bh, int br)
{
	if(tr >= br)
	{
		return false;
	}

	double h = ((double)tr*bh)/((double)br);

	return h < (double) th;
}

int g[55][55];

#define MAXN 110

class BipartiteMatching{
	int isMatched[MAXN]; // equal to the partner (from the left) if matched or = -1 ...
	bool checkedAlready[MAXN];
	bool matchedAlready[MAXN];
	bool search(int);
	public:
	BipartiteMatching(int,int);
	int nleft, nright; // number of nodes in the left and right ..
	bool edges[MAXN][MAXN];
	int maxMatching();
};

BipartiteMatching::BipartiteMatching(int nl, int nr)
{
	nleft = nl;
	nright = nr;
	int i,j;
	for(i=0;i<nleft;++i) for(j=0;j<nright;++j) edges[i][j] = false;
	for(j=0;j<nright;++j) isMatched[j] = -1;
	for(i=0;i<nleft;++i) matchedAlready[i] = false;
}

bool BipartiteMatching::search(int pos)
{
	if(checkedAlready[pos]) return false;
	checkedAlready[pos] = true;
	int i;
	for(i = 0; i<nright; ++i){
		if(edges[pos][i]){
			if(isMatched[i] == -1){
				isMatched[i] = pos;
				matchedAlready[pos] = true;
				return true;
			}
			else{
				if(search(isMatched[i])){
					isMatched[i] = pos;
					matchedAlready[pos] = true;
					return true;
				}
			}
		}
	}
	return false;
}

int BipartiteMatching::maxMatching()
{
	int i,j,ans=0;
	bool changed = true;
	while(changed){
		changed = false;
		for(i=0;i<nleft;++i) checkedAlready[i] = false;
		for(i=0;i<nleft;++i){
			if(matchedAlready[i] == false){
				if(search(i)){ ++ans; changed = true; }
			}
		}
	}
	return ans;
}


int PointyWizardHats::getNumHats(vector <int> th, vector <int> tr, vector <int> bh, vector <int> br) {
	int sh = th.size(), sb = bh.size();

	BipartiteMatching bm(sh, sb);

	FILL(g, 0);
	REP(i,sh)
	{
		REP(j,sb)
		{
			if(valid(th[i], tr[i], bh[j], br[j]))
			{
				bm.edges[i][j] = 1;
			}
		}
	}

	return bm.maxMatching();
}


double test0() {
	int t0[] = {30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {30};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {5,12};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {5,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {10,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,9};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3,6};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {3,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,4,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3,4,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3,8,5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {1,2,3,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,4,5,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,5,6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,2,3,4,5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int t0[] = {123,214,232,323,342,343};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {123,123,232,123,323,434};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {545,322,123,545,777,999};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {323,443,123,656,767,888};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test7() {
	int t0[] = {999,999,999,10000,10000,10000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10000,10000,10000,1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2324,2323,234,5454,323,232};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,2,3222,434,5454,23};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
