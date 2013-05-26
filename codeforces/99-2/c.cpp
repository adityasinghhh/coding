
#include<algorithm>
#include<assert.h>
#include<bitset>
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
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

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

string s[10000];
int N, K;

bool vowel(char ch)
{
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool checkABAB(int id)
{
	int l1 = s[id].length();
	int l2 = s[id+1].length();
	int l3 = s[id+2].length();
	int l4 = s[id+3].length();

	int cnt, k1,k2,k3,k4;
	cnt = 0; REPD(i,l1) { if(vowel(s[id][i]))   { ++cnt; if(cnt == K) { k1 = i; } } } if(cnt < K) { return false; }
	cnt = 0; REPD(i,l2) { if(vowel(s[id+1][i])) { ++cnt; if(cnt == K) { k2 = i; } } } if(cnt < K) { return false; }
	cnt = 0; REPD(i,l3) { if(vowel(s[id+2][i])) { ++cnt; if(cnt == K) { k3 = i; } } } if(cnt < K) { return false; }
	cnt = 0; REPD(i,l4) { if(vowel(s[id+3][i])) { ++cnt; if(cnt == K) { k4 = i; } } } if(cnt < K) { return false; }

	while(k1 < l1 && k3 < l3) { if(s[id][k1] != s[id+2][k3]) { return false; } ++k1; ++k3; } if(k1 != l1 || k3 != l3) { return false; }
	while(k2 < l2 && k4 < l4) { if(s[id+1][k2] != s[id+3][k4]) { return false; } ++k2; ++k4; } if(k2 != l2 || k4 != l4) { return false; }

	return true;
}

bool checkAABB(int id)
{
	int l1 = s[id].length();
	int l2 = s[id+1].length();
	int l3 = s[id+2].length();
	int l4 = s[id+3].length();

	int cnt, k1,k2,k3,k4;
	cnt = 0; REPD(i,l1) { if(vowel(s[id][i]))   { ++cnt; if(cnt == K) { k1 = i; } } } if(cnt < K) { return false; }
	cnt = 0; REPD(i,l2) { if(vowel(s[id+1][i])) { ++cnt; if(cnt == K) { k2 = i; } } } if(cnt < K) { return false; }
	cnt = 0; REPD(i,l3) { if(vowel(s[id+2][i])) { ++cnt; if(cnt == K) { k3 = i; } } } if(cnt < K) { return false; }
	cnt = 0; REPD(i,l4) { if(vowel(s[id+3][i])) { ++cnt; if(cnt == K) { k4 = i; } } } if(cnt < K) { return false; }

	while(k1 < l1 && k2 < l2) { if(s[id][k1] != s[id+1][k2]) { return false; } ++k1; ++k2; } if(k1 != l1 || k2 != l2) { return false; }
	while(k3 < l3 && k4 < l4) { if(s[id+2][k3] != s[id+3][k4]) { return false; } ++k3; ++k4; } if(k3 != l3 || k4 != l4) { return false; }

	return true;
}

bool checkABBA(int id)
{
	int l1 = s[id].length();
	int l2 = s[id+1].length();
	int l3 = s[id+2].length();
	int l4 = s[id+3].length();

	int cnt, k1,k2,k3,k4;
	cnt = 0; REPD(i,l1) { if(vowel(s[id][i]))   { ++cnt; if(cnt == K) { k1 = i; } } } if(cnt < K) { return false; }
	cnt = 0; REPD(i,l2) { if(vowel(s[id+1][i])) { ++cnt; if(cnt == K) { k2 = i; } } } if(cnt < K) { return false; }
	cnt = 0; REPD(i,l3) { if(vowel(s[id+2][i])) { ++cnt; if(cnt == K) { k3 = i; } } } if(cnt < K) { return false; }
	cnt = 0; REPD(i,l4) { if(vowel(s[id+3][i])) { ++cnt; if(cnt == K) { k4 = i; } } } if(cnt < K) { return false; }

	while(k1 < l1 && k4 < l4) { if(s[id][k1] != s[id+3][k4]) { return false; } ++k1; ++k4; } if(k1 != l1 || k4 != l4) { return false; }
	while(k2 < l2 && k3 < l3) { if(s[id+1][k2] != s[id+2][k3]) { return false; } ++k2; ++k3; } if(k2 != l2 || k3 != l3) { return false; }

	return true;
}

int main()
{
	N = SI; K = SI;
	N *= 4;
	char a[100000];
	REP(i,N) { sscan(a); s[i] = a; }

	int i;
	int flag1 = 0, flag2 = 0, flag3 = 0, tot = 0;
	for(i=0; i<N; i+=4)
	{
		bool f1 = false, f2 = false, f3 = false; 
		if(checkAABB(i)) { f1 = true; }
		if(checkABAB(i)) { f2 = true; }
		if(checkABBA(i)) { f3 = true; }

		if(f1&f2&f3) { ++tot; }

		if(f1) { ++flag1; }
		if(f2) { ++flag2; }
		if(f3) { ++flag3; }
	}

	N /= 4;

	if(tot == N) { printf("aaaa\n"); }
	else if(flag1 == N) { printf("aabb\n"); }
	else if(flag2 == N) { printf("abab\n"); }
	else if(flag3 == N) { printf("abba\n"); }
	else { printf("NO\n"); }

	return 0;
}
