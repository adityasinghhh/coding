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

class Spacetsk {
public:
	int countsets(int, int, int);
};

LL dp[2001][2001];

LL nCr(int n, int r)
{
	if(dp[n][r] != -1ll)
	{
		return dp[n][r];
	}

	LL ret = 1ll, j = 1;
	FOR(i,r+1,n+1)
	{
		ret *= 1ll*i;
		ret /= 1ll*j;
		++j;
	}

	return dp[n][r] = ret;
}

LL BASE = 1000000007ll;
int Spacetsk::countsets(int L, int H, int K) {

	if(K == 1)
	{
		LL ans = 1ll*(L+1);
		ans *= (H+1);

		return ans % BASE;
	}

	FILL(dp, -1);

	int mid = L/2, l = L;
		
	LL cnt = 0ll;
	
	int maxi = max(L+1, H+1);
	queue<PI> q;
	REP(i,maxi)
	{
		FOR(j,i,maxi)
		{
			if(__gcd(i,j) == 1)
			{
				if(i <= L && j <= H)
				{
					q.push(make_pair(i, j));
				}

				if(i != j && j <= L && i <= H)
				{
					q.push(make_pair(j, i));
				}
			}
		}
	}

	queue<PI> Q = q;

	while(mid--)
	{
		q = Q;
		while(!q.empty())
		{
			PI p = q.front();
			q.pop();

			int x = p.first, y = p.second;

			if(x > L)
			{
				continue;
			}

			cout << x << " " << y << endl;

			if(x == 0)
			{
				if(K > H+1)
				{
				}
				else
				{
					cnt += nCr(H+1, K);
					cnt %= BASE;
				}
			}
			else if(y == 0)
			{
				if(K > L+1)
				{
				}
				else
				{
					cnt += nCr(L+1, K);
					cnt %= BASE;
				}
			}
			else
			{
				int pts = min(L/x, H/y) + 1;
				if(K > pts)
				{
				}
				else
				{
					cnt += nCr(pts, K);
					cnt %= BASE;
				}
			}
		}

		--L;
	}

	cnt *= 2ll;
	cnt %= BASE;

	if(l&1)
	{
		q = Q;
		while(!q.empty())
		{
			PI p = q.front();
			q.pop();

			int x = p.first, y = p.second;
			
			if(x > L)
			{
				continue;
			}

			if(x == 0)
			{
				if(K > H)
				{
				}
				else
				{
					cnt += nCr(H, K);
					cnt %= BASE;
				}
			}
			else if(y == 0)
			{
				if(K > L)
				{
				}
				else
				{
					cnt += nCr(L, K);
					cnt %= BASE;
				}
			}
			else
			{
				int pts = min(L/x, H/y);
				if(K > pts)
				{
				}
				else
				{
					cnt += nCr(pts, K);
					cnt %= BASE;
				}
			}
		}
	}

	return cnt;
}


double test0() {
	int p0 = 1;
	int p1 = 1;
	int p2 = 2;
	Spacetsk * obj = new Spacetsk();
	clock_t start = clock();
	int my_answer = obj->countsets(p0, p1, p2);
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
double test1() {
	int p0 = 1;
	int p1 = 1;
	int p2 = 1;
	Spacetsk * obj = new Spacetsk();
	clock_t start = clock();
	int my_answer = obj->countsets(p0, p1, p2);
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
double test2() {
	int p0 = 2;
	int p1 = 2;
	int p2 = 1;
	Spacetsk * obj = new Spacetsk();
	clock_t start = clock();
	int my_answer = obj->countsets(p0, p1, p2);
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
double test3() {
	int p0 = 2;
	int p1 = 2;
	int p2 = 2;
	Spacetsk * obj = new Spacetsk();
	clock_t start = clock();
	int my_answer = obj->countsets(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 23;
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
	int p0 = 5;
	int p1 = 5;
	int p2 = 3;
	Spacetsk * obj = new Spacetsk();
	clock_t start = clock();
	int my_answer = obj->countsets(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 202;
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
	int p0 = 561;
	int p1 = 394;
	int p2 = 20;
	Spacetsk * obj = new Spacetsk();
	clock_t start = clock();
	int my_answer = obj->countsets(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 786097180;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
