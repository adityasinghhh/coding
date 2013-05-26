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

class AntsMeet {
public:
	int countAnts(vector <int>, vector <int>, string);
};

int AntsMeet::countAnts(vector <int> X, vector <int> Y, string s) {
	int sz = X.size(), cnt = sz;
	int mark[sz+1];
	FILL(mark, 0);
	
	vector<double> x, y;
	REP(i,sz)
	{
		x.PB(X[i]);
		y.PB(Y[i]);
	}
	
	while(true)
	{
		bool flag = false;
		REP(i,sz)
		{
			if(mark[i])
			{
				continue;
			}

			if((s[i] == 'N' && y[i] < 2000.0) || (s[i] == 'S' && y[i] > -2000.0) || (s[i] == 'E' && x[i] < 2000.0) || (s[i] == 'W' && x[i] > -2000.0))
			{
				flag = true;
				break;
			}
		}

		if(!flag)
		{
			return cnt;
		}

		REP(i,sz)
		{
			if(mark[i])
			{
				continue;
			}

			if(s[i] == 'N')
			{
				y[i] += 0.5;
			}
			else if(s[i] == 'S')
			{
				y[i] -= 0.5;
			}
			else if(s[i] == 'W')
			{
				x[i] -= 0.5;
			}
			else 
			{
				x[i] += 0.5;
			}
		}

		REP(i,sz)
		{
			if(mark[i])
			{
				continue;
			}

			REP(j,sz)
			{
				if(mark[j])
				{
					continue;
				}

				if(i == j)
				{
					continue;
				}

				if(abs(x[i]-x[j]) < 0.000001 && abs(y[i]-y[j]) < 0.00001)
				{
					if(mark[i] == 0)
					{
						mark[i] = 1;
						--cnt;
					}

					if(mark[j] == 0)
					{
						mark[j] = 1;
						--cnt;
					}
				}
			}
		}
	}	
}


double test0() {
	int t0[] = {0,10,20,30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,10,20,30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "NWNE";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int t0[] = {-10,0,0,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,-10,10,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "NEWS";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	int t0[] = {-1,-1,-1,0,0,0,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1,0,1,-1,0,1,-1,0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "ESEWNNEWW";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	int t0[] = {4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" ;
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 25;
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
	int t0[] = {478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423
,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216
,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 44;
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
