
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

double dist(int x1, int y1, int x2, int y2)
{
    double x = x1-x2;
    double y = y1-y2;

    return sqrt(x*x + y*y);
}

int main()
{
    int N = SI, M = SI, A = SI, B = SI;
    int va[N+1];
    int vb[M+1];
    int L[M+1];

    VI v;
    FOR(i,1,N+1)
    {
        va[i] = SI;
        v.PB(va[i]);
    }
    SORT(v);

    FOR(i,1,M+1)
    {
        vb[i] = SI;
    }

    VPI w;
    FOR(i,1,M+1)
    {
        L[i] = SI;
        w.PB(MP(vb[i], L[i]));
    }
    SORT(w);

//    REP(i,v.size()) { cout << v[i] << ":" << dist(0,0,A,v[i]) << " "; } cout << endl;
//    REP(i,w.size()) { cout << w[i].first << "," << w[i].second << " "; } cout << endl;

    double mini = (double)INT_MAX;
    int i = 0, j = 0;
    int minia, minib;
    while(i < v.size() && j < w.size())
    {
        if(mini > dist(0, 0, A, v[i]) + dist(A, v[i], B, w[j].first) + w[j].second)
        {
            mini = dist(0, 0, A, v[i]) + dist(A, v[i], B, w[j].first) + w[j].second;
            minia = i;
            minib = j;

//            cout << "(" << minia << "," << minib << ")" << endl;
        }

        if(v[i] < w[j].first)
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }

    while(i < v.size())
    {
        if(mini > dist(0, 0, A, v[i]) + dist(A, v[i], B, w[M-1].first) + w[M-1].second)
        {
            mini = dist(0, 0, A, v[i]) + dist(A, v[i], B, w[M-1].first) + w[M-1].second;
            minia = i;
            minib = M-1;

//           cout << "(" << minia << "," << minib << ")" << endl;
        }

        ++i;
    }

    while(j < w.size())
    {
        if(mini > dist(0, 0, A, v[N-1]) + dist(A, v[N-1], B, w[j].first) + w[j].second)
        {
            mini = dist(0, 0, A, v[N-1]) + dist(A, v[N-1], B, w[j].first) + w[j].second;
            minia = N-1;
            minib = j;

//           cout << "(" << minia << "," << minib << ")" << endl;
        }

        ++j;
    }

    i = v.size()-1, j = w.size()-1;
    while(i >= 0 && j >= 0)
    {
        if(mini > dist(0, 0, A, v[i]) + dist(A, v[i], B, w[j].first) + w[j].second)
        {
            mini = dist(0, 0, A, v[i]) + dist(A, v[i], B, w[j].first) + w[j].second;
            minia = i;
            minib = j;

//            cout << "(" << minia << "," << minib << ")" << endl;
        }

        if(v[i] > w[j].first)
        {
            --i;
        }
        else
        {
            --j;
        }
    }

    while(i >= 0)
    {
        if(mini > dist(0, 0, A, v[i]) + dist(A, v[i], B, w[0].first) + w[0].second)
        {
            mini = dist(0, 0, A, v[i]) + dist(A, v[i], B, w[0].first) + w[0].second;
            minia = i;
            minib = 0;

//           cout << "(" << minia << "," << minib << ")" << endl;
        }

        --i;
    }

    while(j >= 0)
    {
        if(mini > dist(0, 0, A, v[0]) + dist(A, v[0], B, w[j].first) + w[j].second)
        {
            mini = dist(0, 0, A, v[0]) + dist(A, v[0], B, w[j].first) + w[j].second;
            minia = 0;
            minib = j;

//           cout << "(" << minia << "," << minib << ")" << endl;
        }

        --j;
    }

    printf("%d %d\n", minia+1, minib+1);
/*    printf("%lf\n", mini);

    mini = (double)INT_MAX;
    REP(i,v.size())
    {
        REP(j,w.size())
        {
            printf("(%d,%d):(%d,%d):%lf:%lf:%d=%lf ", A, v[i], B, w[j].first, dist(0,0,A,v[i]),dist(A,v[i],B,w[j].first),w[j].second, dist(0,0,A,v[i])+dist(A,v[i],B,w[j].first)+w[j].second);
        }
        printf("\n");
    }
*/
    return 0;
}