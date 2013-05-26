#include<cstdio>
#include<limits.h>
int main()
{
	int n, ii, i, j, x, y, oldx, oldy, minx, miny;
	double min;

	scanf("%d", &n);

	double a[n+1][n+1];

	x = y = 0;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%lf", &a[i][j]);

	int markx[100000] = {0};
	int marky[100000] = {0}, maxx;
	int rowmaxx[100000], rowmaxy[100000];

	for(i=0; i<n; i++)
	{
		rowmaxy[i] = 0;
		for(j=0; j<n; j++)
			if(a[i][rowmaxy[i]] < a[i][j])
				rowmaxy[i] = j;
	}

	min = (double)INT_MAX;
	for(i=0; i<n; i++)
		if(min > a[i][rowmaxy[i]])
		{
			min = a[i][rowmaxy[i]];
			minx = i;
			miny = rowmaxy[i];
		}

	printf("%d %d %lf\n", minx, miny, a[minx][miny]);
}


