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
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define LL long long int

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

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

int a[100001], b[100001], N, X, maxi, A[100001], B[100001];
int acnt, bcnt;
void init()
{
	int j = N-2, cnt = 0;
	while(j > 0 && a[j]+b[j+1] >= X)
	{
		++cnt;
		--j;
	}
	acnt = cnt;

	j = N-2, cnt = 0;
	while(j > 0 && a[j+1]+b[j] >= X)
	{
		++cnt;
		--j;
	}
	bcnt = cnt;

}

void f(int i, int j)
{
	if(i >= N || j < 0)
	{
		return;
	}

	if(a[i]+b[j] == X)
	{
		//int mini = MIN(A[i], B[j]);
		int mini = MIN(N-i, N-j);
		maxi = MAX(maxi, mini);

		f(i+1, j);
		f(i, j-1);
	}
	else if(a[i]+b[j] < X)
	{
		f(i+1, j);
	}
	else
	{
		//int mini = MIN(A[i], B[j]);
		int mini = MIN(N-i, N-j);
		maxi = MAX(maxi, mini);

		f(i, j-1);
	}
}

void print(int a[])
{
	REP(i,N)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	N = SI, X = SI;
	REP(i,N)
	{
		a[i] = SI;
	}
	sort(a, a+N);

	REP(i,N)
	{
		b[i] = SI;
	}
	sort(b, b+N);

	init();

	printf("1 %d\n", MAX(acnt, bcnt)+1);

	return 0;
	//print(a);
//	print(A);
//	print(b);
//	print(B);

	printf("1 ");
	maxi = 1;
	f(0, N-1);

	printf("%d\n", maxi);

	return 0;
}
