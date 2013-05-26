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

class FavouriteDigits {
public:
	long long findNext(long long, int, int, int, int);
};

long long FavouriteDigits::findNext(long long N, int digit1, int count1, int digit2, int count2) {
	if(count1 || count2)
	{
		if(digit1 > digit2)
		{
			swap(digit1, digit2);
			swap(count1, count2);
		}

		LL x = N, cnt1 = 0, cnt2 = 0;
		VI v;
		while(x)
		{
			int y = x%10;
			if(y == digit1)
			{
				++cnt1;
			}
			else if(y == digit2)
			{
				++cnt2;
			}
			v.PB(y);
			x /= 10;
		}

		if(cnt1 >= count1 && cnt2 >= count2)
		{
			return N;
		}

		if(count1 + count2 > v.size())
		{
			LL x = 0ll;
			REP(i,count1)
			{
				x = x * 10ll + digit1;
			}
			REP(i,count2)
			{
				x = x * 10ll + digit2;
			}
			return x;
		}

		count2 -= cnt2;
		count1 -= cnt1;

		while(true)
		{
			int i = 0;
			while(count2)
			{
				if(v[i] < digit2)
				{
					v[i] = digit2;
					--count2;
					++i;
				}
				else
				{
					v[i] = digit2;
					--count2;
					int j = i+1;
					while(count2 && j < v.size() && v[j] == 9)
					{
						v[j] = 0;
					}

					if(j == v.size())
					{
						v.PB(1);
					}
					else
					{
						if(v[j] == digit1)
						{
							++count1;
						}
						v[j] += 1;
					}
					++i;
				}
			}

			while(count1)
			{
				if(v[i] < digit1)
				{
					v[i] = digit1;
					--count1;
					++i;
				}
				else
				{
					v[i] = digit1;
					--count1;
					int j = i+1;
					while(count1 && j < v.size() && v[j] == 9)
					{
						v[j] = 0;
					}

					if(j == v.size())
					{
						v.PB(1);
					}
					else
					{
						if(v[j] == digit2)
						{
							++count2;
						}
						v[j] += 1;
					}
					++i;
				}
			}

			if(!count1 && !count2)
			{
				break;
			}
		}

		x = 0ll;
		REPD(i,v.size())
		{
			x = x * 10 + v[i];
		}

		return x;
	}
	else
	{
		return N;
	}
}


double test0() {
	long long p0 = 47LL;
	int p1 = 1;
	int p2 = 0;
	int p3 = 2;
	int p4 = 0;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 47LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	long long p0 = 47LL;
	int p1 = 5;
	int p2 = 0;
	int p3 = 9;
	int p4 = 1;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 49LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	long long p0 = 47LL;
	int p1 = 5;
	int p2 = 0;
	int p3 = 3;
	int p4 = 1;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 53LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	long long p0 = 47LL;
	int p1 = 2;
	int p2 = 1;
	int p3 = 0;
	int p4 = 2;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 200LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	long long p0 = 123456789012345LL;
	int p1 = 1;
	int p2 = 2;
	int p3 = 2;
	int p4 = 4;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 123456789012422LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	long long p0 = 92LL;
	int p1 = 1;
	int p2 = 1;
	int p3 = 0;
	int p4 = 0;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 100LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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
