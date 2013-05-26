
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
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define LL long long int
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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int main()
{
	int N = SI;
	set<string> m;
	set<string>::iterator it;
	while(N--)
	{
		string s;
		cin>>s;

		int l = s.length();

		REP(i,l)
		{
			string s1 = "";
			FOR(j,i,l)
			{
				s1 += s[j];
			}
			
			int l1 = l-i;

			while(l1)
			{
				cout<<"::"<<s1<<"::";
				it = m.find(s1);
				if(it == m.end()) { m.insert(s1); cout<<"inserting::"<<s1<<"::"<<endl; }
				else { break; }
				
				s1[l1-1] = 0;
				--l1;
			}
		}
	}

	for(it = m.begin(); it != m.end(); ++it) { cout<<"**"<<*it<<"**"<<endl; } 
	vector<string> v(m.begin(),m.end());
//	REP(i,v.size()) { printf("%d: %s*\n", i,v[i].c_str()); }

	int Q = SI; 
	int sz = v.size();
	while(Q--)
	{
		int K = SI;
		if(K > sz) { printf("INVALID\n"); }
		else { cout<< v[K] << endl; }
	}

	return 0;
}
