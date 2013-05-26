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

class Stamp {
	public:
		bool valid(string &s, int start, int end)
		{
			bool r = false, b = false, g = false;
			FOR(i,start,end+1)
			{
				r |= (s[i] == 'R');
				g |= (s[i] == 'G');
				b |= (s[i] == 'B');
			}

			if(!r && !g && !b)
			{
				return true;
			}

			return !(r&g || r&b || g&b);
		}

		int dp[105][105];
		int f(string &s, int i, int l)
		{
			int &m = dp[i][l];
			if(m != -1)
			{
				return m;
			}

			if(i+l >= s.length())
			{
				if(valid(s, s.length()-l, s.length()-1))
				{
					return m = 1;
				}
				return m = -1;
			}

			int mini = INT_MAX;
			REP(k,l)
			{
				if(i-l+1+k < 0)
				{
					continue;
				}

				if(valid(s, i-l+1+k, i+k))
				{
					int ret = f(s, i+k+1, l);
					if(ret != -1)
					{
						mini = MIN(mini, ret+1);
					}
				}
			}


			return m = (mini == INT_MAX ? -1 : mini);
		}

		int getMinimumCost(string s, int sc, int pc) {
			int l = s.length();
			int mini = INT_MAX;
			FILL(dp, -1);
			FOR(i,1,l+1)
			{
//				cout << i << " : " << f(s, 0, i) << endl;
				int ret = f(s, 0, i);
				if(ret == -1)
				{
					continue;
				}

				mini = MIN(mini, pc * ret + i*sc);
			}

/*			REP(i,l+1)
			{
				REP(j,l+1)
				{
					cout << "(" << i << "," << j << "): " << dp[i][j] << " ";
				}
				cout << endl;
			}
*/
			return mini;
		}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1 << "," << p2;
	cout << "]" << endl;
	Stamp *obj;
	int answer;
	obj = new Stamp();
	clock_t startTime = clock();
	answer = obj->getMinimumCost(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	string p0;
	int p1;
	int p2;
	int p3;

	{
		// ----- test 0 -----
		p0 = "RRGGBB";
		p1 = 1;
		p2 = 1;
		p3 = 5;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = "R**GB*";
		p1 = 1;
		p2 = 1;
		p3 = 5;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = "BRRB";
		p1 = 2;
		p2 = 7;
		p3 = 30;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = "R*RR*GG";
		p1 = 10;
		p2 = 58;
		p3 = 204;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		p0 = "*B**B**B*BB*G*BBB**B**B*";
		p1 = 5;
		p2 = 2;
		p3 = 33;
		all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		p0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
		p1 = 7;
		p2 = 1;
		p3 = 30;
		all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
