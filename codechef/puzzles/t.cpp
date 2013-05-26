#include<cstdio>
int main()
{
	long long int dp[101][710] = {0};

	int no, n, i, j, q, r;
	long long int p;

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d", &n);

		int a[n+1];

		for(i=1; i<n; i++)
		{
			for(j=0; j<50; j++)
				printf("%lld ", dp[i][j]);
			printf("\n");
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);

			for(j=0; j<i; j++)
			{
				for(k=0; k<700; k++)
				{
					if(!dp[j][k])
					{
						x = dp[j][k];

						c = 0;
						while(x)
						{
							if(x%2)
							{

							}

							x>>=1;
						}

						q = a[i]/64;
						r = a[i]%64;

						printf("%d: %d %d\n", a[i], q, r);

						p = 1<<r;

						dp[j][q] |= p;
					}
				}
			}

			q = a[i]/64;
			r = a[i]%64;

			p = 1<<r;

			dp[1][q] != p;
		}

		for(i=1; i<n; i++)
		{
			for(j=0; j<50; j++)
				printf("%lld ", dp[i][j]);
			printf("\n");
		}
	}
}

