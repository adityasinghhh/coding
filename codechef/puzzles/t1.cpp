#include<cstdio>
#include<climits>
int abs(int a)
{
	if(a<0)
		return -a;
	return a;
}

int main()
{

	int no, n, i, j, q, r, sum, x, k, m, sum1, max, t1, t2, min;
	int p;

	scanf("%d", &no);

	while(no--)
	{
		bool dp[51][50000] = {0};

		scanf("%d", &n);

		int a[n+1];

		m = n/2;
		if(n%2 == 1)
			m++;
		
		m = n;

		sum = 0;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}

		if(n == 1)
		{
			printf("0 %d\n", a[1]);

			if(no)
				printf("\n");

			continue;
		}

		//printf("sum: %d\n", sum);
		sum=0;
		for(i=1; i<=n; i++)
		{
			x = a[i];
			for(j=i<m?i:m; j>0; j--)
				for(k=0; k<=sum; k++)
					if(dp[j][k])
						dp[j+1][k+x] = 1;

			dp[1][x] = 1;
			sum += x;
			
			/*for(int ii=0; ii<=n; ii++)
			{
				printf("%d: ", ii);

				for(j=0; j<=sum; j++)
					if(dp[ii][j])
						printf("%d ", j);
				printf("\n");
			}*/
		}

		for(i=0; i<=n; i++)
		{
			printf("%d: ", i);

			for(j=0; j<=sum; j++)
				if(dp[i][j])
					printf("%d ", j);
			printf("\n");
		}

		if(n%2 == 1)
		{
			min = INT_MAX;
			for(i=0; i<2; i++)
				for(j=0; j<=sum; j++)
					if(dp[i+n/2][j])
						if(abs(sum-2*j) < min)
						{
							t1 = sum-j;
							t2 = j;
							min = abs(sum-2*j);
						}
		}
		else
		{
			min = INT_MAX;
			for(j=0; j<=sum; j++)
				if(dp[n/2][j])
					if(abs(sum-2*j) < min)
					{
						t1 = sum-j;
						t2 = j;
						min = abs(sum-2*j);
					}
		}

		if(t1 < t2)
			printf("%d %d\n", t1, t2);
		else
			printf("%d %d\n", t2, t1);

		if(no)
			printf("\n");
	}
}

