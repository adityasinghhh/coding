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

class SafeReturn {
	public:
		int minRisk(int, vector <string>);
};

VI pre[100];
int f(int i, int &N)
{
	if(pre[i].size() == 0)
	{
		return 0;
	}

	int ret = 0;
	REP(j,pre[i].size())
	{
		if(pre[i][j] >= 1 && pre[i][j] <= N)
		{
			return 1;
		}

		if(f(pre[i][j], N))
		{
			return 1;
		}
	}

	return 0;
}

int SafeReturn::minRisk(int N, vector <string> s) {
	int sz = s.size();
	vector<PI> V[sz+1];
	REP(i,sz)
	{
		pre[i].clear();
		REP(j,sz)
		{
			if(s[i][j] == '-')
			{
				continue;
			}

			int d = s[i][j]-'0';
			V[i].PB(MP(j,d));
			V[j].PB(MP(i,d)); // Remove this if the edges are directed
		}
	}

	bool mark[sz+1]; FILL(mark,0);
	int dist[sz+1];  REP(i,sz+1) { dist[i] = INT_MAX; } // Fill with 'INT_MAX'

	PI p;
	priority_queue<PI> pq;

	pq.push(MP(0,0)); 
	dist[0] = 0;
	while(!pq.empty())
	{
		p = pq.top(); pq.pop();

		int d = -p.first, x = p.second;

		if(mark[x]) { continue; }
		
		mark[x] = 1;

		REP(i,V[x].size())
		{
			p = V[x][i];
			int y = p.first, dxy = p.second;

			if(dist[y] >= d + dxy)
			{
				pre[y].PB(x);
				dist[y] = d + dxy;
				pq.push(MP(-dist[y], y));
			}
		}
	}

	int cnt = 0;
	FOR(i,1,N+1)
	{
		cnt += f(i, N);
	}

	return N-cnt;
}


double test0() {
	int p0 = 3;
	string t1[] = {"-234",
 "2---",
 "3---",
 "4---"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SafeReturn * obj = new SafeReturn();
	clock_t start = clock();
	int my_answer = obj->minRisk(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int p0 = 2;
	string t1[] = {"-12",
 "1-1",
 "21-"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SafeReturn * obj = new SafeReturn();
	clock_t start = clock();
	int my_answer = obj->minRisk(p0, p1);
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
double test2() {
	int p0 = 3;
	string t1[] = {"-----7",
 "--1---",
 "-1-5--",
 "--5-1-",
 "---1-3",
 "7---3-"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SafeReturn * obj = new SafeReturn();
	clock_t start = clock();
	int my_answer = obj->minRisk(p0, p1);
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
double test3() {
	int p0 = 2;
	string t1[] = {"-11",
 "1-1",
 "11-"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SafeReturn * obj = new SafeReturn();
	clock_t start = clock();
	int my_answer = obj->minRisk(p0, p1);
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
