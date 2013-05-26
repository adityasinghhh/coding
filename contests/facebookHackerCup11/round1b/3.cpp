#include<cstdio>
#include<cmath>
int main()
{
	long long int no, n, k, i, d;

	scanf("%lld", &no);

	while(no--)
	{
		scanf("%lld %lld", &n, &k);

		k++;
		d = 1;

		while(d<=(k-1)*n)
			d = ceil(k*d*1./(k-1));

		printf("%lld\n", k*n+1 - d);
	}

	return 0;
}
