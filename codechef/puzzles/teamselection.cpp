#include<cstdio>
#include<climits>
int abs(int a)
{
	if(a<0)
		return (-1*a);
	return a;
}

int main()
{
	int n, i, j, k, sum, min, x, t1, t2, no;
	char ch;

	scanf("%d", &no);

	while(no--)
	{
		while((ch=getchar()) != '\n' && ch != EOF);

		scanf("%d", &n);

		if(n == 1)
		{
			scanf("%d", &x);
			printf("0 %d\n", x);

			if(no != 0)
				printf("\n");

			continue;
		}
		
		int dp[51][23001] = {0};

		sum = 0;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &x);

			j = i; 
			if(i > n/2)
				j = n/2;

			for(; j >= 1; j--)
				for(k=1; k<=sum; k++)
					if(dp[j][k] != 0)
						dp[j+1][k+x] = 1;

			dp[1][x] = 1;
			sum += x;
		}

/*		for(i=0; i<=n/2; i++)
		{
			printf("%d: ", i);
			for(j=0; j<=sum; j++)
				if(dp[i][j] == 1)
					printf("%d ", j);
			printf("\n");
		}
*/
		j = n/2;

		min = INT_MAX;
		for(k=1; k<=sum; k++)
		{
			if(dp[j][k] != 0)
			{
				if(abs(2*k-sum) < min)
				{
					t1 = k;
					t2 = sum-k;
					min = abs(2*k-sum);
				}
			}
		}

		if(t1 > t2)
			printf("%d %d\n", t2, t1);
		else
			printf("%d %d\n", t1, t2);
			
		if(no != 0)
			printf("\n");

	}
	return 0;
}

