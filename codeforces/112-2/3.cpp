
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

void bf(int K, string &s)
{
	int l = s.length(), cnt = 0;
	REP(i,l)
	{
		FOR(j,i,l)
		{
			int c = 0;
			FOR(k,i,j+1)
			{
				if(s[k] == '1')
				{
					++c;
				}
			}

			if(c == K)
			{
				printf("%d to %d\n", i, j);
				++cnt;
			}
		}
	}

	printf("%d\n", cnt);
}

int main()
{
	int K = SI;
	string s;
	cin >> s;

//	bf(K, s);

	if(K == 0)
	{
		LL ans = 0ll;
		int i = 0, l = s.length();
		while(i < l)
		{
			int cnt = 0;
			while(i < l && s[i] == '1')
			{
				++i;
			}

			while(i < l && s[i] == '0')
			{
				++i;
				++cnt;
			}

			ans += 1ll*cnt*(cnt+1)/2;
		}

		cout << ans << endl;
	}
	else if(K == 1)
	{
		int l = s.length();
		LL ans = 0ll;
		REP(i,l)
		{
			if(s[i] == '1')
			{
				int left = i-1;
				while(left >=0 && s[left] == '0')
				{
					--left;
				}
				int right = i+1;
				while(right < l && s[right] == '0')
				{
					++right;
				}

				++left;
				--right;
				if(left == -1) { ++left; }
				if(right == l) { --right; }
				
//				printf("At %d, left = %d, right = %d\n", i, left, right);

				ans += 1ll*(i-left+1)*(right-i+1);
			}
		}

		cout << ans << endl;
	}
	else
	{
		int l = s.length(), i = 0, j = 0, cnt = 0;
		while(j < l && cnt < K)
		{
			if(s[j] == '1')
			{
				++cnt;
			}

			++j;
		}

		if(cnt != K)
		{
			printf("0\n");
			return 0;
		}

		LL ans = 0ll;
		while(j < l)
		{
//			printf("Starting at %d and %d\n", i, j);
			int cntj = 1;
			while(j < l && s[j] == '0')
			{
				++j;
				++cntj;
			}

			int cnti = 1;
			while(i < l && s[i] == '0')
			{
				++i;
				++cnti;
			}

			++i;
			++j;
//			printf("Leaving at %d and %d\n", i, j);

			ans += 1ll*cnti*cntj;
		}

		if(s[l-1] == '1')
		{
//			printf("Compensating %d to %d\n", i, j);
			int cnti = 1;
			while(i < l && s[i] == '0')
			{
				++i;
				++cnti;
			}

			ans += 1ll*cnti;
		}
			
		cout << ans << endl;
	}

	return 0;
}
