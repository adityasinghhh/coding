#include<cstdio>
int main()
{
	int t, n;
	
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		num = 1;
		den = 1;

		for(i=1; i<=n; i++)
		{
			f = 1;
			for(j=i+1, k=1; j<=n; j++)
			{
				f *= j;
				f /= k;
			}


		}
	}

	return 0;
}
