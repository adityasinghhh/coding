
#include<algorithm>
#include<assert.h>
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
#include<sstream>
#include<vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

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
	int N = SI, M = SI;

	vector<string> ans;
	VI sign;
	vector<vector<double> > feature;

	REP(i,N)
	{
		string s; cin>>s; ans.PB(s);

		cin>>s; if(s[0] == '+') { sign.PB(1); } else { sign.PB(-1); }

		vector<double> f; f.PB(0.0);
		int id;
		char ch;
		double val;
		REP(j,M)
		{
			cin>>s; 
			istringstream inp(s); inp >> id >> ch >> val;
			f.PB(val);
		}
		feature.PB(f);
	}

	vector<double> mean, maxi;

	mean.PB(0.0); maxi.PB(0.0);
	FOR(j,1,M+1)
	{
		double sum = 0.0;
		REP(i,N) { sum += feature[i][j]; }
		double avg = sum/N;
		mean.PB(avg);
		REP(i,N) { feature[i][j] -= avg; }
		double maxii = LLONG_MIN;
		REP(i,N) { maxii = max(maxii, feature[i][j]); }
		maxi.PB(maxii);
		if(maxii == 0.0) { continue; }
		REP(i,N) { feature[i][j] /= maxii; }
		REP(i,N) { feature[i][j] += 1.0; }
		REP(i,N) { feature[i][j] /= 2.0; }
	}

	/*REP(i,N)
	{
		printf("%s\t", ans[i].c_str());
		printf("%d\t", sign[i]);
		FOR(j,1,M+1)
		{
			printf("%d:%lf\t", j, feature[i][j]);
		}
		printf("\n");
	}*/

	int T = SI;
	while(T--)
	{
		string s, q; cin>>q;

		vector<double> f; f.PB(0.0);
		int id;
		char ch;
		double val;
		FOR(j,1,M+1)
		{
			cin>>s; 
			istringstream inp(s); inp >> id >> ch >> val;
			val -= mean[j];

			if(maxi[j] == 0.0) { f.PB(val); }
			else
			{
				val /= maxi[j];
				val += 1.0;
				val /= 2.0;
				f.PB(val);
			}
		}

		/*FOR(j,1,M+1)
		{
			printf("%d:%lf\t", j, f[j]);
		}
		printf("\n");*/

		int cntp = 0, cntn = 0;
		double mini = LLONG_MAX, sgn;
		REP(i,N)
		{
			double d = 0.0;
			FOR(j,1,M)
			{
				d += (f[j]-feature[i][j])*(f[j]-feature[i][j]);
			}

			//printf("Distance from %s with sign %d is %lf\n", ans[i].c_str(), sign[i], d);

			if(mini > d)
			{
				mini = d;
				sgn = sign[i];
			}
		}

		printf("%s ", q.c_str());
		printf(sgn == 1 ? "+1\n" : "-1\n");
	}
	
	return 0;
}
