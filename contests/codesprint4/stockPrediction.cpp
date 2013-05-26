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

void printTransactions(double m, int k, int d, vector <string> name, vector <int> owned, vector < vector <double> > prices) 
{
	int sz = name.size();
	vector<pair<double, int> > diff;
	REP(i,sz)
	{
		diff.PB(MP(prices[i][4]-prices[i][1], i));
	}

	SORT(diff);

	vector<pair<pair<string, string>, int> > print;
	int i = 0;
	while(diff[i].first < 0.0)
	{
		int buy = (int)(int)(m/prices[diff[i].second][4]);
		
		if(buy == 0)
		{
			++i;
			continue;
		}

		print.PB(MP(MP(name[diff[i].second], "BUY"), buy));
		
		break;
	}

	i = sz-1;
	while(diff[i].first > 0.0)
	{
		if(owned[diff[i].second])
		{
			print.PB(MP(MP(name[diff[i].second], "SELL"), owned[diff[i].second]));
			
			break;
		}

		--i;
	}

	printf("%d\n", (int)print.size());
	REP(i,print.size())
	{
		cout << print[i].first.first << " " << print[i].first.second << " " << print[i].second << endl;
	}
}

int main() {
	double _m;
	cin >> _m;

	int _k;
	cin >> _k;

	int _d;
	cin >> _d;

	vector<string> _name;
	vector<int> _owned;
	vector < vector <double> > _prices;

	string _name_item;
	int _owned_item;
	double _prices_item_item;

	for(int _i=0; _i<_k; _i++) {
		cin >> _name_item;
		_name.push_back(_name_item);

		cin >> _owned_item;
		_owned.push_back(_owned_item);

		vector <double> _prices_item;
		for(int _j = 0; _j<5; _j++) {
			cin >> _prices_item_item;
			_prices_item.push_back(_prices_item_item);
		}
		_prices.push_back(_prices_item);        

	}

	printTransactions(_m, _k, _d, _name, _owned, _prices);

	return 0;
}
