#include<iostream>
#include<cstdio>
int n, k;
int a[200001][2];

int f(int i, int j, int level)
{
	if(j == -1)
		return 0;

	int v, ii;

	v = level+1;
	for(ii=0; ii<k; ii++)
		v = (v*(level+1))%1000000007;

	if(a[j][0] == i)
		return v + f(j, a[j][1], level+1);
	else
		return v + f(j, a[j][0], level+1);
}

int main()
{
	int no, i, x, y;

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d %d", &n, &k);

		for(i=0; i<n; i++)
			a[i][0] = a[i][1] = -1;

		for(i=0; i<n-1; i++)
		{
			scanf("%d %d", &x, &y);

			if(a[x][0] == -1)
				a[x][0] = y;
			else
				a[x][1] = y;
			
			if(a[y][0] == -1)
				a[y][0] = x;
			else
				a[y][1] = x;
		}

		for(i=0; i<n; i++)
		{
			printf("%d\n", (1 + f(i, a[i][0], 1)+f(i, a[i][1], 1))%1000000007);
		}
		printf("\n");
	}

	return 0;
}
