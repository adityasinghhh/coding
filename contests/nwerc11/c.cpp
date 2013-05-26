
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

void test()
{
	tree.PB(0);	tree.PB(1);	tree.PB(1);	tree.PB(2);	tree.PB(4);	tree.PB(1);	tree.PB(4);	tree.PB(0);
	tree.PB(12);	tree.PB(2);	tree.PB(7);	tree.PB(2);	tree.PB(11);	tree.PB(3);	tree.PB(4);	tree.PB(0);
	tree.PB(29);

	printf("Cumulative Frequency at %d = %d\n", 8, read(8));
	printf("Cumulative Frequency at %d = %d\n", 13, read(13));

	update(13, 3);
	
	printf("Cumulative Frequency at %d = %d\n", 8, read(8));
	printf("Cumulative Frequency at %d = %d\n", 13, read(13));

	printf("Frequency at %d = %d\n", 13, read(13)-read(12));

	printf("Cumulative Frequency %d is at %d\n", 30, find(30));
	printf("Cumulative Frequency %d is at %d\n", 30, findG(30));

	printf("Cumulative Frequency with binary search: %d at %d\n", 30, find_binary_search(30));

	int i; REP(i,tree.size()) { printf("%d:%d ", i, read(i)); } printf("\n");
}

int main()
{
	int T; iscan(T);
	while(T--)
	{
		int M, R;

		iscan(M); iscan(R);

		int i, j, a[M+1]; VI v; REP(i,M) { v.PB(0); } FOR(j,M,2*M) { v.PB(j-M+1); a[j-M+1] = j; } tree = v;

		REP(i,tree.size()) { printf("%d ", tree[i]); } printf("\n");

		printf("%d\n", read(a[4]));
	}

	return 0;
}
