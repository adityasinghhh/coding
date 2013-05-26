
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

int main()
{
	int N = SI, Q = SI;
	string a, b;
	cin >> a >> b;

	set<int> zz, zo, oz, oo;
	REP(i,N)
	{
		if(a[i] == '0')
		{
			if(b[i] == '0') { zz.insert(i); }
			else { zo.insert(i); }
		}
		else
		{
			if(b[i] == '0') { oz.insert(i); }
			else { oo.insert(i); }
		}
	}

	while(Q--)
	{
		string s;
		cin >> s;

		if(s == "set_a")
		{
			int i = SI, ch = SI + '0';
			if(a[i] == ch)
			{
			}
			else
			{
				if(a[i] == '0')
				{
					if(b[i] == '0')
					{
						zz.erase(i);
						oz.insert(i);
					}
					else
					{
						zo.erase(i);
						oo.insert(i);
					}
				}
				else
				{
					if(b[i] == '0')
					{
						oz.erase(i);
						zz.insert(i);
					}
					else
					{
						oo.erase(i);
						zo.insert(i);
					}
				}
				a[i] = ch;
			}
		}
		else if(s == "set_b")
		{
			int i = SI, ch = SI + '0';
			if(b[i] == ch)
			{
			}
			else
			{
				if(a[i] == '0')
				{
					if(b[i] == '0')
					{
						zz.erase(i);
						zo.insert(i);
					}
					else
					{
						zo.erase(i);
						zz.insert(i);
					}
				}
				else
				{
					if(b[i] == '0')
					{
						oz.erase(i);
						oo.insert(i);
					}
					else
					{
						oo.erase(i);
						oz.insert(i);
					}
				}
				b[i] = ch;
			}
		}
		else 
		{
			int x = SI;
			set<int>::iterator it;

			if(x == N)
			{
				if(zz.size() == 0)
				{
					if(oo.size() == 0) { printf("0"); }
					else { printf("1"); }
				} 
				else if(oo.size() == 0)
				{
					printf("0");
				}
				else 
				{
					it = lower_bound(zz.begin(), zz.end(), x);
					--it;

					int zzi = *it;

					it = lower_bound(oo.begin(), oo.end(), x);
					--it;

					int ooi = *it;

					if(ooi < zzi) { printf("0"); }
					else { printf("1"); }
				}
			}
			else
			{
				if(oo.size() == 0)
				{
					int v = (a[x]-'0') + (b[x]-'0');
					if(v == 2)
					{
						printf("0");
					}
					else
					{
						printf("1");
					}
				}
				else
				{
					it = oo.begin();
					if(*it > x)
					{
						int v = (a[x]-'0') + (b[x]-'0');
						if(v == 2)
						{
							printf("0");
						}
						else
						{
							printf("1");
						}
					}
					else if(*it == x)
					{
						printf("0");
					}
					else
					{
						if(zz.size() == 0)
						{
							int v = 1 + (a[x]-'0') + (b[x]-'0');
							if(v == 3)
							{
								printf("1");
							}
							else if(v == 2)
							{
								printf("0");
							}
							else
							{
								printf("1");
							}
						}
						else
						{
							it = zz.begin();
							if(*it > x)
							{
								int v = 1 + (a[x]-'0') + (b[x]-'0');
								if(v == 3)
								{
									printf("1");
								}
								else if(v == 2)
								{
									printf("0");
								}
								else
								{
									printf("1");
								}

							}
							else if(*it == x)
							{
								printf("1");
							}
							else
							{
								it = lower_bound(zz.begin(), zz.end(), x);
								--it;

								int zzi = *it;

								it = lower_bound(oo.begin(), oo.end(), x);
								--it;

								int ooi = *it;

								if(ooi < zzi)
								{
									int v = (a[x]-'0') + (b[x]-'0');
									if(v == 2)
									{
										printf("0");
									}
									else
									{
										printf("1");
									}
								}
								else
								{
									int v = 1 + (a[x]-'0') + (b[x]-'0');
									if(v == 3)
									{
										printf("1");
									}
									else if(v == 2)
									{
										printf("0");
									}
									else
									{
										printf("1");
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("\n");

	return 0;
}
