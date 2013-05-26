/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<sstream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define MP make_pair
#define PB push_back
#define LL long long
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REPD(i,b) for(int i=(b)-1;i>=0;--i)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a) ((a)<0?-(a):(a))

typedef vector<int> VI; 
typedef pair<int,int> PI; 
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define RAND(x) ((int)(((rand()*1.0)/RAND_MAX)*(x)))

int dp[21234];

const int lose = 1, win = 2, tie2 = 3, invalid = 4;

pair <string,int> conv(int n)
{
	string ret;
	int cntx = 0, cnto = 0;
	REP(i,9)
	{
		int t = n%3;
		if(t == 0) ret += '.';
		else if(t == 1) { ret += 'o'; ++cnto; }
		else { ret += 'x'; ++cntx; }
		n/=3;
	}
	return MP(ret,cntx-cnto);
}

bool wins(string s, char c)
{
	for(int i = 0;i<=6; i+=3)
	{
		bool ret = true;
		REP(j,3) if(s[i+j] != c) ret = false;
		if(ret) return ret;
	}
	REP(i,3)
	{
		bool ret = true;
		for(int j = 0;j<=6; j+=3)
		{
			if(s[i+j] != c) ret = false;
		}
		if(ret) return ret;
	}
	if(s[0] == c && s[4] == c && s[8] == c) return true;
	if(s[2] == c && s[4] == c && s[6] == c) return true;
	return false;
}

char check(string s)
{
	int ws = 0, wo = 0;
	if(wins(s,'x')) ws = 1;
	if(wins(s,'o')) wo = 1;
	if(ws == 1 && wo == 1) return 'b';
	if(ws == 1) return 'x';
	if(wo == 1) return 'o';
	return 'n';
}

int find(string s)
{
	int pw = 1;
	int ret = 0;
	REP(i,9)
	{
		if(s[i] == 'o') ret += pw;
		else if(s[i] == 'x') ret += pw*2;
		pw*=3;
	}
	return ret;
}

int compute(int n)
{
	if(dp[n] != -1) return dp[n];
	pair <string,int> s = conv(n);
	if(s.second <0 || s.second > 1) return dp[n] = invalid;
	char temp = check(s.first);
	if(temp == 'b') return dp[n] = invalid;
	if(s.second == 0)
	{
		if(temp == 'x') return invalid;
		if(temp == 'o') return lose;
		bool canwin = false, cantie = false;
		int cntdot = 0;
		REP(i,9)
		{
			if(s.first[i] == '.')
			{
				++cntdot;
				s.first[i] = 'x';
				int num = find(s.first);
				int t = compute(num);
				s.first[i] = '.';
				if(t == lose) { canwin = true; break; }
				if(t == tie2) cantie = true;
			}
		}
		if(canwin) return win;
		if(cantie || cntdot == 0) return tie2;
		return lose;
	}
	if(temp == 'o') return invalid;
	if(temp == 'x') return lose;
	bool canwin = false, cantie = false;
	int cntdot = 0;
	REP(i,9)
	{
		if(s.first[i] == '.')
		{
			++cntdot;
			s.first[i] = 'o';
			int num = find(s.first);
			int t = compute(num);
			s.first[i] = '.';
			if(t == lose) { canwin = true; break; }
			if(t == tie2) cantie = true;
		}
	}
	if(canwin) return win;
	if(cantie || cntdot == 0) return tie2;
	return lose;
}

int main()
{
	FILL(dp,-1);
	REP(i,19683) dp[i] = compute(i);
	int t = SI;
	while(t--)
	{
		string s,s2;
		REP(i,3) { cin>>s2; s+=s2; }
		int ans = dp[find(s)];
		if(ans == win) printf("win\n");
		else if(ans == tie2) printf("tie\n");
		else if(ans == invalid) printf("invalid\n");
		else if(ans == lose) printf("lose\n");
	}
	return 0;
}
