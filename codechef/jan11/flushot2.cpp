#include<cstdio>
long long int abs(long long int a)
{
	if(a < 0)
		return -a;
	return a;
}

long long int t, *a;
long long int n;

void f()
{
	long long int i, j, k;
	long long int c, v, diff;

	i = 0;
	while(1)
	{
		j=i+1;
		c = 1;
		while(j != n && c*t >= a[j] - a[i])
		{
			j++;
			c++;
		}

		v = a[j-1]-a[i];
		diff = (c-1)*t-v;

		a[i] -= diff/2;
		a[j-1] += diff/2;

		for(k=i+1; k<j-1; k++)
			a[k] = a[k-1] + t;

		i = j;

//		for(int ii=0; ii<n; ii++)
//			printf("%lld ", a[ii]);
//		printf("\n");

		if(i >= n)
			break;
	}

	if(a[0] < 0)
	{
		v = a[0];
		for(i=0; i<n; i++)
			a[i] -= v;
	}
}

int main()
{
	long long int no, i, j, c, k, diff, max;
	double t1;

	scanf("%lld", &no);

	while(no--)
	{
		scanf("%lld %lf", &n, &t1);

		t1 *= 10000.0;
		t = (long long int)t1;

		long long int b[n+1];

		a = new long long int[n+1];

		for(i=0; i<n; i++)
		{
			scanf("%lf", &t1);

			t1 *= 10000.0;
			b[i] = a[i] = (long long int)t1;
		}

//		for(i=0; i<n; i++)
//			printf("%lld ", a[i]);
//		printf("\n");

//		while(f() == 0);

		f();

		max = -1;
		for(i=0; i<n; i++)
		{
			diff = abs(b[i]-a[i]);

			if(max < diff)
				max = diff;
		}

		printf("%lld.", max/10000);

		long long int p1 = max%10000;

		if(p1 < 10)
			printf("000");
		else if(p1 < 100)
			printf("00");
		else if(p1 < 1000)
			printf("0");

		printf("%lld\n", p1);
	}

	return 0;
}
