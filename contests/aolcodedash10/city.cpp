#include<cstdio>
void f(int i, int j)
{
	if(i == j)
		return;


}

int main()
{
	scanf("%d", &no);

	while(no--)
	{
		scanf("%d %d", &n, &m);

		for(i=0; i<=n; i++)
			p[i] = 0;

		for(i=0; i<m; i++)
		{
			scanf("%d %d", &x, &y);

			a[x][p[x]++] = y;
			a[y][p[y]++] = x;
		}

		for(i=1; i<=n; i++)
			for(j=i+1; j<=n; j++)
			{
				f(i, j);
			}

	}

	return 0;
}
