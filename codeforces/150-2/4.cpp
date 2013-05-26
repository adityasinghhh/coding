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

int main()
{
    int N = SI, M = SI, H = SI, T = SI;
    int p[N+1];
    FILL(p,0);
    VI v[N+1];
    VPI e;
    REP(i,M)
    {
        int x = SI, y = SI;
        v[x].PB(y);
        v[y].PB(x);
        ++p[x];
        ++p[y];
        e.PB(MP(x,y));
    }

    REP(i,e.size())
    {
        int x = e[i].first, y = e[i].second;
        if(p[x] == H+1 && p[y] == T+1)
        {
            set<int> sx;
            REP(j,v[x].size())
            {
                if(v[x][j] != y)
                {
                    sx.insert(v[x][j]);
                }
            }
            bool flag = true;
            REP(j,v[y].size())
            {
                if(v[y][j] != x)
                {
                    if(sx.find(v[y][j]) != sx.end())
                    {
                        flag = false;
                        break;
                    }
                }
            }

            if(flag)
            {
                bool flag1 = true;
                REP(j,v[x].size())
                {
                    if(v[x][j] != y)
                    {
                        int z = v[x][j];
                        REP(k,v[z].size())
                        {
                            if(v[z][k] == y)
                            {
                                flag1 = false;
                                break;
                            }
                        }
                        if(flag1 == false)
                        {
                            break;
                        }
                    }
                }
                if(flag1)
                {
                    REP(j,v[y].size())
                    {
                        if(v[y][j] != x)
                        {
                            int z = v[y][j];
                            REP(k,v[z].size())
                            {
                                if(v[z][k] == x)
                                {
                                    flag1 = false;
                                    break;
                                }
                            }
                            if(flag1 == false)
                            {
                                break;
                            }
                        }
                    }
                }

                if(flag1)
                {
                    printf("YES\n");
                    printf("%d %d\n", x, y);
                    REP(j,v[x].size())
                    {
                        if(v[x][j] != y)
                        {
                            printf("%d ", v[x][j]);
                        }
                    }
                    printf("\n");
                    REP(j,v[y].size())
                    {
                        if(v[y][j] != x)
                        {
                            printf("%d ", v[y][j]);
                        }
                    }
                    printf("\n");
                    return 0;
                }
            }
        }
        else if(p[x] == T+1 && p[y] == H+1)
        {
            set<int> sx;
            REP(j,v[x].size())
            {
                if(v[x][j] != y)
                {
                    sx.insert(v[x][j]);
                }
            }
            bool flag = true;
            REP(j,v[y].size())
            {
                if(v[y][j] != x)
                {
                    if(sx.find(v[y][j]) != sx.end())
                    {
                        flag = false;
                        break;
                    }
                }
            }

            if(flag)
            {
                bool flag1 = true;
                REP(j,v[x].size())
                {
                    if(v[x][j] != y)
                    {
                        int z = v[x][j];
                        REP(k,v[z].size())
                        {
                            if(v[z][k] == y)
                            {
                                flag1 = false;
                                break;
                            }
                        }
                        if(flag1 == false)
                        {
                            break;
                        }
                    }
                }
                if(flag1)
                {
                    REP(j,v[y].size())
                    {
                        if(v[y][j] != x)
                        {
                            int z = v[y][j];
                            REP(k,v[z].size())
                            {
                                if(v[z][k] == x)
                                {
                                    flag1 = false;
                                    break;
                                }
                            }
                            if(flag1 == false)
                            {
                                break;
                            }
                        }
                    }
                }

                if(flag1)
                {
                    printf("YES\n");
                    printf("%d %d\n", y, x);
                    REP(j,v[y].size())
                    {
                        if(v[y][j] != x)
                        {
                            printf("%d ", v[y][j]);
                        }
                    }
                    printf("\n");
                    REP(j,v[x].size())
                    {
                        if(v[x][j] != y)
                        {
                            printf("%d ", v[x][j]);
                        }
                    }
                    printf("\n");
                    return 0;
                }
            }
        }
    }

    printf("NO\n");

    return 0;
}