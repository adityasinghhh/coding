#include<cstdio>
#define N 1051962371
long long mulmod(long long a,long long b,long long c){
	long long x = 0,y=a%c;
	while(b > 0){
		if(b%2 == 1){
			x = (x+y)%c;
		}
		y = (y*2)%c;
		b /= 2;
	}
	return x%c;
}
long long f(long long n, long long r)
{
	long long i, f=1, j;

	for(i=r+1, j=1; i<=n; i++, j++)
	{
		f *= i;
		f /= j;
	}

	return f%N;
}

int main()
{
	printf("%lld\n", f(13, 10));

	long long c, i, a, b, j, no;

	long long sum = 0;
	for(i=2, j=1; i<=13; j++, i++)
	{
		sum += j*f(13, i);
		printf("%lld: %lld: %lld\n", i, f(13, i), sum);
	}

	scanf("%lld", &no);

	while(no--)
	{
		scanf("%lld %lld", &a, &b);

		c = 1;
		for(i=a, j=1; i>=b; i--, j++)
		{
			printf("%lld %lld\n", j, f(a, i));
			c += j*f(a, i);
		}

		printf("%lld\n", c);

	}
}
