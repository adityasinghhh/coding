#include<cstdio>
int **power(int** a, int n, int p)
{
	int i, j, k;

	int **c = new int*[n+1];
	for(i=0; i<n; i++)
		c[i] = new int[n+1];
	

	if(p == 1)
	{
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				c[i][j] = a[i][j];

		return c;
	}
	else if(p == 2)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				c[i][j] = 0;

				for(k=0; k<n; k++)
				{
					c[i][j] += a[i][k]*a[k][j];
				}
			}
		}
		
		return c;
	}
	else if(p%2 == 0)
	{
		return power(power(a, n, 2), n, p/2);
	}
	else
	{
		int **b = power(a, n, p-1);

		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
				printf("%d ", b[i][j]);
			printf("\n");
		}
		
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				c[i][j] = 0;

				for(k=0; k<n; k++)
				{
					c[i][j] += a[i][k]*b[k][j];
				}
			}
		}
		
		return c;
	}
}

int main()
{
	int i, j, n, p;

	scanf("%d %d", &n, &p);

	int** a = new int*[n+1];

	for(i=0; i<n; i++)
	{
		a[i] = new int [n+1];

		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	}

	int** c = power(a, n, p);

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
}
