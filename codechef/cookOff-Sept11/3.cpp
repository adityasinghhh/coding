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
#include<vector>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define LL long long int

LL T, A, B;
LL zero[20];
char s1[10000];

LL f(LL a, LL b)
{
	sprintf(s1, "%lld", a);
	LL l1 = strlen(s1);
	sprintf(s1, "%lld", b);
	LL l2 = strlen(s1);
	LL c=10, d=1, l=0, i, sum=0, s, x;

	while(l1 != l2)
	{
		while(a%c != 0)
		{
			a+=d;

			if(a > b)
				break;

			if(c == 10)
			{
				x = a;
				s = 0;
				while(x)
				{
					i = x%10;
					s += (i%2 == 0 ? 2*i : i);
					x /= 10;
				}

				sum = sum + s%10;
			}
			else
				sum += zero[l];
			printf("%lld %lld %lld\n", a, b, sum);
		}

		c*=10;
		d*=10;
		l++;

		printf("%lld %lld\n", a, b);
		sprintf(s1, "%lld", a);
		l1 = strlen(s1);
		sprintf(s1, "%lld", b);
		l2 = strlen(s1);
	}

	c /= 10;
	d /= 10;
			printf("%lld %lld %lld\n", a, b, sum);

	while(a != b)
	{

		while(a <= b)
		{
			a += c;

			if(a > b)
			{
				a -= c;
				break;
			}

			if(l == 0)
			{
				x = a;
				s = 0;
				while(x)
				{
					i = x%10;
					s += (i%2 == 0 ? 2*i : i);
					x /= 10;
				}

				sum = sum + s%10;
			}
			else
			{
				sum += zero[l];
			}
			printf("%lld %lld %lld\n", a, b, sum);
		}

		c /= 10;
		d /= 10;
		l--;
	}

	return sum;
}

int main()
{
	llscan(T);

	LL i;
	zero[1] = 45;
	FOR(i,2,12)
		zero[i] = zero[i-1]*10;

	while(T--)
	{
		llscan(A);
		llscan(B);

		printf("%lld\n", f(A, B));
	}

	return 0;
}
