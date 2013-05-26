#include<cstdio>
int gcd(int a, int b)
{
	if(a%b == 0)
		return b;
	return gcd(b, a%b);
}

int main()
{
	int no, n, i, g;
	scanf("%d", &no);
	while(no--)
	{
		scanf("%d", &n);

		if(n == 0)
			continue;

		int a[n+1];

		scanf("%d", &a[0]);

		if(n == 1)
		{
			printf("%d\n", a[0]);
			continue;
		}

		g = a[0];
		for(i=1; i<n; i++)
		{
			scanf("%d", &a[i]);

			g = gcd(a[i], g);
		}

		for(i=0; i<n; i++)
			printf("%d ", a[i]/g);
		printf("\n");
	}

	return 0;
}
