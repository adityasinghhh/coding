#include<cstdio>
int main()
{
	long long int no, n, k, i, r;

	scanf("%lld", &no);

	while(no--)
	{
		scanf("%lld %lld", &n, &k);

		k++;

		r = 0;
		for(i=1; i<=n; i++)
			r = (r+k)%i;

		printf("%lld\n", r+1);
	}
}
