#include<cstdio>
int main()
{
	long long int n, ii, i, j, x, y, oldx, oldy;

	scanf("%lld", &n);

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

	long long int markx[n+1], marky[n+1], maxx;

	for(i=0; i<n; i++)
		markx[i] = marky[i] = 0;

	for(ii=0; ii<n-1; ii++)
	{
		//printf("%lld %lld %lf\n", x, y, a[x][y]);
		printf("%lld %lld\n", x, y);

		//for(j=0; j<n; j++)
		//	a[x][j] = a[j][y] = 0.0;

		markx[x] = 1;
		marky[y] = 1;

		oldx = x;
		oldy = y;

		x = y = 0;
		maxx = -1.0;
		for(j=0; j<n; j++)
		{
			if(marky[j] == 0 && markx[j] == 0 && j != oldy && a[oldy][j] > maxx)
			{
				maxx = a[oldy][j];
				x = oldy;
				y = j;
			}

			if(markx[j] == 0 && marky[j] == 0 && j != oldx && a[j][oldx] > maxx)
			{
				maxx = a[j][oldx];
				x = j;
				y = oldx;
			}
		}
	}
	
	for(i=0; i<n; i++)
		if(markx[i] == 0)
		{
			printf("%lld ", i);
			break;
		}

	for(i=0; i<n; i++)
		if(marky[i] == 0)
		{
			printf("%lld\n", i);
			break;
		}

	return 0;
}


