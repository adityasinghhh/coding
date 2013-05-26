#include<cstdio>
double abs(double a)
{
	if(a < 0.00000001)
		return -a;
	return a;
}

double t, *a;
int n;

int f()
{
	int i, j, k;
	double c, v, diff;

	i = 0;
	while(1)
	{
		j=i+1;
		c = 1.0;
		while(j !=n && c*t - a[j] + a[i] >= 0.00000001)
		{
			j++;
			c+=1.0;
		}

		if(c*t - a[j] + a[i] >= 0.0000000001)
			return 1;

		v = a[j-1]-a[i];
		diff = (c-1)*t-v;

		a[i] -= diff/2.000000000000;
		a[j-1] += diff/2.000000000000;

		for(k=i+1; k<j-1; k++)
			a[k] = a[k-1] + t;

		i = j;

		if(i >= n)
			break;
	}

	if(a[0] < 0.00000001)
	{
		v = a[0];
		for(i=0; i<n; i++)
			a[i] -= v;
	}

	return 0;
}

int main()
{
	int no, i, j, c, k;
	double diff, max;

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d %lf", &n, &t);

		double b[n+1];

		a = new double[n+1];

		for(i=0; i<n; i++)
		{
			scanf("%lf", &a[i]);
			b[i] = a[i];
		}

		while(f() == 0);

		max = -1.0;
		for(i=0; i<n; i++)
		{
			diff = abs(b[i]-a[i]);

			if(max - diff <  0.00000001)
				max = diff;
		}

		printf("%.4lf\n", max);
	}

	return 0;
}
