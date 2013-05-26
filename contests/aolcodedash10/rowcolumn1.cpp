#include<cstdio>
int main()
{
	int n, ii, i, j, x, y, oldx, oldy;

	scanf("%d", &n);

	double a[n+1][n+1];

	x = y = 0;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			scanf("%lf", &a[i][j]);

			if(i!=j && a[x][y] < a[i][j])
			{
				x=i;
				y=j;
			}
		}

	int markx[100000] = {0};
	int marky[100000] = {0}, maxx;

	for(ii=0; ii<n; ii++)
	{
		printf("%d %d %lf\n", x, y, a[x][y]);

		markx[x] = 1;
		marky[y] = 1;

		oldx = x;
		oldy = y;

		x = y = 0;
		maxx = -1.0;
		for(j=0; j<n; j++)
		{
			if(marky[j] == 0 && j!=oldy && a[oldy][j] > maxx)
			{
				maxx = a[oldy][j];
				x = oldy;
				y = j;
			}

			if(markx[j] == 0 && j!=oldx && a[j][oldx] > maxx)
			{
				maxx = a[j][oldx];
				x = j;
				y = oldx;
			}
		}
	}
}


