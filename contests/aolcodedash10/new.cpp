#include<cstdio>
#include<limits.h>
int main()
{
	int n, ii, i, j, x, y, oldx, oldy, minx, miny;

	scanf("%d", &n);

	double a[n+1][n+1], min;

	x = y = 0;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			scanf("%lf", &a[i][j]);

			if(i == j)
				a[i][j] = 0.0;
		}

	int iii, lawl;
	double minu = (double)INT_MAX;

	for(iii=1; iii<n; iii++)
	{
		x = iii;
		y = 0;

		int markx[n+1], marky[n+1], maxx;

		for(i=0; i<n; i++)
			markx[i] = marky[i] = 0;

		int xx[n+1][2];

		for(ii=0; ii<n-1; ii++)
		{
			//printf("%d %d %lf\n", x, y, a[x][y]);
			//
			xx[ii][0] = x;
			xx[ii][1] = y;

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
			}

			for(j=0; j<n; j++)
			{
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
				xx[n-1][0] = i;
				//			printf("%d ", i);
				break;
			}

		for(i=0; i<n; i++)
			if(marky[i] == 0)
			{
				xx[n-1][1] = i;
				//printf("%d\n", i);
				break;
			}

		double minr = (double)INT_MAX;
		for(i=0; i<n; i++)
			if(minr > a[xx[i][0]][xx[i][1]])
				minr = a[xx[i][0]][xx[i][1]];

		if(minu > minr)
		{
			minu = minr;
			lawl = iii;
		}
	}
		
	x = lawl;
	y = 0;

	int markx[n+1], marky[n+1], maxx;

	for(i=0; i<n; i++)
		markx[i] = marky[i] = 0;

	int xx[n+1][2];

	for(ii=0; ii<n-1; ii++)
	{
		//printf("%d %d %lf\n", x, y, a[x][y]);
		//
		xx[ii][0] = x;
		xx[ii][1] = y;

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
		}
		for(j=0; j<n; j++)
		{
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
			xx[n-1][0] = i;
			//			printf("%d ", i);
			break;
		}

	for(i=0; i<n; i++)
		if(marky[i] == 0)
		{
			xx[n-1][1] = i;
			//printf("%d\n", i);
			break;
		}

	int temp;

	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(xx[i][0] > xx[j][0])
			{
				temp = xx[i][0];
				xx[i][0] = xx[j][0];
				xx[j][0] = temp;
				temp = xx[i][1];
				xx[i][1] = xx[j][1];
				xx[j][1] = temp;
			}

	for(i=0; i<n; i++)
		printf("%d %d\n", xx[i][0], xx[i][1]);

	return 0;
}

