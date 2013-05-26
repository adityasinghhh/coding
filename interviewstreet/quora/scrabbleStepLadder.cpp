
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

int dp[100];
void init()
{
	dp['A'] = 1;
	dp['B'] = 3;
	dp['C'] = 3;
	dp['D'] = 2;
	dp['E'] = 1;
	dp['F'] = 4;
	dp['G'] = 2;
	dp['H'] = 4;
	dp['I'] = 1;
	dp['J'] = 8;
	dp['K'] = 5;
	dp['L'] = 1;
	dp['M'] = 3;
	dp['N'] = 1;
	dp['O'] = 1;
	dp['P'] = 3;
	dp['Q'] = 10;
	dp['R'] = 1;
	dp['S'] = 1;
	dp['T'] = 1;
	dp['U'] = 1;
	dp['V'] = 4;
	dp['W'] = 4;
	dp['X'] = 8;
	dp['Y'] = 4;
	dp['Z'] = 10;
}

map<string, int> S, ID;
map<string, int>::iterator Sit, IDit;
map<string, set<string> > M;
int K, N;
int *v1, *v2;
int f1(string a, int ind, int score)
{
//	cout << a << " " << ind << " " << score << endl; 

	int maxi = score;
	set<string> SET = M[a];
	set<string>::iterator it;
	for(it = SET.begin(); it != SET.end(); ++it)
	{
		if(S[*it] < S[a])
		{
			M[*it].erase(a);
			int x = f1(*it, ind+1, score + S[*it]);
			maxi = MAX(maxi, x);
			M[*it].insert(a);
		}	
	}

	v1[ind] = MAX(maxi, v1[ind]);

	return maxi;
}

int f2(string a, int ind, int score)
{
//	cout << a << " " << ind << " " << score << endl; 

	int maxi = score;
	set<string> SET = M[a];
	set<string>::iterator it;
	for(it = SET.begin(); it != SET.end(); ++it)
	{
		if(S[*it] > S[a])
		{
			M[*it].erase(a);
			int x = f2(*it, ind+1, score + S[*it]);
			maxi = MAX(maxi, x);
			M[*it].insert(a);
		}	
	}
	
	v2[ind] = MAX(maxi, v2[ind]);

	return maxi;
}

int main()
{
	init();

	K = SI; N = SI;
	string s[20][N+1];
	int p[20] = {0};

	REP(i,N)
	{
		string t; 
		cin >> t;
		int l = t.length();

		s[l][p[l]++] = t;
	}
	
	sort(s[K], s[K]+p[K]);

	int score[20][N+1];
	REP(i,p[K])
	{
		score[K][i] = 0;
		REP(j,K)
		{
			score[K][i] += dp[s[K][i][j]];
		}

		S[s[K][i]] = score[K][i];
		ID[s[K][i]] = i;
	}

	REP(i,p[K])
	{
		REP(j,K)
		{
			string t = s[K][i];
			REP(k,26)
			{
				if(s[K][i][j] == k+'A') { continue; }
				
				t[j] = k+'A';

				IDit = ID.find(t);
				if(IDit != ID.end())
				{
					map<string, set<string> >::iterator it = M.find(s[K][i]);
					if(it == M.end())
					{
						set<string> SET;
						M[s[K][i]] = SET;
					}

					M[s[K][i]].insert(t);
				}
			}
		}
	}

//	REP(i,p[K]) { cout << s[K][i] << " " << S[s[K][i]] << endl; }

	int maxi = -1;
	REP(i,p[K])
	{
//		printf("Midpoint %s\n", s[K][i].c_str());

		v1 = new int[p[K]+1];
		v2 = new int[p[K]+1];
		FILL(v1,-1); FILL(v2,-1);
		f1(s[K][i], 1, 0);
		f2(s[K][i], 1, 0);

//		cout << "V1: "; REP(j,p[K]) { cout << v1[j] << " "; } cout << endl;
//		cout << "V2: "; REP(j,p[K]) { cout << v2[j] << " "; } cout << endl;

		FOR(j,1,p[K])
		{
			if(!v1[j] || !v2[j]) { break; }

			maxi = MAX(maxi, v1[j] + S[s[K][i]] + v2[j]);
			++j;
		}
	}

	printf("%d\n", maxi);
	
	return 0;
}
