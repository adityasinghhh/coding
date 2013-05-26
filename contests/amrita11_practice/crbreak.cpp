
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

vector<int> tree;

int read(int idx) { int sum = 0; while(idx > 0) { sum += tree[idx]; idx -= (idx&-idx); } return sum; }

void update(int idx, int val) { while(idx <= tree.size()) { tree[idx] += val; idx += (idx&-idx); } }

void scale(int c) { int i; REP(i,tree.size()) { tree[i]/c; } }

int find(int freq) 
{
	int sz = tree.size(), i=0; while(sz) { sz >>= 1; ++i; } 
	int bitMask = (1<<(i-1)), idx = 0;

	while((bitMask != 0) && (idx < tree.size()))
	{ 
		int tIdx = idx + bitMask;

		if (freq == tree[tIdx]) { return tIdx; } else if (freq > tree[tIdx]) { idx = tIdx; freq -= tree[tIdx]; }
		
		bitMask >>= 1;
	}
	
	if (freq != 0) { return -1; } else { return idx; }
}

int findG(int freq) 
{
	int sz = tree.size(), i=0; while(sz) { sz >>= 1; ++i; } 
	int bitMask = (1<<(i-1)), idx = 0;

	while((bitMask != 0) && (idx < tree.size()))
	{ 
		int tIdx = idx + bitMask;

		if (freq >= tree[tIdx]) { idx = tIdx; freq -= tree[tIdx]; }
		
		bitMask >>= 1;
	}
	
	if (freq != 0) { return -1; } else { return idx; }
}

int binary_search(int freq, int m)
{
	return read(m) < freq;
}

int find_binary_search(int freq) 
{
	
	int l = 0, e = tree.size()-1, m;

	while(l<e) { m = l+(e-l+1)/2; if(binary_search(freq, m)) { l = m; } else { e = m-1; } printf("%d %d\n", l, e); }

	return l+1;
}

int bf(VI v, int s)
{
	int cnt;
	REP(i,v.size())
	{
		FOR(j,i,v.size())
		{
			int s1 = 0;
			FOR(k,i,j+1)
			{
				s1 += v[k];
			}

			if(s == s1) { ++cnt; }
		}
	}

	return cnt;
}

int main()
{
	int T = SI;
	while(T--)
	{
		tree.clear(); REP(i,100100) { tree.PB(0); }

		VI v; int N = SI, s = 0; FOR(i,1,N+1) { int x = SI; v.PB(x); update(i,x); s+=x; }

		REP(j,N) { update(N+1+j, v[j]); }

		// REP(i,2*N) { printf("%d ", read(i+1)); } printf("\n");
		
		if(s&1) { printf("0\n"); continue; }

		s /= 2;

		VI v1;
		int x;
		map<int, int> m;
		map<int, int>::iterator it, it1;
		REP(i,N) { x = read(i+1); v1.PB(x); ++m[x]; }

		// REP(i,N) { printf("%d ", v1[i]); } printf("\n");

		int cnt = 0; REP(i,N) { x = v1[i]; --m[x]; cnt += m[x+s]; } // printf("%d summed up %d times\n", x, m[x+s]); }

//		printf("Brute Force: %d\n", bf(v, s));
		printf("%d\n", cnt);
	}

	return 0;
}
