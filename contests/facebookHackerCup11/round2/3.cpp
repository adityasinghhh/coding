#include<cstdio>
int C(int n, int r)
{
	int f = 1, i, j;

	for(i=r+1, j=1; i<=n; i++)
	{
		f*=i;
		f/=j;
	}

	return f;
}

int main()
{
	int t, n, a, b, c, d, total, i, j;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		scanf("%d %d", &a, &b);

		scanf("%d %d", &c, &d);

		if(b<c)
		{
			total = 0;
			for(i=a; i<=b; i++)
				for(j=c; j<=d; j++)
					total += 2*(C(j-i, n-2));

			printf("%d\n", total);
		}
	}

	return 0;
}
