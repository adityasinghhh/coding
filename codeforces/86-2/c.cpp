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

char lios[]   = "lios";
char etr[]    = "etr";
char initis[] = "initis";
char liala[]  = "liala";
char etra[]   = "etra";
char inites[] = "inites";

bool check(char *a, char *b)
{
	int l1 = strlen(a), l2 = strlen(b), i, j;

	if(l1 < l2)
		return 0;

	for(i=l1-1, j=l2-1; j>=0; i--, j--)
		if(a[i] != b[j])
			return 0;

	return 1;
}

int main()
{
	char ch, a[1000000];
	int ncount = 0, newsex, sex = 0, newstage, stage = 0;
	bool flag = 0, flag1 = 0;
	
	scanf("%s%c", a, &ch);
		
	if(check(a, lios))
	{
		sex = 1;
		stage = 0;
	}
	else if(check(a, etr))
	{
		sex = 1;
		stage = 1;
		ncount++;
		flag1 = 1;
	}
	else if(check(a, initis))
	{
		sex = 1;
		stage = 2;
	}
	else if(check(a, liala))
	{
		sex = 0;
		stage = 0;
	}
	else if(check(a, etra))
	{
		sex = 0;
		ncount++;
		stage = 1;
		flag1 = 1;
	}
	else if(check(a, inites))
	{
		sex = 0;
		stage = 2;
	}
	else
	{
		flag = 1;
	}

	if(ch == EOF || ch == '\n')
	{
		if(!flag)
			printf("YES\n");
		else
			printf("NO\n");

		return 0;
	}

	while(scanf("%s%c", a, &ch))
	{
		if(flag)
		{
			if(ch == EOF || ch == '\n')
				break;
			
			continue;
		}

		if(check(a, lios))
		{
			newsex = 1;
			newstage = 0;
		}
		else if(check(a, etr))
		{
			newsex = 1;
			newstage = 1;
		ncount++;
			flag1 = 1;
		}
		else if(check(a, initis))
		{
			newsex = 1;
			newstage = 2;
		}
		else if(check(a, liala))
		{
			newsex = 0;
			newstage = 0;
		}
		else if(check(a, etra))
		{
			newsex = 0;
			newstage = 1;
			flag1 = 1;
		ncount++;
		}
		else if(check(a, inites))
		{
			newsex = 0;
			newstage = 2;
		}
		else
		{
			flag = 1;
		}

		if(sex != newsex || newstage < stage)
		{
			flag = 1;
		}
		stage = newstage;
		
		if(ch == EOF || ch == '\n')
			break;
	}

	if(!flag && flag1 && ncount == 1)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
