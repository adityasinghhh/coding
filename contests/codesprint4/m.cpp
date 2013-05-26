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
	int cycle = -1;
	FOR(i,1,name.size())
	{
		if(name[i] == name[0])
		{
			cycle = i;
			break;
		}
	}

	int sz;
	if(cycle == -1)
	{
		sz = name.size();
	}
	else
	{
		sz = cycle;
	}

	int T = name.size()/sz;
	REP(zz,T)
	{
		vector<pair<double, int> > diff;
		REP(i,sz)
		{
			diff.PB(MP(prices[zz*T+i][4]-prices[zz*T+i][0], zz*T+i));
		}

		SORT(diff);

		double M = m;
		vector<pair<string, pair<string, int> > > sell, buy;
		REPD(i,sz)
		{
			if(diff[i].first < 0.0)
			{
				break;
			}

			M += prices[diff[i].second][4] * owned[diff[i].second];

			if(owned[diff[i].second])
			{
				sell.PB(MP(name[diff[i].second], MP("SELL", owned[diff[i].second])));
			}
		}

		double x = 2.0, i = 0;
		while(m/x > 1.0)
		{
			if(diff[i].first > 0.0)
			{
				int prevI = i;
				i = 0;
				if(i == prevI)
				{
					break;
				}
			}

			int l = 0, e = 1000000000, mid;
			while(l < e)
			{
				mid = l + (e-l+1)/2;
				if(m/x - mid * prices[diff[i].second][4] >= 0.0)
				{
					l = mid;
				}
				else
				{
					e = mid-1;
				}
			}

			if(l)
			{
				buy.PB(MP(name[diff[i].second], MP("BUY", l)));
			}
			x *= 2.0;
			++i;

			M -= prices[diff[i].second][4] * l;
		}

		printf("%d\n", (int)(sell.size()+buy.size()));
		REP(i,sell.size())
		{
			cout << sell[i].first << " " << sell[i].second.first << " " << sell[i].second.second << endl;
		}
		REP(i,buy.size())
		{
			cout << buy[i].first << " " << buy[i].second.first << " " << buy[i].second.second << endl;
		}
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
