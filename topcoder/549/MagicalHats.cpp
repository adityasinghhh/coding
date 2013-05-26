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

class MagicalHats {
public:
	int findMaximumReward(vector <string>, vector <int>, int);
};

vector<string> b;
vector<int> coins;
int r, c, g;

int markr[20], markc[20];
int f(VI &oddr, VI &oddc)
{
	int maxi = 0;
	REP(i,oddr.size())
	{
		if(markr[oddr[i]])
		{
			continue;
		}

		REP(j,oddc.size())
		{
			if(markc[oddc[j]])
			{
				continue;
			}

			if(b[oddr[i]][oddc[j]] == 'H')
			{
				markr[oddr[i]] = 1;
				markc[oddc[j]] = 1;
				maxi = MAX(maxi, 1+f(oddr, oddc));
				markr[oddr[i]] = 0;
				markc[oddc[j]] = 0;
			}
		}
	}

	return maxi;
}

map<pair<vector<string>, pair<vector<int>, int> >, int> m;
map<pair<vector<string>, pair<vector<int>, int> >, int>::iterator it;

int MagicalHats::findMaximumReward(vector <string> b, vector <int> coins, int g) {
	pair<vector<string>, pair<vector<int>, int> > p = MP(b, MP(coins, g));
	it = m.find(p);
	if(it != m.end())
	{
		return it->second;
	}
	
	if(g == 0)
	{
		return m[p] = 0;
	}

	::b = b;
	::r = r;
	::c = c;
	::coins = coins;
	::g = g;

	int r = b.size(), c = b[0].length();
	int numH = 0;
	REP(i,r)
	{
		REP(j,c)
		{
			numH += (b[i][j] == 'H');
		}
	}

	if(numH < coins.size())
	{
		return m[p] = -1;
	}

	VI oddr, oddc;
	REP(i,r)
	{
		int cnt = 0;
		REP(j,c)
		{
			cnt += (b[i][j] == 'H');
		}

		if(cnt&1)
		{
			oddr.PB(i);
		}
	}

	REP(j,c)
	{
		int cnt = 0;
		REP(i,r)
		{
			cnt += (b[i][j] == 'H');
		}

		if(cnt&1)
		{
			oddc.PB(j);
		}
	}

	FILL(markr, 0);
	FILL(markc, 0);
	int z = f(oddr, oddc);

	if(z > coins.size())
	{
		return m[p] = -1;
	}

	if((coins.size()-z)&1)
	{
		return m[p] = -1;
	}

	SORT(coins);
	int maxi = 0;
	REP(i,r)
	{
		REP(j,c)
		{
			if(b[i][j] == 'H')
			{
				b[i][j] = '.';
				maxi = MAX(maxi, MagicalHats::findMaximumReward(b, coins, g-1));
				maxi = MAX(maxi, coins[0] + MagicalHats::findMaximumReward(b, vector<int>(coins.begin()+1, coins.end()), g-1));
				b[i][j] = 'H';
			}
		}
	}

	return m[p] = maxi;
}

double test0() {
	string t0[] = {"H"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	MagicalHats * obj = new MagicalHats();
	clock_t start = clock();
	int my_answer = obj->findMaximumReward(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	string t0[] = {"HHH",
 "H.H",
 "HH."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	MagicalHats * obj = new MagicalHats();
	clock_t start = clock();
	int my_answer = obj->findMaximumReward(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 9;
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
	string t0[] = {"HH",
 "HH"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1,2,3,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	MagicalHats * obj = new MagicalHats();
	clock_t start = clock();
	int my_answer = obj->findMaximumReward(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
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
	string t0[] = {"HHH",
 "HHH",
 "H.H"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {13,13,13,13};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	MagicalHats * obj = new MagicalHats();
	clock_t start = clock();
	int my_answer = obj->findMaximumReward(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 13;
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
	string t0[] = {"HHH",
 "HHH",
 "H.H"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {13,13,13,13};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	MagicalHats * obj = new MagicalHats();
	clock_t start = clock();
	int my_answer = obj->findMaximumReward(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 26;
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
double test5() {
	string t0[] = {"H.H.",
 ".H.H",
 "H.H."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {17};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 6;
	MagicalHats * obj = new MagicalHats();
	clock_t start = clock();
	int my_answer = obj->findMaximumReward(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
double test6() {
	string t0[] = {"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {33,337,1007,2403,5601,6003,9999};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 5;
	MagicalHats * obj = new MagicalHats();
	clock_t start = clock();
	int my_answer = obj->findMaximumReward(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1377;
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
double test7() {
	string t0[] = {".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {22};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	MagicalHats * obj = new MagicalHats();
	clock_t start = clock();
	int my_answer = obj->findMaximumReward(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 22;
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
