
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
#define PI(x) printf("%d",x)
#define PC(x) printf("%c",x)
#define PLL(x) printf("%lld",x)
#define PLF(x) printf("%lf",x)
#define PS(x) printf("%s",x)
#define P32() printf(" ")
#define P10() printf("\n")
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

LL HF[101][100001], HB[101][100001];
LL P = 31, mod = 1000000009;
string s[101];
int N, M;

void f(int i)
{
	LL h = 0ll;
	REP(j,M)
	{
		h = (h*P + s[i][j]) % mod;
		HF[i][j] = h;
	}

	h = 0ll;
	REPD(j,M)
	{
		h = (h*P + s[i][j]) % mod;
		HB[i][M-j-1] = h;
	}
}
	
int g(int i, int j)
{
	int l = -1, e = M-1, m;
	while(l < e)
	{
		m = l + (e-l+1)/2;

		if(HF[i][m] == HB[j][m])
		{
			l = m;
		}
		else
		{
			e = m-1;
		}
	}

	return l+1;
}

bool isPalindrome(int i)
{
	REP(j,M)
	{
		if(s[i][j] != s[i][M-j-1])
		{
			return false;
		}
	}

	return true;
}

void bf()
{
	int maxi = -1;
	REP(i,N)
	{
		if(isPalindrome(i))
		{
			maxi = MAX(maxi, M);
		}

		REP(j,N)
		{
			if(i == j)
			{
				continue;
			}
			else
			{
				int ret = 0;
				REP(k,M)
				{
					if(s[i][k] == s[j][M-k-1])
					{
						++ret;
					}
					else
					{
						break;
					}
				}
				
				int c1 = 0, ind = ret;
				while(ind < M && s[i][ind] == s[i][ret])
				{
					++c1;
					++ind;
				}

				int c2 = 0;
				ind = M-ret-1;
				while(ind >= 0 && s[j][ind] == s[j][M-ret-1])
				{
					++c2;
					--ind;
				}

//				cout << s[i] << " " << s[j] << " " << ret << " " << c1 << " " << c2 << endl;

				maxi = MAX(maxi, 2*ret + MAX(c1, c2));
			}
		}
	}

	printf("BF: %d\n", maxi);
}

int main()
{
	N = SI;
	M = SI;
	REP(i,N)
	{
		cin >> s[i];
		f(i);
	}

/*	REP(i,N)
	{
		cout << s[i] <<": ";
		REP(j,M)
		{
			cout << HF[i][j] << " ";
		}
		cout << endl;
	}
	REP(i,N)
	{
		cout << s[i] <<": ";
		REP(j,M)
		{
			cout << HB[i][j] << " ";
		}
		cout << endl;
	}
*/

	bf();

	int maxi = -1;
	REP(i,N)
	{
		if(isPalindrome(i))
		{
			maxi = MAX(maxi, M);
		}
		
		REP(j,N)
		{
			if(i == j)
			{	
				continue;
			}
			else
			{
				int ret = g(i, j);

				int c1 = 0, ind = ret;
				while(ind < M && s[i][ind] == s[i][ret])
				{
					++c1;
					++ind;
				}

				int c2 = 0;
				ind = M-ret-1;
				while(ind >= 0 && s[j][ind] == s[j][M-ret-1])
				{
					++c2;
					--ind;
				}

//				cout << s[i] << " " << s[j] << " " << ret << " " << c1 << " " << c2 << endl;

				maxi = MAX(maxi, 2*ret + MAX(c1, c2));
			}
		}
	}

	printf("%d\n", maxi);

	return 0;
}
