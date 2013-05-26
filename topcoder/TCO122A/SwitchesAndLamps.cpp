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
#define TR(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

class SwitchesAndLamps {
public:
	int theMin(vector <string>, vector <string>);
};

int r, c;

int SwitchesAndLamps::theMin(vector <string> switches, vector <string> lamps) {
	r = lamps.size();
	c = lamps[0].length();

	set<int> s[c+1];
	map<string, string> m;
	REP(i,r)
	{
		if(m.find(lamps[i]) == m.end())
		{
		}
		else
		{
			if(m[lamps[i]] != switches[i])
			{
				return -1;
			}
		}

		m[lamps[i]] = switches[i];

		set<int> t;
		REP(j,c)
		{
			if(lamps[i][j] == 'Y')
			{
				t.insert(j);
			}
		}

		REP(j,c)
		{
			if(switches[i][j] == 'Y')
			{
				if(s[j].size())
				{
					set<int> u;
					TR(it,t)
					{
						if(s[j].find(*it) != s[j].end())
						{
							u.insert(*it);
						}
					}

					if(u.size())
					{
						s[j] = u;
					}
					else
					{
						return -1;
					}
				}
				else
				{
					s[j] = t;
				}
			}
		}
	}

	int maxi = -1, cnt = 0;
	REP(i,c)
	{
		int mini = INT_MAX;
		REP(j,c)
		{
			if(i == j || s[i] == s[j])
			{
				continue;
			}

			set<int> u;
			TR(it, s[i])
			{
				if(s[j].find(*it) != s[j].end())
				{
					u.insert(*it);
				}
			}

			mini = MIN(mini, s[i].size() - u.size());
		}

		if(maxi > mini)
		{
			maxi = mini;
			cnt = 1;
		}
		else if(maxi == mini)
		{
			++cnt;
		}
	}

	return cnt-1;
}


double test0() {
	string t0[] = {"NYNN", "NNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NNNY", "NNYN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
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
	string t0[] = {"YYN", "YNY", "YYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YNY", "NYY", "YNY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
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
	string t0[] = {"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
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
	string t0[] = {"YYNNN", "NNYYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NYNNY", "NNNYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
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
double test4() {
	string t0[] = {"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
