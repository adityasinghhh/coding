#include<iostream>
#include<sstream>
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

#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define MP make_pair
#define PB push_back
#define LL long long
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REPD(i,b) for(int i=(b)-1;i>=0;--i)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a) ((a)<0?-(a):(a))

typedef vector<int> VI; 
typedef pair<int,int> PI; 
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define RAND(x) ((int)(((rand()*1.0)/RAND_MAX)*(x)))

//-----------------------BINARY INDEXED TREE---------------------------------
int tree[100000 + 10];
int BIT_RANGE; // this is the maximum value of the index ...
int read(int idx) { int ans = 0;
	while(idx > 0) {
		ans += tree[idx]; idx -= (idx & -idx); 
	} return ans; }

void update(int idx, int val){
	while(idx <= BIT_RANGE)
	{ tree[idx] += val; idx += (idx & -idx); }
	return; }
//--------------------------------------------------------------------------
//-----------------------BIPARTITE MATCHING---------------------------------
#define MAXN 1000

class BipartiteMatching{
	int isMatched[MAXN]; // equal to the partner (from the left) if matched or = -1 ...
	bool checkedAlready[MAXN];
	bool matchedAlready[MAXN];
	bool search(int);
	public:
		BipartiteMatching(int,int);
		int nleft, nright; // number of nodes in the left and right ..
		bool edges[MAXN][MAXN];
		int maxMatching();
};

BipartiteMatching::BipartiteMatching(int nl, int nr)
{
	nleft = nl;
	nright = nr;
	int i,j;
	for(i=0;i<nleft;++i) for(j=0;j<nright;++j) edges[i][j] = false;
	for(j=0;j<nright;++j) isMatched[j] = -1;
	for(i=0;i<nleft;++i) matchedAlready[i] = false;
}

bool BipartiteMatching::search(int pos)
{
	if(checkedAlready[pos])	return false;
	checkedAlready[pos] = true;
	int i;
	for(i = 0; i<nright; ++i){
		if(edges[pos][i]){
			if(isMatched[i] == -1){
				isMatched[i] = pos;
				matchedAlready[pos] = true;
				return true;
			}
			else{
				if(search(isMatched[i])){
					isMatched[i] = pos;
					matchedAlready[pos] = true;
					return true;
				}
			}
		}
	}
	return false;
}

int BipartiteMatching::maxMatching()
{
	int i,j,ans=0;
	bool changed = true;
	while(changed){
		changed = false;
		for(i=0;i<nleft;++i) checkedAlready[i] = false;
		for(i=0;i<nleft;++i){
			if(matchedAlready[i] == false){
				if(search(i)){ ++ans; changed = true; }
			}
		}
	}
	return ans;
}
//--------------------------------------------------------------------------
//-----------------CLOSEST PAIR------------------------------------------
vector <pair <int, PI > > pt;
// ^^^ is the input vector of points - first id and then (x,y)
bool compare(pair <int, PI > p, pair <int, PI > q) { return p.second.first < q.second.first; }
bool compare2(pair <int, PI > p, pair <int, PI > q) { return p.second.second < q.second.second; }
int dist(int i, int j)
{
	int d1 = (pt[i].second.first - pt[j].second.first), d2 = (pt[i].second.second - pt[j].second.second);
	return d1*d1 + d2*d2;
}

PI solve(int s, int e) // start and end index in the vector pt ..
{
	if(e-s+1 <= 3){
		int mini = INT_MAX;
		PI ans;
		for(int i = s;i<=e;++i)
			for(int j = i+1;j<=e;++j){
				int d = dist(i,j);
				if(mini > d) { mini = d; ans = MP(i,j);}
			}
		return ans;
	}
	PI ans;
	int mid = (s+e)/2;
	PI lans = solve(s,mid), rans = solve(mid+1,e);
	int mini;
	int dl = dist(lans.first,lans.second), dr = dist(rans.first,rans.second);
	if(dl < dr) { mini = dl; ans = lans; }
	else { mini = dr; ans = rans; }
	vector <pair <int, PI> > v;
	int midx = pt[mid].second.first;
	int i = mid;
	while(i>=s && (midx - pt[i].second.first) <= mini) { v.PB(MP(i,pt[i].second)); --i; }
	i = mid+1;
	while(i<=e && (pt[i].second.first - midx) <= mini) { v.PB(MP(i,pt[i].second)); ++i; }
	sort(ALL(v),compare2);
	int up = 0, down = 0;
	int sz = SZ(v);
	while(up < sz)
	{
		while(down < sz-1 && v[down+1].second.second - v[up].second.second <= mini) ++down;
		for(int i = up; i<=down; ++i)
			for(int j = i+1; j<=down; ++j){
				int d = dist(v[i].first,v[j].first);
				if(mini > d) { mini = d; ans = MP(v[i].first,v[j].first); }
			}
		++up;
	}
	return ans;
}
//----------------------------------------------------------------------------
//------------------------EXTENDED EUCLID------------------------------------
PI extendedEuclid(int a, int b)
{
	int x = 0, y = 1, lastx = 1, lasty = 0;
	while(b){
		int q = a/b;
		int temp = a; a = b; b = temp % b;
		temp = x; x = lastx - q*x; lastx = temp;
		temp = y; y = lasty - q*y; lasty = temp;
	}
	return MP(lastx,lasty);
}
//---------------------------------------------------------------------------
//---------------------CONVEX HULL------------------------------------------
template<class T> inline int size(const T&c) { return c.size(); }

typedef int coord;

struct Point {
	coord x,y;
	Point() {}
	Point(coord x,coord y):x(x),y(y) {}
};

Point operator+(const Point &A,const Point&B) { return Point(A.x+B.x,A.y+B.y); }
Point operator-(const Point &A,const Point&B) { return Point(A.x-B.x,A.y-B.y); }
Point operator*(coord c, const Point &A) { return Point(c*A.x,c*A.y); }
coord operator^(const Point&A,const Point&B) { return A.x*B.y-A.y*B.x; }
coord operator*(const Point&A,const Point&B) { return A.x*B.x+A.y*B.y; }
coord len2(const Point&A) { return A*A; }

bool operator<(const Point&a, const Point&b) {
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

vector<Point> points;
vector<Point> hull;

void cHull() { //prints in anticlockwise starting from the bottommost (leftmost) ..
	sort(ALL(points));
	int npoints = SZ(points);
	int start = 0;
	hull.clear();
	hull.push_back(points[0]);
	int nh = 1;
	FOR(i,1,npoints) {
		Point p = points[i];
		while(nh-start >= 2 && ((p-hull[nh-2])^(p-hull[nh-1])) >= 0) {
			--nh; hull.pop_back();
		}
		hull.push_back(p); ++nh;
	}
	start = nh-1;
	for(int i = npoints-2; i>=0; --i) {
		Point p = points[i];
		while(nh-start >= 2 && ((p-hull[nh-2])^(p-hull[nh-1])) >= 0) {
			--nh; hull.pop_back();
		}
		hull.push_back(p); ++nh;
	}
	hull.pop_back();
}
//---------------------------------------------------------------------------
//--------KMP---------------------
int F[1000000 + 10];
void compute_failure_function(char *pat,int l)
{
	F[0] = 0; F[1] = 0;
	for(int i=2;i<=l;++i){
		int j = F[i-1];
		while(true){
			if(pat[j] == pat[i-1])	{F[i] = j+1;	break;}
			else if(j == 0)		{F[i] = 0;	break;}
			else			{j = F[j];}
		}
	}
	return;
}
//-------------------------------------------------
//----------------------LCA------------------------
#define MAX_NODES 11234
typedef struct{
	int v,dist;
}Ed;
int numOfNodes, logOfNodes;
int level[MAX_NODES], parent[MAX_NODES], mark[MAX_NODES], upcost[MAX_NODES];
vector <Ed> edge[MAX_NODES];
int P[MAX_NODES][16], C[MAX_NODES][16]; //P[i][j] has the 2^jth parent of i and C[i][j] has the cost of reaching P[i][j] from i ...
//Both the arrays have positive values for valid indices and -1 or 0 (or undefined) for invalid (i,j)
void init()
{
	int i,fp,fn,fl,fc,sz;
	queue <int> qn,qp,ql,qc;//qn stores nodes, qp their parent and ql their level and qc the cost of the edge with the parent ..
	FILL(mark,-1);
	qn.push(1); qp.push(0);	ql.push(0); qc.push(0);
	mark[1] = 1;
	while(!qn.empty())
	{
		fn = qn.front(); fp = qp.front(); fl = ql.front(); fc = qc.front();
		qn.pop(); qp.pop(); ql.pop(); qc.pop();
		parent[fn] = fp;
		level[fn] = fl;
		upcost[fn] = fc;
		sz = SZ(edge[fn]);
		REP(i,sz){
			if(mark[edge[fn][i].v] == -1){
				qn.push(edge[fn][i].v);
				mark[edge[fn][i].v] = 1;
				qp.push(fn);
				ql.push(fl+1);
				qc.push(edge[fn][i].dist);
			}
		}
	}
	return;
}
int compute(int i, int j)
{
	if(P[i][j] != -1) return P[i][j];
	if((1<<j) > level[i]) return P[i][j] = 0;
	if(j == 0) return P[i][j] = parent[i];
	return P[i][j] = compute(compute(i,j-1),j-1);
}
int computeminc(int i,int j)
{
	if(C[i][j] != -1) return C[i][j];
	if((1<<j) > level[i]) return C[i][j] = 0;
	if(j == 0) return C[i][j] = upcost[i];
	return C[i][j] = computeminc(i,j-1) + computeminc(compute(i,j-1),j-1);
}
void initLCA()
{
	FILL(P,-1); FILL(C,-1);
	for(logOfNodes = 0; (1<<logOfNodes) <= numOfNodes; ++logOfNodes); --logOfNodes;
	for(int i=1;i<=numOfNodes;++i) {
		for(int j=0;j<=logOfNodes;++j) {
			P[i][j] = compute(i,j);
			C[i][j] = computeminc(i,j);
		}
	}
	return;
}
int findLCA(int a,int b)
{
	if(level[a] < level[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	int j = logOfNodes;
	while(level[a] != level[b]){
		if( (level[a] - (1<<j)) >= level[b] ) a = P[a][j];
		--j;
	}
	if(a == b) return a;
	for(j=logOfNodes; j>=0; --j) {
		if(P[a][j] != 0 && P[a][j] != P[b][j]) { a = P[a][j]; b = P[b][j];}
	} // this gets me one level lower to the LCA ...
	return parent[a];
}
//-------------------------------------------------
//---------------LONGEST INCREASING SUBSEQUENCE-----------------
#define MAXLEN 11234
class LIS{
	public:
	int maxlen;
	int help[MAXLEN], arr[MAXLEN], lis[MAXLEN]; //lis[i] has the length of LIS ending at arr[i] 
	int bin_search_max(int num, int HI);
	LIS(int a[], int n) { maxlen = n; REP(i,n) arr[i] = a[i]; }
	int findLIS();
	VI getLIS();
};
int LIS::bin_search_max(int num, int HI)
{
	int hi = HI+1, lo = 0, mid;
	while(hi  > lo + 1) {
		mid = (hi+lo)>>1;
		if(help[mid] < num) lo = mid;
		else hi = mid;
	}
	return lo;
}
int LIS::findLIS()
{
	// initialize help[] to INT_MAX ..
	int i;
	for(i=0;i<=maxlen;++i) help[i] = INT_MAX;
	//--------------------------------
	int ans = 0,len;
	help[0] = INT_MIN; // this assumes that no number in the array is less than or equal to INT_MIN
	for(i=0;i<maxlen;++i){
		len = bin_search_max(arr[i],ans) + 1;
		lis[i] = len;
		if(help[len] > arr[i]) help[len] = arr[i];
		if(ans < len) ans = len;
	}
	return ans;
}

VI LIS::getLIS()
{
	int len = findLIS();
	VI v(len);
	int prev = INT_MAX, loc = maxlen-1;
	for(int i = len-1; i>=0; --i) {
		while(loc >= 0 && lis[loc] != i+1 && arr[loc] >= prev) --loc;
		prev = v[i] = arr[loc];
	}
	return v;
}
//----------------------------------------------------------------
//-------------------------MATRIX EXPONENTIATION------------------
#define SIZE 2
#define MOD 1000000007
struct matrix{
	int a[SIZE][SIZE];
	matrix() {}
	matrix(int init[][SIZE]) { REP(i,SIZE) REP(j,SIZE) a[i][j] = init[i][j]; }
};

matrix mult_mat(matrix &A, matrix &B)
{
	matrix ans;
	REP(i,SIZE) REP(j,SIZE) ans.a[i][j] = 0;
	REP(i,SIZE) REP(j,SIZE) REP(k,SIZE) { LL add = (((LL)(A.a[i][k]))*B.a[k][j])%MOD;
						ans.a[i][j] += add; if(ans.a[i][j] >= MOD) ans.a[i][j] -= MOD;}
	return ans;
}
matrix matExp(matrix A, int n)
{
	matrix ans;
	REP(i,SIZE) REP(j,SIZE) ans.a[i][j] = 0;
	REP(i,SIZE) ans.a[i][i] = 1;
	while(n)
	{
		if(n&1) ans = mult_mat(ans,A);
		A = mult_mat(A,A);
		n>>=1;
	}
	return ans;
}
//-------------------------------------------------------------------
//--------------------mypow, gcd, sieve -------------------------------
template<class T> T mypow(T a, T n, T mod = 0) { LL ans = 1, A = a; while(n) { if(n&1) ans*=A; n>>=1; A*=A; if(mod){ans %= mod; A%=mod; } } return (T)(ans);}
template<class T> T gcd(T a, T b) { if(a<b) swap(a,b); if(b==0) return a; return gcd(b,a%b); }

/* Either all arguments in the functions should be int or all should be long long */
//-------------------------------------------------------------------------
//-------------------------MAX FLOW BFS------------------------------------
#define MAXN 200
#define INF 20000000
//INF should be greater than the 2*max edge cap
int g[MAXN][MAXN];
char vis[MAXN];
int maxFlow(int source, int sink, int n)
{
	int ans = 0;
	int curr,i;
	queue <int> q,minc;
	bool flag = true;
	int prev[MAXN];
	while(flag){
		flag = false;
		FILL(vis,0);
		q.push(source); vis[source] = 1;
		minc.push(INF);
		while(!q.empty()){
			curr = q.front();	q.pop();
			int cap = minc.front(); minc.pop();
			if(curr == sink){
				//empty the queue ...
				while(!q.empty())	q.pop();
				while(!minc.empty()) minc.pop();

				// increase the flow ...
				ans += cap;

				//residual graph ...
				while(curr != source){
					g[prev[curr]][curr] -= cap; //flow will always be of value 1...
					g[curr][prev[curr]] += cap;
					curr = prev[curr];
				}
				flag = true;
			}
			else{
				for(i=0;i<n;++i){
					if(g[curr][i] > 0 && vis[i] == 0){
						prev[i] = curr;
						vis[i] = 1;
						q.push(i);
						minc.push(MIN(cap, g[curr][i]));
					}
				}
			}
		}
	}
	return ans;
}
//---------------------------------------------------------
//--------------------MAX FLOW DFS-------------------------
#define INF 20000000
//INF should be greater than the 2*max edge cap
int g[112][112];
char vis[112];
int sink, numNodes;
int dfs(int current, int mincap)
{
	if(current == sink) return mincap;
	vis[current] = 1;
	REP(i,numNodes)
	{
		if(!vis[i] && g[current][i] > 0)
		{
			int tmp = dfs(i,MIN(mincap,g[current][i]));
			if(tmp > 0)
			{
				g[current][i] -= tmp;
				g[i][current] += tmp;
				return tmp;
			}
		}
	}
	return 0;
}
int maxFlow(int source, int sink, int n)
{
	::sink = sink;
	numNodes = n;
	int ans = 0;
	for(;;)
	{
		FILL(vis,0);
		int tmp = dfs(source,INF);
		if(tmp == 0) return ans;
		ans += tmp;
	}
	return ans;
}
//-------------------------------------------------
//---------------------nCr-------------------------
long long int C[250][250]; //fill it with -1

long long int nCr(int n, int r) {
	if(n < r) return 0;
	if(r > n - r) r = n-r;
	if(r == 0) return 1;
	if(C[n][r] != -1) return C[n][r];
	C[n][r] = nCr(n-1,r-1) + nCr(n-1,r);
	return C[n][r];
}
//------------------------------------------------------
//------------PRIME SIEVE----------------------------
#define PRIME_RANGE 1000000
char isPrime[PRIME_RANGE + 100]; //isPrime[prime] = 0
int prime[100000], p_cnt;
void generate()
{
	isPrime[0] = isPrime[1] = 1;
	int i=2,z=0;
	while(i<PRIME_RANGE + 10) {
		if(isPrime[i] == 0) {
			prime[z++]=i;
			for(long long j=i; i*j < PRIME_RANGE + 10; ++j)
				isPrime[i*j] = 1;
		}
		++i;
	}
	p_cnt = z;
	return;
}
//-----------------------------------------------------
//----------------------Strongly Connected Components------
#define MAXNODES 1123
vector <int> graph[MAXNODES], Xpose[MAXNODES];
vector < set <int> > SCC;
vector <PI> ft; //finishing time paired with node id..
char vis[MAXNODES];
int ttime;
set <int> cur; // current set .. i.e. the one we are constructing in a particular dfs2
void dfs(int i)
{
	vis[i] = 1;
	int sz = SZ(graph[i]);
	REP(j,sz) if(!vis[graph[i][j]]) dfs(graph[i][j]);
	++ttime;
	ft.PB(MP(ttime,i));
	return;
}
void dfs2(int i)
{
	vis[i] = 1; cur.insert(i);
	int sz = SZ(Xpose[i]);
	REP(j,sz) if(!vis[Xpose[i][j]]) dfs2(Xpose[i][j]);
	return;
}
void stronglyConnected(int n) // assumes nodes are from 0 to n-1 and graph has the edges and Xpose has the inverted edges...
{ //ignores self-edges..
	FILL(vis,0); ttime = 0; ft.clear();
	REP(i,n) if(!vis[i]) dfs(i);
	sort(ALL(ft));
	reverse(ALL(ft)); // now it has the nodes (ft[].second) in topological order ..
	FILL(vis,0);
	REP(i,n) // ft has n elements
	{
		int j = ft[i].second;
		if(!vis[j]){
			cur.clear();
			dfs2(j);
			SCC.PB(cur);
		}
	}
}
//----------------------------------------------------------
//-------------------SEGMENT TREE (LAZY PROPOGATION------------
LL tree[400000],xtra[400000];
void update(int id,int s,int e,int p,int q,int v)
{
	if(s == p && e == q) { xtra[id] += v; return; }

	tree[id] += (LL)v*(q-p+1);
	int mid = (s+e)>>1;
	if(p>mid) { update((id<<1)+1,mid+1,e,p,q,v); return; }
	if(q<=mid) { update(id<<1,s,mid,p,q,v); return; }
	update((id<<1)+1,mid+1,e,mid+1,q,v);
	update(id<<1,s,mid,p,mid,v);
	return;
}
long long int read(int id, int s,int e, int p, int q)
{
	if(xtra[id] != 0) // push the xtra to the children
	{
		if(s != e) // if there are any children
		{
			xtra[id<<1] += xtra[id];
			xtra[(id<<1)+1] += xtra[id];
		}
		tree[id] += xtra[id]*(e-s+1);
		xtra[id] = 0;
	}
	if(s == p && e == q) return tree[id];
	int mid = (s+e)>>1;
	if(p>mid) return read((id<<1)+1,mid+1,e,p,q);
	if(q<=mid) return read(id<<1,s,mid,p,q);
	return read((id<<1)+1,mid+1,e,mid+1,q) + read(id<<1,s,mid,p,mid);
}
//-----------------------------------------------------------------
//--------------------SUFFIX ARRAY----------------------------------
#define MAXLEN 1000
//Suffix array. O(n log2 n) time, 16 bytes/char overhead.
// Input: text, N
// Output: sa[] is a sorted list of offsets to all non-empty suffixes,
// lcp[i] = length of longest common prefix of text+sa[i] and text+sa[i+1]
char text[MAXLEN]; long long key[MAXLEN]; int N, sa[MAXLEN], rank[MAXLEN], *lcp=(int*)key;
struct Cmp { bool operator()(int i, int j) const { return key[i]<key[j]; } };
void build() {
	for (int i = 0; i < N; i++) { sa[i] = i; key[i] = text[i]; }
	sort(sa, sa+N, Cmp());
	for (int K = 1; ; K *= 2) {
		for (int i = 0; i < N; i++)
			rank[sa[i]] = i>0 && key[sa[i-1]]==key[sa[i]] ? rank[sa[i-1]] : i;
		if (K >= N) break;
		for (int i = 0; i < N; i++)
			key[i] = rank[i] * (N+1LL) + (i+K < N ? rank[i+K]+1 : 0);
			sort(sa, sa+N, Cmp());
	}
	for (int i = 0, k = 0; i < N; i++) {
		if (k > 0) k--;
		if (rank[i] == N-1) { lcp[N-1] = -1; k = 0; continue; }
		int j = sa[rank[i]+1];
		while (text[i+k] == text[j+k]) k++;
		lcp[rank[i]] = k;
	}
}

int main()
{
	cin>>text;
	int l = strlen(text); N = l;
	build();
	REP(i,l) {
		cout<<(text + sa[i]) << " "<<lcp[i]<<endl;
	}
	return 0;
}
//------------------------------------------------------------------
//-----------------DIJKSTRA ----------------------------------------
int dijkstra()
{
	int N = SI, M = SI; 
	vector<PI> V[N+1];
	REP(i,M) 
	{ 
		int x = SI, y = SI, z = SI; 
		V[x].PB(MP(y,z)); 
		V[y].PB(MP(x,z)); // Remove this if the edges are directed
	}
	bool mark[N+1]; FILL(mark,0);
	int dist[N+1];  REP(i,N+1) { dist[i] = INT_MAX; } // Fill with 'INT_MAX'
	PI p;
	priority_queue<PI> pq; 
	pq.push(MP(0,1)); dist[1] = 0;
	while(!pq.empty())
	{
		p = pq.top(); pq.pop(); 
		int d = -p.first, x = p.second;
		if(mark[x]) { continue; }
		REP(i,V[x].size()) 
		{ 
			p = V[x][i];
			int y = p.first, dxy = p.second;
			if(dist[y] > d + dxy) 
			{ 
				dist[y] = d + dxy; 
				pq.push(MP(-dist[y], y)); 
			}
		}
		mark[x] = 1;
	}
	return dist[N];
}
//------------------------------------------------------
//-------------------MST: PRIMS--------------------------
int N, M, X;
vector<PI> v[1000];
vector<pair<int, PI> > edges;

int prims(int sign)
{
	X = 0;
	int mark[N+1]; FILL(mark,0); mark[X] = 1;
	priority_queue<pair<int, PI> > pq;
	pair<int, PI> p;
	int i, x, d, y, dist = 0;
	REP(i,v[X].size()) { pq.push(MP(sign*v[X][i].first, MP(X, v[X][i].second))); }
	while(!pq.empty())
	{
		p = pq.top(); pq.pop(); if(mark[p.second.second]) { continue; }
		x = p.second.first; y = p.second.second; mark[y] = 1; d = sign*p.first;
		edges.PB(MP(d,MP(x,y)));
		dist += d;
		REP(i,v[y].size()) { if(!mark[v[y][i].second]) { pq.push(MP(sign*v[y][i].first, MP(y, v[y][i].second))); } } 
	}

	printf(sign == 1 ? "Maximum Spanning Tree\n" : "Minimum Spanning Tree\n");
	SORT(edges);
	REP(i,edges.size())
	{
		printf("%d %d: %d\n", edges[i].second.first, edges[i].second.second, edges[i].first);
	}
	edges.clear();
	
	return dist;
}
//--------------------------------------------------------
//-------------------POINT CLASS--------------------------
typedef double coord;
typedef pair<double,double> PD;
struct Point {
	coord x,y;
	Point() {}
	Point(coord x,coord y):x(x),y(y) {}
};
 
Point operator+(const Point &A,const Point&B) { return Point(A.x+B.x,A.y+B.y); }
Point operator-(const Point &A,const Point&B) { return Point(A.x-B.x,A.y-B.y); }
Point operator*(coord c, const Point &A) { return Point(c*A.x,c*A.y); }
coord operator^(const Point&A,const Point&B) { return A.x*B.y-A.y*B.x; }
coord operator*(const Point&A,const Point&B) { return A.x*B.x+A.y*B.y; }
coord len2(const Point&A) { return A*A; }
double len(const Point&A) { return sqrt((double)len2(A)); }

double distance(const Point&A, const Point&B) { Point X = A-B; return len(X); }

double angle(const Point&A, const Point&B) { return acos((double)(A*B)/len(A)/len(B)); }

double area(const Point&A, const Point&B, const Point&C) { return fabs((double)((A-C)^(B-C))/2.0); }

double linePointDistance(const Point&A, const Point&B, const Point&C, bool isSegment = false)
{
	Point X = B-A; Point Y = C-A;

	double dist = (X^Y)/sqrt((double)len2(A-B));
	
	if(isSegment)
	{
		X = C-B; Y = B-A;
		int dot1 = X*Y;
		if(dot1 > 0) { return sqrt((double)len2(B-C)); }
		X = C-A; Y = A-B;
		int dot2 = (C-A)*(A-B);
		if(dot2 > 0) { return sqrt((double)len2(A-C)); }
	}

	return fabs(dist);
}

double PolygonArea(vector<Point> points)
{
	double Area = 0.0;

	FOR(i,1,points.size()-1) { Area += area(points[0], points[i], points[i+1]); }

	return Area;
}
bool check(coord x, coord y, const Point&A, const Point&B)
{
	double minix = MIN(A.x, B.x);	double maxix = MAX(A.x, B.x);
	double miniy = MIN(A.y, B.y);	double maxiy = MAX(A.y, B.y);

	return minix <= x && x <= maxix && miniy <= y && y <= maxiy;
}
/* Line is given by 'Ax + By = C' */
PD intersectionPoint(const Point&A, const Point&B, const Point&C, const Point&D, double A1, double B1, double C1, double A2, double B2, double C2, bool isSegment = false)
{
	double det = A1*B2 - A2*B1;

	if(det == 0.0) { return MP(INT_MAX, INT_MAX); }
	else
	{
		double x = (B2*C1 - B1*C2)/det;
		double y = (A1*C2 - A2*C1)/det;

		if(isSegment) 
		{
			if(check(x, y, A, B) && check(x, y, C, D)) { return MP(x,y); }
			else { return MP(INT_MAX, INT_MAX); }
		}
		
		return MP(x,y);		
	}
}
/* Returns the point of intersection for the lines formed by A and B and C and D */
PD lineLineIntersection(const Point&A, const Point&B, const Point&C, const Point&D, bool isSegment = false)
{
	double A1 = B.y-A.y;	double B1 = A.x-B.x;	double C1 = A1*A.x+B1*A.y;
	double A2 = D.y-C.y;	double B2 = C.x-D.x;	double C2 = A2*C.x+B2*C.y;

	return intersectionPoint(A, B, C, D, A1, B1, C1, A2, B2, C2, isSegment);
}
/* Returns the coordinates of the centre of the circle */
PD findCircle(const Point&A, const Point&B, const Point&C)
{
	double A1, A2, B1, B2, C1, C2, midx1, midy1;
	double A3, A4, B3, B4, C3, C4, midx2, midy2;
	Point mid1, mid2;

	A1 = B.y-A.y;	B1 = A.x-B.x;	C1 = A1*A.x+B1*A.y;
	mid1.x = midx1 = (double)(A.x+B.x)/2.0;   
	mid1.y = midy1 = (double)(A.y+B.y)/2.0;
	A2 = -B1; 	B2 = A1;	C2 = A2*midx1+B2*midy1;

	A3 = C.y-B.y;	B3 = B.x-C.x;	C3 = A3*B.x+B3*B.y;
	mid2.x = midx2 = (double)(B.x+C.x)/2.0;	
	mid2.y = midy2 = (double)(B.y+C.y)/2.0;
	A4 = -B3;	B4 = A3;	C4 = A4*midx2+B4*midy2;
	
	PD p = intersectionPoint(mid1, mid1, mid2, mid2, A2, B2, C2, A4, B4, C4);

	return MP(p.first, p.second);
}
PD pointReflectionOnALine(const Point&A, const Point&B, const Point&C)//line = AB
{
	double A1, A2, B1, B2, C1, C2;
	
	A1 = B.y-A.y;	B1 = A.x-B.x;	C1 = A1*A.x+B1*A.y;
	A2 = -B1; 	B2 = A1;	C2 = A2*C.x+B2*C.y;

	PD p = intersectionPoint(A, B, C, C, A1, B1, C1, A2, B2, C2);

	return MP(p.first - (C.x - p.first), p.second - (C.y - p.second));
}
/* Rotate A around B by theta degree*/
PD pointRotationAroundAPoint(const Point&A, const Point&B, double theta)
{
	double angle = M_PI*theta/180.0;

	Point C = A-B;
	double x = C.x*cos(angle) - C.y*sin(angle);
	double y = C.x*sin(angle) + C.y*cos(angle);

	x += B.x;	y += B.y;

	return MP(x, y);
}
//-----------------------------------------------------
//-----------------------RABIN KARP----------------------
#define MOD 1000003
#define val(ch) ((int)((ch)-'a'+1))
#define PRIME 31
#define PRIME2 29
#define MOD2 2000003

char s[100000 + 10];
int len;
LL inv,inv2;
map <int,int> subcnt[MOD+5];
char vis[MOD+3];
int mypow(LL a, int n, int BASE)
{
	LL ret = 1LL;
	while(n){
		if(n&1)
			ret = (ret * a)%BASE; 
		a = (a*a)%BASE; n>>=1;
	}
	return (int)ret;
}
PI hash(int st, int end)
{
	LL ret1 = 0LL, ret2 = 0LL, pw1 = 1LL, pw2 = 1LL;
	for(int i = st;i<=end;++i)
	{
	//	cout<<val(s[i])<<endl;
		ret1 = (ret1 + pw1 * val(s[i])) % MOD;
		pw1 = (pw1 * PRIME) % MOD;
		ret2 = (ret2 + pw2 * val(s[i])) % MOD2;
		pw2 = (pw2 * PRIME2) % MOD2;
	}
	return MP((int)ret1, (int)ret2);
}
//------------------------------------------------------------
//---------------------MILLER RABIN---------------------------
LL mod_mult(LL a,LL b,LL n) 
{ 
	LL s=0; 
	a=a%n; 
	while(b) 
	{ 
		if(b&1) 
		{ 
			s+=a; 
			s%=n; 
		} 
		a=a<<1; 
		a%=n; 
		b=b>>1; 
	} 
	return s; 
} 

LL mod_exp(LL a,LL b,LL n)   
{ 
	LL d=1; 
	a=a%n; 
	while(b>=1) 
	{ 
		if(b&1)    d=mod_mult(d,a,n); 
		a=mod_mult(a,a,n); 
		b=b>>1; 
	} 
	return d; 
} 
bool Witness(LL a, LL n) 
{ 
	LL m,x,y; 
	int i,j=0; 
	m=n-1; 
	while(m%2==0) 
	{ 
		m=m>>1; 
		j++;  
	} 
	x=mod_exp(a,m,n); 
	for(i=1;i<=j;i++) 
	{ 
		y=mod_exp(x,2,n); 
		if((y==1)&&(x!=1)&&(x!= n - 1)) 
			return true;
		x=y; 
	} 
	if(y!=1)  return true; 
	return false; 
} 

bool miller_rabin(LL n,int times)  
{ 
	LL a; 
	int i; 
	if(n==1)  return false; 
	if(n==2)  return true; 
	if(n%2==0)  return false; 
//	srand(time(NULL)); 
	for(i=1;i<=times;i++) 
	{ 
		a=rand()%(n-1)+1; 
		if(Witness(a,n))  
			return false; 
	} 
	return true; 
}
//----------------------------------------------
//---------------FLOYD WARSHAL------------------
REP(k,n) REP(i,n) REP(j,n) adj[i][j] = MIN(adj[i][j], adj[i][k]+adj[k][j]);
//----------------------------------------------
//-----------------------BELLMAN FORD-----------------
#define INF 1000000000
vector <PI> edge[1123];
int dist[1123];

void relax(int u, int v, int cost)
{
	dist[v] = MIN(dist[v], dist[u] + cost);
	return;
}

bool bellmanFord(int source, int n)
{
	REP(i,n) dist[i] = INF;
	dist[source] = 0;
	REP(k,n-1) //|V|-1 times
	{ REP(i,n) { int sz = SZ(edge[i]);
		REP(j,sz) relax(i,edge[i][j].first, edge[i][j].second); }
	}
	REP(i,n) {int sz = SZ(edge[i]);
		REP(j,sz) if(dist[edge[i][j].first] > dist[i] + edge[i][j].second) return false;}
	return true;
}
//---------------------------------------------------
