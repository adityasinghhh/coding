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
#define cscan(n) scanf("%c",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

bool mark[20][20] = {0};
vector<string> v;
map<string, int> m;
vector<int> maxv;
int maxi, n;

void f(vector<int> v1, int ind)
{
	if(ind == n)
	{
		int sz = v1.size();
		if(sz > maxi)
		{
			maxi = sz;
			maxv = v1;
		}

		return;
	}

	int i, sz = v1.size(), j;
	FOR(i,ind,n)
	{
		FOR(j,0,sz)
		{
			if(mark[v1[j]][m[v[i]]])
			{
				break;
			}
		}

		if(j == sz)
		{
			v1.push_back(i);
			f(v1, i+1);
			v1.pop_back();
		}
	}
}

int main()
{
	int r, i;
	char a[1000], b[1000];

	iscan(n);
	iscan(r);

	FOR(i,0,n)
	{
		sscan(a);
		m[a] = i;
		v.push_back(a);
	}

	FOR(i,0,r)
	{
		sscan(a);
		sscan(b);

		mark[m[a]][m[b]] = 1;
		mark[m[b]][m[a]] = 1;		
	}

	maxi = -1;
	vector<int> v1;
	f(v1, 1);
	v1.push_back(0);
	f(v1, 1);

	vector<string> print;
	int sz = maxv.size();
	FOR(i,0,sz)
	{
		print.PB(v[maxv[i]]);
	}

	sort(print.begin(), print.end());

	printf("%d\n", sz);
	FOR(i,0,sz)
		printf("%s\n", print[i].c_str());

	return 0;
}
