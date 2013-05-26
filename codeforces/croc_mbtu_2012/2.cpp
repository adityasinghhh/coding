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
    int T = SI;
    while(T--)
    {
        string s;
        cin >> s;

        if(s == "::")
        {
            cout << "0000:0000:0000:0000:0000:0000:0000:0000" << endl;
        }
        else
        {
            string s1 = "";
            s1 += s[0];
            int ind = -1;
            FOR(i,1,s.length())
            {
                if(s[i] == ':' && s[i-1] == ':')
                {
                    ind = i;
                    break;
                }

                s1 += s[i];
            }

//            cout << "Actual: " << s << endl;
            if(ind != -1)
            {
                s1 = s1.substr(0, s1.length()-1);

                string s2 = "";
                ++ind;
                FOR(i,ind,s.length())
                {
                    s2 += s[i];
                }

                int cnt = 0;
                REP(i,s.length())
                {
                    if(s[i] == ':')
                    {
                        ++cnt;
                    }
                }

                int cnt1 = 0;
                REP(i,s1.length())
                {
                    if(s1[i] == ':')
                    {
                        ++cnt1;
                    }
                }

                int cnt2 = 0;
                REP(i,s2.length())
                {
                    if(s2[i] == ':')
                    {
                        ++cnt2;
                    }
                }

                string s3 = "";

                if(s1.length() > 0)
                {
                }
                else
                {
                    s3 += "0000";
                }

                REP(i,7-cnt1-cnt2-1)
                {
                    s3 += ":0000";
                }

                if(s2.length() > 0)
                {
                    s3 += ":";
                }
                else
                {
                    s3 += ":0000";
                }

//                cout << "Current: " << s << endl;
//                cout << s1 << endl;
//                cout << s3 << endl;
//                cout << s2 << endl;

                s = s1 + s3 + s2;
            }

//            cout << "Now: " << s << endl;

            REP(i,s.length())
            {
                if(s[i] == ':')
                {
                    s[i] = ' ';
                }
            }

            istringstream sin(s);
            int cnt = 0;
            while(sin >> s)
            {
                REP(i,4-s.length())
                {
                    printf("0");
                }
                cout << s;
                ++cnt;

                printf(cnt == 8 ? "\n" : ":");
            }
        }
    }

        return 0;
}
