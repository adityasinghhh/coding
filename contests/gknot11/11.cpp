#include<cstdio>
long long int C(long long int n, long long int r)
{
	long long int f=1, i, j;
	for(i=r+1, j=1; i<=n; i++)
	{
		f*=i;
		f/=j;
	}

	return f;
}
long long int p[81] = {0}, total = 0;

void f(long long int i)
{
	if(i == 6)
	{
		total++;
		return;
	}

	p[i] = 0;
	f(i+1);

	if(!p[i-1])
	{
		p[i] = 1;
		f(i+1);
	}
}

int main()
{
	p[0] = 0;
	f(1);
	p[0] = 1;
	f(1);

	printf("%lld\n", total);
}
