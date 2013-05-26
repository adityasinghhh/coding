#include<cstdio>
int a[1000][1000], b[1000][1000], c[1000][1000];
void multiply(int r1, int c1, int r2, int c2)
{
	int i, j, k;

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c2; j++)
		{
			c[i][j] = 0;

			for(k=0; k<c1; k++)
			{
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
}

int main()
{
	int i, j, r1, c1, r2, c2;

	scanf("%d %d", &r1, &c1);

	for(i=0; i<r1; i++)
		for(j=0; j<c1; j++)
			scanf("%d", &a[i][j]);
	
	scanf("%d %d", &r2, &c2);

	for(i=0; i<r2; i++)
		for(j=0; j<c2; j++)
			scanf("%d", &b[i][j]);

	multiply(r1, c1, r2, c2);

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
	
	for(i=0; i<r2; i++)
	{
		for(j=0; j<c2; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	printf("\n");

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c2; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
	printf("\n");
}
