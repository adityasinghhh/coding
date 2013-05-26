#include<cstdio>
#include<cstring>
#include<cmath>
long long mod(long long a, long long b, long long c)
{
	long long int x = 1, y = a;

	while(b > 0)
	{
		if(b%2 == 1)
		{
			x = (x*y)%c;
		}

		y = (y*y)%c;
		b /= 2;
	}

	return x%c;
}

int main()
{
	long long t, i, k, n, maxi, c, diff, z;
	
	scanf("%lld", &t);

	while(t--)
	{
		scanf("%lld %lld", &k, &n);

		if(k == 1)
		{
			if(n == 1)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}

		if(n == 1)
		{
			printf("%lld\n", k);
			continue;
		}

		maxi = mod(k, n, 1000000007);

		c = k;
		for(i=2; i*i<=n; i++)
			if(n%i == 0)
			{
				if(i*i == n)
					c = (c + mod(k, i, 1000000007))%1000000007;
				else
					c = (c + mod(k, i, 1000000007) + mod(k, n/i, 1000000007))%1000000007;
			}

		diff = (maxi-c)%1000000007;

		while(diff<0)
			diff += 1000000007;

		printf("%lld\n", diff);
	}

	return 0;
}
