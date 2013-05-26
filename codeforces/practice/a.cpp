#include<iostream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define llscan(n) scanf("%lld",&n)
#define cscan(n) scanf("%c",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define MP make_pair
#define PB push_back
#define LL long long
#define _MAX 10000
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(i=0;i<n;++i)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
typedef pair<long long,int> PL;
#define SZ(a) int((a).size())
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

struct nd{
	LL a,b;
	int c,id;
};

bool compare(nd n1, nd n2) { return n1.c < n2.c; }

pair <LL, PI > dp[53][53][105];
const pair <LL, PI > nul = MP(-1,MP(-1,-1));

nd inp[55];
int m,K;

LL maxLL(LL a, LL b) {return a>b?a:b;}

pair <LL, PI> compute(int id, int days, LL diff)
{
	if(dp[id][days][diff] != nul) return dp[id][days][diff];
	LL ex = inp[id].a + diff;
	if(days == 1) return dp[id][days][diff] = MP(ex,MP(-1,-1));
	LL prev = -1;
	if(ex - K < 0) return nul;
	vector <LL> v; v.PB(ex - K); if(ex % K == 0) v.PB(ex/K);
	LL maxi = -1, prevdiff = -1;
	int pos=-1;
	for(int i = 0;inp[i].c<inp[id].c;++i){
		TR(v,it){
			prev = *it;
			LL cdiff = -1;
			if(prev < inp[i].a || prev > inp[i].b) continue;
			cdiff = prev - inp[i].a;
			LL tmp = dp[i][days-1][cdiff].first;
			if(tmp > maxi) { maxi = tmp; pos = i; prevdiff = cdiff; }
		}
	}
	if(maxi == -1) return nul;
	return dp[id][days][diff] = MP(maxi + ex, MP(pos,(int)(prevdiff)));
}

int main()
{
	int n,k,i,j;
	iscan(n);
	iscan(m);
	iscan(K);
	for(i=0;i<=m;++i) for(k=0;k<=n;++k) for(j=0;j<=100;++j) dp[i][k][j] = nul;
	REP(i,m) {
		LL aa,bb;
		int cc;
		cin>>aa;
		cin >> bb;
		iscan(cc);
		inp[i] = (nd){aa,bb,cc,i+1};
	}

	sort(inp,inp+m,compare);

	for(k=1;k<=n;++k) for(i=0;i<m;++i) for(LL j = inp[i].a; j<=inp[i].b; ++j) dp[i][k][j - inp[i].a] = compute(i, k, j - inp[i].a);

	LL maxi = -1;
	int pos = -1;
	LL cdiff;
	for(i=0;i<m;++i)
	{
		for(LL j = inp[i].a; j<=inp[i].b; ++j){
			LL diff=j - inp[i].a;
			if(dp[i][n][diff].first > maxi) {maxi = dp[i][n][diff].first; pos = i; cdiff = diff;}
		}
	}
	if(pos == -1) {printf("NO\n"); return 0; }

	vector < pair <int, LL> > ans;

	int cur = pos;

	ans.PB(MP(inp[pos].id,inp[pos].a+cdiff));
	for(i=n-1;i>=1;--i){
		int tcur = dp[cur][i+1][cdiff].second.first;
		LL tdiff = dp[cur][i+1][cdiff].second.second;
		cur = tcur; cdiff = tdiff;
		ans.PB(MP(inp[cur].id,inp[cur].a + cdiff));
	}

	int sz=SZ(ans);
	cout<<"YES\n";
	for(i=sz-1;i>=0;--i) cout<<ans[i].first<< " "<<ans[i].second<<endl;

	return 0;
}
