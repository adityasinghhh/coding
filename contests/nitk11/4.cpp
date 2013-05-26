
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

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=b-1;i>=a;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define LL long long int
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define ABS(a) a<0?-a:a

int main()
{
	int N, i, M;
	char a[100000];
	string s;
	vector<string> v;
	map<string, vector<string> > m;
	map<string, vector<string> >::iterator it;
	
	iscan(N); 
	REP(i,N) 
	{ 
		sscan(a); 
		s = a; 
		sort(s.begin(), s.end());
		it = m.find(s);

		if(it == m.end()) { vector<string> v; v.PB(a); m[s] = v; } else { m[s].PB(a); }
	}

	for(it = m.begin(); it != m.end(); ++it)
	{
		s = (*it).first;
		v = (*it).second;
		sort(v.begin(), v.end());
		m[s] = v;
	}

	iscan(M);
	REP(i,M)
	{
		sscan(a);
		s = a;
		sort(s.begin(), s.end());
		it = m.find(s);

		if(it != m.end()) { printf("%s\n", m[s][0].c_str()); } else { printf("No match\n"); }
	}

	return 0;
}
