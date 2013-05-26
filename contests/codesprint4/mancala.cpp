
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

/* Head ends here */

void printNextMove(int player, int player1Mancala, vector <int> player1Marbles, int player2Mancala, vector <int> player2Marbles) {
	if(player == 2)
	{
		swap(player1Mancala, player2Mancala);
		swap(player1Marbles, player2Marbles);

		REP(i,3)
		{
			swap(player1Marbles[i], player1Marbles[6-i-1]);
			swap(player2Marbles[i], player2Marbles[6-i-1]);
		}
	}

	int best = 0, maxi = -1;
	REP(i,6)
	{
		if(player1Marbles[i] == 0)
		{
			continue;
		}

		int p1m = player1Mancala, p2m = player2Mancala;
		VI p1M = player1Marbles, p2M = player2Marbles;

		while(true)
		{
			bool flag = false, flag1 = false;
			int x = p1M[i], z = 0, j = i+1, ind = -1;
			p1M[i] = 0;

			while(x)
			{
				if(z)
				{
					if(j>=0)
					{
						++p2M[j];
						--j;
						--x;
					}
					else
					{
						j = 0;
						z = 1-z;
					}
				}
				else
				{
					if(j<6)
					{
						++p1M[j];
						++j;
						--x;
						if(x == 0 && p1M[j] == 1)
						{
							flag1 = true;
							ind = j-1;
						}
					}
					else
					{
						j = 5;
						++p1m;
						--x;
						if(x == 0)
						{
							flag = true;
						}
						z = 1-z;
					}
				}
			}

			if(flag)
			{
				continue;
			}

			if(flag1)
			{
				p1M[ind] += p2M[6-ind-1];
			}

			break;
		}

		int tot = p1m;
		REP(j,6)
		{
			tot += p1M[j];
		}

		if(tot > maxi)
		{
			maxi = tot;
			best = i;
		}
	}

	printf("%d\n", best+1);
}
/* Tail starts here */
int main() {
	int _player;
	cin >> _player;

	int _player1Mancala;
	cin >> _player1Mancala;


	int _player1Marbles_size=6;
	vector<int> _player1Marbles;
	int _player1Marbles_item;
	for(int _player1Marbles_i=0; _player1Marbles_i<_player1Marbles_size; _player1Marbles_i++) {
		cin >> _player1Marbles_item;
		_player1Marbles.push_back(_player1Marbles_item);
	}

	int _player2Mancala;
	cin >> _player2Mancala;


	int _player2Marbles_size=6;
	vector<int> _player2Marbles;
	int _player2Marbles_item;
	for(int _player2Marbles_i=0; _player2Marbles_i<_player2Marbles_size; _player2Marbles_i++) {
		cin >> _player2Marbles_item;
		_player2Marbles.push_back(_player2Marbles_item);
	}

	printNextMove(_player, _player1Mancala, _player1Marbles, _player2Mancala, _player2Marbles);

	return 0;
}

