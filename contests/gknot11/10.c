#include<stdio.h>
#include<limits.h>

int main()
{
	long long int n = 1ll*INT_MAX + 1ll*235500282;
	printf("%lld\n", n);

	long long int i, no, m;

		m = n;

		for(i=2; i*i<=n; i++)
		{
			if(n%i == 0)
			{
				m=m/i*(i-1);

				while(n%i == 0)
					n/=i;
			}
		}

		if(n>1)
			m=m/n*(n-1);

		printf("%lld\n", m);

	return 0;
}





