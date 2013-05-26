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

class AkariDaisukiDiv1 {
public:
	int countF(string, string, string, string, string, int);
};

int T[100];
void kmp_table(string &w)
{
	T[0] = -1;
	T[1] = 0;

	int p = 2, cnd = 0, l = w.length();

	while(p <= l)
	{
		if(w[p-1] == w[cnd])
		{
			T[p] = T[p-1] + 1;
			cnd++;
		}
		else
		{
			T[p] = 0;
			cnd = 0;
		}
		p++;
	}
}

string D[10000001], W[10000001];

int AkariDaisukiDiv1::countF(string w, string a, string d, string x, string f, int k) {
	string s = x + a + x + d + a + w + x + a + x;

	kmp_table(f);

	int cnt = 0;
	int m = 0, i = 0, lw = f.length();

	while(true)
	{
		while(m+i < ls)
		{
			if(s[m] == w[i])
			{
				m++;
				i++;

				if(i == lw)
				{
					printf("Match at %d\n", m-i);

					if(T[i] > -1)
						i = T[i];
					else
						i = 0;
				}
			}
			else
			{
				m = m + i - T[i];

				if(T[i] > -1)
					i = T[i];
				else
					i = 0;
			}
		}
	}
}


double test0() {
	string p0 = "a";
	string p1 = "b";
	string p2 = "c";
	string p3 = "x";
	string p4 = "axb";
	int p5 = 2;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "a";
	string p1 = "b";
	string p2 = "c";
	string p3 = "x";
	string p4 = "abcdefghij";
	int p5 = 1;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "a";
	string p1 = "a";
	string p2 = "a";
	string p3 = "b";
	string p4 = "aba";
	int p5 = 2;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "a";
	string p1 = "b";
	string p2 = "c";
	string p3 = "d";
	string p4 = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba";
	int p5 = 58;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 191690599;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "a";
	string p1 = "x";
	string p2 = "y";
	string p3 = "b";
	string p4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	int p5 = 49;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string p0 = "waai";
	string p1 = "akari";
	string p2 = "daisuki";
	string p3 = "usushio";
	string p4 = "id";
	int p5 = 10000000;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 127859200;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	string p0 = "vfsebgjfyfgerkqlr";
	string p1 = "ezbiwls";
	string p2 = "kjerx";
	string p3 = "jbmjvaawoxycfndukrjfg";
	string p4 = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs";
	int p5 = 1575724;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 483599313;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
